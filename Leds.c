//-----------------
// Leds.c
//
// Descripcion:
// Objeto encargado de mostrar las notas
// de la melodía en los displays (matriz de leds)
//
// Autores: Daniela Zapata y Joge Coca
//-----------------

#include "Leds.h"

#define TAM_PANTALLA 8      //tamaño de la pantalla de leds en vertical
#define MASCARA_AUX 0x0001  //máscara auxiliar de desplazamiento
#define COLUMNA1 0xFF21	    //máscara de activación de columna 1
#define COLUMNA2 0xFF41	    //máscara de activación de columna 2
#define COLUMNA3 0xFF81	    //máscara de activación de columna 3
#define BORRA_COLUMNA 0xFF01  //borra los datos del puerto de salida correspondientes a las columnas
#define NO_TOCAR_BITS_TECLADO 0xFFF1  //evita problemas con los bits de columna del teclado matricial


Tleds led;

//------------------------------------------------------
// void columnasBarrer(void)
//
// Descripcion:
// Función encargada de refrescar las columnas de los LEDs para evitar
// el parpadeo. Este refresco se produce cada 10 ms. El flag
// encargado de decidir qué columna se ilumina es 
// led.controladorColumna. En led.columnaX tenemos guardada
// la información de las filas que se deben encender en la
// columna X.
//------------------------------------------------------

void columnasBarrer(void){
	puerto.variableAux=puerto.variableAux & BORRA_COLUMNA;
	if(led.controladorColumna==0){	//las columnas no se iluminan simultaneamente
		puerto.variableAux=led.columna1;
	}
	if(led.controladorColumna==1){
		puerto.variableAux=led.columna2;
	}
	if(led.controladorColumna==2){	
		puerto.variableAux=led.columna3;
	}
	
	led.controladorColumna++;
	if(led.controladorColumna==3){
		led.controladorColumna=0;
	}
	puerto.variableAux=puerto.variableAux&NO_TOCAR_BITS_TECLADO; //desactivamos los bits 1,2 y 3 del
								     //puerto de salida. 	
	set16_puertoS(puerto.variableAux); //enviamos la información al puerto
}


//----------------------------------------------------
// void activarFilas(int pantallaActual[])
// 
// Descripcion:
// se encarga de separar la información que tenemos en la pantalla
// de LEDS en información por columnas para un mejor procesamiento.
// En cada variable led.columnaX guardamos el valor de las filas
// que deben encenderse en la columna X.
//----------------------------------------------------
void activarFilas(int pantallaActual[8]){
	int i=0;
	int auxiliar=0x0000;
	led.columna1=0xFFFF;
	led.columna2=0xFFFF;
	led.columna3=0xFFFF;
	for(i=0; i<=TAM_PANTALLA-1; i++){
		auxiliar=MASCARA_AUX<<(i+8); // Se desplaza el bit encargado de iluminar la fila.
		auxiliar=~(auxiliar); //activamos el bit de fila a 0
		if(pantallaActual[i]==1){ //activamos el bit correspondiente a la fila y columna
					  //que indica la nota que se muestra en pantalla.
			led.columna1=(led.columna1&auxiliar)&COLUMNA1; 
		}if(pantallaActual[i]==4){
			led.columna2=(led.columna2&auxiliar)&COLUMNA2;
		}if(pantallaActual[i]==7){
			led.columna3=(led.columna3&auxiliar)&COLUMNA3;
		}
	}
}


//-----------------------------------------------------
// void actualizarPantalla(void)
//
// Descripcion:
// Funcion que controla lo que sucede en la pantalla de leds en cada 
// momento, así como de insertar la nueva nota que entra en la pantalla
// de leds.
//-----------------------------------------------------

void actualizarPantalla(void){

	int k=0;
		for(k=TAM_PANTALLA-2; k>=0; k--){ //desplazamos las notas de la pantalla de Leds
						  //una posición hacia abajo.
			led.pantallaActual[k+1]=led.pantallaActual[k];
		}
	led.pantallaActual[0]=cancionElegida.teclas[audio.posicionActual+8]; //introducimos la nueva nota en la pantalla de leds
	activarFilas(led.pantallaActual); //desgrana la información a columnas para simplificar.
}


//------------------------------------------------------
// void Leds__init(void)
//
// Descripcion:
// Función encargada de inicializar los objetos de Leds.
//------------------------------------------------------

void Leds__init(void){

	led.controladorColumna=0;
	led.columna1=0xFFF1;
	led.columna2=0xFFF1;
	led.columna3=0xFFF1;
	}
	
	
//-------------------------------------------------------
// void inicializaPantallaActual(void)
// 
// Descripción:
// Función que mete las primeras 8 notas que se 
// mostrarán en los displays. La pantalla actual es
// como una fotografía de los 8 displays en cada
// momento.
//-------------------------------------------------------	
void inicializaPantallaActual(void){
	int n=0;
	for(n=0; n<=TAM_PANTALLA-1; n++){
		led.pantallaActual[n]=cancionElegida.teclas[n];
	}
}


