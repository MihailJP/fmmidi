object Form3: TForm3
  Left = 260
  Top = 137
  BorderStyle = bsToolWindow
  Caption = #38899#33394#32232#38598
  ClientHeight = 156
  ClientWidth = 520
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label3: TLabel
    Left = 44
    Top = 36
    Width = 16
    Height = 12
    Caption = 'AR'
  end
  object Label4: TLabel
    Left = 92
    Top = 36
    Width = 16
    Height = 12
    Caption = 'DR'
  end
  object Label5: TLabel
    Left = 140
    Top = 36
    Width = 15
    Height = 12
    Caption = 'SR'
  end
  object Label6: TLabel
    Left = 188
    Top = 36
    Width = 16
    Height = 12
    Caption = 'RR'
  end
  object Label7: TLabel
    Left = 236
    Top = 36
    Width = 13
    Height = 12
    Caption = 'SL'
  end
  object Label8: TLabel
    Left = 284
    Top = 36
    Width = 13
    Height = 12
    Caption = 'TL'
  end
  object Label9: TLabel
    Left = 332
    Top = 36
    Width = 14
    Height = 12
    Caption = 'KS'
  end
  object Label10: TLabel
    Left = 380
    Top = 36
    Width = 15
    Height = 12
    Caption = 'ML'
  end
  object Label11: TLabel
    Left = 428
    Top = 36
    Width = 15
    Height = 12
    Caption = 'DT'
  end
  object Label12: TLabel
    Left = 8
    Top = 56
    Width = 21
    Height = 12
    Caption = 'OP1'
  end
  object Label13: TLabel
    Left = 8
    Top = 80
    Width = 21
    Height = 12
    Caption = 'OP2'
  end
  object Label14: TLabel
    Left = 8
    Top = 104
    Width = 21
    Height = 12
    Caption = 'OP3'
  end
  object Label15: TLabel
    Left = 8
    Top = 128
    Width = 21
    Height = 12
    Caption = 'OP4'
  end
  object Label17: TLabel
    Left = 476
    Top = 36
    Width = 24
    Height = 12
    Caption = 'AMS'
  end
  object Label16: TLabel
    Left = 160
    Top = 12
    Width = 21
    Height = 12
    Caption = 'LFO'
  end
  object Label2: TLabel
    Left = 88
    Top = 12
    Width = 15
    Height = 12
    Caption = 'FB'
  end
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 22
    Height = 12
    Caption = 'ALG'
  end
  object ComboProgram: TComboBox
    Left = 244
    Top = 8
    Width = 193
    Height = 20
    Style = csDropDownList
    ItemHeight = 12
    ItemIndex = 0
    TabOrder = 0
    Text = '  0 '#12464#12521#12531#12489#12500#12450#12494
    OnChange = ComboProgramChange
    Items.Strings = (
      '  0 '#12464#12521#12531#12489#12500#12450#12494
      '  1 '#12502#12521#12452#12488#12500#12450#12494
      '  2 '#12456#12524#12463#12488#12522#12483#12463#12464#12521#12531#12489#12500#12450#12494
      '  3 '#12507#12531#12461#12540#12488#12531#12463
      '  4 '#12456#12524#12463#12488#12522#12483#12463#12500#12450#12494'1'
      '  5 '#12456#12524#12463#12488#12522#12483#12463#12500#12450#12494'2'
      '  6 '#12495#12540#12503#12471#12467#12540#12489
      '  7 '#12463#12521#12499
      '  8 '#12481#12455#12524#12473#12479
      '  9 '#37444#29748
      ' 10 '#12458#12523#12468#12540#12523
      ' 11 '#12499#12502#12521#12501#12457#12531
      ' 12 '#12510#12522#12531#12496
      ' 13 '#26408#29748
      ' 14 '#12481#12517#12540#12502#12521#12540#12505#12523
      ' 15 '#12480#12523#12471#12510#12540
      ' 16 '#12489#12525#12540#12496#12540#12458#12523#12460#12531
      ' 17 '#12497#12540#12459#12483#12471#12502#12458#12523#12460#12531
      ' 18 '#12525#12483#12463#12458#12523#12460#12531
      ' 19 '#12497#12452#12503#12458#12523#12460#12531
      ' 20 '#12522#12540#12489#12458#12523#12460#12531
      ' 21 '#12450#12467#12540#12487#12451#12458#12531
      ' 22 '#12495#12540#12514#12491#12459
      ' 23 '#12496#12531#12489#12493#12458#12531
      ' 24 '#12490#12452#12525#12531#24358#12462#12479#12540
      ' 25 '#12473#12481#12540#12523#24358#12462#12479#12540
      ' 26 '#12456#12524#12461#12462#12479#12540'/'#12472#12515#12474
      ' 27 '#12456#12524#12461#12462#12479#12540'/'#12463#12522#12540#12531
      ' 28 '#12456#12524#12461#12462#12479#12540'/'#12511#12517#12540#12488
      ' 29 '#12456#12524#12461#12462#12479#12540'/'#12458#12540#12496#12540#12489#12521#12452#12502
      ' 30 '#12456#12524#12461#12462#12479#12540'/'#12487#12451#12473#12488#12540#12471#12519#12531
      ' 31 '#12462#12479#12540#12495#12540#12514#12491#12463#12473
      ' 32 '#12505#12540#12473
      ' 33 '#12456#12524#12461#12505#12540#12473'/'#12501#12451#12531#12460#12540
      ' 34 '#12456#12524#12461#12505#12540#12473'/'#12500#12483#12463
      ' 35 '#12501#12524#12483#12488#12524#12473#12505#12540#12473
      ' 36 '#12473#12521#12483#12503#12505#12540#12473'1'
      ' 37 '#12473#12521#12483#12503#12505#12540#12473'2'
      ' 38 '#12471#12531#12475#12505#12540#12473'1'
      ' 39 '#12471#12531#12475#12505#12540#12473'2'
      ' 40 '#12496#12452#12458#12522#12531
      ' 41 '#12499#12458#12521
      ' 42 '#12481#12455#12525
      ' 43 '#12467#12531#12488#12521#12496#12473
      ' 44 '#12488#12524#12514#12525#12473#12488#12522#12531#12464#12473
      ' 45 '#12500#12481#12459#12540#12488
      ' 46 '#12495#12540#12503
      ' 47 '#12486#12451#12531#12497#12491
      ' 48 '#12473#12488#12522#12531#12464#12473
      ' 49 '#12473#12525#12540#12473#12488#12522#12531#12464#12473
      ' 50 '#12471#12531#12475#12473#12488#12522#12531#12464#12473'1'
      ' 51 '#12471#12531#12475#12473#12488#12522#12531#12464#12473'2'
      ' 52 '#12463#12527#12452#12450
      ' 53 '#12508#12452#12473
      ' 54 '#12471#12531#12475#12508#12452#12473
      ' 55 '#12458#12540#12465#12473#12488#12521#12498#12483#12488
      ' 56 '#12488#12521#12531#12506#12483#12488
      ' 57 '#12488#12525#12531#12508#12540#12531
      ' 58 '#12481#12517#12540#12496
      ' 59 '#12488#12521#12531#12506#12483#12488'/'#12511#12517#12540#12488
      ' 60 '#12507#12523#12531
      ' 61 '#12502#12521#12473
      ' 62 '#12471#12531#12475#12502#12521#12473'1'
      ' 63 '#12471#12531#12475#12502#12521#12473'2'
      ' 64 '#12477#12503#12521#12494#12469#12483#12463#12473
      ' 65 '#12450#12523#12488#12469#12483#12463#12473
      ' 66 '#12486#12490#12540#12469#12483#12463#12473
      ' 67 '#12496#12522#12488#12531#12469#12483#12463#12473
      ' 68 '#12458#12540#12508#12456
      ' 69 '#12452#12531#12464#12522#12483#12471#12517#12507#12523#12531
      ' 70 '#12496#12473#12540#12531
      ' 71 '#12463#12521#12522#12493#12483#12488
      ' 72 '#12500#12483#12467#12525
      ' 73 '#12501#12523#12540#12488
      ' 74 '#12522#12467#12540#12480#12540
      ' 75 '#12497#12531#12501#12523#12540#12488
      ' 76 '#12508#12488#12523#12502#12525#12540
      ' 77 '#23610#20843
      ' 78 '#12507#12452#12483#12473#12523
      ' 79 '#12458#12459#12522#12490
      ' 80 '#30697#24418#27874
      ' 81 '#19977#35282#27874
      ' 82 '#12459#12522#12458#12505
      ' 83 '#12481#12501#12449#12540
      ' 84 '#12481#12515#12521#12531#12464
      ' 85 '#12477#12525#12508#12483#12463#12473
      ' 86 '#12501#12451#12501#12473#12522#12540#12489
      ' 87 '#12505#12540#12473#65286#12522#12540#12489
      ' 88 '#12501#12449#12531#12479#12472#12450
      ' 89 '#12454#12457#12540#12512#12497#12483#12489
      ' 90 '#12509#12522#12471#12531#12475
      ' 91 '#12473#12506#12540#12473#12463#12527#12452#12450
      ' 92 '#12464#12521#12473#12495#12540#12514#12491#12459
      ' 93 '#12513#12479#12522#12483#12463#12497#12483#12489
      ' 94 '#12504#12452#12525#12540#12497#12483#12489
      ' 95 '#12473#12452#12540#12503#12497#12483#12489
      ' 96 '#12450#12452#12473#12524#12452#12531
      ' 97 '#12469#12454#12531#12489#12488#12521#12483#12463
      ' 98 '#12463#12522#12473#12479#12523
      ' 99 '#12450#12488#12514#12473#12501#12451#12450
      '100 '#12502#12521#12452#12488#12493#12473
      '101 '#12468#12502#12522#12531
      '102 '#12456#12467#12540#12489#12525#12483#12503
      '103 '#12469#12452#12456#12531#12473#12501#12451#12463#12471#12519#12531
      '104 '#12471#12479#12540#12523
      '105 '#12496#12531#12472#12519#12540
      '106 '#19977#21619#32218
      '107 '#29748
      '108 '#12459#12522#12531#12496
      '109 '#12496#12464#12497#12452#12503
      '110 '#12501#12451#12540#12489#12523
      '111 '#12471#12515#12490#12452
      '112 '#12486#12451#12531#12463#12523#12505#12523
      '113 '#12450#12468#12468
      '114 '#12473#12481#12540#12523#12489#12521#12512
      '115 '#12454#12483#12489#12502#12525#12483#12463
      '116 '#22826#40723
      '117 '#12513#12525#12487#12451#12483#12463#12479#12512
      '118 '#12471#12531#12475#12489#12521#12512
      '119 '#12522#12496#12540#12473#12471#12531#12496#12523
      '120 '#12462#12479#12540#12501#12524#12483#12489#12494#12452#12474
      '121 '#12502#12524#12473#12494#12452#12474
      '122 '#27874
      '123 '#40165#12398#12373#12360#12378#12426
      '124 '#38651#35441#12398#12505#12523
      '125 '#12504#12522#12467#12503#12479#12540
      '126 '#25293#25163
      '127 '#37507#22768)
  end
  object Button1: TButton
    Left = 448
    Top = 8
    Width = 63
    Height = 25
    Caption = #28040#38899
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 36
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 2
    Text = '31'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AR1: TUpDown
    Left = 65
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit3
    Min = 0
    Max = 31
    Position = 31
    TabOrder = 3
    Wrap = False
  end
  object Edit4: TEdit
    Left = 84
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 4
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DR1: TUpDown
    Left = 113
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit4
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 5
    Wrap = False
  end
  object Edit5: TEdit
    Left = 132
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 6
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SR1: TUpDown
    Left = 161
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit5
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 7
    Wrap = False
  end
  object Edit6: TEdit
    Left = 180
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 8
    Text = '15'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object RR1: TUpDown
    Left = 209
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit6
    Min = 0
    Max = 15
    Position = 15
    TabOrder = 9
    Wrap = False
  end
  object Edit7: TEdit
    Left = 228
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 10
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SL1: TUpDown
    Left = 257
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit7
    Min = 0
    Max = 15
    Position = 0
    TabOrder = 11
    Wrap = False
  end
  object Edit8: TEdit
    Left = 276
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 12
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object TL1: TUpDown
    Left = 305
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit8
    Min = 0
    Max = 127
    Position = 0
    TabOrder = 13
    Wrap = False
  end
  object Edit9: TEdit
    Left = 324
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 14
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object KS1: TUpDown
    Left = 353
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit9
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 15
    Wrap = False
  end
  object Edit10: TEdit
    Left = 372
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 16
    Text = '1'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object ML1: TUpDown
    Left = 401
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit10
    Min = 0
    Max = 15
    Position = 1
    TabOrder = 17
    Wrap = False
  end
  object Edit11: TEdit
    Left = 420
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 18
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DT1: TUpDown
    Left = 449
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit11
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 19
    Wrap = False
  end
  object Edit12: TEdit
    Left = 36
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 20
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AR2: TUpDown
    Left = 65
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit12
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 21
    Wrap = False
  end
  object Edit13: TEdit
    Left = 84
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 22
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DR2: TUpDown
    Left = 113
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit13
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 23
    Wrap = False
  end
  object Edit14: TEdit
    Left = 132
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 24
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SR2: TUpDown
    Left = 161
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit14
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 25
    Wrap = False
  end
  object Edit15: TEdit
    Left = 180
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 26
    Text = '15'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object RR2: TUpDown
    Left = 209
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit15
    Min = 0
    Max = 15
    Position = 15
    TabOrder = 27
    Wrap = False
  end
  object Edit16: TEdit
    Left = 228
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 28
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SL2: TUpDown
    Left = 257
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit16
    Min = 0
    Max = 15
    Position = 0
    TabOrder = 29
    Wrap = False
  end
  object Edit17: TEdit
    Left = 276
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 30
    Text = '127'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object TL2: TUpDown
    Left = 305
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit17
    Min = 0
    Max = 127
    Position = 127
    TabOrder = 31
    Wrap = False
  end
  object Edit18: TEdit
    Left = 324
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 32
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object KS2: TUpDown
    Left = 353
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit18
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 33
    Wrap = False
  end
  object Edit19: TEdit
    Left = 372
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 34
    Text = '1'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object ML2: TUpDown
    Left = 401
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit19
    Min = 0
    Max = 15
    Position = 1
    TabOrder = 35
    Wrap = False
  end
  object Edit20: TEdit
    Left = 420
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 36
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DT2: TUpDown
    Left = 449
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit20
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 37
    Wrap = False
  end
  object Edit21: TEdit
    Left = 36
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 38
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AR3: TUpDown
    Left = 65
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit21
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 39
    Wrap = False
  end
  object Edit22: TEdit
    Left = 84
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 40
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DR3: TUpDown
    Left = 113
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit22
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 41
    Wrap = False
  end
  object Edit23: TEdit
    Left = 132
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 42
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SR3: TUpDown
    Left = 161
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit23
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 43
    Wrap = False
  end
  object Edit24: TEdit
    Left = 180
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 44
    Text = '15'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object RR3: TUpDown
    Left = 209
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit24
    Min = 0
    Max = 15
    Position = 15
    TabOrder = 45
    Wrap = False
  end
  object Edit25: TEdit
    Left = 228
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 46
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SL3: TUpDown
    Left = 257
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit25
    Min = 0
    Max = 15
    Position = 0
    TabOrder = 47
    Wrap = False
  end
  object Edit26: TEdit
    Left = 276
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 48
    Text = '127'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object TL3: TUpDown
    Left = 305
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit26
    Min = 0
    Max = 127
    Position = 127
    TabOrder = 49
    Wrap = False
  end
  object Edit27: TEdit
    Left = 324
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 50
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object KS3: TUpDown
    Left = 353
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit27
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 51
    Wrap = False
  end
  object Edit28: TEdit
    Left = 372
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 52
    Text = '1'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object ML3: TUpDown
    Left = 401
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit28
    Min = 0
    Max = 15
    Position = 1
    TabOrder = 53
    Wrap = False
  end
  object Edit29: TEdit
    Left = 420
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 54
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DT3: TUpDown
    Left = 449
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit29
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 55
    Wrap = False
  end
  object Edit30: TEdit
    Left = 36
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 56
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AR4: TUpDown
    Left = 65
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit30
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 57
    Wrap = False
  end
  object Edit31: TEdit
    Left = 84
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 58
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DR4: TUpDown
    Left = 113
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit31
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 59
    Wrap = False
  end
  object Edit32: TEdit
    Left = 132
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 60
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SR4: TUpDown
    Left = 161
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit32
    Min = 0
    Max = 31
    Position = 0
    TabOrder = 61
    Wrap = False
  end
  object Edit33: TEdit
    Left = 180
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 62
    Text = '15'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object RR4: TUpDown
    Left = 209
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit33
    Min = 0
    Max = 15
    Position = 15
    TabOrder = 63
    Wrap = False
  end
  object Edit34: TEdit
    Left = 228
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 64
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object SL4: TUpDown
    Left = 257
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit34
    Min = 0
    Max = 15
    Position = 0
    TabOrder = 65
    Wrap = False
  end
  object Edit35: TEdit
    Left = 276
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 66
    Text = '127'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object TL4: TUpDown
    Left = 305
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit35
    Min = 0
    Max = 127
    Position = 127
    TabOrder = 67
    Wrap = False
  end
  object Edit36: TEdit
    Left = 324
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 68
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object KS4: TUpDown
    Left = 353
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit36
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 69
    Wrap = False
  end
  object Edit37: TEdit
    Left = 372
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 70
    Text = '1'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object ML4: TUpDown
    Left = 401
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit37
    Min = 0
    Max = 15
    Position = 1
    TabOrder = 71
    Wrap = False
  end
  object Edit38: TEdit
    Left = 420
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 72
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object DT4: TUpDown
    Left = 449
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit38
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 73
    Wrap = False
  end
  object Edit40: TEdit
    Left = 468
    Top = 52
    Width = 29
    Height = 20
    TabOrder = 74
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AMS1: TUpDown
    Left = 497
    Top = 52
    Width = 15
    Height = 20
    Associate = Edit40
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 75
    Wrap = False
  end
  object Edit41: TEdit
    Left = 468
    Top = 76
    Width = 29
    Height = 20
    TabOrder = 76
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AMS2: TUpDown
    Left = 497
    Top = 76
    Width = 15
    Height = 20
    Associate = Edit41
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 77
    Wrap = False
  end
  object Edit42: TEdit
    Left = 468
    Top = 100
    Width = 29
    Height = 20
    TabOrder = 78
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AMS3: TUpDown
    Left = 497
    Top = 100
    Width = 15
    Height = 20
    Associate = Edit42
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 79
    Wrap = False
  end
  object Edit43: TEdit
    Left = 468
    Top = 124
    Width = 29
    Height = 20
    TabOrder = 80
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object AMS4: TUpDown
    Left = 497
    Top = 124
    Width = 15
    Height = 20
    Associate = Edit43
    Min = 0
    Max = 3
    Position = 0
    TabOrder = 81
    Wrap = False
  end
  object LFO: TUpDown
    Left = 213
    Top = 8
    Width = 15
    Height = 20
    Associate = Edit39
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 82
    Wrap = False
  end
  object Edit39: TEdit
    Left = 184
    Top = 8
    Width = 29
    Height = 20
    TabOrder = 83
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object FB: TUpDown
    Left = 137
    Top = 8
    Width = 15
    Height = 20
    Associate = Edit2
    Min = 0
    Max = 7
    Position = 0
    TabOrder = 84
    Wrap = False
  end
  object Edit2: TEdit
    Left = 108
    Top = 8
    Width = 29
    Height = 20
    TabOrder = 85
    Text = '0'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
  object ALG: TUpDown
    Left = 65
    Top = 8
    Width = 15
    Height = 20
    Associate = Edit1
    Min = 0
    Max = 7
    Position = 7
    TabOrder = 86
    Wrap = False
  end
  object Edit1: TEdit
    Left = 36
    Top = 8
    Width = 29
    Height = 20
    TabOrder = 87
    Text = '7'
    OnChange = Edit1Change
    OnExit = Edit1Exit
  end
end
