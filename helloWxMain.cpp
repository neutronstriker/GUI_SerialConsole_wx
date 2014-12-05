/***************************************************************
 * Name:      helloWxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    NeutroNStrikeR (striker.dbz@hotmail.com)
 * Created:   2014-09-11
 * Copyright: NeutroNStrikeR (http://nvstech.weebly.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "helloWxMain.h"
#include <wx/msgdlg.h>
#include<windows.h>


//(*InternalHeaders(helloWxFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
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

//(*IdInit(helloWxFrame)
const long helloWxFrame::ID_STATICBOX2 = wxNewId();
const long helloWxFrame::ID_STATICBOX1 = wxNewId();
const long helloWxFrame::ID_BUTTON1 = wxNewId();
const long helloWxFrame::ID_TEXTCTRL1 = wxNewId();
const long helloWxFrame::ID_TEXTCTRL2 = wxNewId();
const long helloWxFrame::ID_BUTTON2 = wxNewId();
const long helloWxFrame::ID_COMBOBOX1 = wxNewId();
const long helloWxFrame::ID_STATICTEXT1 = wxNewId();
const long helloWxFrame::ID_CHECKBOX1 = wxNewId();
const long helloWxFrame::ID_TEXTCTRL3 = wxNewId();
const long helloWxFrame::ID_RADIOBUTTON1 = wxNewId();
const long helloWxFrame::ID_RADIOBUTTON2 = wxNewId();
const long helloWxFrame::ID_CHECKBOX2 = wxNewId();
const long helloWxFrame::ID_PANEL1 = wxNewId();
const long helloWxFrame::idMenuOnCountByte = wxNewId();
const long helloWxFrame::idMenuQuit = wxNewId();
const long helloWxFrame::idMenuOnReceiveClear = wxNewId();
const long helloWxFrame::idMenuOnSendClear = wxNewId();
const long helloWxFrame::idMenuAbout = wxNewId();
const long helloWxFrame::ID_STATUSBAR1 = wxNewId();
const long helloWxFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(helloWxFrame,wxFrame)
    //(*EventTable(helloWxFrame)
    //*)
END_EVENT_TABLE()

helloWxFrame::helloWxFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(helloWxFrame)
    wxMenuItem* MenuItem2;
    wxMenu* Menu3;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem4;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("neo-Serial Terminal"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetMinSize(wxSize(400,378));
    SetMaxSize(wxSize(400,378));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\neutron\\Downloads\\Fatcow-Farm-Fresh-Port.ico"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(152,16), wxSize(400,376), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBox2 = new wxStaticBox(Panel1, ID_STATICBOX2, _("Received Data"), wxPoint(8,136), wxSize(368,160), 0, _T("ID_STATICBOX2"));
    StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Port Setup"), wxPoint(256,8), wxSize(120,120), 0, _T("ID_STATICBOX1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Send"), wxPoint(176,80), wxSize(72,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetDefault();
    Button1->SetFocus();
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(24,16), wxSize(224,56), wxTE_AUTO_SCROLL|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetToolTip(_("Enter Characters to Send to Serial Device"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("COM16"), wxPoint(272,24), wxSize(88,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Connect"), wxPoint(272,48), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(272,96), wxSize(88,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->Append(_("1200"));
    ComboBox1->Append(_("4800"));
    ComboBox1->SetSelection( ComboBox1->Append(_("9600")) );
    ComboBox1->Append(_("19200"));
    ComboBox1->Append(_("38400"));
    ComboBox1->Append(_("57600"));
    ComboBox1->SetToolTip(_("Select BaudRate for serial Comm"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("BAUD RATE"), wxPoint(288,80), wxSize(64,16), 0, _T("ID_STATICTEXT1"));
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Instant Send"), wxPoint(24,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    CheckBox1->SetToolTip(_("Check this button so that characters entered are sent instantly i.e. Don\'t wait until \"send\" is clicked."));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(24,160), wxSize(336,120), wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->SetToolTip(_("This is response console, data received from serial port is shown here."));
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Char"), wxPoint(24,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetValue(true);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Hex"), wxPoint(80,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    CheckBox2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Start Listening"), wxPoint(136,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(true);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu1, idMenuOnCountByte, _("Count Received byte\tALT+C"), _("Count number of bytes/chars received."), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuOnReceiveClear, _("Clear Receive Panel\tALT+R"), _("Clear the Receive Text input Panel"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, idMenuOnSendClear, _("Clear Send Panel\tALT+S"), _("Clear the Send Text panel."), wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("Clear"));
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
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1000, false);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&helloWxFrame::OnButton1Click1);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&helloWxFrame::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_MAXLEN,(wxObjectEventFunction)&helloWxFrame::OnTextCtrl1TextMaxLen);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&helloWxFrame::OnButton2Click);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnComboBox1Select);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnRadioButtonChar);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnRadioButtonHex);
    Connect(idMenuOnCountByte,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnMenuCountBytes);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnQuit);
    Connect(idMenuOnReceiveClear,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnMenuItem3Selected);
    Connect(idMenuOnSendClear,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnMenuItem4Selected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&helloWxFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&helloWxFrame::OnTimer1Trigger1);
    //*)
}

helloWxFrame::~helloWxFrame()
{
    //(*Destroy(helloWxFrame)
    //*)
}

//Gloabal serial related vars
#define CHAR 0
#define HEX 1
   HANDLE	hCom; //Handle variable
	DWORD	rwlen;
	static int connection_flag=0;
    static int output_flag = CHAR;
void helloWxFrame::OnQuit(wxCommandEvent& event)
{
    CloseHandle( hCom );
    Close();

}

void helloWxFrame::OnAbout(wxCommandEvent& event)
{
   // wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to..."));
    wxMessageBox(_("neo-Serial Terminal v1.0\nDesigned by N.Srinivas  a.k.a. NeutroN StrikeR\nhttp:\\\\www.xmechtronics.com\nhttp:\\\\nvstech.weebly.com\nmailto:striker.dbz@hotmail.com"),_("About neo-Serial Terminal"));
}

void helloWxFrame::OnMenuhello(wxCommandEvent& event)
{

    wxMessageBox(_("hello"),_("hello"));//neutron did this _("string") does autocasting to requiered format.
    //TextCtrl1->SetValue(_("getlost")); //serials an event EVT_TEXT
    TextCtrl1->ChangeValue(_("getout"));//doesn't invoke the event
    //if you don't want to destroy data in it use AppendText
}

void helloWxFrame::OnButton1Click(wxCommandEvent& event)
{

}


void helloWxFrame::OnButton1Click1(wxCommandEvent& event)
{
   // ShellAboutA(NULL,"Hello","How are u", NULL);
  // wxString value = TextCtrl1->GetValue();
   //wxMessageBox(_("user has entered\n")+value, _("Message Box title /*Optional */"));
  //  TextCtrl1->AppendText(_("hello"));
   // *TextCtrl1<<12.45<<'c'<<17000<<_("hello");
  // TextCtrl1->SetValue(_("hello"));

    //send data
    if(!connection_flag)
    {
        wxMessageBox(_("First Connect to A port"),_("Error!"),wxICON_ERROR);
        return;
    }
    wxString temp = TextCtrl1->GetValue();
    char *serialbuf;
    int n =0;

    serialbuf = strdup(temp.ToAscii()); //to convert to ascii from wxString
    n= strlen(serialbuf);           //very important for me
    WriteFile(hCom, serialbuf ,n,&rwlen,0 );
   // Sleep(100);
 /*   //read data
    Sleep(1000);
    char receive[32];

    int bytes2receive=32;
    ReadFile( hCom, receive, bytes2receive, &rwlen, 0 );

    wxString tempo;
    tempo = tempo.FromAscii(receive); // to convert to wxString from Ascii
    TextCtrl3->SetValue(tempo);         //very important for me
*/
}

wxString GetCurrentChar(wxTextCtrl *tc)
{//algorithm to get just entered character through any TextCtrl
    long pos = tc->GetInsertionPoint();
    // if ( pos == tc->GetLastPosition() )//neutron modified this example provided by wxWidgets wiki
    //return wxString();
    return tc->GetRange(pos-1, pos);

}


void helloWxFrame::OnTextCtrl1Text(wxCommandEvent& event)
{

    //Timer1.Stop();//look end of this function for description

    wxString hyperstr = GetCurrentChar(TextCtrl1);
    char *character;
    character = strdup(hyperstr.ToAscii());
    //ShellExecuteA(0,0,"wmplayer","play",0,SW_SHOWMAXIMIZED);
    int n= strlen(character); //we can skip this line since we are entering
    //only single character and we also now that the data in *character is a single
    //character instead of 'n' we can pass 1 to WriteFile();
    if(CheckBox1->IsChecked() && connection_flag)
    {

        WriteFile(hCom,character,n,&rwlen,0);

    }
  // Sleep(100);
  // Timer1.Start();//some times it is necessary to stop the timer
   //so that the receive panel doesn't dump garbage
}

int connectport(char * port, unsigned long BAUD)
{

    char port_name[20];

    sprintf( port_name, "\\\\.\\%s", port );

	hCom = CreateFileA( port_name, GENERIC_READ|GENERIC_WRITE,
					0, 0, OPEN_EXISTING, 0, 0 );
     if( hCom==INVALID_HANDLE_VALUE )
        {
            printf( "\terror: %s is not available.\n", port );
            return 0;
        }
         DCB dcbSerialParams = {0};

    dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

    if (!GetCommState(hCom, &dcbSerialParams))
    {
        printf("Unable to get the state of serial port");
    //error getting state
    }

    dcbSerialParams.BaudRate= BAUD; //= CBR_9600;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;

    if(!SetCommState(hCom, &dcbSerialParams))
    {
        printf("Unable to set serial port settings\n");
               //error setting serial port state
    }

    /* DCB optional part ends here */

    /* COMTIMEOUTS Optional Part but very usefull especially against ReadHAngs */

    COMMTIMEOUTS timeouts={0};
                                               //previous values
    timeouts.ReadIntervalTimeout=1;//=MAXDWORD;//=50;
    timeouts.ReadTotalTimeoutConstant=1;//=50;
    timeouts.ReadTotalTimeoutMultiplier=1;//=10;
    timeouts.WriteTotalTimeoutConstant=10;//=50;
    timeouts.WriteTotalTimeoutMultiplier=2;//=10;

    if(!SetCommTimeouts(hCom, &timeouts))
    {

        printf("Error setting Serial Port timeouts property\n");
        //error occureed. Inform user
    }
    return 1;
}

void helloWxFrame::OnButton2Click(wxCommandEvent& event)
{

    if(!connection_flag)
    {


    wxString port = TextCtrl2->GetValue();
    wxString baud = ComboBox1->GetValue();
    char *portname;
    unsigned long baudrate;

    if(!baud.ToULong(&baudrate))
    {
        wxMessageBox(_("Enter a Valid BaudRate"), _("Warning"),wxICON_WARNING);
        return;
    }

    if(baudrate < 300 || baudrate > 460800  )
    {
        wxMessageBox(_("Enter a Valid BaudRate"), _("Warning"),wxICON_WARNING);
        return;
    }

    portname = strdup(port.ToAscii());

    if(connectport(portname,baudrate))
        {
            wxMessageBox(_("Connected to port ")+port,_("Info"));
            Button2->SetLabel(_("Disconnect"));
            connection_flag = 1;

        }
    else
         wxMessageBox(port+_(" port not available"),_("Info"));
    }

    else
    {
        CloseHandle(hCom);
        connection_flag = 0;
        Button2->SetLabel(_("Connect"));
    }
}

void helloWxFrame::OnPanel1Paint(wxPaintEvent& event)
{
}

void helloWxFrame::OnComboBox1Select(wxCommandEvent& event)
{
}

void helloWxFrame::OnTextCtrl1TextMaxLen(wxCommandEvent& event)
{
    TextCtrl1->Clear(); //clear the TextBOx1 if characters in it exceed
    //maxlength
}

void helloWxFrame::OnTimer1Trigger1(wxTimerEvent& event)
{
    if(CheckBox2->IsChecked())
    if(connection_flag)
    {
        char receive[128];//when buffer size was 32 i used to receive lot of garbage  but by making 128 it has
        //been significantly reduced

        int bytes2receive=sizeof(receive);
        ReadFile( hCom, receive, bytes2receive, &rwlen, 0 );

        char actualdata[128];

        strncpy(actualdata,receive,rwlen);

        if(rwlen!=0)
        {
            wxString tempo;

            if(output_flag == CHAR)
            {

            tempo = tempo.FromAscii(actualdata); // to convert to wxString from Ascii
                  //very important for me
            TextCtrl3->AppendText(tempo);
            }

            else if (output_flag == HEX)
            {
                for(uint8_t i=0;i<rwlen;i++)
                {


                    tempo.Printf(_("0x%x "),actualdata[i]);
                    TextCtrl3->AppendText(tempo);
                }
            }


        }

    }
}

void helloWxFrame::OnMenuItem3Selected(wxCommandEvent& event)
{//clear receive text panel
    TextCtrl3->Clear();
}

void helloWxFrame::OnMenuItem4Selected(wxCommandEvent& event)
{//clear send text input panel
    TextCtrl1->Clear();
}

void helloWxFrame::OnMenuCountBytes(wxCommandEvent& event)
{
    long count = TextCtrl3->GetLastPosition();
    wxString countvalue;
    countvalue.Printf(_("%ld"),count);
    //count the number of bytes or characters present in receive text box
    wxMessageBox(_("Character Count is ")+countvalue,_("Count"));
}

void helloWxFrame::OnRadioButtonHex(wxCommandEvent& event)
{
    output_flag = HEX;
}

void helloWxFrame::OnRadioButtonChar(wxCommandEvent& event)
{
    output_flag  = CHAR;
}


//And last but not the least to reduce the glitches completely in
//reception part we will need atleast a new thread which would
//continuously check for new data in the fifo buffer and print
//it to the textctrl using some kind of interthread coomunication
//to access objects of mainthread.Currently there is a clash between the INPUT
//and ouput methods when entering text so we get a kind of
//garbage values sometimes.
