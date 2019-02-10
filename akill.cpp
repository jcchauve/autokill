//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "akill.h"

#include "piduti.h"
#include <stdio.h>

#include "WindowList.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MAX_TASKS           256

TAutoKill *AutoKill;

//---------------------------------------------------------------------------
__fastcall TAutoKill::TAutoKill(TComponent* Owner)
        : TForm(Owner)
{
    bool lAuto = false;
    AutoHide = false;
    mAutoShutdown= false;
    GridList->ColCount = 4;
    GridList->Cells[0][0]="Program Name";
    GridList->Cells[1][0]="Pid";
    GridList->Cells[2][0]="Hwnd";
    GridList->Cells[3][0]="Caption";


    GridList->RowCount = 2;

// Determine what system we're on and do the right thing
    //
    mVerInfo ;
    mVerInfo.dwOSVersionInfoSize = sizeof (mVerInfo);
    GetVersionEx(&mVerInfo);

    switch (mVerInfo.dwPlatformId)
    {
    case VER_PLATFORM_WIN32_NT:
       GetTaskList     = GetTaskListNT;
       EnableDebugPriv = EnableDebugPrivNT;
       break;

    case VER_PLATFORM_WIN32_WINDOWS:
       GetTaskList = GetTaskList95;
       EnableDebugPriv = EnableDebugPriv95;
       break;

    default:
       //printf ("tlist requires Windows NT or Windows 95\n");
       return ;
    }
    EnableDebugPriv(SE_DEBUG_NAME);
    EnableDebugPriv(SE_SHUTDOWN_NAME);
    ChkAutoHide->Checked = false;
    if ((_argc>1))
    {
      int li;
      AnsiString lPrg="";
      for (li=1;li<_argc;li++)
      {
        char *lArg =_argv[li];
        AnsiString lPrg1 = lArg;
        lPrg = lPrg.LowerCase();
        if (lArg[0]=='-')
        {
          if (lPrg1=="-auto")
          {
            lAuto = true;
          }
          if (lPrg1=="-autohide")
          {
            ChkAutoHide->Checked=true;
          }

          if (lPrg1=="-hide")
          {
            AutoHide = true;
          }
          if (lPrg1=="-shutdown")
          {
            mAutoShutdown = true;
          }
        }
        else
        {
          lPrg = lPrg1;
        }
      }
      ChkAutomKill->Checked = lAuto;
      if (lPrg!="")
      {
            //EdtName->Text = lPrg;
            GridList->Cells[0][1]=lPrg;
            //PshGetPidClick(PshGetPid);

            if (lAuto)
            {
              PshGetPidClick(0);
              PshKillClick(0);
            }
            if (AutoHide)
            {
              PshHideClick(0);
              //Visible = false;
            }
      }
    }

}
//---------------------------------------------------------------------------
void __fastcall TAutoKill::PshKillClick(TObject *Sender)
{
    DWORD             ThisPid;




    TASK_LIST   lpTList[MAX_TASKS];
    int li;

            //
  for (li=1;li<GridList->RowCount;li++)
  {
    //unsigned int lPid = EdtPid->Text.ToDouble();
    unsigned int lPid = GridList->Cells[1][li].ToIntDef(0);
    if (lPid) {
        lpTList[0].dwProcessId = lPid;
        if (KillProcess( lpTList, TRUE )) {
            printf( "process #%d killed\n", lPid );
            return ;
        } else {
            printf( "process #%d could not be killed\n", lPid );
            return ;
        }
    }
    if (mAutoShutdown)
    {
      //rundll32.exe shell32.dll,SHExitWindowsEx 5
      //SHExitWindowsEx(5);
      //ExitWindowsEx(EWX_SHUTDOWN+EWX_FORCE+EWX_POWEROFF,0xFFFFFFFF);
      //ExitWindowsEx(EWX_SHUTDOWN+EWX_FORCE,0xFFFFFFFF);
      //ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF);
      //ExitWindowsEx(EWX_SHUTDOWN,0xFFFFFFFF);
      if (mVerInfo.dwPlatformId==VER_PLATFORM_WIN32_NT)
      {
        ExitWindowsEx(EWX_POWEROFF+EWX_FORCE,0xFFFFFFFF);
      }
      else
      {
        ExitWindowsEx(EWX_SHUTDOWN,0xFFFFFFFF);
      }
      //system("rundll32.exe shell32.dll,SHExitWindowsEx 5");
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TAutoKill::PshGetPidClick(TObject *Sender)
{
        //
    // get the task list for the system
    //
 TASK_LIST   lpTList[MAX_TASKS];
 int ThisPid = GetCurrentProcessId();
 int numTasks = GetTaskList( lpTList, MAX_TASKS );
 int lLigne;
 TWindowList *lpWindowList = new TWindowList(this);
 TList *lpListe =lpWindowList->mLst;
 TWindowObject *lpWObj;

  for (lLigne=1;lLigne<GridList->RowCount;lLigne++)
  {

    //AnsiString lNameCh = EdtName->Text.UpperCase();
    AnsiString lNameCh = GridList->Cells[0][lLigne].UpperCase();

    TASK_LIST_ENUM    te;


    //
    // enumerate all windows and try to get the window
    // titles for each task
    //
    te.tlist = lpTList;
    te.numtasks = numTasks;
    GetWindowTitles( &te );


    int li,lj;
    //EdtPid->Text = "0";
    GridList->Cells[1][lLigne]="0";
    for (li=0;li<numTasks;li++)
    {
            AnsiString lName=lpTList[li].ProcessName ;
            lName = lName.UpperCase();
            if (lName.AnsiPos(lNameCh)>0)
            {
                //EdtPid->Text = lpTList[li].dwProcessId;
                GridList->Cells[1][lLigne]=AnsiString(lpTList[li].dwProcessId);
                GridList->Cells[2][lLigne]=AnsiString(int(lpTList[li].hwnd));
                GridList->Cells[3][lLigne]=AnsiString(lpTList[li].WindowTitle);
                /*
                for (lj=0;lj<lpListe->Count;lj++)
                {
                  //lpWObj =lpWindowList->Windows[lj];
                  lpWObj =(TWindowObject*) lpListe->Items[lj];
                  if ((lpWObj->WinCaption!="") &&(lpWObj->IsVisible))
                  {
                    if (lpWObj->ProcessID==lpTList[li].dwProcessId)
                    {

                      GridList->Cells[2][lLigne]= (int)lpWObj->WinHandle;
                      GridList->Cells[3][lLigne]= lpWObj->WinCaption;
                      break;
                    }
                  }

                } */
                li = numTasks;
            }
    }
    GridList->Refresh();
    delete lpWindowList;
  }
}
//---------------------------------------------------------------------------
void __fastcall TAutoKill::Timer1Timer(TObject *Sender)
{
  static int iii = 0;

        if (ChkAutomKill->Checked && iii==0)
        {
                PshGetPidClick(0);
                PshKillClick(0);
                fAutoHide();
        }
        if (ChkAutoHide->Checked && iii==0)
        {
                PshGetPidClick(0);
                PshHideProcessClick(0);
                fAutoHide();
        }
        if (EdtBox->Text!="")
        {
           TWindowList *lpWindowList = new TWindowList(this);
           //TList *lpListe =lpWindowList->mLst;
           int li;
           TWindowObject lObject;
           AnsiString lCher=EdtBox->Text.UpperCase();
           FILE * lFile=fopen("wlist.txt","wt");
           for (li=0;li<lpWindowList->Count;li++)
           {
            try
            {
              lObject=lpWindowList->Windows[li];
              AnsiString lCaption=lObject.WinCaption.UpperCase();
              fprintf(lFile,"%s\n",lCaption.c_str());
              if (lCaption.Pos(lCher)>0)
              {
                int aaa=1;
                void * lHandle=lObject.WinHandle;
                //SendMessage(lHandle,WM_KEYDOWN,VK_ALT+VK_I);
				SendMessage((HWND)lHandle,WM_LBUTTONDOWN,0,0);
                SendMessage((HWND)lHandle,WM_LBUTTONUP,0,0);
              }
            }
            catch ( Exception &Ex)
            {
              1;
            }
           }
           fclose(lFile);
           delete lpWindowList;

        }
        iii=(iii+1) % 10;
}
//---------------------------------------------------------------------------

void __fastcall TAutoKill::QuitClick(TObject *Sender)
{
        	Application->Terminate();;
}
//---------------------------------------------------------------------------

void __fastcall TAutoKill::PshHideClick(TObject *Sender)
{
        Hide();
}
//---------------------------------------------------------------------------

void __fastcall TAutoKill::FormCreate(TObject *Sender)
{
        if (AutoHide)
        {
          PshHideClick(0);
        }

}
//---------------------------------------------------------------------------


void TAutoKill::fAutoHide()
{
      if (AutoHide)
        {
          PshHideClick(0);
        }

}


//---------------------------------------------------------------------------



void __fastcall TAutoKill::GridListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key==VK_INSERT)
  {
      GridList->RowCount++;
  }
  if (Key==VK_DELETE && GridList->RowCount>2)
  {
      GridList->RowCount--;
  }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TAutoKill::PshHideProcessClick(TObject *Sender)
{
  int li;
  for (li=1;li<GridList->RowCount;li++)
  {
    //unsigned int lPid = EdtPid->Text.ToDouble();
    HANDLE   lHwnd = (HANDLE)(GridList->Cells[2][li].ToIntDef(0));
    if (lHwnd)
    {
      ShowWindow((HWND)lHwnd,SW_HIDE);
    }
  }
}
//---------------------------------------------------------------------------

