object Form2: TForm2
  Left = 269
  Top = 148
  BorderStyle = bsDialog
  Caption = 'midi-in'#35373#23450
  ClientHeight = 268
  ClientWidth = 275
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 113
    Height = 12
    Caption = #12471#12473#12486#12512#12513#12483#12475#12540#12472' ->'
  end
  object Label2: TLabel
    Left = 20
    Top = 40
    Width = 46
    Height = 12
    Caption = 'CH 1 -> '
  end
  object Label3: TLabel
    Left = 20
    Top = 64
    Width = 46
    Height = 12
    Caption = 'CH 2 -> '
  end
  object Label4: TLabel
    Left = 20
    Top = 88
    Width = 46
    Height = 12
    Caption = 'CH 3 -> '
  end
  object Label5: TLabel
    Left = 20
    Top = 112
    Width = 46
    Height = 12
    Caption = 'CH 4 -> '
  end
  object Label6: TLabel
    Left = 20
    Top = 136
    Width = 46
    Height = 12
    Caption = 'CH 5 -> '
  end
  object Label7: TLabel
    Left = 20
    Top = 160
    Width = 46
    Height = 12
    Caption = 'CH 6 -> '
  end
  object Label8: TLabel
    Left = 20
    Top = 184
    Width = 46
    Height = 12
    Caption = 'CH 7 -> '
  end
  object Label9: TLabel
    Left = 20
    Top = 208
    Width = 46
    Height = 12
    Caption = 'CH 8 -> '
  end
  object Label10: TLabel
    Left = 148
    Top = 40
    Width = 46
    Height = 12
    Caption = 'CH 9 -> '
  end
  object Label11: TLabel
    Left = 148
    Top = 64
    Width = 48
    Height = 12
    Caption = 'CH10 -> '
  end
  object Label12: TLabel
    Left = 148
    Top = 88
    Width = 48
    Height = 12
    Caption = 'CH11 -> '
  end
  object Label13: TLabel
    Left = 148
    Top = 112
    Width = 48
    Height = 12
    Caption = 'CH12 -> '
  end
  object Label14: TLabel
    Left = 148
    Top = 136
    Width = 48
    Height = 12
    Caption = 'CH13 -> '
  end
  object Label15: TLabel
    Left = 148
    Top = 160
    Width = 48
    Height = 12
    Caption = 'CH14 -> '
  end
  object Label16: TLabel
    Left = 148
    Top = 184
    Width = 48
    Height = 12
    Caption = 'CH15 -> '
  end
  object Label17: TLabel
    Left = 148
    Top = 208
    Width = 48
    Height = 12
    Caption = 'CH16 -> '
  end
  object Port: TComboBox
    Left = 128
    Top = 8
    Width = 137
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 0
    Text = 'port1 (CH 1'#65374'CH16)'
    Items.Strings = (
      'port1 (CH 1'#65374'CH16)'
      'port2 (CH17'#65374'CH32)'
      'port3 (CH33'#65374'CH48)'
      'port4 (CH49'#65374'CH64)')
  end
  object Button1: TButton
    Left = 104
    Top = 236
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 188
    Top = 236
    Width = 75
    Height = 25
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 2
  end
  object ChannelMap1: TComboBox
    Left = 68
    Top = 36
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 3
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap2: TComboBox
    Left = 68
    Top = 60
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 4
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap3: TComboBox
    Left = 68
    Top = 84
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 5
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap4: TComboBox
    Left = 68
    Top = 108
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 6
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap5: TComboBox
    Left = 68
    Top = 132
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 7
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap6: TComboBox
    Left = 68
    Top = 156
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 8
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap7: TComboBox
    Left = 68
    Top = 180
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 9
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap8: TComboBox
    Left = 68
    Top = 204
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 10
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap9: TComboBox
    Left = 196
    Top = 36
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 11
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap10: TComboBox
    Left = 196
    Top = 60
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 12
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap11: TComboBox
    Left = 196
    Top = 84
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 13
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap12: TComboBox
    Left = 196
    Top = 108
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 14
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap13: TComboBox
    Left = 196
    Top = 132
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 15
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap14: TComboBox
    Left = 196
    Top = 156
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 16
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap15: TComboBox
    Left = 196
    Top = 180
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 17
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
  object ChannelMap16: TComboBox
    Left = 196
    Top = 204
    Width = 57
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 18
    Text = 'CH 1'
    Items.Strings = (
      'CH 1'
      'CH 2'
      'CH 3'
      'CH 4'
      'CH 5'
      'CH 6'
      'CH 7'
      'CH 8'
      'CH 9'
      'CH10'
      'CH11'
      'CH12'
      'CH13'
      'CH14'
      'CH15'
      'CH16'
      'CH17'
      'CH18'
      'CH19'
      'CH20'
      'CH21'
      'CH22'
      'CH23'
      'CH24'
      'CH25'
      'CH26'
      'CH27'
      'CH28'
      'CH29'
      'CH30'
      'CH31'
      'CH32'
      'CH33'
      'CH34'
      'CH35'
      'CH36'
      'CH37'
      'CH38'
      'CH39'
      'CH40'
      'CH41'
      'CH42'
      'CH43'
      'CH44'
      'CH45'
      'CH46'
      'CH47'
      'CH48'
      'CH49'
      'CH50'
      'CH51'
      'CH52'
      'CH53'
      'CH54'
      'CH55'
      'CH56'
      'CH57'
      'CH58'
      'CH59'
      'CH60'
      'CH61'
      'CH62'
      'CH63'
      'CH64')
  end
end
