#include "main.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT,  MainWindow::OnExit)
    EVT_MENU(ID_opengl, MainWindow::OnGL)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(wxGLtest);

wxGLtest::wxGLtest()
{
    XInitThreads();
}

bool wxGLtest::OnInit()
{
    XInitThreads();
    this->frame = new MainWindow("wxWidgets / OpenGL test", wxPoint(20, 20), wxSize(1285, 810));

    this->frame->glc = this->frame->canvas->createContext();
    return true;
}

void MainWindow::OnGL(wxCommandEvent &event)
{
    this->glc = this->canvas->createContext();
    this->canvas->SetCurrent(*glc);

    glewExperimental = true; // Needed in core profile
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
    }
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
    menuFile->Append(ID_opengl, "&OpenGL init...\tCtrl-H", "");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    CreateStatusBar(1);
    this->Show(true);

    wxGLAttributes dispAttrs;
    dispAttrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();

    if(wxGLCanvas::IsDisplaySupported(dispAttrs)) std::cout << "Display supported" << std::endl;
    else std::cout << "Display not supported" << std::endl;

    this->canvas = new testGLCanvas(this, dispAttrs);
}
