//-----------------------------------------------------
// Puerto.c
//
// Descripcion:
// objeto encargado de controlar la informaci�n
// que se env�a al puerto de salida del 
// Motorola Coldfire.
//-----------------------------------------------------

#include "Puerto.h"

TPuerto puerto;


//-----------------------------------------------------
// void puerto_init(void)
//
// Descripcion:
// inicializa las variables del objeto Puerto.
//-----------------------------------------------------
void puerto_init(void){
	puerto.variableAux=0xFF01;
	set16_puertoS(puerto.variableAux);
	}


//------------------------------------------------------
// void puertoReset(void)
//
// Descripci�n:
// reinicializa las variables del objeto Puerto.
//------------------------------------------------------

void puertoReset(void){
	puerto.variableAux=0xFF01;
}