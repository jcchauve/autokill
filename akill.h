//---------------------------------------------------------------------------

#ifndef akillH
#define akillH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "piduti.h"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//#include "ThemeMgr.hpp"
//---------------------------------------------------------------------------
class TAutoKill : public TForm
{
__published:	// Composants gérés par l'EDI
        TButton *PshGetPid;
        TButton *PshKill;
        TTimer *Timer1;
        TButton *Quit;
  TCheckBox *ChkAutomKill;
        TButton *PshHide;
  TStringGrid *GridList;
  TButton *PshHideProcess;
  TCheckBox *ChkAutoHide;
  TLabel *BoxButton;
  TEdit *EdtBox;
        void __fastcall PshKillClick(TObject *Sender);
        void __fastcall PshGetPidClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall QuitClick(TObject *Sender);
        void __fastcall PshHideClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall GridListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall PshHideProcessClick(TObject *Sender);

//  void __fastcall OnActivate(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
        __fastcall TAutoKill(TComponent* Owner);
        LPGetTaskList     GetTaskList;
        LPEnableDebugPriv EnableDebugPriv;
        bool AutoHide;
        void fAutoHide();
        bool mAutoShutdown;
        OSVERSIONINFO     mVerInfo ;

};
//---------------------------------------------------------------------------
extern PACKAGE TAutoKill *AutoKill;
//---------------------------------------------------------------------------
#endif
