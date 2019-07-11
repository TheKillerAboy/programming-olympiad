unit Probelm_1_Cellphone_Solution_1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    edt1: TEdit;
    edt2: TEdit;
    btnProcess: TButton;
    edt3: TEdit;
    edtOut: TEdit;
    procedure btnProcessClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.btnProcessClick(Sender: TObject);
var
D,E,W : integer;
begin
  D := StrToInt(edt1.Text);
  E := StrToInt(edt2.Text);
  W := StrToInt(edt3.Text);

  if D > 100 then
    D := D - 100
  else
    D := 0;

  edtOut.Text := IntToStr(80*D+70*E+50*W)+'c';
end;

end.
