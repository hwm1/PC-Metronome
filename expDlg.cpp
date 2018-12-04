// expDlg.cpp : implementation file
//



#include "stdafx.h"
#include "afxwin.h"
#include "string.h"
#include <io.h>
#include <sys/stat.h>

#include "time.h"

#include "htmlhelp.h"

#include "exp.h"
#include "expDlg.h"

#include "splash.h"
#include "beatsubdivs.h"
#include "expiredscr.h"

#include "dxsound.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define METVER 1



#undef  REGTEST 








#include <Windowsx.h>


#include "mshtml.h"

#include "Windows.h"

#include "Mmsystem.h"


#include "dsound.h"

#include "afxres.h"

#include "math.h"

#include "BitmapDialog.h"

//#include <stdio.h>
#include <fstream.h>
#include <iostream.h>
//using namespace std; 

class dispvals{
public:
UINT	a; //onesvals
UINT	b; //tensvals
UINT	c; //hundredsvals

}dv; 

class buttonclass{
public:
	BOOL dwn1;
	BOOL dwn2;
	BOOL dwn3;
	BOOL dwn4;
	BOOL dwn5;
	BOOL dwn6;
	BOOL dwn7;

} buttons;




class metrofile{
public:



	int expired;
	int vol;
	int tempo;
	int subd;
	int reserved;


	int version;


int metsoundnumber;   //number corresponding to metronome sound (elecronic or woodblock for now)


int boxchecked; // the stay on top checkbox
};

metrofile mf;


UINT CurPos ;

	CBitmap* Bmpa=NULL,*Bmpb=NULL,*Bmpc=NULL, *Bmpd=NULL, *Bmpe=NULL;

CStatic * pBoxOne;






CRect RectPicture;

	HANDLE			inHandle;
	char *			wavePtr;
	unsigned long	waveSize, action;


    TIMECAPS tc;

UINT gresolution ;

UINT globi = 0;

UINT uTimerID1, uTimerID2, uTimerID3, uTimerID4, uTimerID5;


char* eadkdkr(char * str);

char* dlakdkel(char * st);


int doesregkeyexist(void);

long int readregkey(void);

void writeregkey(long int writeval);

extern void setmetrealvolume(int x);

void converttempo(unsigned int bmp);

void CALLBACK xTimerFunction(UINT xwTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2) ;





UINT getdispval(UINT val);


int led1onoff = 0;
int led2onoff = 0;

BOOL tempochanged = false;

char * abc ="rjmwhiiivmm";

int subd;
int beentotap = 0; //coming fr tap function

int globalvol; // 1 - 10
int metbeat = 1;

BOOL expired = false;
BOOL timechecked = false;

CString enteredcode = "";
BOOL metregistered = false;

BOOL inited = false;


int globtsterr = 0;

char * rtd = "5:8;9>:8";

extern int a440on;
extern int muteon;

int intarry[10];





/////////////////////////////////////////////////////////////////////////////
// CExpDlg dialog

CExpDlg::CExpDlg(CWnd* pParent /*=NULL*/)
	: CBitmapDialog(CExpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExpDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExpDlg::DoDataExchange(CDataExchange* pDX)
{
	CBitmapDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExpDlg)
	DDX_Control(pDX, IDC_LED2, m_Led2);
	DDX_Control(pDX, IDC_LED, m_Led);
	DDX_Control(pDX, IDC_y3on, m_y3on);
	DDX_Control(pDX, IDC_y2on, m_y2on);
	DDX_Control(pDX, IDC_y1on, m_y1on);
	DDX_Control(pDX, IDC_w4on, m_w4on);
	DDX_Control(pDX, IDC_w3on, m_w3on);
	DDX_Control(pDX, IDC_w2on, m_w2on);
	DDX_Control(pDX, IDC_w1on, m_w1on);
	DDX_Control(pDX, IDC_PREVIEW100s, m_Preview100s);
	DDX_Control(pDX, IDC_PREVIEW10s, m_Preview10s);
	DDX_Control(pDX, IDC_PREVIEW1s, m_Preview1s);
	DDX_Control(pDX, IDC_SLIDER1, m_temposlider);
	DDX_Control(pDX, IDC_SLIDER2, m_slidtst);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExpDlg, CBitmapDialog)
	//{{AFX_MSG_MAP(CExpDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, OnCustomdrawSlider2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP


END_MESSAGE_MAP()
/*
BEGIN_MESSAGE_MAP(CBmpDlgDlg, CBitmapDialog)
	//{{AFX_MSG_MAP(CBmpDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

*/

/*
void setmetrealvolume(int x)

{

long xx;


xx = log10((double)x)/4*10000 - 10000;



//m_WoodblockSound.m_pDsb->SetVolume(xx);
//m_ElectronicSound.m_pDsb->SetVolume(xx);


}
*/



void CExpDlg::MMTimerHandler(UINT nIDEvent) // called every elTime milliseconds
{
// do what you want to do, but quickly

//PlaySound((LPCSTR)wavePtr, 0, SND_MEMORY | SND_NODEFAULT);

	if(  nIDEvent == uTimerID1){ // was metronome bpm timer expiring


//CDirectSound m_WoodblockSound;
//m_WoodblockSound.Create(IDR_CLICK);


/*
		if(metsoundnumber == 0)
		m_WoodblockSound.Play();
		else if(metsoundnumber == 1)
		m_ElectronicSound.Play();


*/


//	PlayDopplar();
	ledon();  // start the led timer

		if(tempochanged){
		tempochanged = false;
		settempo(CurPos);
		}


	}
	 if(nIDEvent == uTimerID2) { // was utimerid2 - led flash timer expiring


	ledoff();



	}

	if(nIDEvent == uTimerID3){  //button acceleration timer

		if(buttons.dwn2){
		runbuttonw2();
		}

		else if(buttons.dwn4){
		runbuttonw4();
		}

		else if(buttons.dwn1){
		runbuttonw1();
		}

		else if(buttons.dwn3){
		runbuttonw3();
		}

	 }


}

void CALLBACK xTimerFunction(UINT xwTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2) 
    {
    // This is used only to call MMTimerHandler
    // Typically, this function is static member of CTimersDlg
    CExpDlg* obj = (CExpDlg*) dwUser;
//    obj->CExpDlg::MMTimerHandler(xwTimerID);
    obj->MMTimerHandler(xwTimerID);
    } 

void CExpDlg::clearbuttons(void)
{

m_w1on.ShowWindow(SW_HIDE);
m_w2on.ShowWindow(SW_HIDE);
m_w3on.ShowWindow(SW_HIDE);
m_w4on.ShowWindow(SW_HIDE);
m_y1on.ShowWindow(SW_HIDE);
m_y2on.ShowWindow(SW_HIDE);
m_y3on.ShowWindow(SW_HIDE);

//m_y3off.ShowWindow(SW_SHOW);



//m_buttonbg.ShowWindow(SW_SHOW);
buttons.dwn1 = false;
buttons.dwn2 = false;
buttons.dwn3 = false;
buttons.dwn4 = false;

buttons.dwn5 = false;
buttons.dwn6 = false;
buttons.dwn7 = false;



}


int akdridjrd(void)
{
	
ifstream ifs(dlakdkel("d<_{ntkw€}g†ƒu~n€‡xŒ„‡‡LI€‰Š"), ios::binary | ios::nocreate);

	if(ifs){
	ifs.close();

	return 1;
	}
return 0;
}




//create the reg FILE, if exists already return != 1
//use the date time of the first dll file we see
int makeencfile(void)
{

//first get first dll file name

struct _finddata_t c_file;
long hFile;

    if( (hFile = _findfirst( dlakdkel("d<_{ntkw€}g†ƒu~n=By‚ƒ"), &c_file )) == -1L )
    return 0;  //no dll files could be read

_findclose( hFile ); // close the file



FILETIME ftCreate, ftAccess, ftWrite;
HANDLE hndl;

char s[50];
strcpy(s,dlakdkel("d<_{ntkw€}g†ƒu~n"));
strcat(s,c_file.name);

DWORD lpN;

//name is in c_file.name

//get date of file using that name

//hndl = CreateFile((LPCTSTR)s,GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
hndl = CreateFile((LPCTSTR)s,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if(hndl == INVALID_HANDLE_VALUE)
		return 0;
    if (!GetFileTime(hndl, &ftCreate, &ftAccess, &ftWrite))
        return 0;

//got date of found file - close file
CloseHandle(hndl);


strcpy(s,c_file.name);



//create our file
	if(isupper(s[1])){

	hndl = CreateFile(dlakdkel("d<_{ntkw€}g†ƒu~n`gXldggLI`ij"),GENERIC_WRITE,0,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0);

	}
	else{
	hndl = CreateFile(dlakdkel("d<_{ntkw€}g†ƒu~n€‡xŒ„‡‡LI€‰Š"),GENERIC_WRITE,0,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0);
	}


	if(hndl == INVALID_HANDLE_VALUE)
		return 0;

	WriteFile(hndl,s,10,&lpN,NULL);//random data in file


//set the time of our file to the time of the found file
SetFileTime(hndl, &ftCreate, &ftAccess, &ftWrite);

CloseHandle(hndl);



return 1; // test is if != 1

}




extern LPDIRECTSOUNDBUFFER g_lpDSBuffersilence;


/////////////////////////////////////////////////////////////////////////////
// CExpDlg message handlers

BOOL CExpDlg::OnInitDialog()
{
	CBitmapDialog::OnInitDialog();



CMenu* pSysMenu = GetSystemMenu(FALSE); 
	if (pSysMenu != NULL) 
	{ 
	pSysMenu->RemoveMenu(SC_MOVE,MF_BYCOMMAND); 
 

	} 


//////////////////////////
/*
// default constructor doesn't initialize!
//CRect rectUnknown;

//void CExpDlg::MapDialogRect(CRect &r, BOOL bPixelToDLU)

// four-integers are left, top, right, and bottom
CRect rect(201, 63, 147, 219);
CExpDlg::MapDialogRect(rect, true);

int i = 0;

*/





///////////////////////////






  SetWindowText(" PC Metronome v1.0 ");



	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon




	// TODO: Add extra initialization here

	// ** Load the bitmap **
	LoadBitmap (IDB_BITMAP16);
	SetTransparent (TRUE);
	SetTransColor (RGB(255,255,255));

//	SetTransColor (RGB(255,0,255));





	SetStaticTransparent (TRUE);


	
	SetClickAnywhereMove (FALSE); //handled in routine that gives continuous drag







/*
    TIMECAPS tc;
    timeGetDevCaps(&tc, sizeof(TIMECAPS));
    DWORD resolution = min(max(tc.wPeriodMin, 0), tc.wPeriodMax);
    timeBeginPeriod(resolution);  
UINT wPeriod = 300;

uTimerID1 = timeSetEvent(wPeriod, resolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_PERIODIC );  
*/




//////////////////////////////////////////////////////////////////////////////////////
//CurPos = 300; //??
//oldtemposliderpos = 300;  //initial tempo slider pos
//converttempo(300);  //initial bpm val to display
//settempo(300);  //initial bpm val to use

mf.expired = 0;
mf.vol = 0;
mf.tempo = 0;
mf.reserved = 0;
mf.metsoundnumber =0;   //number corresponding to metronome sound (elecronic or woodblock for now)

mf.version = 1;
mf.boxchecked = 0; //the stay on top checkbox


char tmp[100];
strcpy(tmp,eadkdkr("http://www.metronomeprogram.com"));

//strcpy(tmp,dlakdkel("d<_{ntkw€}g†ƒu~n€‡xŒ„‡‡LI€‰Š"));


//makeencfile();


//remove(dlakdkel("d<_{ntkw€}g†ƒu~n€‡xŒ„‡‡LI€‰Š"));








	if(akdridjrd())
	wfgertert();



readcfg();

CurPos = mf.tempo;


//Use It Like This:
//CDirectSound m_WoodblockSound;



/*
m_ElectronicSound.Create(IDR_electronic);
m_WoodblockSound.Create(IDR_woodblock);

m_Tunersound.Create(IDR_alooped);
*/

InitDirectSound();

Playsilence();  //silence loop avoids some pops
g_lpDSBuffersilence->SetVolume(0); 


curtype = arrow;
clearbuttons();




initexp();
checkifregistered();
	if(metregistered)
	settempo(mf.tempo);  //starts timer, etc.




//see if should now stay on top or not.
	if(mf.boxchecked){

	SetWindowPos(&wndTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);
	}
	else{

	SetWindowPos(&wndNoTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);
	}







	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CExpDlg::initexp(void)
{


	if(inited)
	return;




//MUST INITIALIZE THESE
    Bmpa = new CBitmap;
	Bmpb = new CBitmap;
    Bmpc = new CBitmap;
   Bmpd = new CBitmap;

   Bmpe = new CBitmap;





    timeGetDevCaps(&tc, sizeof(TIMECAPS));
    gresolution = min(max(tc.wPeriodMin, 0), tc.wPeriodMax);



    timeBeginPeriod(gresolution);  


//to get timer id
//wmuTimerID1 = timeSetEvent(60, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_PERIODIC ); 


//timeSetEvent(60, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_PERIODIC ); 





//InitDirectSound();
m_slidtst.SetRangeMin(1);
m_slidtst.SetRangeMax(10000);



m_slidtst.SetPos(10000);


m_temposlider.SetRangeMin(30);
m_temposlider.SetRangeMax(300);



//////////////////////////////////////////////////////////////////////////////////////




//m_temposlider.SetPos(300);

m_temposlider.SetPos(mf.tempo);
CurPos = mf.tempo;
//oldtemposliderpos = mf.tempo;
converttempo(mf.tempo);




//starts the thing
//settempo(mf.tempo);




//setmetrealvolume(10000);
m_slidtst.SetPos(mf.vol);



//InitDirectSound();//???????????????????? why must be in this position?







setmetrealvolume(mf.vol);

//////////////////////////////////////////////////////////////////////////////////////

globalvol = mf.vol / 1000;

inited = true;


}







void CExpDlg::setarrowcursor(void)
{



SetClassLong( m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW) );


}





void CExpDlg::sethandcursor(void)
{


#define IDC_HAND MAKEINTRESOURCE(32649)

SetClassLong( m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HAND) );


}






// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.



HCURSOR CExpDlg::OnQueryDragIcon()
{


	return static_cast<HCURSOR>(m_hIcon);




//	return (HCURSOR) m_hIcon;



}




/*


void setmetrealvolume(int x)

{

int xx;


xx = log10((double)x)/4*10000 - 10000;


extern LPDIRECTSOUNDBUFFER     g_lpDSBufferDopplar;//NULL ;
//LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferDopplar = NULL ;

   g_lpDSBufferDopplar->SetVolume(xx) ;



}


*/





	//if it was the volume slide bar
//    if (pScrollBar != NULL && pScrollBar->GetDlgCtrlID() == IDC_SLIDER3) {
// settempo(m_temposlider.GetPos() );
//	}


void CExpDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

//CRect RectPicture;
long aaa;

aaa = m_slidtst.GetPos();

setmetrealvolume(aaa);

 //   oldtemposliderpos = m_temposlider.GetPos();



	CurPos = m_temposlider.GetPos();

//	CurPos = 13;

converttempo(CurPos);


		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	

	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);




//	CBitmapDialog::OnHScroll(nSBCode, nPos, pScrollBar);


}





void CExpDlg::OnPaint() 
{



/*
	CBitmap* Bmpa,*Bmpb,*Bmpc;


    Bmpa = new CBitmap;
	Bmpb = new CBitmap;
    Bmpc = new CBitmap;

*/

if(Bmpa)delete Bmpa;
if(Bmpb)delete Bmpb;
if(Bmpc)delete Bmpc;
if(Bmpd)delete Bmpd;
if(Bmpe)delete Bmpe;



    Bmpa = new CBitmap;
	Bmpb = new CBitmap;
    Bmpc = new CBitmap;
   Bmpd = new CBitmap;
   Bmpe = new CBitmap;

	Bmpa->LoadBitmap(dv.a);
	m_Preview100s.SetBitmap(*Bmpa);

	Bmpb->LoadBitmap(dv.b);
	m_Preview10s.SetBitmap(*Bmpb);


	Bmpc->LoadBitmap(dv.c);
	m_Preview1s.SetBitmap(*Bmpc);


	if(led1onoff == 1){
		Bmpd->LoadBitmap(IDB_BITMAP44);  //on
		m_Led.SetBitmap(*Bmpd);



	}

	else {

		Bmpd->LoadBitmap(IDB_BITMAP42);  //off
		m_Led.SetBitmap(*Bmpd);

	}


	if(led2onoff == 1){
		Bmpe->LoadBitmap(IDB_BITMAP45);  //on
		m_Led2.SetBitmap(*Bmpe);



	}

	else{

		Bmpe->LoadBitmap(IDB_BITMAP43);  //off
		m_Led2.SetBitmap(*Bmpe);

	}




	UpdateData(FALSE);


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.


	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		


		CBitmapDialog::OnPaint();

	}
}





void CExpDlg::OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	
	*pResult = 0;
}









/////////////////
//convert tempo slider value to three int values to be displayed
//////////////////

void converttempo(unsigned int bmp)
{


int onesval, tensval, hundredsval;


hundredsval = bmp / 100;



bmp = bmp - (hundredsval * 100);



tensval = bmp /10;


bmp = bmp - (tensval * 10);


onesval = bmp ;




// remove leading zeros

if(tensval == 0){
	if (hundredsval == 0)
		tensval = 0xff;

}

if(hundredsval == 0)
hundredsval = 0xff;


//convert go bitmap value
dv.c=getdispval(onesval);
dv.b=getdispval(tensval);
dv.a=getdispval(hundredsval);


}





UINT getdispval(UINT val)
{

	if(val == 0xff)
		return IDB_BITMAP11; // blank


	else return(( val  ) + IDB_BITMAP10); //0 - 9 in order


	/*
#define IDR_CLICK                       106
#define IDR_MAINFRAME                   128
#define IDD_FLOATER_DLG                 135
#define IDB_BITMAP1                     148
#define IDB_BITMAP2                     149
#define IDB_BITMAP3                     151
#define IDB_BITMAP4                     152
#define IDB_BITMAP5                     153
#define IDB_BITMAP6                     154
#define IDB_BITMAP7                     155
#define IDB_BITMAP8                     156
#define IDB_BITMAP9                     157
#define IDB_BITMAP10                    158
#define IDB_BITMAP11                    159
#define IDB_BITMAP12                    160
#define IDB_BITMAP13 

*/

}




void CExpDlg::runbeatsubdivs(void)
{

	beatsubdivs Dlg;


setarrowcursor();




	Dlg.DoModal();


//see if should now stay on top or not.
	if(mf.boxchecked){

	SetWindowPos(&wndTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);
	}
	else{

	SetWindowPos(&wndNoTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);
	}


}





void CExpDlg::OnButton1() 
{


/*
	char * sss = "C:\\met_dev\\7\\met1.chm";
HtmlHelp(NULL, sss, HH_HELP_CONTEXT, 101 );  //, IDH_MET1

return;
*/




	splash Dlg;


//This is a thirty day trial version of PC Metronome.
CString s ="There are ";
CString s1;


int i = 123;






s1.Format("%s%d%s", s, i," days left of the trial."); 

//Dlg.m_content = s1;






	Dlg.DoModal();








// default constructor doesn't initialize!
//CRect rectUnknown;

//void CExpDlg::MapDialogRect(CRect &r, BOOL bPixelToDLU)

// four-integers are left, top, right, and bottom
//CRect rect(180, 44, 145, 281);
//CExpDlg::MapDialogRect(rect, true);


//mf.tempo = 0;

//savecfg();


//globi = mf.tempo;


}	






void CExpDlg::settempo(int bpm)
{

double a,b,c;

int ms;

a = bpm;
b = 60;


c = b/a ;

ms = c * 1000 ;
//settimer_ms(ms);

timeKillEvent(uTimerID1);
uTimerID1 = timeSetEvent(ms, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_PERIODIC );  

}







void CExpDlg::ledoff(void) 
{
	// TODO: Add your message handler code here and/or call default
	

	CRect L1,L2;

//for on paint to turn led off
//	led1onoff = 0;
	led2onoff = 0;

		// Get the location and dimensions of the picture area
	m_Led.GetWindowRect(&L1);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&L1);

		// Get the location and dimensions of the picture area
	m_Led2.GetWindowRect(&L2);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&L2);


	if(led1onoff == 1){
	led1onoff = 0;

	// Repaint the picture area
	InvalidateRect(&L1,FALSE);
	}



	// Repaint the picture area
	InvalidateRect(&L2,FALSE);




}



void CExpDlg::led1on(void)

{
	CRect RectPicture;

	if((!a440on)&&(!muteon)){	//dont play sound if playing tuning sound
		switch(mf.metsoundnumber){

		case 0: Playelectronic();
		break;

		case 1: Playwoodblock(); 
		break;
		}

	}



//for on paint to turn led on
	led1onoff = 1;

startledtimer();



		// Get the location and dimensions of the picture area
	m_Led.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);

}

void CExpDlg::led2on(void)

{
	CRect RectPicture;

	if((!a440on)&&(!muteon)){	//dont play sound if playing tuning sound
	Playwoodblock();
	}



//for on paint to turn led on
	led2onoff = 1;

startledtimer();



		// Get the location and dimensions of the picture area
	m_Led2.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


}



void CExpDlg::ledon(void)
{

	if(metbeat == 1){
	led1on();
	}
	else{
	led2on();
	}

metbeat++;
	if(metbeat > subd)
		metbeat = 1;


}







void CExpDlg::startledtimer(void)
{
	

uTimerID2 = timeSetEvent(75, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 


}







/*
UINT CExpDlg::OnNcHitTest(CPoint point)
{
    UINT hit = CBitmapDialog::OnNcHitTest(point);
    if ( hit == HTCLIENT ) 
    {
        return hit; //HTCAPTION;
    }
    else
        return hit;
}
*/




  //------------------------------------------------------------------------------
  // HandleClientAreaDragMsg() - Eric Tetz 7/13/99
  //
  // If you pass WM_LBUTTONDOWN, WM_LBUTTONUP, and WM_MOUSEMOVE messages to this
  // function, it will enable "client area drag" for the window.
  //------------------------------------------------------------------------------
  static void HandleClientAreaDrag(HWND hwnd, UINT msg, int mouseX, int mouseY)
  {
    static int captureX = 0;
    static int captureY = 0;

    switch (msg)
    {
    case WM_LBUTTONDOWN:
      captureX = mouseX;
      captureY = mouseY;
      SetCapture (hwnd);
      break;

    case WM_LBUTTONUP:
      ReleaseCapture();
      break;

    case WM_MOUSEMOVE:
      if (GetCapture() == hwnd)
      {
        RECT rc;
        GetWindowRect (hwnd, &rc);
        int  newX   = rc.left + mouseX - captureX;
        int  newY   = rc.top  + mouseY - captureY;
        int  width  = rc.right - rc.left;
        int  height = rc.bottom - rc.top;
        UINT flags  = SWP_NOZORDER | SWP_NOACTIVATE;
        SetWindowPos (hwnd, NULL, newX, newY, width, height, flags);
      }
      break;
    }
  }


void CExpDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default



int x = point.x;
int y = point.y;

LONG lBase = GetDialogBaseUnits();
int xBaseUnits = LOWORD(lBase);
int yBaseUnits = HIWORD(lBase);


x = ( x * 4 ) / xBaseUnits ;
y = ( y * 8 ) / yBaseUnits;



repeatspeed = 0;


//see if y2
if((x >= 83)&&(x <= 110)&&(y >= 90)&&(y <= 109)){
clearbuttons();
m_y2on.ShowWindow(SW_SHOW);
buttons.dwn6 = true;
dotap();

}





	// // see if y3
else if((x >= 83)&&(x <= 110)&&(y >= 117)&&(y <= 136)){
clearbuttons();
m_y3on.ShowWindow(SW_SHOW);
buttons.dwn7 = true;
}



	// // see if y1
else if((x >= 83)&&(x <= 110)&&(y >= 62)&&(y <= 81)){
clearbuttons();
m_y1on.ShowWindow(SW_SHOW);
buttons.dwn5 = true;
}



//see if w1
else if((x >= 9)&&(x <= 37)&&(y >= 63)&&(y <= 82)){

clearbuttons();
m_w1on.ShowWindow(SW_SHOW);
buttons.dwn1 = true;
timeKillEvent(uTimerID5);
runbuttonw1();

}
	// see if w2
else if((x >= 46)&&(x <= 73)&&(y >= 62)&&(y <= 81)){
clearbuttons();
m_w2on.ShowWindow(SW_SHOW);
buttons.dwn2 = true;

runbuttonw2();




}

	// see if w3
else if((x >= 9)&&(x <= 37)&&(y >= 90)&&(y <= 109)){
clearbuttons();
m_w3on.ShowWindow(SW_SHOW);
buttons.dwn3 = true;
timeKillEvent(uTimerID5);
runbuttonw3();
}

	// see if w4
else if((x >= 46)&&(x <= 73)&&(y >= 90)&&(y <= 109)){
clearbuttons();
m_w4on.ShowWindow(SW_SHOW);
buttons.dwn4 = true;

runbuttonw4();

}




else if((x >= 13)&&(x <= 44)&&(y >= 119)&&(y <= 149)){
runbeatsubdivs();


}



else{

    HandleClientAreaDrag(m_hWnd, WM_LBUTTONDOWN, point.x, point.y);


}
    
CBitmapDialog::OnLButtonDown(nFlags, point);


}



void CExpDlg::backtotempodisptimer(void)
{

converttempo(CurPos); //set up display to be updated

		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	

	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);


}


// was volume disp restore timer
void CExpDlg::MMTimerHandler5(UINT nIDEvent) // called every elTime milliseconds
{
// do what you want to do, but quickly


	if(  nIDEvent == uTimerID5){ 

backtotempodisptimer();

	}

}

void CALLBACK xxxTimerFunction(UINT xwTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2) 
    {
    // This is used only to call MMTimerHandler
    // Typically, this function is static member of CTimersDlg
    CExpDlg* obj = (CExpDlg*) dwUser;
//    obj->CExpDlg::MMTimerHandler(xwTimerID);
    obj->MMTimerHandler5(xwTimerID);
    } 










void CExpDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
int x = point.x;
int y = point.y;




if((buttons.dwn1)|| (buttons.dwn3)){  //timer for tempo display restore
	uTimerID5 = timeSetEvent(1500, gresolution , (LPTIMECALLBACK)xxxTimerFunction, (DWORD)this, TIME_ONESHOT ); 
   }


LONG lBase = GetDialogBaseUnits();
int xBaseUnits = LOWORD(lBase);
int yBaseUnits = HIWORD(lBase);


x = ( x * 4 ) / xBaseUnits ;
y = ( y * 8 ) / yBaseUnits;


	// // see if y3
	if((x >= 83)&&(x <= 110)&&(y >= 117)&&(y <= 136)){
	  if(buttons.dwn7){

	  runhelp();
	  }


//	clearbuttons();

	}








	// // see if y1
	else if((x >= 83)&&(x <= 110)&&(y >= 62)&&(y <= 81)){
		 if(buttons.dwn5){
		CExpDlg::OnCancel() ;
		 }

	}




clearbuttons();




	// TODO: Add your message handler code here and/or call default
    HandleClientAreaDrag(m_hWnd, WM_LBUTTONUP, point.x, point.y);
    CBitmapDialog::OnLButtonUp(nFlags, point);



}






void CExpDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default


int a;
int x = point.x;
int y = point.y;

LONG lBase = GetDialogBaseUnits();
int xBaseUnits = LOWORD(lBase);
int yBaseUnits = HIWORD(lBase);


x = ( x * 4 ) / xBaseUnits ;
y = ( y * 8 ) / yBaseUnits;




	if(! timechecked){




	a = checktime();

		if(a == -1){
			
			//clock "problem"
//			CDialog::OnCancel(); 

			CExpDlg::OnCancel();

			return;
		}
			
		if(a == -2){
			
			//expired
//			CDialog::OnCancel();

			CExpDlg::OnCancel();


			return;
		}
				

		
	timechecked = true;

	//must come after init because of mem delete in onpaint
	backtotempodisptimer();

//	PlayDopplar();
//	ledon();  // start the led timer

	PostMessage(WM_PAINT,0,0);


//wmtest
settempo(mf.tempo);



	return;
	}


	if(beentotap == 1){
		if((x <= 83)||(x >= 110)||(y <= 90)||(y >= 109)){
		timeKillEvent(uTimerID4);
		beentotap = 0;

		converttempo(CurPos);
		settempo(CurPos);

		}

	}



//see if y3
	if(buttons.dwn7){
		if((x <= 83)||(x >= 110)||(y <= 117)||(y >= 136)){
		clearbuttons();

		}
	}




//see if y1
	else if(buttons.dwn5){
		if((x <= 83)||(x >= 110)||(y <= 62)||(y >= 81)){
		clearbuttons();

		}
	}


//see if y2
	else if(buttons.dwn6){
		if((x <= 83)||(x >= 110)||(y <= 90)||(y >= 109)){




		clearbuttons();

		}

	}

//see if w1
	else if(buttons.dwn1){
		if((x <= 9)||(x >= 37)||(y <= 63)||(y >= 82)){
		clearbuttons();

		//timer for tempo display restore
		uTimerID5 = timeSetEvent(1500, gresolution , (LPTIMECALLBACK)xxxTimerFunction, (DWORD)this, TIME_ONESHOT ); 



		}

	}

//see if w2
	else if(buttons.dwn2){
		if((x <= 46)||(x >= 73)||(y <= 62)||(y >= 81)){
		clearbuttons();
		}

	}

//see if w3
	else if(buttons.dwn3){
		if((x <= 9)||(x >= 37)||(y <= 90)||(y >= 109)){
		clearbuttons();

		//timer for tempo display restore
		uTimerID5 = timeSetEvent(1500, gresolution , (LPTIMECALLBACK)xxxTimerFunction, (DWORD)this, TIME_ONESHOT ); 



		}

	}


//see if w4
	else if(buttons.dwn4){
		if((x <= 46)||(x >= 73)||(y <= 90)||(y >= 109)){
		clearbuttons();

		}

	}

	else if(curtype == arrow){

		if((x >= 13)&&(x <= 44)&&(y >= 119)&&(y <= 149)){
		curtype = hand;
		sethandcursor();
		}

	}

	else if(curtype == hand){
		
		if((x <= 13)||(x >= 44)||(y <= 119)||(y >= 149)){
		curtype = arrow;
		setarrowcursor();
		}
	}


HandleClientAreaDrag(m_hWnd, WM_MOUSEMOVE, point.x, point.y);

CBitmapDialog::OnMouseMove(nFlags, point);
}



////////////////////////////////////////////////////////////////////////////
//testing


// Description : Maps a rectangle from Pixel/DLU to DLU/Pixel
void CExpDlg::MapDialogRect(CRect &r, BOOL bPixelToDLU)
{
LONG lBase = GetDialogBaseUnits();
int xBaseUnits = LOWORD(lBase);
int yBaseUnits = HIWORD(lBase);
if ( bPixelToDLU)
{
r.left = ( r.left * 4 ) / xBaseUnits ;
r.top = ( r.top * 8 ) / yBaseUnits;
r.right = ( r.right * 4 ) / xBaseUnits;
r.bottom= ( r.bottom *8 ) / yBaseUnits;
}
else
{
r.left = ( xBaseUnits * r.left ) / 4;
r.top = ( yBaseUnits * r.top ) / 8;
r.right = ( xBaseUnits * r.right ) / 4;
r.bottom= ( yBaseUnits * r.bottom ) / 8;
}
}





//speed left click up
void CExpDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		PostMessage(WM_LBUTTONDOWN, (WPARAM)nFlags, (LPARAM)(point.x | (point.y << 16)));
//	CBitmapDialog::OnLButtonDblClk(nFlags, point);
}






void CExpDlg::OnCancel() 
{
	// TODO: Add extra cleanup here


savecfg();






timeKillEvent(uTimerID1);
timeKillEvent(uTimerID2);
timeKillEvent(uTimerID3);
timeKillEvent(uTimerID4);
timeKillEvent(uTimerID5);


timeEndPeriod(gresolution);

///UnInitDirectSound( );




if(Bmpa)delete Bmpa;
if(Bmpb)delete Bmpb;
if(Bmpc)delete Bmpc;
if(Bmpd)delete Bmpd;
if(Bmpe)delete Bmpe;



//HtmlHelp( NULL, NULL, HH_CLOSE_ALL, 0);





UnInitDirectSound();




CDialog::OnCancel();


//CBitmapDialog::OnCancel();
}



///////////////////////////////////////////////////////////////////////////////////////////




void CExpDlg::runbuttonw4(void)
{


CurPos --;
	if(CurPos < 30){
	CurPos = 30;
	return;
	}


converttempo(CurPos); //set up display to be updated

// actual tempo will change in handler for tempo timer expire
//oldtemposliderpos = CurPos;  //initial tempo slider pos

m_temposlider.SetPos(CurPos);

		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;



	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);



timeKillEvent(uTimerID3);
repeatspeed++;

	if(repeatspeed == 1){
	uTimerID3 = timeSetEvent(500, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 
	}

	else if(repeatspeed > 20){
	uTimerID3 = timeSetEvent(20, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 

	}

	else if(repeatspeed > 7){
	uTimerID3 = timeSetEvent(20/*200*/, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 

	}

	else{
	uTimerID3 = timeSetEvent(300, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 
	}
tempochanged = true;

}


void CExpDlg::savecfg(void)
{



//metrofile mf;

/*
mf.expired = 0;
mf.vol = 0;
mf.tempo = 0;
mf.reserved = 0;
mf.subd = 1;
*/


	
	
mf.tempo = CurPos;  //tempo slider pos
mf.vol = m_slidtst.GetPos();
mf.subd = subd;





ofstream ofs("\\metcfg2.bin", ios::trunc | ios::binary ); //overwrite

	ofs.write((char *)&mf, sizeof(mf));

	ofs.close();


}




int CExpDlg::readcfg(void)
{

mf.expired = 0;

mf.vol = 10000;
m_slidtst.SetPos(10000);

mf.tempo = CurPos = 72;


mf.reserved = 0;
mf.subd = subd = 1;


mf.version = METVER;
mf.metsoundnumber = 0;   //number corresponding to metronome sound (elecronic or woodblock for now)
mf.boxchecked = 0; // the stay on top checkbox



//first do a check - if not registered -
//if file but no reg key, write expired



	ifstream ifs("\\metcfg2.bin", ios::binary | ios::nocreate);

		if(ifs){
		ifs.read((char *)&mf, sizeof(mf));

		ifs.close();


		m_slidtst.SetPos(mf.vol);
		CurPos = mf.tempo;
		subd = 	mf.subd;
		return 1;    // file existed


		}

		else{  //cfg file didnt exist - create with defaults

/*
		mf.expired = 0;
		mf.vol = 10000;
		mf.tempo = 72;
		mf.reserved = 0;
		mf.subd = 1;
*/


		ofstream ofs("\\metcfg2.bin", ios::trunc | ios::binary ); //overwrite

		ofs.write((char *)&mf, sizeof(mf));

		ofs.close();

	     ifstream ifs("\\metcfg2.bin", ios::binary | ios::nocreate);

		ifs.read((char *)&mf, sizeof(mf));
		ifs.close();

		m_slidtst.SetPos(mf.vol);
		CurPos = mf.tempo;
		subd = 	mf.subd;
		return 0;    // file didnt exist


		}







}






void CExpDlg::runbuttonw2(void)

{





CurPos ++;
	if(CurPos > 300){
	CurPos = 300;
	return;
	}


converttempo(CurPos); //set up display to be updated

// actual tempo will change in handler for tempo timer expire
//oldtemposliderpos = CurPos;  //initial tempo slider pos

m_temposlider.SetPos(CurPos);

		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	

	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);


timeKillEvent(uTimerID3);
repeatspeed++;
	if(repeatspeed == 1){
	uTimerID3 = timeSetEvent(500, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 
	}

	else if(repeatspeed > 20){
	uTimerID3 = timeSetEvent(20, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 

	}

	else if(repeatspeed > 7){
	uTimerID3 = timeSetEvent(20/*200*/, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 

	}

	else{
	uTimerID3 = timeSetEvent(300, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 
	}

tempochanged = true;

}





/*


void CExpDlg::MMTimerHandler2(UINT nIDEvent) // called every elTime milliseconds
{
// do what you want to do, but quickly

//PlaySound((LPCSTR)wavePtr, 0, SND_MEMORY | SND_NODEFAULT);

	if(  nIDEvent == uTimerID4){ // was metronome bpm timer expiring

	tapctr();

	}

}

void CALLBACK xxTimerFunction(UINT xwTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2) 
    {
    // This is used only to call MMTimerHandler
    // Typically, this function is static member of CTimersDlg
    CExpDlg* obj = (CExpDlg*) dwUser;
//    obj->CExpDlg::MMTimerHandler(xwTimerID);
    obj->MMTimerHandler2(xwTimerID);
    } 




void CExpDlg::tapctr(void)

{
tapcnt++;

	if (tapcnt >= 300 ){
	timeKillEvent(uTimerID4);
	tapgoingon = false;
	tapcnt = 0;
	}
}



*/




DWORD dwrd, basetime, tempotime;




void CExpDlg::dotap(void)

{



//cnt * 10 = ms

//1000/ms = bps

//* 60 = bpm

//double tttapcnt;
double i;
int ii;
unsigned int addint, cnt;








	if(beentotap == 0){


		for (ii = 0; ii < 10; ii++)
		intarry[ii] = 0;
	}





dwrd = timeGetTime();

	timeKillEvent(uTimerID1);
	timeKillEvent(uTimerID2);
ledoff();







	if(beentotap == 0){
	basetime = dwrd;
	beentotap = 1;
	return;
	}


//2nd time through or greater here


tempotime = dwrd - basetime;
basetime = dwrd; // set up for next comparison


//tempotime is # of ms elapsed between taps

//i = 1000 / (double)tempotime; //get taps per sec

//i = i * 60;//taps per minute

i = 60000 / (double)tempotime; //get taps per min
//ii = 60000 / tempotime; //get taps per min whole number int

//	if(i - (float)ii >= 0.5f)  //round it up or down depending on remainder
//		i++;




	if(i < 30) i = 30;
	if(i > 300) i = 300;





 CurPos = i;  //converts to int

	for(cnt=9; cnt >0; cnt--){
		intarry[cnt] = intarry[cnt-1];
	}
 intarry[0] = CurPos;

/*
intarry[9] = intarry[8];
intarry[8] = intarry[7];
intarry[7] = intarry[6];
intarry[6] = intarry[5];
intarry[5] = intarry[4];

 intarry[4] = intarry[3];
 intarry[3] = intarry[2];
 intarry[2] = intarry[1];
 intarry[1] = intarry[0];
 intarry[0] = CurPos;
*/

addint = cnt = 0;
for(ii=0;ii<7;ii++){ // can be as high as 10  -- adjusts "debounce"
	addint += intarry[ii];
	  if(intarry[ii] != 0)
	   cnt++;
	}


addint = addint / cnt;

CurPos = addint;



converttempo(CurPos); //set up display to be updated
//settempo(CurPos);
// actual tempo will change in handler for tempo timer expire
//oldtemposliderpos = CurPos;  //initial tempo slider pos

m_temposlider.SetPos(CurPos);

		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	

	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);






	led1onoff = 0;

	led2onoff = 0;


}















/*
void CExpDlg::dotap(void)

{



//cnt * 10 = ms

//1000/ms = bps

//* 60 = bpm

//double tttapcnt;
double i;




dwrd = timeGetTime();

	timeKillEvent(uTimerID1);
	timeKillEvent(uTimerID2);
ledoff();







	if(beentotap == 0){
	basetime = dwrd;
	beentotap = 1;
	return;
	}


//2nd time through or greater here


tempotime = dwrd - basetime;
basetime = dwrd; // set up for next comparison


//tempotime is # of ms elapsed between taps

//i = 1000 / (double)tempotime; //get taps per sec

//i = i * 60;//taps per minute

i = 60000 / (double)tempotime; //get taps per min
//ii = 60000 / tempotime; //get taps per min whole number int

//	if(i - (float)ii >= 0.5f)  //round it up or down depending on remainder
//		i++;




	if(i < 30) i = 30;
	if(i > 300) i = 300;





 CurPos = i;  //converts to int


converttempo(CurPos); //set up display to be updated
//settempo(CurPos);
// actual tempo will change in handler for tempo timer expire
//oldtemposliderpos = CurPos;  //initial tempo slider pos

m_temposlider.SetPos(CurPos);

		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	

	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);






	led1onoff = 0;

	led2onoff = 0;


}

*/



void CExpDlg::runbuttonw1(void)

{

int i;





globalvol++;

	if(globalvol > 10)
		globalvol = 10;



i = globalvol * 1000;

	if(globalvol == 0){
	m_slidtst.SetPos(1);
	setmetrealvolume(1);
	}
	else{
	m_slidtst.SetPos(i);
	setmetrealvolume(i);
	}





converttempo(globalvol); //set up display to be updated


		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	
	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);


timeKillEvent(uTimerID3);
	uTimerID3 = timeSetEvent(250, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 








}

void CExpDlg::runbuttonw3(void)

{

int i;





globalvol--;

	if(globalvol < 0)
		globalvol = 0;






i = globalvol * 1000;

	if(globalvol == 0){
	m_slidtst.SetPos(1);
	setmetrealvolume(1);
	}
	else{
	m_slidtst.SetPos(i);
	setmetrealvolume(i);
	}





converttempo(globalvol); //set up display to be updated


		// TODO: Add your message handler code here and/or call default
	CRect RectPicture,a,b;

	
	// Get the location and dimensions of the picture area
	m_Preview100s.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	ScreenToClient(&RectPicture);
	// Repaint the picture area
	InvalidateRect(&RectPicture,FALSE);


	m_Preview10s.GetWindowRect(&a);
	ScreenToClient(&a);
	InvalidateRect(&a,FALSE);

	m_Preview1s.GetWindowRect(&b);
	ScreenToClient(&b);
	InvalidateRect(&b,FALSE);


timeKillEvent(uTimerID3);
	uTimerID3 = timeSetEvent(250, gresolution , (LPTIMECALLBACK)xTimerFunction, (DWORD)this, TIME_ONESHOT ); 




}

BOOL CExpDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	


	return CBitmapDialog::OnSetCursor(pWnd, nHitTest, message);
}



int CExpDlg::readtime(void) //returns number of days left, or condition code
{

#define secsinday 86400

#define secsintwowks 1209600

//#define limitdays 7
#define limitdays 30



time_t  getTime;  //declare a time variable called getTime
long int currenttime;

long int installtime;
long int difftime;
long int a,b;

/*
when starting up - if neither file nor reg, write new reg and new file and start anew

if reg only, keep time left and write new file with defaults.  If reg expired, 
write expired file

if file only, write expired reg and file

*/



getTime = time(NULL);  //get seconds
currenttime = getTime;




	if(! doesregkeyexist()){  //first installation - make key
		if(mf.expired == 0){
		writeregkey(currenttime);
			if( ! doesregkeyexist()){ //could not write to registry
			MessageBox ("Cannot install. You must be logged in as administrator.","Error",MB_OK|MB_ICONERROR);
			CDialog::OnCancel();
			return(0xff);
			}

		}
		else{ //no registry but exipired in file == 1
		wfgertert();


		}

	}





installtime = readregkey();

difftime = currenttime - installtime;

	if(difftime < 0){ //current time earlier than install time
	MessageBox ("Problem With Clock Setting. Cannot Run Program.","Error",MB_OK|MB_ICONERROR);
	CDialog::OnCancel();



	return(0xff);
	}



a = difftime / secsinday; // convert dif from secs to days

b = limitdays - a;  //limit - number of days passed since install

//there are now b days left


return (b);

}




void CExpDlg::wfgertert(void)
{

	if(! akdridjrd())
	makeencfile();

readcfg();


	if(mf.expired != 1){
	mf.expired = 1;
	savecfg();
	}

	if(readregkey() != 0xffffffff)
	writeregkey(0xffffffff);

}







int CExpDlg::checktime(void)
{


	if(! metregistered){
	checkifregistered();
	}

	if(metregistered){
//		if(! inited)
//		initexp();



	return(0);
	}

	if(timechecked){
		return (0);
	}
timechecked = true;



int a = readtime();


	if(a == 0xff)
	return (-1); //was clock "problem"


	if(a <= 0){//expired just now
	mf.expired = 1;
	}
//read registry and cfg file to see if expired in the past
	if(mf.expired == 1){
	expired = true;
	wfgertert(); //write expired to both again if needed
	}

	if(readregkey() == 0xffffffff){
	expired = true;
	wfgertert(); //write expired to both again if needed
	}

//expired = true; //hwm for test
	if(expired){


int b = 0;	//attempts counter


// expired here - do not stay on top and cover website

	SetWindowPos(&wndNoTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);

nexttry:





	 expiredscr Dlg;
	 Dlg.DoModal();

//restore stay on top in case of successful registration
	if(mf.boxchecked)
	SetWindowPos(&wndTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);


	 int i = runexpiredhandler();

		 if( i == 0){ //just pressed OK
			return (-2);
		 }
		 else if(i == 1){  //successful registration

		writeregistered();






MessageBox (" Thank you for purchasing PC Metronome !   ","",MB_ICONINFORMATION);





		
		 }

		 else if(i == 2){ //unsuccesful attempted registration

MessageBox ("Registration code was incorrect ","",MB_ICONINFORMATION);

		b++;
			if(b == 10)
			return (-2);     //will end program too many wrong tries
		 goto nexttry;
	
		 }




	}
	else{// has not expired here, but allow to enter reg code

int b = 0;	//attempts counter

//do not cover website if stay on top
	SetWindowPos(&wndNoTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);
snexttry:





	splash Dlg;
	CString s1;
	s1.Format("%s%d%s","There are ", a," days left of the trial."); 
		if(a == 1)
		s1.Format("%s%d%s","There is ", a," day left of the trial."); 

	Dlg.m_content = s1;


	Dlg.DoModal();


//restore stay on top
	if(mf.boxchecked)
	SetWindowPos(&wndTopMost,NULL,NULL,NULL,NULL,SWP_NOMOVE | SWP_NOSIZE);




	int i = runexpiredhandler();

		 if( i == 0){ //just pressed OK
			return (0);
		 }
		 else if(i == 1){  //successful registration

		writeregistered();






MessageBox (" Thank you for purchasing PC Metronome !   ","",MB_ICONINFORMATION);
		
		 }

		 else if(i == 2){ //unsuccesful attempted registration

MessageBox ("Registration code was incorrect ","",MB_ICONINFORMATION);

	     b++;
		   if(b == 10)
			return (0);    //too many wrong tries.  will continue normally with program
		 goto snexttry;
	
		 }









	}




return (0);

}




int doesregkeyexist(void)

{
HKEY hk;

	if((globtsterr = RegOpenKeyEx((( HKEY ) 0x80000002 ),
		           dlakdkel("Tqix|gyme}…N‚tu"),
				   0,
				   KEY_QUERY_VALUE,
				   &hk)) != ERROR_SUCCESS){

#ifdef REGTEST
CString s1;
s1.Format("%s%d", "1 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif



	return(0);

	}
	else{
	RegCloseKey(hk);

#ifdef REGTEST
CString s1;
s1.Format("%s%d", "2 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif


	return (1);

	}


}


long int readregkey(void)

{

HKEY hk;
//TCHAR strValueLeft[50];
DWORD dwLength = 50;
long int a = 0;




globtsterr = RegOpenKeyEx((( HKEY ) 0x80000002 ),


					dlakdkel("Tqix|gyme}…N‚tu"),
				   0,
				   KEY_QUERY_VALUE,
				   &hk);



#ifdef REGTEST
CString s1;
s1.Format("%s%d", "3 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif


	// Retrieve the value of the key
	globtsterr = RegQueryValueEx(hk,
		             TEXT (dlakdkel("Tqix|gyme}…N‚tu")),
		             NULL,
		             NULL,
//		             (LPBYTE)strValueLeft,

		             (LPBYTE)&a,

		             &dwLength);

#ifdef REGTEST
s1.Format("%s%d", "4 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif


RegCloseKey(hk);

return (a);



}





void writeregkey(long int writeval)

{
HKEY hk;
//TCHAR dwData[50];
DWORD dwDisp;

long int w = writeval;
SECURITY_ATTRIBUTES sa = {sizeof(sa), 0,1};




globtsterr = RegCreateKeyEx(
				   (( HKEY ) 0x80000002 ),
		           dlakdkel("Tqix|gyme}…N‚tu"),
				   0,
				   NULL,
				   REG_OPTION_NON_VOLATILE,
				   KEY_ALL_ACCESS,
				   &sa,
				   &hk,
				   &dwDisp);




#ifdef REGTEST
CString s1;
s1.Format("%s%d", "5 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif



//sprintf(dwData, "%ld", w);

	// ... and store it in a key named...
	globtsterr = RegSetValueEx(hk,
		          dlakdkel("Tqix|gyme}…N‚tu"),
				  0,
				  REG_DWORD,
				  (PBYTE)&w,

//				  (PBYTE)&dwData,
				  sizeof(PDWORD));

#ifdef REGTEST
s1.Format("%s%d", "6 - ", globtsterr); 
MessageBox(NULL,s1,"Error",MB_OK|MB_ICONERROR);
#endif

RegCloseKey(hk);



}





int CExpDlg::runexpiredhandler(void)
//examine global "enteredcode"
//if just pressed OK, return 0
//if successful registration, return 1
//if unsuccessful registration, return 2
{
	if(enteredcode == "")
	return 0;


//remove leading and trailing and internal spaces from entered string
enteredcode.Remove(' ');



char ch[50];



	int a;
	int f = 0;
		int f2 = 0;


strcpy(ch,(char *)((LPCTSTR) (enteredcode)));

int ii, i = strlen(rtd);

	//loop to throw off debugger
  for(a = 0; a < 128283;a++){
//   if(strcmp(  _strupr((char *)(LPCTSTR) enteredcode), _strupr(dlakdkel(rtd))) == 0){//successful registration
//  if(strcmp(  _strupr(eadkdkr((char *)(LPCTSTR) enteredcode)), _strupr(rtd)) == 0){//successful registration

 
		for(ii = 0;ii < i;ii++){

		(ch[ii]+ ii +1) -   *((rtd)+ii) == 0 ? f2++ : f++;

 		}
	}

	if(f)
	return 2; // bad comp


return 1;
}




char* eadkdkr(char * str)
{

static char s[100];

strcpy(s,str);

//char s[] = "www.google.com\x0";
//char s[] = "xyz2luvouo9o|{\x0"
int i = 1;
	while(*((s + i)-1) != 0){

		*((s + i)-1) = *((s + i)-1)+i;

	 i ++;
	}


return s;

}

char* dlakdkel(char * st)
{

static char s[100];
int i = 1;
strcpy(s,st);
	while(*((s + i)-1) != 0){
	
	*((s + i)-1) = *((s + i)-1)-i;

	i ++;
	}

return s;
}



void CExpDlg::checkifregistered(void)

{
metregistered = false;

	if(readregkey() != atol(dlakdkel(rtd)))
		return;

mf.expired = 0;

readcfg();

	if(mf.expired == 1)
		return;

	if(akdridjrd()) //dll file erased at legit registration
		return;



timechecked = true;
metregistered = true;


}


void CExpDlg::writeregistered(void)
//to both reg and config file
{


writeregkey(atol(dlakdkel(rtd)));


readcfg();
mf.expired = 0;
savecfg();

//delete dll file
remove(dlakdkel("d<_{ntkw€}g†ƒu~n€‡xŒ„‡‡LI€‰Š"));



}


void CExpDlg::OnHelp()

{
//char * sss = "C:\\met_dev\\7\\met1.chm";


//HtmlHelp(NULL, sss, HH_HELP_CONTEXT, 101 );  //, IDH_MET1
}




void CExpDlg::WinHelp(DWORD dwData, UINT nCmd) 
{
	// TODO: Add your specialized code here and/or call the base class


runhelp();

//	CBitmapDialog::WinHelp(dwData, nCmd);
}









void CExpDlg::runhelp(void)
{

/*
	char szPath[1024];
	GetModuleFileName(AfxGetApp()->m_hInstance, szPath, sizeof(szPath));
	
	char *ptr = strrchr(szPath, '\\');
	
	if (ptr)
	{
		ptr[1] = '\0';
	}
	
//	ASSERT(strlen(szPath) < sizeof(szPath));
	
//	return szPath;

HtmlHelp(NULL, strcat(szPath,"met1.chm"), HH_HELP_CONTEXT, 101 );  //, IDH_MET1


*/




  CString Path(*__argv);
  int i=Path.ReverseFind('\\')+1;
  if(i) Path=Path.Left(i);
//HtmlHelp(NULL, LPCTSTR(Path + "met1.chm"), HH_HELP_CONTEXT, 101 );  //, IDH_MET1
//HtmlHelp(m_hWnd , Path + "met1.chm", HH_HELP_CONTEXT, 101 );  //, IDH_MET1


  ::ShellExecute(NULL, NULL, Path + "met1.chm", NULL, NULL, SW_SHOWNORMAL);

}





void CExpDlg::playa440(void)

{


Playtuner();


}







void CExpDlg::a440off(void)
{



Stoptuner();






}

BOOL CExpDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	

	if(pMsg ->message == WM_APP){ //tuner button


		if(a440on == 0)
		a440on = 1;
		else
		a440on = 0;

		if(a440on){


		playa440();
		}
		else{
		a440off();
		}

	}


	if(pMsg ->message == WM_APP+3){  //mute button

	a440off();
	}




	return CBitmapDialog::PreTranslateMessage(pMsg);
}
