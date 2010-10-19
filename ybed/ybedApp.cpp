/***************************************************************
 * Name:      ybedApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Pedro Sa (pedro.pbs@gmail.com)
 * Created:   2010-10-18
 * Copyright: Pedro Sa ()
 * License:
 **************************************************************/

#include "ybedApp.h"

//(*AppHeaders
#include "ybedMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ybedApp);

bool ybedApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ybedFrame* Frame = new ybedFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
