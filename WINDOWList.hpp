// CodeGear C++Builder
// Copyright (c) 1995, 2015 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WindowList.pas' rev: 29.00 (Windows)

#ifndef WindowlistHPP
#define WindowlistHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Windowlist
{
//-- forward type declarations -----------------------------------------------
struct TWindowObject;
class DELPHICLASS TWindowList;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TWindowObject
{
public:
	HWND WinHandle;
	System::UnicodeString WinCaption;
	int ProcessID;
	bool IsVisible;
	bool IsEnabled;
	bool IsIconic;
	System::Types::TRect WindowRect;
};


typedef TWindowObject *PTWindowObject;

class PASCALIMPLEMENTATION TWindowList : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* WindowLst;
	int FCount;
	
protected:
	TWindowObject __fastcall GetAWindow(int Index);
	
public:
	__fastcall virtual TWindowList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TWindowList(void);
	void __fastcall Refresh(void);
	__property TWindowObject Windows[int Index] = {read=GetAWindow};
	__property int Count = {read=FCount, nodefault};
	__property System::Classes::TList* mLst = {read=WindowLst};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Windowlist */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINDOWLIST)
using namespace Windowlist;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WindowlistHPP
