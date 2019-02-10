//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("autokill.res");
USEFORM("akill.cpp", AutoKill);
USEUNIT("piduti.cpp");
USEUNIT("WindowList.pas");
//---------------------------------------------------------------------------
WINAPI int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	   try
	   {
			  Application->Initialize();
			  Application->Title = "Auto Kill";
     Application->CreateForm(__classid(TAutoKill), &AutoKill);
     Application->Run();
	   }
	   catch (Exception &exception)
	   {
			  Application->ShowException(&exception);
	   }
	   return 0;
}
//---------------------------------------------------------------------------
