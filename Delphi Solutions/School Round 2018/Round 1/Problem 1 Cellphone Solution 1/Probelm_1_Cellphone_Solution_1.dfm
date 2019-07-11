object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 153
  ClientWidth = 138
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edt1: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object edt2: TEdit
    Left = 8
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object btnProcess: TButton
    Left = 8
    Top = 89
    Width = 122
    Height = 25
    Caption = 'Process'
    TabOrder = 2
    OnClick = btnProcessClick
  end
  object edt3: TEdit
    Left = 8
    Top = 62
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object edtOut: TEdit
    Left = 8
    Top = 120
    Width = 121
    Height = 21
    TabOrder = 4
  end
end
