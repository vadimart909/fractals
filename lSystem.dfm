object lSystemForm: TlSystemForm
  Left = 304
  Top = 200
  Width = 696
  Height = 480
  Caption = 'lSystemForm'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 688
    Height = 89
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 112
      Top = 8
      Width = 25
      Height = 13
      Caption = #1059#1075#1086#1083
    end
    object Label2: TLabel
      Left = 96
      Top = 32
      Width = 45
      Height = 13
      Caption = #1040#1082#1089#1080#1086#1084#1072
    end
    object Label3: TLabel
      Left = 96
      Top = 56
      Width = 44
      Height = 13
      Caption = #1069#1083#1077#1084#1077#1085#1090
    end
    object Label4: TLabel
      Left = 224
      Top = 8
      Width = 33
      Height = 13
      Caption = #1044#1083#1080#1085#1072
    end
    object Label5: TLabel
      Left = 344
      Top = 8
      Width = 49
      Height = 13
      Caption = #1048#1090#1077#1088#1072#1094#1080#1080
    end
    object Label6: TLabel
      Left = 472
      Top = 8
      Width = 53
      Height = 13
      Caption = #1050#1088#1072#1090#1085#1086#1089#1090#1100
    end
    object Edit1: TEdit
      Left = 144
      Top = 8
      Width = 73
      Height = 21
      TabOrder = 0
      Text = '90'
    end
    object Edit2: TEdit
      Left = 144
      Top = 32
      Width = 449
      Height = 21
      TabOrder = 1
      Text = 'f+f+f+f'
    end
    object Edit3: TEdit
      Left = 144
      Top = 56
      Width = 449
      Height = 21
      TabOrder = 2
      Text = 'f-ff+ff+f+f-f-ff+f+f-f-ff-ff+f'
    end
    object Button1: TButton
      Left = 8
      Top = 8
      Width = 81
      Height = 73
      Caption = #1056#1080#1089#1086#1074#1072#1090#1100
      TabOrder = 3
      OnClick = Button1Click
    end
    object Edit4: TEdit
      Left = 272
      Top = 8
      Width = 65
      Height = 21
      TabOrder = 4
      Text = '30'
    end
    object Edit5: TEdit
      Left = 400
      Top = 8
      Width = 65
      Height = 21
      TabOrder = 5
      Text = '2'
    end
    object Edit6: TEdit
      Left = 528
      Top = 8
      Width = 65
      Height = 21
      TabOrder = 6
      Text = '6'
    end
  end
end
