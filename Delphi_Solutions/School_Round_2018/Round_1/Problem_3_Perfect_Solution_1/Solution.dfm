object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 90
  ClientWidth = 135
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edtN: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object btnProcess: TButton
    Left = 8
    Top = 35
    Width = 121
    Height = 25
    Caption = 'Process'
    TabOrder = 1
    OnClick = btnProcessClick
  end
  object edtOut: TEdit
    Left = 8
    Top = 66
    Width = 121
    Height = 21
    TabOrder = 2
  end
end
