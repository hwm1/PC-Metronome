/******************************************************************************
FILE: DXSound.h
******************************************************************************/

#include "Demo.h"


BOOL InitDirectSound( void ) ;
void DSActive( void ) ;
void DSInactive( void ) ;
BOOL SetListenerPos( DemoListener *, BOOL ) ;
//BOOL SetDopplarPos( DemoDopplar *pDD, BOOL bDeferred ) ;


BOOL SetelectronicrPos( Demoelectronic *pDD, BOOL bDeferred ) ;
BOOL SetwoodblockPos( Demowoodblock *pDD, BOOL bDeferred ) ;

//void PlayDopplar( void ) ;


void Playelectronic( void ) ;
void Playwoodblock( void ) ;
void Playtuner( void ) ;
void Stoptuner( void ) ;
void Playsilence( void ) ;



BOOL SetConePos( DemoCone *pDLS, BOOL bDeferred ) ;
void PlayCone( void ) ;
void PlayOuch( int nX, int nY, BOOL ) ;
void PlayDance( int nX, int nY, BOOL ) ;
void StopDance( void ) ;
void CommitChanges(void) ;
void UnInitDirectSound( void ) ;