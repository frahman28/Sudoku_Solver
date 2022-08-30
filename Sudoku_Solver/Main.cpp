#include "Main.h"
#include <wx/wx.h>
#include "Solver.h"
#include <vector>

std::vector<std::vector<wxTextCtrl*>> allBoxes;
wxFont correctNumberfont((wxFontInfo(38).Bold()));
wxFont font(wxFontInfo(38));

enum IDs {
	SOLVE_BUTTON = 2,
	NEW_GRID_BUTTON = 3,
	RESET_GRID_BUTTON = 4,
	CUSTOM_GRID_BUTTON = 5,
	CLEAR_GRID_BUTTON = 6,
	CHECK_GRID_BUTTON = 7
};

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(SOLVE_BUTTON, Main::onSolveClicked)
	EVT_BUTTON(NEW_GRID_BUTTON, Main::onNewGridClicked)
	EVT_BUTTON(RESET_GRID_BUTTON, Main::onResetGridClicked)
	EVT_BUTTON(CUSTOM_GRID_BUTTON, Main::onCustomGridClicked)
	EVT_BUTTON(CLEAR_GRID_BUTTON, Main::onClearGridClicked)
	EVT_BUTTON(CHECK_GRID_BUTTON, Main::onCheckGridClicked)
wxEND_EVENT_TABLE()

Main::Main(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* solveBtn = new wxButton(panel, SOLVE_BUTTON, "Solve", wxPoint(620, 20), wxSize(170, 60));
	wxButton* newGridBtn = new wxButton(panel, NEW_GRID_BUTTON, "New Grid", wxPoint(620, 100), wxSize(170, 60));
	wxButton* resetGridBtn = new wxButton(panel, RESET_GRID_BUTTON, "Reset Grid", wxPoint(620, 180), wxSize(170, 60));
	wxButton* checkGridBtn = new wxButton(panel, CHECK_GRID_BUTTON, "Check Grid", wxPoint(620, 260), wxSize(170, 60));
	//wxButton* customGridBtn = new wxButton(panel, CUSTOM_GRID_BUTTON, "Solve Custom Grid", wxPoint(620, 340), wxSize(170, 60));
	//wxButton* clearGridBtn = new wxButton(panel, CLEAR_GRID_BUTTON, "Clear Grid", wxPoint(620, 420), wxSize(170, 60));

	wxTextCtrl* zeroZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroZero->SetFont(font);
	zeroZero->SetMaxLength(1);
	wxTextCtrl* zeroOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroOne->SetFont(font);
	zeroOne->SetMaxLength(1);
	wxTextCtrl* zeroTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroTwo->SetFont(font);
	zeroTwo->SetMaxLength(1);
	wxTextCtrl* zeroThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroThree->SetFont(font);
	zeroThree->SetMaxLength(1);
	wxTextCtrl* zeroFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroFour->SetFont(font);
	zeroFour->SetMaxLength(1);
	wxTextCtrl* zeroFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroFive->SetFont(font);
	zeroFive->SetMaxLength(1);
	wxTextCtrl* zeroSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroSix->SetFont(font);
	zeroSix->SetMaxLength(1);
	wxTextCtrl* zeroSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroSeven->SetFont(font);
	zeroSeven->SetMaxLength(1);
	wxTextCtrl* zeroEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 20), wxSize(60, 60), wxTE_CENTRE);
	zeroEight->SetFont(font);
	zeroEight->SetMaxLength(1);

	wxTextCtrl* oneZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 85), wxSize(60, 60), wxTE_CENTRE);
	oneZero->SetFont(font);
	oneZero->SetMaxLength(1);
	wxTextCtrl* oneOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 85), wxSize(60, 60), wxTE_CENTRE);
	oneOne->SetFont(font);
	oneOne->SetMaxLength(1);
	wxTextCtrl* oneTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 85), wxSize(60, 60), wxTE_CENTRE);
	oneTwo->SetFont(font);
	oneTwo->SetMaxLength(1);
	wxTextCtrl* oneThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 85), wxSize(60, 60), wxTE_CENTRE);
	oneThree->SetFont(font);
	oneThree->SetMaxLength(1);
	wxTextCtrl* oneFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 85), wxSize(60, 60), wxTE_CENTRE);
	oneFour->SetFont(font);
	oneFour->SetMaxLength(1);
	wxTextCtrl* oneFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 85), wxSize(60, 60), wxTE_CENTRE);
	oneFive->SetFont(font);
	oneFive->SetMaxLength(1);
	wxTextCtrl* oneSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 85), wxSize(60, 60), wxTE_CENTRE);
	oneSix->SetFont(font);
	oneSix->SetMaxLength(1);
	wxTextCtrl* oneSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 85), wxSize(60, 60), wxTE_CENTRE);
	oneSeven->SetFont(font);
	oneSeven->SetMaxLength(1);
	wxTextCtrl* oneEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 85), wxSize(60, 60), wxTE_CENTRE);
	oneEight->SetFont(font);
	oneEight->SetMaxLength(1);

	wxTextCtrl* twoZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 150), wxSize(60, 60), wxTE_CENTRE);
	twoZero->SetFont(font);
	twoZero->SetMaxLength(1);
	wxTextCtrl* twoOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 150), wxSize(60, 60), wxTE_CENTRE);
	twoOne->SetFont(font);
	twoOne->SetMaxLength(1);
	wxTextCtrl* twoTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 150), wxSize(60, 60), wxTE_CENTRE);
	twoTwo->SetFont(font);
	twoTwo->SetMaxLength(1);
	wxTextCtrl* twoThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 150), wxSize(60, 60), wxTE_CENTRE);
	twoThree->SetFont(font);
	twoThree->SetMaxLength(1);
	wxTextCtrl* twoFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 150), wxSize(60, 60), wxTE_CENTRE);
	twoFour->SetFont(font);
	twoFour->SetMaxLength(1);
	wxTextCtrl* twoFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 150), wxSize(60, 60), wxTE_CENTRE);
	twoFive->SetFont(font);
	twoFive->SetMaxLength(1);
	wxTextCtrl* twoSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 150), wxSize(60, 60), wxTE_CENTRE);
	twoSix->SetFont(font);
	twoSix->SetMaxLength(1);
	wxTextCtrl* twoSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 150), wxSize(60, 60), wxTE_CENTRE);
	twoSeven->SetFont(font);
	twoSeven->SetMaxLength(1);
	wxTextCtrl* twoEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 150), wxSize(60, 60), wxTE_CENTRE);
	twoEight->SetFont(font);
	twoEight->SetMaxLength(1);

	wxTextCtrl* threeZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 220), wxSize(60, 60), wxTE_CENTRE);
	threeZero->SetFont(font);
	threeZero->SetMaxLength(1);
	wxTextCtrl* threeOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 220), wxSize(60, 60), wxTE_CENTRE);
	threeOne->SetFont(font);
	threeOne->SetMaxLength(1);
	wxTextCtrl* threeTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 220), wxSize(60, 60), wxTE_CENTRE);
	threeTwo->SetFont(font);
	threeTwo->SetMaxLength(1);
	wxTextCtrl* threeThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 220), wxSize(60, 60), wxTE_CENTRE);
	threeThree->SetFont(font);
	threeThree->SetMaxLength(1);
	wxTextCtrl* threeFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 220), wxSize(60, 60), wxTE_CENTRE);
	threeFour->SetFont(font);
	threeFour->SetMaxLength(1);
	wxTextCtrl* threeFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 220), wxSize(60, 60), wxTE_CENTRE);
	threeFive->SetFont(font);
	threeFive->SetMaxLength(1);
	wxTextCtrl* threeSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 220), wxSize(60, 60), wxTE_CENTRE);
	threeSix->SetFont(font);
	threeSix->SetMaxLength(1);
	wxTextCtrl* threeSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 220), wxSize(60, 60), wxTE_CENTRE);
	threeSeven->SetFont(font);
	threeSeven->SetMaxLength(1);
	wxTextCtrl* threeEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 220), wxSize(60, 60), wxTE_CENTRE);
	threeEight->SetFont(font);
	threeEight->SetMaxLength(1);

	wxTextCtrl* fourZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 285), wxSize(60, 60), wxTE_CENTRE);
	fourZero->SetFont(font);
	fourZero->SetMaxLength(1);
	wxTextCtrl* fourOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 285), wxSize(60, 60), wxTE_CENTRE);
	fourOne->SetFont(font);
	fourOne->SetMaxLength(1);
	wxTextCtrl* fourTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 285), wxSize(60, 60), wxTE_CENTRE);
	fourTwo->SetFont(font);
	fourTwo->SetMaxLength(1);
	wxTextCtrl* fourThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 285), wxSize(60, 60), wxTE_CENTRE);
	fourThree->SetFont(font);
	fourThree->SetMaxLength(1);
	wxTextCtrl* fourFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 285), wxSize(60, 60), wxTE_CENTRE);
	fourFour->SetFont(font);
	fourFour->SetMaxLength(1);
	wxTextCtrl* fourFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 285), wxSize(60, 60), wxTE_CENTRE);
	fourFive->SetFont(font);
	fourFive->SetMaxLength(1);
	wxTextCtrl* fourSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 285), wxSize(60, 60), wxTE_CENTRE);
	fourSix->SetFont(font);
	fourSix->SetMaxLength(1);
	wxTextCtrl* fourSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 285), wxSize(60, 60), wxTE_CENTRE);
	fourSeven->SetFont(font);
	fourSeven->SetMaxLength(1);
	wxTextCtrl* fourEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 285), wxSize(60, 60), wxTE_CENTRE);
	fourEight->SetFont(font);
	fourEight->SetMaxLength(1);

	wxTextCtrl* fiveZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveZero->SetFont(font);
	fiveZero->SetMaxLength(1);
	wxTextCtrl* fiveOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveOne->SetFont(font);
	fiveOne->SetMaxLength(1);
	wxTextCtrl* fiveTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveTwo->SetFont(font);
	fiveTwo->SetMaxLength(1);
	wxTextCtrl* fiveThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveThree->SetFont(font);
	fiveThree->SetMaxLength(1);
	wxTextCtrl* fiveFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveFour->SetFont(font);
	fiveFour->SetMaxLength(1);
	wxTextCtrl* fiveFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveFive->SetFont(font);
	fiveFive->SetMaxLength(1);
	wxTextCtrl* fiveSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveSix->SetFont(font);
	fiveSix->SetMaxLength(1);
	wxTextCtrl* fiveSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveSeven->SetFont(font);
	fiveSeven->SetMaxLength(1);
	wxTextCtrl* fiveEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 350), wxSize(60, 60), wxTE_CENTRE);
	fiveEight->SetFont(font);
	fiveEight->SetMaxLength(1);

	wxTextCtrl* sixZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 420), wxSize(60, 60), wxTE_CENTRE);
	sixZero->SetFont(font);
	sixZero->SetMaxLength(1);
	wxTextCtrl* sixOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 420), wxSize(60, 60), wxTE_CENTRE);
	sixOne->SetFont(font);
	sixOne->SetMaxLength(1);
	wxTextCtrl* sixTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 420), wxSize(60, 60), wxTE_CENTRE);
	sixTwo->SetFont(font);
	sixTwo->SetMaxLength(1);
	wxTextCtrl* sixThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 420), wxSize(60, 60), wxTE_CENTRE);
	sixThree->SetFont(font);
	sixThree->SetMaxLength(1);
	wxTextCtrl* sixFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 420), wxSize(60, 60), wxTE_CENTRE);
	sixFour->SetFont(font);
	sixFour->SetMaxLength(1);
	wxTextCtrl* sixFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 420), wxSize(60, 60), wxTE_CENTRE);
	sixFive->SetFont(font);
	sixFive->SetMaxLength(1);
	wxTextCtrl* sixSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 420), wxSize(60, 60), wxTE_CENTRE);
	sixSix->SetFont(font);
	sixSix->SetMaxLength(1);
	wxTextCtrl* sixSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 420), wxSize(60, 60), wxTE_CENTRE);
	sixSeven->SetFont(font);
	sixSeven->SetMaxLength(1);
	wxTextCtrl* sixEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 420), wxSize(60, 60), wxTE_CENTRE);
	sixEight->SetFont(font);
	sixEight->SetMaxLength(1);

	wxTextCtrl* sevenZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenZero->SetFont(font);
	sevenZero->SetMaxLength(1);
	wxTextCtrl* sevenOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenOne->SetFont(font);
	sevenOne->SetMaxLength(1);
	wxTextCtrl* sevenTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenTwo->SetFont(font);
	sevenTwo->SetMaxLength(1);
	wxTextCtrl* sevenThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenThree->SetFont(font);
	sevenThree->SetMaxLength(1);
	wxTextCtrl* sevenFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenFour->SetFont(font);
	sevenFour->SetMaxLength(1);
	wxTextCtrl* sevenFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenFive->SetFont(font);
	sevenFive->SetMaxLength(1);
	wxTextCtrl* sevenSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenSix->SetFont(font);
	sevenSix->SetMaxLength(1);
	wxTextCtrl* sevenSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenSeven->SetFont(font);
	sevenSeven->SetMaxLength(1);
	wxTextCtrl* sevenEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 485), wxSize(60, 60), wxTE_CENTRE);
	sevenEight->SetFont(font);
	sevenEight->SetMaxLength(1);

	wxTextCtrl* eightZero = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 550), wxSize(60, 60), wxTE_CENTRE);
	eightZero->SetFont(font);
	eightZero->SetMaxLength(1);
	wxTextCtrl* eightOne = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(85, 550), wxSize(60, 60), wxTE_CENTRE);
	eightOne->SetFont(font);
	eightOne->SetMaxLength(1);
	wxTextCtrl* eightTwo = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 550), wxSize(60, 60), wxTE_CENTRE);
	eightTwo->SetFont(font);
	eightTwo->SetMaxLength(1);
	wxTextCtrl* eightThree = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 550), wxSize(60, 60), wxTE_CENTRE);
	eightThree->SetFont(font);
	eightThree->SetMaxLength(1);
	wxTextCtrl* eightFour = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(285, 550), wxSize(60, 60), wxTE_CENTRE);
	eightFour->SetFont(font);
	eightFour->SetMaxLength(1);
	wxTextCtrl* eightFive = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350, 550), wxSize(60, 60), wxTE_CENTRE);
	eightFive->SetFont(font);
	eightFive->SetMaxLength(1);
	wxTextCtrl* eightSix = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(420, 550), wxSize(60, 60), wxTE_CENTRE);
	eightSix->SetFont(font);
	eightSix->SetMaxLength(1);
	wxTextCtrl* eightSeven = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(485, 550), wxSize(60, 60), wxTE_CENTRE);
	eightSeven->SetFont(font);
	eightSeven->SetMaxLength(1);
	wxTextCtrl* eightEight = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550, 550), wxSize(60, 60), wxTE_CENTRE);
	eightEight->SetFont(font);
	eightEight->SetMaxLength(1);

	allBoxes = {
		{zeroZero, zeroOne, zeroTwo, zeroThree, zeroFour, zeroFive, zeroSix, zeroSeven, zeroEight},
		{oneZero, oneOne, oneTwo, oneThree, oneFour, oneFive, oneSix, oneSeven, oneEight},
		{twoZero, twoOne, twoTwo, twoThree, twoFour, twoFive, twoSix, twoSeven, twoEight},
		{threeZero, threeOne, threeTwo, threeThree, threeFour, threeFive, threeSix, threeSeven, threeEight},
		{fourZero, fourOne, fourTwo, fourThree, fourFour, fourFive, fourSix, fourSeven, fourEight},
		{fiveZero, fiveOne, fiveTwo, fiveThree, fiveFour, fiveFive, fiveSix, fiveSeven, fiveEight},
		{sixZero, sixOne, sixTwo, sixThree, sixFour, sixFive, sixSix, sixSeven, sixEight},
		{sevenZero, sevenOne, sevenTwo, sevenThree, sevenFour, sevenFive, sevenSix, sevenSeven, sevenEight},
		{eightZero, eightOne, eightTwo, eightThree, eightFour, eightFive, eightSix, eightSeven, eightEight}
	};

	assessValidGraph();
	renderDisplayGrid();

	CreateStatusBar();
}

void Main::renderDisplayGrid() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString value = wxString::Format(wxT("%i"), displayGrid[i][j]);
			if (value == "0") {

			}
			else {
				allBoxes[i][j]->ChangeValue(value);
			}
		}
	}
}

void Main::clearDisplayedGrid() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			allBoxes[i][j]->Clear();
		}
	}
}

void Main::onSolveClicked(wxCommandEvent& evt) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString correctValue = wxString::Format(wxT("%i"), grid[i][j]);
			if (correctValue == allBoxes[i][j]->GetValue()) {
				allBoxes[i][j]->SetFont(font);
				allBoxes[i][j]->SetForegroundColour(*wxBLACK);
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString value = wxString::Format(wxT("%i"), grid[i][j]);
			if (value == "0") {

			}
			else {
				allBoxes[i][j]->ChangeValue(value);
			}
		}
	}
}

void Main::onNewGridClicked(wxCommandEvent& evt) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString correctValue = wxString::Format(wxT("%i"), grid[i][j]);
			if (correctValue == allBoxes[i][j]->GetValue()) {
				allBoxes[i][j]->SetFont(font);
				allBoxes[i][j]->SetForegroundColour(*wxBLACK);
			}
		}
	}
	wxString value = wxString::Format(wxT("%i"), solved);
	wxLogStatus(value);
	resetGrids();
	clearDisplayedGrid();
	assessValidGraph();
	renderDisplayGrid();
}

void Main::onResetGridClicked(wxCommandEvent& evt) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString correctValue = wxString::Format(wxT("%i"), grid[i][j]);
			if (correctValue == allBoxes[i][j]->GetValue()) {
				allBoxes[i][j]->SetFont(font);
				allBoxes[i][j]->SetForegroundColour(*wxBLACK);
			}
		}
	}
	clearDisplayedGrid();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString value = wxString::Format(wxT("%i"), displayGrid[i][j]);
			if (value == "0") {

			}
			else {
				allBoxes[i][j]->ChangeValue(value);
			}
		}
	}
}

void Main::onCustomGridClicked(wxCommandEvent& evt) {
	int inputGrid[9][9] = {
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0},
	   {0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (allBoxes[i][j]->GetValue() != "" || allBoxes[i][j]->GetValue() != "1" || allBoxes[i][j]->GetValue() != "2" || allBoxes[i][j]->GetValue() != "3" || allBoxes[i][j]->GetValue() != "4" || allBoxes[i][j]->GetValue() != "5" || allBoxes[i][j]->GetValue() != "6" || allBoxes[i][j]->GetValue() != "7" || allBoxes[i][j]->GetValue() != "8" || allBoxes[i][j]->GetValue() != "9") {
				wxLogStatus("Enter Valid Grid");
			}
			else {
				int val;
				val = wxAtoi(allBoxes[i][j]->GetValue());
				inputGrid[i][j] = val;
			}
		}
	}

	resetGrids();
	clearDisplayedGrid();
	copyInputGrid(inputGrid);
	renderDisplayGrid();
}

void Main::onClearGridClicked(wxCommandEvent& evt) {
	resetGrids();
	clearDisplayedGrid();
}

void Main::onCheckGridClicked(wxCommandEvent& evt) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			wxString correctValue = wxString::Format(wxT("%i"), grid[i][j]);
			if (correctValue == allBoxes[i][j]->GetValue()) {
				allBoxes[i][j]->SetFont(correctNumberfont);
				allBoxes[i][j]->SetForegroundColour(*wxGREEN);
			}
		}
	}
}

