#include "App.h"
#include "Main.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	Main* mainFrame = new Main("Sudoku Solver");
	mainFrame->SetClientSize(800, 600);
	mainFrame->SetMaxClientSize(mainFrame->GetSize());
	mainFrame->SetMinClientSize(mainFrame->GetSize());
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
