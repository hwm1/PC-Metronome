; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CExpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "exp.h"

ClassCount=6
Class1=CExpApp
Class2=CExpDlg

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_EXP_DIALOG
Class3=splash
Class4=ttt
Resource3=IDD_DIALOG1
Class5=beatsubdivs
Resource4=IDD_DIALOG2
Class6=expiredscr
Resource5=IDD_DIALOG3
Resource6=IDR_SUBMIT

[CLS:CExpApp]
Type=0
HeaderFile=exp.h
ImplementationFile=exp.cpp
Filter=N
LastObject=CExpApp

[CLS:CExpDlg]
Type=0
HeaderFile=expDlg.h
ImplementationFile=expDlg.cpp
Filter=D
LastObject=CExpDlg
BaseClass=CBitmapDialog
VirtualFilter=dWC



[DLG:IDD_EXP_DIALOG]
Type=1
Class=CExpDlg
ControlCount=15
Control1=IDC_SLIDER2,msctls_trackbar32,1073807384
Control2=IDC_PREVIEW100s,static,1342177294
Control3=IDC_SLIDER1,msctls_trackbar32,1073807384
Control4=IDC_PREVIEW10s,static,1342177294
Control5=IDC_PREVIEW1s,static,1342177294
Control6=IDC_BUTTON1,button,1073807360
Control7=IDC_w4on,static,1342177294
Control8=IDC_w3on,static,1342177294
Control9=IDC_w1on,static,1342177294
Control10=IDC_w2on,static,1342177294
Control11=IDC_y2on,static,1342177294
Control12=IDC_y1on,static,1342177294
Control13=IDC_y3on,static,1342177294
Control14=IDC_LED,static,1342177294
Control15=IDC_LED2,static,1342177294

[DLG:IDD_DIALOG1]
Type=1
Class=splash
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1342179329
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,static,1342308353
Control6=IDC_website,static,1342177281
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_STATIC,static,1342308352

[CLS:splash]
Type=0
HeaderFile=splash.h
ImplementationFile=splash.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_website

[CLS:ttt]
Type=0
HeaderFile=ttt.h
ImplementationFile=ttt.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK

[DLG:IDD_DIALOG2]
Type=1
Class=beatsubdivs
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_RADIO1,button,1342308361
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_RADIO4,button,1342177289
Control7=IDC_RADIO6,button,1342177289
Control8=IDC_COMBO1,combobox,1344339971
Control9=IDC_a440,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CHECK1,button,1342242819
Control14=IDC_mute,button,1342242816

[CLS:beatsubdivs]
Type=0
HeaderFile=beatsubdivs.h
ImplementationFile=beatsubdivs.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_a440
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=expiredscr
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_expiredwebsite,static,1342373888
Control6=IDC_entercode,edit,1350631552
Control7=IDC_STATIC,static,1342177280

[CLS:expiredscr]
Type=0
HeaderFile=expiredscr.h
ImplementationFile=expiredscr.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_expiredwebsite
VirtualFilter=dWC

[MNU:IDR_SUBMIT]
Type=1
Class=?
Command1=ID_POPUPSUBMIT_RED
CommandCount=1

