// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WindowList.pas' rev: 5.00

#ifndef WindowListHPP
#define WindowListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Windowlist
{
//-- type declarations -------------------------------------------------------
struct TWindowObject
{
	HWND WinHandle;
	AnsiString WinCaption;
	int ProcessID;
	bool IsVisible;
	bool IsEnabled;
	bool IsIconic;
	Windows::TRect WindowRect;
} ;

typedef TWindowObject *PTWindowObject;

class DELPHICLASS TWindowList;
class PASCALIMPLEMENTATION TWindowList : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TList* WindowLst;
	int FCount;
	
protected:
	TWindowObject __fastcall GetAWindow(int Index);
	
public:
	__fastcall virtual TWindowList(Classes::TComponent* AOwner);
	__fastcall virtual ~TWindowList(void);
	void __fastcall Refresh(void);
	__property TWindowObject Windows[int Index] = {read=GetAWindow};
	__property int Count = {read=FCount, nodefault};
	__property Classes::TList* mLst = {read=WindowLst};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Windowlist */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Windowlist;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WindowList
