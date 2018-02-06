#include "main.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT,  MainWindow::OnExit)
    EVT_SHOW(MainWindow::setupGL)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(wxGLtest);

void MainWindow::setupGL(wxShowEvent &event)
{
    wxGLAttributes dispAttrs;
    dispAttrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();

    if(wxGLCanvas::IsDisplaySupported(dispAttrs)) std::cout << "Display supported" << std::endl;
    else std::cout << "Display not supported" << std::endl;

    this->canvas = new testGLCanvas(this, dispAttrs);
    this->glc = this->canvas->createContext();
    this->canvas->SetCurrent(*this->glc);

    glewExperimental = true; // Needed in core profile
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
        return;
    }
    std::cout << "GLEW initialized." << std::endl;
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
}
