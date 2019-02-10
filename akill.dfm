object AutoKill: TAutoKill
  Left = 190
  Top = 145
  Caption = 'AutoKill'
  ClientHeight = 303
  ClientWidth = 427
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    427
    303)
  PixelsPerInch = 96
  TextHeight = 13
  object BoxButton: TLabel
    Left = 8
    Top = 224
    Width = 49
    Height = 13
    Caption = 'BoxButton'
  end
  object PshGetPid: TButton
    Left = 292
    Top = 14
    Width = 75
    Height = 25
    Caption = 'GetPid'
    TabOrder = 0
    OnClick = PshGetPidClick
  end
  object PshKill: TButton
    Left = 292
    Top = 46
    Width = 75
    Height = 25
    Caption = 'Kill'
    TabOrder = 1
    OnClick = PshKillClick
  end
  object Quit: TButton
    Left = 292
    Top = 108
    Width = 75
    Height = 25
    Caption = 'Quit'
    TabOrder = 2
    OnClick = QuitClick
  end
  object ChkAutomKill: TCheckBox
    Left = 290
    Top = 192
    Width = 81
    Height = 17
    Caption = 'Auto Kill'
    TabOrder = 3
  end
  object PshHide: TButton
    Left = 292
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Hide AutoKill'
    TabOrder = 4
    OnClick = PshHideClick
  end
  object GridList: TStringGrid
    Left = 6
    Top = 12
    Width = 310
    Height = 239
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 2
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    TabOrder = 5
    OnKeyDown = GridListKeyDown
  end
  object PshHideProcess: TButton
    Left = 320
    Top = 76
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Hide Process'
    TabOrder = 6
    OnClick = PshHideProcessClick
  end
  object ChkAutoHide: TCheckBox
    Left = 320
    Top = 212
    Width = 71
    Height = 17
    Anchors = [akTop, akRight]
    Caption = 'Auto Hide'
    TabOrder = 7
  end
  object EdtBox: TEdit
    Left = 96
    Top = 250
    Width = 222
    Height = 21
    Anchors = [akLeft, akRight, akBottom]
    TabOrder = 8
    Text = 'Ignore'
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 220
    Top = 132
  end
end
