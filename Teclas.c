//-----------------
//Teclas.c
//
//Descripcion:
//Objeto encargado del control del teclado matricial
//
//Autores: Daniela Zapata y Joge Coca
//-----------------

#include "Relojes.h"
#include "m5272lib.c"
#include "Teclas.h"
#include "Leds.h"
#include "Estado.h"



#define NUM_FILAS 4	//numero de filas del teclado matricial	
#define EXCIT 1		//m�scara auxiliar de excitaci�n
#define COLUMNA_TECLADO_0  0x00   //columna 0 del teclado matricial

TTeclado teclas;

//------------------------------------------------------------
//char teclado(void)
//
//Descripcion:
//Explora el teclado matricial y deuelve la tecla pulsada de
//la primera columna. Esta rutina ser� utilizada durante la
//ejecuci�n del men� del juego, ya que entra en un bucle
//infinito del que no se sale hasta que no se pulsa
//ninguna de las teclas reconocidas. 
//------------------------------------------------------------
char teclado(void){

		BYTE fila, columna, fila_mask;
		static char teclas[4][1] = {{"1"},
					    {"4"},
					    {"7"},
					    {"A"}};

		// Bucle de exploraci�n del teclado

		while(TRUE){	
			// Excitamos la columna 0
			columna=0;
			set_puertoS(EXCIT<<columna); // Se env�a la excitaci�n de columna
			retardo(1150);              // Esperamos respuesta de optoacopladores

			// Exploramos las filas en busca de respuesta
			for(fila = NUM_FILAS - 1; fila >= 0; fila--){
				fila_mask = EXCIT << fila; // M�scara para leer el bit de la fila actual
				if(lee_puertoE() & fila_mask){ // Si encuentra tecla pulsada,
					while(lee_puertoE() & fila_mask); // Esperamos a que se suelte
					retardo(1150); // Retardo antirrebotes
					return teclas[fila][columna]; // Devolvemos la tecla pulsada
				}

			} // Exploraci�n finalizada sin encontrar una tecla pulsada

		} // Reiniciamos exploraci�n

	}
	
//-----------------------------------------------------
// int tecladoJuego(void)
// 
// Descripci�n:
// devuelve la tecla pulsada durante la ejecuci�n del juego.
// Se utiliza esta rutina en lugar de la anterior porque con
// esta, en caso de que no se produzca ninguna pulsaci�n,
// al terminar el tiempo habilitado devolver� un valor
// que registre el error cometido.
// Tambi�n resulta muy �til que devuelva un valor de tipo
// entero, ya que la comparaci�n con la nota deseada, que 
// tambi�n es un entero, resulta muy c�moda de realizar.
//-----------------------------------------------------

int tecladoJuego(void){
		
	BYTE fila, fila_mask;
	static int teclas[3][1] = {{1},
			           {4},
				   {7}};
	// Bucle de exploraci�n del teclado
	while(relojes.iTiempoNota<=cancionElegida.duraciones[audio.posicionActual-1]&&estado.reproduciendo==1){
		// Exploramos las filas en busca de respuesta
		for(fila = NUM_FILAS - 2; fila >= 0; fila--){//as� ya no se puede pulsar la tecla A 
			fila_mask = EXCIT << fila; 	       // M�scara para leer el bit de la fila actual
			if(lee_puertoE() & fila_mask){ 	       // Si encuentra tecla pulsada,
				while(lee_puertoE() & fila_mask);    // Esperamos a que se suelte
				retardo(1150); // Retardo antirrebotes
				resultados.totalPulsaciones++;
				return teclas[fila][COLUMNA_TECLADO_0]; 	// Devolvemos la tecla pulsada	
			}
		} // Exploraci�n finalizada sin encontrar una tecla pulsada	
	} // Reiniciamos exploraci�n
	return -1; //si no se pulsa ninguna tecla es porque hay un silencio, o
		   //porque se nos ha pasado el tiempo, y no se contabiliza
		   //como acierto.	
}
	
	
//-------------------------------------------------
// void compruebaTeclaAcertada(int teclaPulsada)
//
// Descripcion:
// esta funcion verfica si la tecla pulsada durante el tiempo
// de la nota coincide con la tecla esperada.El flag
// "teclaAcertada" ser� utilizado por el sistema de audio
// para determinar si debe o no reproducir la nota cuando
// estamos en modo competici�n.

//-------------------------------------------------

void compruebaTeclaAcertada(int teclaPulsada){
	if(teclaPulsada==led.pantallaActual[7]){
		teclas.teclaAcertada=1; //si acertamos, este flag permite reproducir la nota
		
	}
	else{
		teclas.teclaAcertada=0;
	}
	teclas.teclaPulsada=-1;
}	

//--------------------------------------------------
// void teclas__init(void)
//
// Descripcion:
// inicializa los objetas de Tecla
//--------------------------------------------------
void teclas__init(void){
	teclas.teclaPulsada=-1; //inicializamos a un valor no reconocido
	teclas.teclaAcertada=0;
}


//------------------------------------------------------
// void teclasReset(void)
//
// Descripci�n:
// reinicializa las variables del objeto Teclas.
//------------------------------------------------------

void teclasReset(void){
	teclas.teclaPulsada=-1;
	teclas.teclaAcertada=0;
}





