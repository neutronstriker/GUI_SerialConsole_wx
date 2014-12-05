/***************************************************************
 * Name:      helloWxMain.h
 * Purpose:   Defines Application Frame
 * Author:    NeutroNStrikeR (striker.dbz@hotmail.com)
 * Created:   2014-09-11
 * Copyright: NeutroNStrikeR (http://nvstech.weebly.com)
 * License:
 **************************************************************/

#ifndef HELLOWXMAIN_H
#define HELLOWXMAIN_H

//(*Headers(helloWxFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class helloWxFrame: public wxFrame
{
    public:

        helloWxFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~helloWxFrame();

    private:

        //(*Handlers(helloWxFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuhello(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnComboBox1Select(wxCommandEvent& event);
        void OnTextCtrl1TextMaxLen(wxCommandEvent& event);
        void OnTimer1Trigger1(wxTimerEvent& event);
        void OnMenuItem3Selected(wxCommandEvent& event);
        void OnMenuItem4Selected(wxCommandEvent& event);
        void OnMenuCountBytes(wxCommandEvent& event);
        void OnRadioButtonHex(wxCommandEvent& event);
        void OnRadioButtonChar(wxCommandEvent& event);
        //*)

        //(*Identifiers(helloWxFrame)
        static const long ID_STATICBOX2;
        static const long ID_STATICBOX1;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON2;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_CHECKBOX1;
        static const long ID_TEXTCTRL3;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_CHECKBOX2;
        static const long ID_PANEL1;
        static const long idMenuOnCountByte;
        static const long idMenuQuit;
        static const long idMenuOnReceiveClear;
        static const long idMenuOnSendClear;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(helloWxFrame)
        wxRadioButton* RadioButton1;
        wxMenuItem* MenuItem5;
        wxRadioButton* RadioButton2;
        wxButton* Button1;
        wxCheckBox* CheckBox2;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticBox* StaticBox1;
        wxButton* Button2;
        wxCheckBox* CheckBox1;
        wxStaticBox* StaticBox2;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxComboBox* ComboBox1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl3;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOWXMAIN_H
