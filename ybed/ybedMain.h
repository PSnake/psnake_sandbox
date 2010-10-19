/***************************************************************
 * Name:      ybedMain.h
 * Purpose:   Defines Application Frame
 * Author:    Pedro Sa (pedro.pbs@gmail.com)
 * Created:   2010-10-18
 * Copyright: Pedro Sa ()
 * License:
 **************************************************************/

#ifndef YBEDMAIN_H
#define YBEDMAIN_H

//(*Headers(ybedFrame)
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class ybedFrame: public wxFrame
{
    public:

        ybedFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ybedFrame();

    private:

        //(*Handlers(ybedFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        //*)

        //(*Identifiers(ybedFrame)
        static const long ID_TEXTCTRL1;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ybedFrame)
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // YBEDMAIN_H
