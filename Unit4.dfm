object Form4: TForm4
  Left = 751
  Top = 106
  BorderStyle = bsToolWindow
  Caption = #37682#38899#20013
  ClientHeight = 96
  ClientWidth = 261
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 67
    Height = 12
    Caption = #20986#21147#12501#12449#12452#12523':'
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 68
    Height = 12
    Caption = #26360#36796#12496#12452#12488#25968':'
  end
  object FileName: TEdit
    Left = 88
    Top = 8
    Width = 165
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 0
  end
  object Written: TEdit
    Left = 88
    Top = 36
    Width = 165
    Height = 20
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 1
  end
  object CloseButton: TButton
    Left = 180
    Top = 64
    Width = 75
    Height = 25
    Cancel = True
    Caption = #38281#12376#12427
    Default = True
    TabOrder = 2
  end
end
