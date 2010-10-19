/***************************************************************
 * Name:      ybedMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Pedro Sa (pedro.pbs@gmail.com)
 * Created:   2010-10-18
 * Copyright: Pedro Sa ()
 * License:
 **************************************************************/

#include "ybedMain.h"

#include <fstream>
#include <string>

#include <wx/msgdlg.h>
#include <wx/filedlg.h>

//(*InternalHeaders(ybedFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ybedFrame)
const long ybedFrame::ID_TEXTCTRL1 = wxNewId();
const long ybedFrame::idMenuSave = wxNewId();
const long ybedFrame::idMenuQuit = wxNewId();
const long ybedFrame::idMenuAbout = wxNewId();
const long ybedFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ybedFrame,wxFrame)
    //(*EventTable(ybedFrame)
    //*)
END_EVENT_TABLE()

ybedFrame::ybedFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ybedFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuItem* MenuItem3;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(782,450));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(216,176), wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(10,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuSave, _("Save\tCtrl-S"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ybedFrame::OnSave);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ybedFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ybedFrame::OnAbout);
    //*)
}

ybedFrame::~ybedFrame()
{
    //(*Destroy(ybedFrame)
    //*)
}

void ybedFrame::OnSave(wxCommandEvent& event) {
    unsigned int line_n = 0;

    wxFileDialog save_dialog( this, _("Save to..."), L"", L"", L"All (*.*)|*.*|Yabasic Program (*.yab)|*.yab", wxSAVE | wxCHANGE_DIR );
    save_dialog.ShowModal();

    wxString path = save_dialog.GetPath();

    std::ofstream out( path.fn_str() );

    if ( !out.fail() ) {

        for ( line_n = 0 ; line_n < TextCtrl1->GetNumberOfLines() ; ++line_n ) {
            out << TextCtrl1->GetLineText( line_n ).ToAscii() << std::endl;
        }

        out.close();
    }
}

void ybedFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ybedFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
