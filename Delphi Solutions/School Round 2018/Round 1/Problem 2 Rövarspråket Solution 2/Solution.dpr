program Solution;

uses
  Forms,
  Problem_2_Rovarspraket_Solution_2 in 'Problem_2_Rovarspraket_Solution_2.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
