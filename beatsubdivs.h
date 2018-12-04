#if !defined(AFX_BEATSUBDIVS_H__C84DFBA5_8F03_11DC_A862_0000E85FCBDE__INCLUDED_)
#define AFX_BEATSUBDIVS_H__C84DFBA5_8F03_11DC_A862_0000E85FCBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// beatsubdivs.h : header file
//




#include "dxsound.h"











/////////////////////////////////////////////////////////////////////////////
// beatsubdivs dialog

class beatsubdivs : public CDialog
{
// Construction
public:
	beatsubdivs(CWnd* pParent = NULL);   // standard constructor




// Dialog Data
	//{{AFX_DATA(beatsubdivs)
	enum { IDD = IDD_DIALOG2 };
	CComboBox	m_combo1var;
	int		m_radios;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(beatsubdivs)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(beatsubdivs)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio6();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnEditupdateCombo1();
	afx_msg void OnKillfocusCombo1();
	afx_msg void OnSelchangeCombo1();
	virtual void OnOK();
	afx_msg void Ona440();
	afx_msg void Onmute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void beatradio(void);












};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEATSUBDIVS_H__C84DFBA5_8F03_11DC_A862_0000E85FCBDE__INCLUDED_)
