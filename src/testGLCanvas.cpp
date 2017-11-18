#include "testGLCanvas.h"

#include "main.h"

testGLCanvas::testGLCanvas(wxFrame *parent, const wxGLAttributes &dispAttrs)
             :wxGLCanvas(parent, dispAttrs, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxT("GLCanvas"), wxNullPalette)
{
    MainWindow *f = (MainWindow *)parent;

    wxGLContextAttrs ctxAttrs;
    ctxAttrs.PlatformDefaults().CoreProfile().OGLVersion(3, 2).EndList();

    f->glc = new wxGLContext(this, NULL, &ctxAttrs);

    if(!f->glc->IsOK())
    {
        std::cout << "GLContext wrong" << std::endl;
    }
    else std::cout << "GLContext ok" << std::endl;
}

testGLCanvas::~testGLCanvas()
{
}
