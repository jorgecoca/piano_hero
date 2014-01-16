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
	
	int iTiempoNota;     // contador para la duraci�n de cada nota.
	int iLedsRefresco;   // contador para el refresco de leds cada 10ms.
	int contadorInterrupciones; // cuenta milisegundos para saber cuando comprobar la duraci�n de cada nota.
	int contadorPulsacion;		//contador de tiempo h�bil para la pulsaci�n de una nota.
	
}Trelojes;
 extern Trelojes relojes;

void relojes__init(void);
void relojesReset(void);

/****************************************************************************/
#endif	/* Relojes_h */
