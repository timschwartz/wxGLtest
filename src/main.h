#pragma once

#include <X11/Xlib.h>
#include <GL/glew.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "testGLCanvas.h"

class MainWindow: public wxFrame
{
  public:
    MainWindow(const wxString &title, const wxPoint &pos, const wxSize &size);
    testGLCanvas *canvas = nullptr;
    wxGLContext *glc = nullptr;
  private:
    void OnExit(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};

class wxGLtest: public wxApp
{
  public:
    wxGLtest();
    virtual bool OnInit();
    MainWindow *frame = nullptr;
};

