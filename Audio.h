//-------------------------------------------------
//
// Audio.h
// Cabecera de Audio.h
//
//-------------------------------------------------     

/****************************************************************************/
#ifndef	Audio_h
#define	Audio_h
/****************************************************************************/

typedef struct{
	int posicionActual;  //nos da la informaci�n sobre qu� nota estamos
	                     //viendo en la �ltima posici�n de la pantalla de leds.
	int reproducir;  //flag que se activa cuando se ha acertado una nota, para 
			 //que se pueda reproducir dicha nota.
}Taudio;

void audio__init(void);
void comprobarAudio(void);
void reproducirAudio(int frecuencia); 
void audioReset(void);  


/****************************************************************************/
#endif	/* Audio_h */
      