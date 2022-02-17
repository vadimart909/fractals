//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", mainWindow);
USEFORM("Unit3.cpp", drawWindow);
USEFORM("lSystem.cpp", lSystemForm);
USEFORM("ddWindow.cpp", directdrawWindow);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Фракталы";
                 Application->CreateForm(__classid(TmainWindow), &mainWindow);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
