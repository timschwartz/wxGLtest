#include "main.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT,  MainWindow::OnExit)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(wxGLtest);

wxGLtest::wxGLtest()
{
    XInitThreads();
}

bool wxGLtest::OnInit()
{
    this->frame = new MainWindow("wxWidgets / OpenGL test", wxPoint(20, 20), wxSize(1285, 810));

    return true;
}

void MainWindow::OnExit(wxCommandEvent& event)
{
    Close(true);
}

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    this->SetBackgroundColour(wxColour(*wxBLACK));

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    CreateStatusBar(1);
    this->Show(true);

    wxGLAttributes dispAttrs;
    dispAttrs.PlatformDefaults().Defaults().EndList();

    if(wxGLCanvas::IsDisplaySupported(dispAttrs)) std::cout << "Display supported" << std::endl;
    else std::cout << "Display not supported" << std::endl;

    this->canvas = new testGLCanvas(this, dispAttrs);
}
