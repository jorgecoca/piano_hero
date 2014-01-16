/****************************************************************************/
#ifndef	Puerto_h
#define	Puerto_h
/****************************************************************************/

//-------------------------------------------
// Cabecera de Puerto.c
//
// Autores: Jorge Coca y Daniela Zapata
//-------------------------------------------

typedef struct{
	int variableAux; //en esta variable se almacena, en todo momento,
			 //la información que se envía al puerto de salida.
}TPuerto;

void puerto_init();
void puertoReset(void);


/****************************************************************************/
#endif	/* Puerto_h */
