// expiredscr.cpp : implementation file
//

#include "stdafx.h"
#include "exp.h"
#include "expiredscr.h"
#include "splash.h"
//#include "expDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



extern CString enteredcode;
extern char * dlakdkel(char *);
extern BOOL SetClipboardText(LPCTSTR pszText);

/*
 * Defines
 */
#define URLMAXLENGTH 256
/*
 * Forward declaration
 */
class CHyperLink;


/////////////////////////////////////////////////////////////////////////////
// expiredscr dialog


expiredscr::expiredscr(CWnd* pParent /*=NULL*/)
	: CDialog(expiredscr::IDD, pParent)
{
	//{{AFX_DATA_INIT(expiredscr)
	m_strenteredcode = _T("");
	//}}AFX_DATA_INIT
}


void expiredscr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(expiredscr)
	DDX_Control(pDX, IDC_entercode, m_enteredcode);
	DDX_Text(pDX, IDC_entercode, m_strenteredcode);
	DDV_MaxChars(pDX, m_strenteredcode, 256);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(expiredscr, CDialog)
	//{{AFX_MSG_MAP(expiredscr)
	ON_WM_CLOSE()
	ON_WM_CANCELMODE()
	ON_COMMAND(ID_POPUPSUBMIT_RED, OnPopupsubmitRed)
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_expiredwebsite, OnBnClickedSubmitBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// expiredscr message handlers

BOOL expiredscr::OnInitDialog() 
{
	CDialog::OnInitDialog();
  setURL(m_DemoLink,IDC_expiredwebsite);	





	// TODO: Add extra initialization here


	m_strenteredcode = "";
	UpdateData(FALSE);  //initializing



	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}






void expiredscr::setURL(CHyperLink &ctr, int id)
{
   TCHAR buffer[URLMAXLENGTH];
   int nLen = ::LoadString(AfxGetResourceHandle(),
                           id, buffer, URLMAXLENGTH);
   if( !nLen )
   {
     lstrcpy( buffer, __TEXT(""));
   }
    ctr.ConvertStaticToHyperlink(GetSafeHwnd(),id,buffer);
}


/*
BOOL SetClipboardText(LPCTSTR pszText)
{
   BOOL ok = FALSE;
   if(OpenClipboard(NULL)) {
      // the text should be placed in "global" memory
      HGLOBAL hMem = GlobalAlloc(GMEM_SHARE | GMEM_MOVEABLE, 
         (lstrlen(pszText)+1)*sizeof(pszText[0]) );
      LPTSTR ptxt = (LPTSTR)GlobalLock(hMem);
      lstrcpy(ptxt, pszText);
      GlobalUnlock(hMem);
      // set data in clipboard; we are no longer responsible for hMem
      ok = (BOOL)SetClipboardData(CF_TEXT, hMem);

      CloseClipboard(); // relinquish it for other windows
   }
   return ok;
}

*/




//eliminates context men on textbox
BOOL expiredscr::PreTranslateMessage(MSG* pMsg) 
{ 


return false;


   if (pMsg->message == WM_RBUTTONDOWN){

	PostMessage(WM_RBUTTONUP);
	return true;
	}

//return CDialog::PreTranslateMessage(pMsg); 

return false;

//tpl.GetDlgRect(pRect);


} 









void expiredscr::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

void expiredscr::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void expiredscr::OnOK() 
{
	// TODO: Add extra validation here


	UpdateData(TRUE);
	enteredcode = m_strenteredcode;
	
	CDialog::OnOK();
}


void expiredscr::OnPopupsubmitRed() 
{
	// TODO: Add your command handler code here
SetClipboardText("http://www.metronomeprogram.com");	
}









void expiredscr::OnContextMenu(CWnd* /*pWnd*/ , CPoint point) 
{



	// TODO: Add your message handler code here
	// Load the desired menu
	CMenu mnuPopupSubmit;
	mnuPopupSubmit.LoadMenu(IDR_SUBMIT);

	// Get a pointer to the button
	CButton *pButton;
	pButton = reinterpret_cast<CButton *>(GetDlgItem(IDC_expiredwebsite));

	// Find the rectangle around the button
	CRect rectSubmitButton;
	pButton->GetWindowRect(&rectSubmitButton);

	// Get a pointer to the first item of the menu
	CMenu *mnuPopupMenu = mnuPopupSubmit.GetSubMenu(0);
	ASSERT(mnuPopupMenu);
	
	// Find out if the user right-clicked the button
	// because we are interested only in the button
	if( rectSubmitButton.PtInRect(point) ) // Since the user right-clicked the button, display the context menu
		mnuPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);



}



void expiredscr::OnBnClickedSubmitBtn() 
{
	// TODO: Add your control notification handler code here
	   PostMessage(BN_CLICKED);	
}
