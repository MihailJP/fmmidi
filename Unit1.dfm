object Form1: TForm1
  Left = 298
  Top = 106
  BorderStyle = bsToolWindow
  Caption = #12477#12501#12488#12454#12455#12450'FM'#38899#28304'MIDI'#12503#12524#12452#12516#12540
  ClientHeight = 371
  ClientWidth = 469
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 12
  object MainMenu1: TMainMenu
    Left = 120
    Top = 84
    object F1: TMenuItem
      Caption = #20837#21147'(&I)'
      object O2: TMenuItem
        Caption = #12501#12449#12452#12523'(&F)...'
        OnClick = O2Click
      end
      object MidiInMenu: TMenuItem
        Caption = 'midi-in(&M)'
        object NoMidiInMenu: TMenuItem
          AutoHotkeys = maManual
          Caption = '('#12394#12375')'
          Enabled = False
          OnClick = NoMidiInMenuClick
        end
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object X1: TMenuItem
        Caption = #38281#12376#12427'(&X)'
        OnClick = X1Click
      end
    end
    object O1: TMenuItem
      Caption = #20986#21147'(&O)'
      object WaveoutMenu: TMenuItem
        Caption = 'wave-out(&W)'
        object WaveMapperMenu: TMenuItem
          Tag = -1
          Caption = '&WAVE_MAPPER'
          Checked = True
          RadioItem = True
          OnClick = WaveMapperMenuClick
        end
        object N2: TMenuItem
          Caption = '-'
        end
        object MenuMute: TMenuItem
          Caption = #12511#12517#12540#12488'(&M)'
          OnClick = MenuMuteClick
        end
      end
      object WaveFileOutputMenu: TMenuItem
        Caption = 'wav'#12501#12449#12452#12523'(&F)...'
        OnClick = WaveFileOutputMenuClick
      end
    end
    object C1: TMenuItem
      Caption = #35373#23450'(&C)'
      object SamplingRateMenu: TMenuItem
        Caption = #20877#29983#21608#27874#25968'(&F)'
        object N4kHz1: TMenuItem
          Tag = 4000
          Caption = '&4kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N8kHz1: TMenuItem
          Tag = 8000
          Caption = '&8kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N11kHz1: TMenuItem
          Tag = 11000
          Caption = '&11kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N22kHz1: TMenuItem
          Tag = 22000
          Caption = '&22kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N32kHz1: TMenuItem
          Tag = 32000
          Caption = '32kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N44kHz1: TMenuItem
          Tag = 44100
          Caption = '44kHz'
          Checked = True
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N48kHz1: TMenuItem
          Tag = 48000
          Caption = '48kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N96kHz1: TMenuItem
          Tag = 96000
          Caption = '96kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
        object N192kHz1: TMenuItem
          Tag = 192000
          Caption = '192kHz'
          RadioItem = True
          OnClick = N192kHz1Click
        end
      end
      object EDITP1: TMenuItem
        Caption = #38899#33394#32232#38598'(&P)'
        OnClick = EDITP1Click
      end
      object E1: TMenuItem
        Caption = #12452#12467#12521#12452#12470'(&E)'
        OnClick = E1Click
      end
      object OutputSilence: TMenuItem
        Caption = #28961#38899#12434#20986#21147#12377#12427'(&S)'
        OnClick = OutputSilenceClick
      end
    end
    object H1: TMenuItem
      Caption = #12504#12523#12503'(&H)'
      object A1: TMenuItem
        Caption = '&About...'
        OnClick = A1Click
      end
    end
  end
  object OpenDialogMid: TOpenDialog
    DefaultExt = 'mid'
    Filter = '*.mid;*.smf|*.mid;*.smf|'#12377#12409#12390#12398#12501#12449#12452#12523'|*.*'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = #12501#12449#12452#12523#12434#28436#22863'('#35079#25968#36984#25246#21487')'
    Left = 32
    Top = 16
  end
  object PlaylistTimer: TTimer
    OnTimer = PlaylistTimerTimer
    Left = 112
    Top = 20
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = ApplicationEvents1Idle
    Left = 204
    Top = 32
  end
  object UpdateTimer: TTimer
    Interval = 100
    OnTimer = UpdateTimerTimer
    Left = 272
    Top = 16
  end
  object SaveDialogWav: TSaveDialog
    DefaultExt = 'wav'
    Filter = '*.wav|*.wav|'#12377#12409#12390#12398#12501#12449#12452#12523'|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 36
    Top = 88
  end
end
