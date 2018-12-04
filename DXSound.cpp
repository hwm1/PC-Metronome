/******************************************************************************
FILE: DXSound.cpp
This module contains all of the DirectSound specific code.  This includes
initialization and uninitializatoin functions as well as functions to create
and play sound buffers.

GLOBALS:
g_lpDSound -- A pointer to the IDirectSound interface
g_lpDSBufferPrimary -- A pointer to the IDirectSoundBuffer interface
                       used for the primary sound buffer
g_lpDS3dListener -- A pointer to the IDirectSound3DListener interface
g_lpDSBufferOuch[NUMOUCHES] -- Array of pointers to IDirectSoundBuffer 
                               interface for the "ouch" sound
g_lpDS3DBufferOuch[NUMOUCHES] -- Array of pointers to the IDirectSound3DBuffer
                                 interface for the "ouch" sound
g_lpDSBufferelectronic -- A pointer to the IDirectSoundBuffer for the doppler 
                       sound
g_lpDS3DBufferelectronic -- A pointer to the IDirectSound3DBuffer for the doppler
                         sound
g_lpDSBufferDance -- A pointer to the IDirectSoundBuffer for the "Dance" sound
g_lpDS3DBufferDance -- A pointer to the IDirectSound3DBuffer for the "Dance"
                       sound
g_lpDSBufferCone -- A pointer to the IDirectSoundBuffer for the "Cone" sound
g_lpDS3DBufferCone -- A pointer to the IDirectSound3DBuffer for the "Cone"
                      sound

g_bDSActive -- Is this application currently active
******************************************************************************/
#include "stdafx.h"
//#include "afxwin.h"





#include <Windowsx.h>

#include <mmsystem.h>

#include "Dsound.H"

#include <mmreg.h>
#include "DXSound.h"

//#include "main.h"
#include "resource.h"


#include "math.h"




#define NUMOUCHES 4

LPDIRECTSOUND           g_lpDSound = NULL ;
LPDIRECTSOUNDBUFFER     g_lpDSBufferPrimary = NULL ;
LPDIRECTSOUND3DLISTENER g_lpDS3dListener = NULL ;
LPDIRECTSOUNDBUFFER     g_lpDSBufferOuch[NUMOUCHES] = {NULL} ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferOuch[NUMOUCHES] = {NULL} ;



LPDIRECTSOUNDBUFFER     g_lpDSBufferelectronic = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferelectronic = NULL ;

LPDIRECTSOUNDBUFFER     g_lpDSBuffertuner = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBuffertuner = NULL ;

LPDIRECTSOUNDBUFFER     g_lpDSBufferwoodblock = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferwoodblock = NULL ;


LPDIRECTSOUNDBUFFER     g_lpDSBuffersilence = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBuffersilence = NULL ;



LPDIRECTSOUNDBUFFER     g_lpDSBufferDance = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferDance = NULL ;
LPDIRECTSOUNDBUFFER     g_lpDSBufferCone = NULL ;
LPDIRECTSOUND3DBUFFER   g_lpDS3DBufferCone = NULL ;

BOOL g_bDSActive = TRUE ;

BOOL InitListener( void ) ;
BOOL InitOuchBuffer( void ) ;
LPDIRECTSOUNDBUFFER WavToStaticBuffer( LPBYTE lpBuffer, DWORD dwSize, 
                                       LPDIRECTSOUNDBUFFER lpdsBuffer ) ;
BOOL RestoreBufferData( LPDIRECTSOUNDBUFFER lpdsBuffer, UINT nResource ) ;



BOOL InitelectronicBuffer( void ) ;
BOOL InitwoodblockBuffer( void ) ;
BOOL InittunerBuffer( void ) ;

BOOL InitsilenceBuffer( void ) ;




BOOL InitDanceBuffer( void ) ;
BOOL InitConeBuffer( void ) ;

void setmetrealvolume(int x)

{

long xx;


xx = log10((double)x)/4*10000 - 10000;



g_lpDSBufferelectronic->SetVolume(xx);
g_lpDSBufferwoodblock->SetVolume(xx);

g_lpDSBuffertuner->SetVolume(0);
}
/******************************************************************************
FUNCTION: InitDirectSound
This is where the actual COM initialization occurs.  The DirectSound object
is created and initialized with the proper cooperative level.  Also the primary
sound buffer is created, and functions are called to create the secondary 
buffers.

PARAMETERS:
None

RETURNS:
Success or Failure
******************************************************************************/
BOOL InitDirectSound( void )
{   
   DSBUFFERDESC   dsBufferDesc ;   

   // Create the DirectSoundObject and retrieve a pointer to its IDirectSound
   // interface
   if ( FAILED( DirectSoundCreate( NULL, &g_lpDSound, NULL ) ) )
      return FALSE ;

   // Set the cooperative level to normal.  This limits us to a primary
   // buffer format of 22kHz, stereo, 8-bit
  // if ( FAILED( g_lpDSound->SetCooperativeLevel( g_hMainWnd, DSSCL_NORMAL ) ) )

   //if ( FAILED( g_lpDSound->SetCooperativeLevel( m_pMainWnd , DSSCL_NORMAL ) ) )

   //if ( FAILED( g_lpDSound->SetCooperativeLevel( AfxGetApp()->m_pMainWnd , DSSCL_NORMAL ) ) )

  // if ( FAILED( g_lpDSound->SetCooperativeLevel( AfxGetMainWnd()->GetSafeHwnd() , DSSCL_NORMAL ) ) )

HWND hwndTop = AfxGetMainWnd()->GetSafeHwnd();  
 if ( FAILED( g_lpDSound->SetCooperativeLevel( hwndTop, DSSCL_NORMAL  ) ) )



   {
      UnInitDirectSound() ;
      return FALSE ;
   }

   // Set up the DSBUFFERDESC structure for creation of the primary buffer.
   // Make sure that the unused items in the structure are set to zero.
   // Notice the DSBCAPS_CTRL3D, we need this for 3d sound support.
   dsBufferDesc.dwSize = sizeof( dsBufferDesc ) ;
//   dsBufferDesc.dwFlags = DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER | 
 //                          DSBCAPS_LOCHARDWARE ; 

   dsBufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER | 
                           DSBCAPS_LOCHARDWARE ; 
 

   dsBufferDesc.dwBufferBytes = 0 ;
   dsBufferDesc.dwReserved = 0 ;
   dsBufferDesc.lpwfxFormat = NULL ;
      
   // Create the primary buffer.  If it fails, uninit DirectSound and exit
   if ( FAILED( g_lpDSound->CreateSoundBuffer( &dsBufferDesc, 
                                               &g_lpDSBufferPrimary, NULL ) ) )
   {        
      UnInitDirectSound() ;
      return FALSE ;
   }   

   // Set the buffer playing and looping.  This keeps the mixer running.
//   g_lpDSBufferPrimary->Play( 0, 0, DSBPLAY_LOOPING ) ;

   // Call function to set up the listener interface
//   if ( !InitListener() )
 //  {
 //     UnInitDirectSound() ;
//      return FALSE ;
 //  }
      
   // Call a function to set up secondary sound buffers for the "ouch" sound
   if ( !InitOuchBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }

   // Call a function to set up secondary sound buffers for the "Doppler" sound
   if ( !InitelectronicBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }

   if ( !InitwoodblockBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }

   if ( !InittunerBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }

   if ( !InitsilenceBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }



   // Call a function to set up secondary sound buffers for the "Dance" sound
   if ( !InitDanceBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }

   // Call a function to set up secondary sound buffers for the "Cone" sound
   if ( !InitConeBuffer() )
   {      
      UnInitDirectSound() ;
      return FALSE ;
   }
   
   return TRUE ;
}


/******************************************************************************
FUNCTION: DSActive
This function is called when the application becomes active.  It replays the
sounds that are constantly playing.

PARAMETERS:
None

RETURNS:
None
******************************************************************************/
void DSActive( void )
{   
   g_bDSActive = TRUE ;
/*
   if ( g_lpDSBufferelectronic )      
      Playelectronic() ;
   if ( g_lpDSBufferCone )
      PlayCone() ;
	  
*/
}


/******************************************************************************
FUNCTION: DSInactive
This function is called when the application becomes inactive.  

PARAMETERS:
None

RETURNS:
None
******************************************************************************/
void DSInactive( void )
{
   // This variable is set false so that we know not to bother restoring 
   // buffers for the moment.
 g_bDSActive = FALSE ;



}




/******************************************************************************
FUNCTION: InitOuchBuffer
This function creates four secondary sound buffers for the "ouch" sound.

PARAMETERS:
None

RETURNS:
Success or Failure
******************************************************************************/
BOOL InitOuchBuffer( void )
{
    

   return TRUE ;
}


/******************************************************************************
FUNCTION: InitelectronicBuffer
This function creates a secondary sound buffer for the "Doppler" sound.

PARAMETERS:
None

RETURNS:
Success or Failure
******************************************************************************/
BOOL InitelectronicBuffer( void )
{
    
   HRSRC    hrsrc ;
   HGLOBAL  hgRes ; 
   DWORD    dwSize ;
   
   // Find and load the user defined resource for the Doppler sound
//   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_electronic ), "WAVE" ) ;   

   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_electronic ), "WAVE" ) ;   



   hgRes = LoadResource( NULL, hrsrc ) ;
   dwSize = SizeofResource( NULL, hrsrc ) ;

   // Pass a pointer to the wav data to our function to create a secondary
   // sound buffer for the sound.
   g_lpDSBufferelectronic = WavToStaticBuffer( (LPBYTE) hgRes, dwSize, NULL ) ;
//   if ( !g_lpDSBufferOuch )

   if ( !g_lpDSBufferelectronic )



      return NULL ;

   // Query interface for the IDirectSound3DBuffer.  This interface is used
   // to implement the 3D features for this sound.
 //  if ( FAILED( g_lpDSBufferelectronic->QueryInterface( IID_IDirectSound3DBuffer, 
  //                                       (void **) &g_lpDS3DBufferelectronic ) ) )
 //  {      
 //     return NULL ;
 //  }

   // Set this sounds velocity.  This is a constant.  The position of the
   // sound source is changed periodically by the demo, causeing the Doppler
   // effect.  Try changing the velocity values to see how it effects the sound
//   g_lpDS3DBufferelectronic->SetVelocity( 20, 20, 0, DS3D_IMMEDIATE ) ;


   return TRUE ;
}


BOOL InitwoodblockBuffer( void )
{
    
   HRSRC    hrsrc ;
   HGLOBAL  hgRes ; 
   DWORD    dwSize ;
   
   // Find and load the user defined resource for the Doppler sound
//   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_woodblock ), "WAVE" ) ;   

   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_woodblock ), "WAVE" ) ;   



   hgRes = LoadResource( NULL, hrsrc ) ;
   dwSize = SizeofResource( NULL, hrsrc ) ;

   // Pass a pointer to the wav data to our function to create a secondary
   // sound buffer for the sound.
   g_lpDSBufferwoodblock = WavToStaticBuffer( (LPBYTE) hgRes, dwSize, NULL ) ;
//   if ( !g_lpDSBufferOuch )

   if ( !g_lpDSBufferwoodblock )



      return NULL ;

   // Query interface for the IDirectSound3DBuffer.  This interface is used
   // to implement the 3D features for this sound.
//   if ( FAILED( g_lpDSBufferwoodblock->QueryInterface( IID_IDirectSound3DBuffer, 
   //                                      (void **) &g_lpDS3DBufferwoodblock ) ) )
 //  {      
//      return NULL ;
 //  }

   // Set this sounds velocity.  This is a constant.  The position of the
   // sound source is changed periodically by the demo, causeing the Doppler
   // effect.  Try changing the velocity values to see how it effects the sound
//   g_lpDS3DBufferwoodblock->SetVelocity( 20, 20, 0, DS3D_IMMEDIATE ) ;


   return TRUE ;
}


BOOL InittunerBuffer( void )
{
    
   HRSRC    hrsrc ;
   HGLOBAL  hgRes ; 
   DWORD    dwSize ;
   
   // Find and load the user defined resource for the Doppler sound
//   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_tuner ), "WAVE" ) ;   

   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_alooped ), "WAVE" ) ;   



   hgRes = LoadResource( NULL, hrsrc ) ;
   dwSize = SizeofResource( NULL, hrsrc ) ;

   // Pass a pointer to the wav data to our function to create a secondary
   // sound buffer for the sound.
   g_lpDSBuffertuner = WavToStaticBuffer( (LPBYTE) hgRes, dwSize, NULL ) ;
//   if ( !g_lpDSBufferOuch )

   if ( !g_lpDSBuffertuner )



      return NULL ;

   // Query interface for the IDirectSound3DBuffer.  This interface is used
   // to implement the 3D features for this sound.
 //  if ( FAILED( g_lpDSBuffertuner->QueryInterface( IID_IDirectSound3DBuffer, 
   //                                      (void **) &g_lpDS3DBuffertuner ) ) )
 //  {      
 //     return NULL ;
 //  }

   // Set this sounds velocity.  This is a constant.  The position of the
   // sound source is changed periodically by the demo, causeing the Doppler
   // effect.  Try changing the velocity values to see how it effects the sound
//   g_lpDS3DBuffertuner->SetVelocity( 20, 20, 0, DS3D_IMMEDIATE ) ;


   return TRUE ;
}


BOOL InitsilenceBuffer( void )
{
    
   HRSRC    hrsrc ;
   HGLOBAL  hgRes ; 
   DWORD    dwSize ;
   
   // Find and load the user defined resource for the Doppler sound
//   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_tuner ), "WAVE" ) ;   

   hrsrc = FindResource( NULL, MAKEINTRESOURCE( IDR_silence ), "WAVE" ) ;   



   hgRes = LoadResource( NULL, hrsrc ) ;
   dwSize = SizeofResource( NULL, hrsrc ) ;

   // Pass a pointer to the wav data to our function to create a secondary
   // sound buffer for the sound.
   g_lpDSBuffersilence = WavToStaticBuffer( (LPBYTE) hgRes, dwSize, NULL ) ;
//   if ( !g_lpDSBufferOuch )

   if ( !g_lpDSBuffersilence )



      return NULL ;

   // Query interface for the IDirectSound3DBuffer.  This interface is used
   // to implement the 3D features for this sound.
 //  if ( FAILED( g_lpDSBuffertuner->QueryInterface( IID_IDirectSound3DBuffer, 
   //                                      (void **) &g_lpDS3DBuffertuner ) ) )
 //  {      
 //     return NULL ;
 //  }

   // Set this sounds velocity.  This is a constant.  The position of the
   // sound source is changed periodically by the demo, causeing the Doppler
   // effect.  Try changing the velocity values to see how it effects the sound
//   g_lpDS3DBuffertuner->SetVelocity( 20, 20, 0, DS3D_IMMEDIATE ) ;


   return TRUE ;
}


/******************************************************************************
FUNCTION: InitDanceBuffer
This function creates a secondary sound buffer for the "Dance" sound.

PARAMETERS:
None

RETURNS:
Success or Failure
******************************************************************************/
BOOL InitDanceBuffer( void )
{
    


   return TRUE ;
}


/******************************************************************************
FUNCTION: InitConeBuffer
This function creates a secondary sound buffer for the "Cone" sound.

PARAMETERS:
None

RETURNS:
Success or Failure
******************************************************************************/
BOOL InitConeBuffer( void )
{
    

   
   return TRUE ;
}


/******************************************************************************
FUNCTION: WavToStaticBuffer
This function takes a buffer which holds a wav file, and creates a secondary
static sound buffer for the wav.  It then loads the data from the buffer into
the static buffer.  This function uses the multimedia functions (mm) to parse
the wave data.  It would be a very simple task to extend this function to read
a WAV file.

PARAMETERS:
lpBuffer -- Pointer to a buffer containing wave data
dwSize -- size of buffer
lpdsBuffer -- pointer to an existinf IDirectSoundBuffer interface.  Pass NULL
              if a new interface should be created.  Otherwise, the data will
              be stored with this interface.

RETURNS:
A pointer to the IDirectSoundBuffer interface, or NULL if it failed
******************************************************************************/
LPDIRECTSOUNDBUFFER WavToStaticBuffer( LPBYTE lpBuffer, DWORD dwSize, 
                                       LPDIRECTSOUNDBUFFER lpdsBuffer )
{
   MMIOINFO       mmIOInfo ;
   HMMIO          mmioWave ;
   MMCKINFO       mmckinfoParent, mmckinfoSubchunk ;
   WAVEFORMATEX   wfPCM ;
   char           *lpFile = (char *) lpBuffer ;
   HRESULT        hr ;
   BOOL           bNewBuffer = FALSE ;
   
   DSBUFFERDESC   dsBufferDesc ;   
   LPBYTE         lpvAudio1 ;
   LPBYTE         lpvAudio2 ;
   DWORD          dwWriteBytes1 ;
   DWORD          dwWriteBytes2 ;

   // Set the MMIOINFO structure up for reading a multimedia WAV file from 
   // memory.
   memset( &mmIOInfo, sizeof( MMIOINFO ), 0 ) ;
   mmIOInfo.pIOProc = NULL ;
   mmIOInfo.fccIOProc = FOURCC_MEM ;
   mmIOInfo.pchBuffer = lpFile ;
   mmIOInfo.cchBuffer = dwSize ;    

   // Open the wave data using the mm functions
   mmioWave = mmioOpen( NULL, &mmIOInfo, MMIO_READWRITE ) ;
   if ( !mmioWave )
      return NULL ;

   // Descend to find a "WAVE" block, if this fails then the data is not
   // WAV data.
   mmckinfoParent.fccType = mmioFOURCC( 'W', 'A', 'V', 'E' ) ;
   if ( mmioDescend( mmioWave, &mmckinfoParent, NULL, MMIO_FINDRIFF ) ) 
   {
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }

   // Descend again to the "fmt " block and retrieve the format information
   mmckinfoSubchunk.ckid = mmioFOURCC( 'f', 'm', 't', ' ' ) ;
   if ( mmioDescend( mmioWave, &mmckinfoSubchunk, &mmckinfoParent, 
                     MMIO_FINDCHUNK ) )
   {
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }

   // This line actually reads the data from the "fmt " chunk, this data
   // should be in the form of a WAVEFORMATEX structure
   if ( mmioRead( mmioWave, (char *) &wfPCM, mmckinfoSubchunk.cksize ) == -1 )
   {
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }
    
   // Step out a layer... think of the mm functions as step in and out of
   // hierarchies of "chunks" of information
   mmioAscend( mmioWave, &mmckinfoSubchunk, 0 ) ;

   // Find the "data" subchunk
    mmckinfoSubchunk.ckid = mmioFOURCC( 'd', 'a', 't', 'a' ) ;
    if ( mmioDescend( mmioWave, &mmckinfoSubchunk, &mmckinfoParent, 
                      MMIO_FINDCHUNK ) ) 
   {
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }   

   // At this point we have succedded in finding the data for the WAV file so
   // we need to create a DirectSoundBuffer if one wasn't passed.
   if ( !lpdsBuffer )
   {
      // Set up DSBUFFERDESC structure for a static secondary buffer.       
      dsBufferDesc.dwSize = sizeof( DSBUFFERDESC ) ;       
 //     dsBufferDesc.dwFlags =  DSBCAPS_CTRL3D | DSBCAPS_STATIC  |DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLVOLUME ;    //hwm
      

     dsBufferDesc.dwFlags =  DSBCAPS_STATIC  |DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLVOLUME ;    //hwm
 


	  
	  
	  
	  // Buffer size retrieved from the mmckinfo structure for the data 
      // portion of the wav
      dsBufferDesc.dwBufferBytes = mmckinfoSubchunk.cksize ; 
      dsBufferDesc.dwReserved = 0 ;
      dsBufferDesc.lpwfxFormat = &wfPCM ; 

      // Create buffer.    
      if ( FAILED( g_lpDSound->CreateSoundBuffer( &dsBufferDesc, &lpdsBuffer, 
                                                  NULL ) ) )
      {
         mmioClose( mmioWave, 0 ) ;
         return NULL ;
      }
      // Did we create a new buffer
      bNewBuffer = TRUE ;
   }
   
   // Lock the buffer for the DirectSoundBuffer object
   hr = lpdsBuffer->Lock( 0, 0, (void **) &lpvAudio1, &dwWriteBytes1, 
                 (void **) &lpvAudio2, &dwWriteBytes2, DSBLOCK_ENTIREBUFFER ) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // If the buffer was lost try restoring it and lock again
      lpdsBuffer->Restore() ;
      hr = lpdsBuffer->Lock( 0, 0, (void **) &lpvAudio1, &dwWriteBytes1, 
                 (void **) &lpvAudio2, &dwWriteBytes2, DSBLOCK_ENTIREBUFFER ) ;
   }

   if ( FAILED( hr ) )
   {
      if ( bNewBuffer )
         lpdsBuffer->Release() ;   
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }

   if ( dwWriteBytes1 != mmckinfoSubchunk.cksize )
   {
      if ( bNewBuffer )
         lpdsBuffer->Release() ;   
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }
 
   // Read the data directly into the locked buffer
   if ( mmioRead( mmioWave, ( char* ) lpvAudio1, mmckinfoSubchunk.cksize ) 
        == -1 )
   {
      if ( bNewBuffer )
         lpdsBuffer->Release() ;   
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }   

   // Unlock the buffer
   if ( FAILED( lpdsBuffer->Unlock( (void *) lpvAudio1, dwWriteBytes1, 
                                    (void *) lpvAudio2, dwWriteBytes2 ) ) )
   {
      if ( bNewBuffer )
         lpdsBuffer->Release() ;
      mmioClose( mmioWave, 0 ) ;
      return NULL ;
   }
   
   // Close the multimedia object
   mmioClose( mmioWave, 0 ) ;

   return lpdsBuffer ;
}


/******************************************************************************
FUNCTION: RestoreBufferData
This function will reload a resource and attempt to restore the buffer for a
direct sound buffer.

PARAMETERS:
lpdsBuffer -- Existing direct sound interface
nResource -- Resource ID of the user defined resource holding the WAV data

RETURNS:
Returns success or failure
******************************************************************************/
BOOL RestoreBufferData( LPDIRECTSOUNDBUFFER lpdsBuffer, UINT nResource )
{
   HRSRC    hrsrc ;
   HGLOBAL  hgRes ; 
   DWORD    dwSize ;
  
   // Don't bother trying if the application window is not in the foreground
   if ( !g_bDSActive )
    return FALSE ;

   // Find and load the resources
   hrsrc = FindResource( NULL, MAKEINTRESOURCE( nResource ), "WAVE" ) ;   
   hgRes = LoadResource( NULL, hrsrc ) ;
   dwSize = SizeofResource( NULL, hrsrc ) ;

   // Copy the data from the resource into our buffer using our nifty function
   lpdsBuffer = WavToStaticBuffer( (LPBYTE) hgRes, dwSize, lpdsBuffer ) ;
   if ( !lpdsBuffer )
      return FALSE ;

   return TRUE ;
}






/******************************************************************************
FUNCTION: Playelectronic
Play the electronic object, and restore it if the buffer has been lost.

PARAMETERS:
void

RETURNS:
void
******************************************************************************/
/*void Playelectronic( void )
{
   HRESULT hr ;

   // Play
   hr = g_lpDSBufferelectronic->Play( 0, 0, DSBPLAY_LOOPING ) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // Failed?  Restore.
      if ( RestoreBufferData( g_lpDSBufferelectronic, IDR_electronic ) )
      {
         // Play again...
         g_lpDSBufferelectronic->Play( 0, 0, DSBPLAY_LOOPING ) ;
      }
   }   
}*/

void Playelectronic( void )
{
   HRESULT hr ;
g_lpDSBufferelectronic->SetCurrentPosition(0);





   // Play
   hr = g_lpDSBufferelectronic->Play( 0, 0, 0 ) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // Failed?  Restore.
      if ( RestoreBufferData( g_lpDSBufferelectronic, IDR_electronic ) )
      {
         // Play again...
         g_lpDSBufferelectronic->Play( 0, 0, 0 ) ;
      }
   }   




}

void Playwoodblock( void )
{
   HRESULT hr ;
g_lpDSBufferwoodblock->SetCurrentPosition(0);
   // Play
   hr = g_lpDSBufferwoodblock->Play( 0, 0, 0 ) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // Failed?  Restore.
      if ( RestoreBufferData( g_lpDSBufferwoodblock, IDR_woodblock ) )
      {
         // Play again...
         g_lpDSBufferwoodblock->Play( 0, 0, 0 ) ;
      }
   }   
}

void Playtuner( void )
{
   

	
	
	HRESULT hr ;

g_lpDSBuffertuner->SetCurrentPosition(0);


   // Play
   hr = g_lpDSBuffertuner->Play( 0, 0, DSBPLAY_LOOPING) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // Failed?  Restore.
      if ( RestoreBufferData( g_lpDSBuffertuner, IDR_alooped ) )
      {
         // Play again...
         g_lpDSBuffertuner->Play( 0, 0, DSBPLAY_LOOPING) ;
      }
   }   
}

void Playsilence( void )
{
   HRESULT hr ;

g_lpDSBuffersilence->SetCurrentPosition(0);


   // Play
   hr = g_lpDSBuffersilence->Play( 0, 0, DSBPLAY_LOOPING) ;
   if ( hr == DSERR_BUFFERLOST )
   {
      // Failed?  Restore.
      if ( RestoreBufferData( g_lpDSBuffersilence, IDR_silence ) )
      {
         // Play again...
         g_lpDSBuffersilence->Play( 0, 0, DSBPLAY_LOOPING) ;
      }
   }   
}

/******************************************************************************
FUNCTION: SetConePos
Set the position of the Cone object in DirectSound 3D space.

PARAMETERS:
void

RETURNS:
void
******************************************************************************/
/*BOOL SetConePos( DemoCone *pDLS, BOOL bDeferred )
{   
   // Set the position.  The demo currently locks the position.

}

*/
/******************************************************************************
FUNCTION: PlayCone
Play the cone object

PARAMETERS:
void

RETURNS:
void
******************************************************************************/
void PlayCone( void )
{     
  
}


/******************************************************************************
FUNCTION: PlayOuch
Play the ouch object.  A little more complicated then the other "Play" 
functions because it plays the first available buffer of 4.
    
PARAMETERS:
nX -- X position of the source
nY -- Y position of the source
bDeferred -- Defer the changes?

RETURNS:
none
******************************************************************************/
void PlayOuch( int nX, int nY, BOOL bDeferred )
{   
 
}


/******************************************************************************
FUNCTION: PlayDance
Play the "Dance" object.  

PARAMETERS:
nX -- X position of the source
nY -- Y position of the source
bDeferred -- Defer the changes?

RETURNS:
none
******************************************************************************/
void PlayDance( int nX, int nY, BOOL bDeferred )
{     


}


/******************************************************************************
FUNCTION: StopDance
Stop the "Dance" object.  It is important that we can stop the "Dance" sound
when the user lets go of the button.

PARAMETERS:
none

RETURNS:
none
******************************************************************************/
void Stoptuner( void )
{
      // Stop


/*
DWORD  w;

do{
g_lpDSBuffertuner->GetCurrentPosition(& w ,NULL);

}while (w != 0);
*/


g_lpDSBuffertuner->Stop();  



}




/******************************************************************************
FUNCTION: UnInitDirectSound
Un init all of the DirectSound stuff.

PARAMETERS:
none

RETURNS:
none
******************************************************************************/
void UnInitDirectSound( void )
{
   int nLoop ;

   // Release
   if ( g_lpDS3DBufferCone )
      g_lpDS3DBufferCone->Release() ;

   // Release
   if ( g_lpDS3DBufferDance )
      g_lpDS3DBufferDance->Release() ;

   // Release
   if ( g_lpDS3DBufferelectronic )
      g_lpDS3DBufferelectronic->Release() ;

   // Release
   if ( g_lpDSBufferCone )
      g_lpDSBufferCone->Release() ;

   // Release
   if ( g_lpDSBufferDance )
      g_lpDSBufferDance->Release() ;

   // Release
   if ( g_lpDSBufferelectronic )
      g_lpDSBufferelectronic->Release() ;

   // Release
   if ( g_lpDSBufferwoodblock )
      g_lpDSBufferwoodblock->Release() ;

   if ( g_lpDSBuffertuner )
      g_lpDSBuffertuner->Release() ;


   if ( g_lpDSBuffersilence )
      g_lpDSBuffersilence->Release() ;

   // Loop and release
   for ( nLoop = 0 ; nLoop < NUMOUCHES ; nLoop++ )
   {
      if ( g_lpDS3DBufferOuch[nLoop] )
         g_lpDS3DBufferOuch[nLoop]->Release() ;

      if ( g_lpDSBufferOuch[nLoop] )
         g_lpDSBufferOuch[nLoop]->Release() ;

   }

   // Release
   if ( g_lpDS3dListener )
      g_lpDS3dListener->Release() ;

   // Release -- talk about your cut and paste comments
   if ( g_lpDSBufferPrimary )
      g_lpDSBufferPrimary->Release() ;

   // Release
   if ( g_lpDSound )
      g_lpDSound->Release() ;
   
}











