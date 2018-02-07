#pragma once
#include <GL/glew.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>

class testGLCanvas: public wxGLCanvas
{
  public:
    testGLCanvas(wxFrame *parent, const wxGLAttributes &dispAttrs);
    wxFrame *parent;
    wxGLContext *createContext();
};
