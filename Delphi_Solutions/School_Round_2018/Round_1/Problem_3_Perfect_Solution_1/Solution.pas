unit Solution;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm2 = class(TForm)
    edtN: TEdit;
    btnProcess: TButton;
    edtOut: TEdit;
    procedure btnProcessClick(Sender: TObject);
  private
    { Private declarations }
  public
    function GetPerfection(N:integer):integer;
  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}

procedure TForm2.btnProcessClick(Sender: TObject);
var
N,Perfection:integer;
begin
  N := StrToInt(edtN.Text);

  Perfection := GetPerfection(N);
  if N = Perfection then
     edtOut.Text := 'Perfect'
  else if N > Perfection then
    edtOut.Text := 'Abundant'
  else
    edtOut.Text := 'Deficent';

end;

function TForm2.GetPerfection(N: integer): integer;
var
I:integer;
begin
  result:=0;
  for I := 1 to N - 1 do
  begin
    if N mod I = 0 then
    begin
      result:=result+I;
    end;
  end;
end;

end.
