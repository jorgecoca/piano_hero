/****************************************************************************/
#ifndef	Relojes_h
#define	Relojes_h
/****************************************************************************/

//----------------------------------------------
// Cabecera de Relojes.h
//
// Autores: Jorge Coca y Daniela Zapata
//----------------------------------------------

typedef struct{
	
	int iTiempoNota;     // contador para la duración de cada nota.
	int iLedsRefresco;   // contador para el refresco de leds cada 10ms.
	int contadorInterrupciones; // cuenta milisegundos para saber cuando comprobar la duración de cada nota.
	int contadorPulsacion;		//contador de tiempo hábil para la pulsación de una nota.
	
}Trelojes;
 extern Trelojes relojes;

void relojes__init(void);
void relojesReset(void);

/****************************************************************************/
#endif	/* Relojes_h */
