#include "testGLCanvas.h"
#include "main.h"

testGLCanvas::testGLCanvas(wxFrame *parent, const wxGLAttributes &dispAttrs)
             :wxGLCanvas(parent, dispAttrs, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxT("GLCanvas"), wxNullPalette)
{
    this->parent = parent;
}

wxGLContext *testGLCanvas::createContext()
{
    wxGLContextAttrs ctxAttrs;
    ctxAttrs.PlatformDefaults().CoreProfile().OGLVersion(4, 5).EndList();

    wxGLContext *glc = new wxGLContext(this, NULL, &ctxAttrs);

    if(!glc->IsOK())
    {
        std::cerr << "GLContext wrong" << std::endl;
        this->parent->Close(true);
    }
    else std::cout << "GLContext ok" << std::endl;

    return glc;
}
