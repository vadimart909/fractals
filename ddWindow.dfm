object directdrawWindow: TdirectdrawWindow
  Left = 259
  Top = 210
  BiDiMode = bdLeftToRight
  BorderIcons = [biMaximize]
  BorderStyle = bsNone
  Caption = 'directdrawWindow'
  ClientHeight = 453
  ClientWidth = 688
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  ParentBiDiMode = False
  Position = poDefault
  Scaled = False
  Visible = True
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 160
    Top = 72
  end
end
