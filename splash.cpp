// splash.cpp : implementation file
//

#include "stdafx.h"


#include "hyperlink.h"
#include "exp.h"
#include "splash.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/*
 * Defines
 */
#define URLMAXLENGTH 256

/*
 * Forward declaration
 */
class CHyperLink;



extern CString enteredcode;


int mpntx, mpnty;







/////////////////////////////////////////////////////////////////////////////
// splash dialog


splash::splash(CWnd* pParent /*=NULL*/)
	: CDialog(splash::IDD, pParent)
{
	//{{AFX_DATA_INIT(splash)
	m_content = _T("");
	m_splashregstr = _T("");
	//}}AFX_DATA_INIT
}


void splash::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(splash)
	DDX_Control(pDX, IDC_EDIT2, m_ed2ctrl);
	DDX_Control(pDX, IDC_EDIT1, m_edctrl);
	DDX_Text(pDX, IDC_EDIT1, m_content);
	DDV_MaxChars(pDX, m_content, 256);
	DDX_Text(pDX, IDC_EDIT2, m_splashregstr);
	DDV_MaxChars(pDX, m_splashregstr, 256);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(splash, CDialog)
	//{{AFX_MSG_MAP(splash)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_website, OnBnClickedSubmitBtn)
	ON_COMMAND(ID_POPUPSUBMIT_RED, OnPopupsubmitRed)
	ON_WM_SETCURSOR()
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	ON_WM_CONTEXTMENU()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// splash message handlers

void splash::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

















void splash::OnButton1() 
{
	// TODO: Add your control notification handler code here
//	ShellExecute ="http://www.google.com";

//ShellExecute(NULL, "open", "http://www.google.com", NULL, NULL, SW_SHOW);

//RunApp_NoFreeze("http://www.google.com");


//char Website[MAX_PATH]="http:\\www.google.com";
//ShellExecute(NULL, "open", Website, NULL, NULL, SW_SHOW);
}




void splash::setURL(CHyperLink &ctr, int id)
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









BOOL splash::OnInitDialog() 
{
	CDialog::OnInitDialog();
   setURL(m_DemoLink,IDC_website);








//CEdit m_edctrl;
//m_edctrl.SubclassDlgItem(IDC_EDIT1, this);







 //  setURL(m_DemoMail,IDC_EMAIL);


	
	// TODO: Add extra initialization here




	m_splashregstr = "";
	UpdateData(FALSE);  //initializing











	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}











void splash::OnBnClickedSubmitBtn() // right button filtered by here, if left button, pass it on
{
	// TODO: Add your control notification handler code here

    PostMessage(BN_CLICKED);

}





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



void splash::OnPopupsubmitRed() 
{
	// TODO: Add your command handler code here

SetClipboardText("http://www.metronomeprogram.com");
}


 





//keeps cursor as arrow when over textbox
BOOL splash::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	


	// Change cursor when over edit
	if( pWnd== GetDlgItem( IDC_EDIT1 ) )
	{
		::SetCursor( ::LoadCursor(NULL, IDC_ARROW) );

//m_edctrl.SetSel(0xffffffff);
//	DestroyCaret();




		return(1);
	}


	return CDialog::OnSetCursor(pWnd, nHitTest, message);


}





void splash::OnSetfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	
SendMessage(WM_NEXTDLGCTL);


}



//eliminates context men on textbox
BOOL splash::PreTranslateMessage(MSG* pMsg) 
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

/*
BOOL splash::PreTranslateMessage(MSG* pMsg) 
{ 

    if ((pMsg->message == WM_RBUTTONDOWN)||
	
	(pMsg->message == WM_LBUTTONDOWN)||
	(pMsg->message == WM_RBUTTONUP)||
	(pMsg->message == WM_LBUTTONUP)){


	PostMessage(WM_LBUTTONDOWN);
	return true;
	}

//return CDialog::PreTranslateMessage(pMsg); 

return false;



} 

*/

void splash::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData(TRUE);
	enteredcode = m_splashregstr;
	
	CDialog::OnOK();
}



void splash::OnContextMenu(CWnd* /*pWnd*/ , CPoint point) 
{



	// TODO: Add your message handler code here
	// Load the desired menu
	CMenu mnuPopupSubmit;
	mnuPopupSubmit.LoadMenu(IDR_SUBMIT);

	// Get a pointer to the button
	CButton *pButton;
	pButton = reinterpret_cast<CButton *>(GetDlgItem(IDC_website));

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


void splash::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	



mpntx = point.x;
mpnty = point.y;

LONG lBase = GetDialogBaseUnits();
int xBaseUnits = LOWORD(lBase);
int yBaseUnits = HIWORD(lBase);


mpntx = ( mpntx * 4 ) / xBaseUnits ;
mpnty = ( mpnty * 8 ) / yBaseUnits;




	CDialog::OnMouseMove(nFlags, point);
}
