program Solution;

uses
  Forms,
  Probelm_1_Cellphone_Solution_1 in 'Probelm_1_Cellphone_Solution_1.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
