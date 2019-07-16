unit Problem_2_Rovarspraket_Solution_2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    edtWord: TEdit;
    btnProcess: TButton;
    edtOut: TEdit;
    procedure btnProcessClick(Sender: TObject);
  private
    { Private declarations }
  public
    function isConsonant(let:char):boolean;
    const
      Vowels = 'aeiou';
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.btnProcessClick(Sender: TObject);
var
sWord,sOut : string;
let:char;
begin
  sWord:=edtWord.Text;
  sOut := '';

  for let in sWord do
  begin
    if isConsonant(let) then
      sOut:=sOut+let+'o'+let
    else
      sOut:=sOut+let;
  end;

  edtOut.Text := sOut;
end;

function TForm1.isConsonant(let: char): boolean;
var
 clet : char;
begin
  result := true;
  for clet in Vowels do
  begin
    if clet = let then
    begin
      result:=false;
      break;
    end;
  end;
end;

end.
