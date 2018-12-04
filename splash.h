#if !defined(AFX_SPLASH_H__8E38D861_8BAF_11DC_A860_0000E85FCBDE__INCLUDED_)
#define AFX_SPLASH_H__8E38D861_8BAF_11DC_A860_0000E85FCBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// splash.h : header file
//

#include "hyperlink.h"


#define URLMAXLENGTH 256


//////////////







/////////////////////////////////////////////////////////////////////////////
// splash dialog

class splash : public CDialog
{
// Construction
public:
	splash(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(splash)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_ed2ctrl;
	CEdit	m_edctrl;
	CString	m_content;
	CString	m_splashregstr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(splash)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

BOOL splash::PreTranslateMessage(MSG* pMsg) ;
void setURL(CHyperLink &ctr, int id);


CDemoLink	m_DemoLink;

protected:

	// Generated message map functions
	//{{AFX_MSG(splash)
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnBnClickedSubmitBtn();
	afx_msg void OnPopupsubmitRed();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSetfocusEdit1();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};








//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLASH_H__8E38D861_8BAF_11DC_A860_0000E85FCBDE__INCLUDED_)







