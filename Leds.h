/****************************************************************************/
#ifndef	Leds_h
#define	Leds_h
/****************************************************************************/


//-------------------------------------------------
// Cabecera de Leds.h
//
// Autores: Jorge Coca y Daniela Zapata
//-------------------------------------------------

typedef struct{
	int controladorColumna; //flag que indica que columna se debe iluminar
	int columna1; //información de la columna 1
	int columna2; //información de la columna 2
	int columna3; //información de la columna 3
	int pantallaActual[8];  //esta variable representa una "fotografía" de 
				//de la información que tenemos en la pantalla 
				//de leds.
} Tleds;



extern Tleds led;
void Leds__init(void);
void columnasBarrer(void);
void activarFilas(int pantallaActual[]);
void actualizarPantalla(void);
void inicializaPantallaActual(void);


/****************************************************************************/
#endif	/* Leds_h */