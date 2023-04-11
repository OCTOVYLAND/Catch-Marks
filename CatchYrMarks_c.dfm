object frmGrabbing: TfrmGrabbing
  Left = 0
  Top = 0
  Caption = '  Catch your Marks!'
  ClientHeight = 416
  ClientWidth = 514
  Color = cl3DLight
  Constraints.MinHeight = 455
  Constraints.MinWidth = 530
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 514
    Height = 45
    Align = alTop
    Color = clMoneyGreen
    ParentBackground = False
    TabOrder = 0
    ExplicitWidth = 670
    object Label1: TLabel
      Left = 75
      Top = 16
      Width = 95
      Height = 13
      Caption = 'Disappearing Speed'
    end
    object Label2: TLabel
      Left = 215
      Top = 16
      Width = 13
      Height = 13
      Caption = 'ms'
    end
    object lblFound: TLabel
      Left = 429
      Top = 7
      Width = 44
      Height = 29
      Caption = '0%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 355
      Top = 16
      Width = 66
      Height = 13
      Caption = 'FINAL score'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblTimeUp: TLabel
      Left = 256
      Top = 13
      Width = 71
      Height = 19
      Caption = 'Time'#39's UP!'
      Font.Charset = ANSI_CHARSET
      Font.Color = clTeal
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object edtDisapp: TEdit
      Left = 176
      Top = 13
      Width = 33
      Height = 21
      TabOrder = 0
      Text = '200'
      OnExit = edtDisappExit
    end
    object btbGo: TBitBtn
      Left = 11
      Top = 10
      Width = 58
      Height = 27
      Caption = 'Go! '
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333333333333333333FFF333333333333000333333333
        3333777FFF3FFFFF33330B000300000333337F777F777773F333000E00BFBFB0
        3333777F773333F7F333000E0BFBF0003333777F7F3337773F33000E0FBFBFBF
        0333777F7F3333FF7FFF000E0BFBF0000003777F7F3337777773000E0FBFBFBF
        BFB0777F7F33FFFFFFF7000E0BF000000003777F7FF777777773000000BFB033
        33337777773FF733333333333300033333333333337773333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333}
      Layout = blGlyphRight
      NumGlyphs = 2
      TabOrder = 1
      OnClick = btbGoClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 276
    Width = 514
    Height = 140
    Align = alBottom
    BevelOuter = bvNone
    Color = clSkyBlue
    ParentBackground = False
    TabOrder = 1
    ExplicitWidth = 516
    object Label7: TLabel
      Left = 9
      Top = 3
      Width = 490
      Height = 13
      Caption = 
        'Mark Seq#         Started with[%]         U Scored [%]          ' +
        'Total scored          Total  missed'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lstMarks: TListBox
      Left = 0
      Top = 19
      Width = 514
      Height = 121
      Align = alBottom
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ItemHeight = 13
      ParentFont = False
      TabOrder = 0
      TabWidth = 75
      ExplicitWidth = 516
    end
  end
  object prgbTime: TProgressBar
    Left = 497
    Top = 45
    Width = 17
    Height = 231
    Align = alRight
    DoubleBuffered = True
    Max = 300
    Orientation = pbVertical
    ParentDoubleBuffered = False
    MarqueeInterval = 4
    SmoothReverse = True
    Step = 1
    TabOrder = 2
    ExplicitLeft = 499
    ExplicitTop = 65
    ExplicitHeight = 200
  end
  object pnlMarks: TPanel
    Left = 0
    Top = 45
    Width = 497
    Height = 231
    Align = alClient
    TabOrder = 3
    ExplicitLeft = 64
    ExplicitTop = 64
    ExplicitWidth = 361
    ExplicitHeight = 193
    object pnlMark2: TPanel
      Left = 263
      Top = 45
      Width = 50
      Height = 50
      Caption = '1'
      Color = clLime
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
      Visible = False
      OnClick = pnlMark2Click
    end
    object pnlMark1: TPanel
      Left = 151
      Top = 112
      Width = 44
      Height = 41
      Caption = '1'
      Color = clGradientActiveCaption
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = pnlMark1Click
    end
    object pnlMark3: TPanel
      Left = 33
      Top = 40
      Width = 60
      Height = 60
      Caption = '1'
      Color = clRed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clYellow
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = pnlMark3Click
    end
  end
  object tmrFall: TTimer
    Enabled = False
    Interval = 50
    OnTimer = tmrFallTimer
    Left = 440
    Top = 56
  end
end
