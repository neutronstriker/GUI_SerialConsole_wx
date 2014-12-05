/***************************************************************
 * Name:      helloWxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    NeutroNStrikeR (striker.dbz@hotmail.com)
 * Created:   2014-09-11
 * Copyright: NeutroNStrikeR (http://nvstech.weebly.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "helloWxApp.h"

//(*AppHeaders
#include "helloWxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(helloWxApp);

bool helloWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	helloWxFrame* Frame = new helloWxFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
