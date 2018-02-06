#include "testGLCanvas.h"

#include "main.h"

testGLCanvas::testGLCanvas(wxFrame *parent, const wxGLAttributes &dispAttrs)
             :wxGLCanvas(parent, dispAttrs, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxT("GLCanvas"), wxNullPalette)
{
}

wxGLContext *testGLCanvas::createContext()
{
    wxGLContextAttrs ctxAttrs;
    ctxAttrs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).EndList();

    wxGLContext *glc = new wxGLContext(this, NULL, &ctxAttrs);

    if(!glc->IsOK())
    {
        std::cout << "GLContext wrong" << std::endl;
    }
    else std::cout << "GLContext ok" << std::endl;

    return glc;
}

testGLCanvas::~testGLCanvas()
{
}
