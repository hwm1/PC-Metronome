#if !defined(AFX_EXPIREDSCR_H__9D9DC522_909D_11DC_A862_0000E85FCBDE__INCLUDED_)
#define AFX_EXPIREDSCR_H__9D9DC522_909D_11DC_A862_0000E85FCBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// expiredscr.h : header file
//


#include "hyperlink.h"


#define URLMAXLENGTH 256





/////////////////////////////////////////////////////////////////////////////
// expiredscr dialog

class expiredscr : public CDialog
{
// Construction
public:
	expiredscr(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(expiredscr)
	enum { IDD = IDD_DIALOG3 };
	CEdit	m_enteredcode;
	CString	m_strenteredcode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(expiredscr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

BOOL expiredscr::PreTranslateMessage(MSG* pMsg) ;
void setURL(CHyperLink &ctr, int id);



CDemoLink	m_DemoLink;






protected:

	// Generated message map functions
	//{{AFX_MSG(expiredscr)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnCancelMode();
	virtual void OnOK();
	afx_msg void OnPopupsubmitRed();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnBnClickedSubmitBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPIREDSCR_H__9D9DC522_909D_11DC_A862_0000E85FCBDE__INCLUDED_)
