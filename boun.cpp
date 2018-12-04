//Main.cpp
#include "stdafx.h"


//#include "BitmapDialog.h"

#include "resource.h"


#include "expDlg.h"

#include "Thread.h"

class CBounce : public CThread {
//  HANDLE hStdOut;
//  CONSOLE_SCREEN_BUFFER_INFO csbi;
//  char BlockCell;
public:
/*  CBounce(char c) : BlockCell(c) {
    hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    Start();
  }
  inline int GetRandom(int min, int max) {return (rand() % (max+1-min))+min;}
*/
  void Main() {
CExpDlg c;

	CRect RectPicture;
		// Get the location and dimensions of the picture area
	c.m_Led2.GetWindowRect(&RectPicture);
	// Convert the current coordinates from the monitor (Screen) to the dialog box (Client)
	c.ScreenToClient(&RectPicture);
	// Repaint the picture area
	c.InvalidateRect(&RectPicture,FALSE);





  
  } 
};


