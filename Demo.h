/******************************************************************************
FILE: Demo.h
This header file defines the DemoPeron structure, the max number of persons
(for a future networked version).
******************************************************************************/
#ifndef _DEMO_H_
#define _DEMO_H_


#define MAXPERSON 4
#define DOPPLARBEGIN -2000
#define DOPPLAREND 5000

typedef struct 
{
    float x,y;
} FPOINT, *LPFPOINT ;

// State data for a listener
struct DemoListener
{
   float m_fnFaceX ;
   float m_fnFaceY ;   
   
   int m_nAngle ;

   int m_nXPos ;
   int m_nYPos ;

   BOOL m_bChanged ;
   BOOL m_bRotating ;
} ;


/*
// State data for dopplar object
struct DemoDopplar
{
   int m_nXPos ;
   int m_nYPos ; 
} ;
*/



// State data for dopplar object
struct Demoelectronic
{
   int m_nXPos ;
   int m_nYPos ; 
} ;



// State data for dopplar object
struct Demowoodblock
{
   int m_nXPos ;
   int m_nYPos ; 
} ;

// State data for dopplar object
struct Demotuner
{
   int m_nXPos ;
   int m_nYPos ; 
} ;



// State data for a demo person
struct DemoPerson
{
    int    m_nX ; // Horizontal coordinate
    int    m_nY ; // Verticle coordinate
    int    m_nVX ; // Horizontal velocity
    int    m_nVY ; // Verticle velocity
    BOOL   m_bAction ; // State information for the trigger
    BOOL   m_bActionHistory ; // History state information for the trigger
} ;

struct DemoCone
{
   float m_fnFaceX ;
   float m_fnFaceY ;   
   
   int m_nAngle ;

   int m_nXPos ;
   int m_nYPos ;   
} ;

extern DemoPerson * g_arrayPeople[MAXPERSON] ;

extern DemoListener g_stateListener ;
//extern DemoDopplar g_stateDopplar ;

extern Demoelectronic g_stateelectronic ;
extern Demowoodblock g_statewoodblock ;



void DrawPerson( HDC hdc, DemoPerson * ) ;

BOOL InitDemo( void ) ;

void UnInitDemo( void ) ;


#endif
