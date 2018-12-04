// beatsubdivs.cpp : implementation file
//

#include "stdafx.h"
#include "exp.h"
#include "beatsubdivs.h"
#include "resource.h"
#include "Mmsystem.h"

#include "expdlg.h"

#include "dxsound.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int a440on = 0;
int muteon  = 0;

extern int subd, metbeat;


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


extern metrofile mf;

/////////////////////////////////////////////////////////////////////////////
// beatsubdivs dialog


beatsubdivs::beatsubdivs(CWnd* pParent /*=NULL*/)
	: CDialog(beatsubdivs::IDD, pParent)
{
	//{{AFX_DATA_INIT(beatsubdivs)
	m_radios = -1;
	//}}AFX_DATA_INIT


switch(subd)
	{
	case 1:
	m_radios = 0;
		break;
	case 2:
	m_radios = 1;
		break;
	case 3:
	
	m_radios = 2;
		break;


	case 4:
	
	m_radios = 3;
		break;

	case 6:
	
	m_radios = 4;
		break;
}

}


void beatsubdivs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(beatsubdivs)
	DDX_Control(pDX, IDC_COMBO1, m_combo1var);
	DDX_Radio(pDX, IDC_RADIO1, m_radios);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(beatsubdivs, CDialog)
	//{{AFX_MSG_MAP(beatsubdivs)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_EDITUPDATE(IDC_COMBO1, OnEditupdateCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, OnKillfocusCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_a440, Ona440)
	ON_BN_CLICKED(IDC_mute, Onmute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// beatsubdivs message handlers






void beatsubdivs::OnRadio1() 
{
	// TODO: Add your control notification handler code here
beatradio();
}

void beatsubdivs::OnRadio2() 
{
	// TODO: Add your control notification handler code here

beatradio();
}

void beatsubdivs::OnRadio3() 
{
	// TODO: Add your control notification handler code here
beatradio();
}

void beatsubdivs::OnRadio4() 
{
	// TODO: Add your control notification handler code here
beatradio();
}

void beatsubdivs::OnRadio6() 
{
	// TODO: Add your control notification handler code here
beatradio();
}



void beatsubdivs::beatradio()
{


	UpdateData();


	metbeat = 1;

switch(m_radios)
	{
	case 0:
		subd = 1;
		break;
	case 1:
		subd = 2;
		break;
	case 2:
	
		subd = 3;
		break;


	case 3:
	
		subd = 4;
		break;

	case 4:
	
		subd = 6;
		break;

}


}

BOOL beatsubdivs::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

a440on = 0;
muteon = 0;









m_combo1var.AddString("Electronic");
m_combo1var.AddString("Woodblock");




m_combo1var.SetCurSel(mf.metsoundnumber);

	if(mf.boxchecked)
	CheckDlgButton(IDC_CHECK1, BST_CHECKED);
	else
	CheckDlgButton(IDC_CHECK1, BST_UNCHECKED);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void beatsubdivs::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void beatsubdivs::OnEditupdateCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void beatsubdivs::OnKillfocusCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void beatsubdivs::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here


CString cs;

m_combo1var.GetLBText(m_combo1var.GetCurSel(),cs);

cs.MakeUpper();

	if(cs == "ELECTRONIC")
		mf.metsoundnumber = 0;

	if(cs == "WOODBLOCK")
		mf.metsoundnumber = 1;

UpdateData(TRUE);



	
}

void beatsubdivs::OnOK() 
{
	// TODO: Add extra validation here

//if stay on top box is checked

	if(IsDlgButtonChecked(IDC_CHECK1)){
	mf.boxchecked = 1;

	}
	else{
	mf.boxchecked = 0;

	}


a440on = 0;	//in case clicked ok without turning tuning sound off - so will make met sound

	CWnd * pMainFrame = ::AfxGetMainWnd();
pMainFrame -> PostMessage(WM_APP+3,NULL,NULL);


muteon = 0;  //in case clicked ok with muted




CDialog::OnOK();
}








void beatsubdivs::Ona440() 
{
	// TODO: Add your control notification handler code here

CString c;

// communicate with base window - base win will use pre translate message function to see it
	CWnd * pMainFrame = ::AfxGetMainWnd();
pMainFrame -> PostMessage(WM_APP,NULL,NULL);

muteon = 0;


	c = TEXT("Mute");

	GetDlgItem(IDC_mute)->SetWindowText(c);
}






void beatsubdivs::Onmute() 
{

CString c;


	// TODO: Add your control notification handler code here
	if(muteon == 0){
		muteon = 1;

	c = TEXT("unMute");

	}
	else{
		muteon = 0;
	c = TEXT("Mute");


	}

GetDlgItem(IDC_mute)->SetWindowText(c);


	if(muteon){
		if(a440on){
		a440on = 0;
	CWnd * pMainFrame = ::AfxGetMainWnd();
pMainFrame -> PostMessage(WM_APP+3,NULL,NULL);
		}
	}


}
