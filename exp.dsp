# Microsoft Developer Studio Project File - Name="exp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=exp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "exp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "exp.mak" CFG="exp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "exp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "exp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "exp - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "exp - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "exp - Win32 Release"
# Name "exp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\beatsubdivs.cpp
# End Source File
# Begin Source File

SOURCE=.\BitmapDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\DXSound.cpp
# End Source File
# Begin Source File

SOURCE=.\exp.cpp
# End Source File
# Begin Source File

SOURCE=.\expDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\expiredscr.cpp
# End Source File
# Begin Source File

SOURCE=.\hyperlink.cpp
# End Source File
# Begin Source File

SOURCE=.\splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\beatsubdivs.h
# End Source File
# Begin Source File

SOURCE=.\BitmapDialog.h
# End Source File
# Begin Source File

SOURCE=.\Demo.h
# End Source File
# Begin Source File

SOURCE="..\Program Files\Microsoft Visual Studio\VC98\Include\DSOUND.H"
# End Source File
# Begin Source File

SOURCE=.\DXSound.h
# End Source File
# Begin Source File

SOURCE=.\exp.h
# End Source File
# Begin Source File

SOURCE=.\expDlg.h
# End Source File
# Begin Source File

SOURCE=.\expiredscr.h
# End Source File
# Begin Source File

SOURCE=.\Htmlhelp.h
# End Source File
# Begin Source File

SOURCE=.\hyperlink.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\0 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\1 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\2 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\3 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\4 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\5 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\6 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\7 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\8 copy.bmp"
# End Source File
# Begin Source File

SOURCE=".\9 copy.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\bitmap12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap17.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap23.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap28.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap31.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap32.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap43.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap44.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap45.bmp
# End Source File
# Begin Source File

SOURCE=".\blank copy.bmp"
# End Source File
# Begin Source File


SOURCE=.\res\exp.ico
# End Source File
# Begin Source File

SOURCE=.\exp.rc
# End Source File
# Begin Source File

SOURCE=.\res\exp.rc2
# End Source File
# Begin Source File

SOURCE=.\Image.bmp
# End Source File
# Begin Source File



SOURCE=.\ledoff.bmp
# End Source File
# Begin Source File



SOURCE=.\ledon.bmp
# End Source File
# Begin Source File



SOURCE=.\w1on.bmp
# End Source File
# Begin Source File

SOURCE=.\w2on.bmp
# End Source File
# Begin Source File

SOURCE=.\w3on.bmp
# End Source File
# Begin Source File

SOURCE=.\w4on.bmp
# End Source File
# Begin Source File



SOURCE=.\y1on.bmp
# End Source File
# Begin Source File

SOURCE=.\y2on.bmp
# End Source File
# Begin Source File



SOURCE=.\y3on.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\alooped.wav
# End Source File
# Begin Source File

SOURCE=.\res\electronic.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\res\silence.wav
# End Source File
# Begin Source File

SOURCE=.\res\woodblock.wav
# End Source File
# Begin Source File

SOURCE="..\..\..\Program Files\Microsoft Visual Studio\Vc98\Lib\Winmm.lib"

!IF  "$(CFG)" == "exp - Win32 Release"

!ELSEIF  "$(CFG)" == "exp - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="c:\Program Files\Microsoft Visual Studio\VC98\Lib\DSOUND.LIB"
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE="..\..\Program Files\Microsoft Visual Studio\VC98\Lib\Dxguid.lib"
# PROP Exclude_From_Build 1
# End Source File
# End Target
# End Project
