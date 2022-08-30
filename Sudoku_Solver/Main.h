#pragma once
#include <wx/wx.h>

class Main : public wxFrame
{
public:
	Main(const wxString& title);
private:
	void renderDisplayGrid();
	void clearDisplayedGrid();
private: 
	void onSolveClicked(wxCommandEvent& evt);
	void onNewGridClicked(wxCommandEvent& evt);
	void onResetGridClicked(wxCommandEvent& evt);
	void onCustomGridClicked(wxCommandEvent& evt);
	void onClearGridClicked(wxCommandEvent& evt);
	void onCheckGridClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

