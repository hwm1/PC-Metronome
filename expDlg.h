// expDlg.h : header file
//

#if !defined(AFX_EXPDLG_H__08E2DA07_7D07_11DC_A85F_0000E85FCBDE__INCLUDED_)
#define AFX_EXPDLG_H__08E2DA07_7D07_11DC_A85F_0000E85FCBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "BitmapDialog.h"

#include "dxsound.h"


#pragma message("linking with Microsoft's DirectSound library ...")
#pragma comment(lib, "Dxguid.lib")



#pragma message("linking with Microsoft's Multimedia library ...")
#pragma comment(lib, "winmm.lib")

#pragma message("linking with Microsoft's DirectSound library ...")
#pragma comment(lib, "DSOUND.LIB")

/////////////////////////////////////////////////////////////////////////////
// CBmpDlgDlg dialog

class CExpDlg : public CBitmapDialog
{
// Construction
public:
	CExpDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CExpDlg)
	enum { IDD = IDD_EXP_DIALOG };
	CStatic	m_Led2;
	CStatic	m_Led;
	CStatic	m_y3on;
	CStatic	m_y2on;
	CStatic	m_y1on;
	CStatic	m_w4on;
	CStatic	m_w3on;
	CStatic	m_w2on;
	CStatic	m_w1on;
	CStatic	m_Preview100s;
	CStatic	m_Preview10s;
	CStatic	m_Preview1s;
	CSliderCtrl	m_temposlider;
	CSliderCtrl	m_slidtst;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExpDlg)
	public:
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
void CExpDlg::clearbuttons(void);

void MapDialogRect(CRect &r, BOOL bPixelToDLU);


void MMTimerHandler(UINT nIDEvent);

void MMTimerHandler2(UINT nIDEvent);
void MMTimerHandler5(UINT nIDEvent);
void MMTimerHandler6(UINT nIDEvent);

//void CALLBACK xTimerFunction(UINT xwTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2) ;
void CExpDlg::startledtimer(void);
void CExpDlg::dotap(void);

void CExpDlg::runbuttonw1(void);

void CExpDlg::runbuttonw2(void);
void CExpDlg::runbuttonw3(void);
void CExpDlg::runbuttonw4(void);
int  CExpDlg::readcfg(void);
void CExpDlg::savecfg(void);
void led1on(void);
void led2on(void);
void ledon(void);
int  CExpDlg::checktime(void);
void CExpDlg::initexp(void);

void ledoff(void);
void settempo(int bpm);
void CExpDlg::tapctr(void);
void CExpDlg::backtotempodisptimer(void);

void CExpDlg::sethandcursor(void);
void CExpDlg::setarrowcursor(void);

void runbeatsubdivs(void);

int CExpDlg::readtime(void);  //returns result

void CExpDlg::wfgertert(void); //writeexpired()
//void CExpDlg::setmetrealvolume(int x);

void CExpDlg::checkifregistered(void);
void CExpDlg::writeregistered(void);


int CExpDlg::runexpiredhandler(void);

void CExpDlg::OnHelp(void);
void CExpDlg::runhelp(void);



void playa440(void);

void a440off(void);






protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnCancel();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg UINT OnNcHitTest(CPoint point);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	bool m_mousedown;



private:
	int buttontimerflg;

DWORD repeatspeed;

#define arrow 1
#define hand 2

int curtype;

/*
CDirectSound m_WoodblockSound;

CDirectSound m_ElectronicSound;

CDirectSound m_Tunersound;
*/

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPDLG_H__08E2DA07_7D07_11DC_A85F_0000E85FCBDE__INCLUDED_)






