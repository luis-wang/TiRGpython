object Form1: TForm1
  Left = 286
  Top = 190
  Width = 958
  Height = 700
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 24
    Top = 16
    Width = 137
    Height = 97
    AutoSize = True
    Center = True
  end
  object Memo1: TMemo
    Left = 752
    Top = 152
    Width = 180
    Height = 145
    TabOrder = 0
  end
  object Button1: TButton
    Left = 752
    Top = 16
    Width = 180
    Height = 33
    Caption = 'Load a jpg/jpeg (24bit) file'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 752
    Top = 80
    Width = 180
    Height = 33
    Caption = 'Detect textlike regions'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 8
    object File1: TMenuItem
      Caption = '&File'
      object Open1: TMenuItem
        Caption = '&Open...'
      end
      object SaveAs1: TMenuItem
        Caption = 'Save &As...'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object N1: TMenuItem
        Caption = '-'
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 296
    Top = 8
  end
end
