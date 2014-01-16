//------------------------------------------------
// Audio.c
//
// Descripción:
// Objeto que controla todas las opciones relacionadas
// con el audio del Piano Hero.
//
// Autores: Jorge Coca Ramos y Daniela Zapata Riesco
//------------------------------------------------


#include "Audio.h"
#include "Relojes.h"
#include "Melodias.h"
#include "Teclas.h"
#include "Resultados.h"

#define LONG_ARRAY_SENO 8000  //numero de muestras de la sinusoide contenida en "seno.c"

Taudio audio;

//--------------------------------------------------                 
// void reproducirAudio(int frecuencia)
//
// Descripción:
// función que se encarga de enviar al DAC la frecuencia
// a la que debe reproducir la melodía.
//----------------------------------------------------

void reproducirAudio(int frecuencia){
	static int i=0;
	DAC_dato(sinusoide[i]); //enviamos una muestra al DAC
	i+=frecuencia; //tomamos el valor de la siguiente muestra a enviar
	i = i % LONG_ARRAY_SENO; //volvemos a entrar en el array en caso de
				 //sobrepasar su tamaño
}

//-------------------------------------------------
// void comprobarAudio(void)
//
// Descripcion:
// función encargada de activar el flag audio reprodcuir
// en caso de haber acertado en la pulsación de una nota,
// para poder reproducir el dicha nota.
//-------------------------------------------------
void comprobarAudio(void){
	if(relojes.contadorPulsacion==cancionElegida.duraciones[audio.posicionActual-1]){ //se comprueba cuando finaliza la
											  //que se está reproduciendo
		relojes.contadorPulsacion=0;
		if(teclas.teclaAcertada==1){
			audio.reproducir=1; //si hemos pulsado correctamente, activamos el flag e incrementamos en
					    //en uno el contador de pulsaciones correctas.
			resultados.pulsacionesCorrectas++;
			teclas.teclaAcertada=0;
		}else{
			audio.reproducir=0;
		}
	}
	
}

//--------------------------------------------------
// void audio__init(void)
//
// Descripcion:
// Inicializa los objetos de audio.
//--------------------------------------------------

void audio__init(void){
	//audio.posicionActual=1;
	audio.posicionActual=0;
	audio.reproducir=0;
}

//------------------------------------------------------
// void audioReset(void)
//
// Descripción:
// reinicializa las variables del objeto Audio
//------------------------------------------------------

void audioReset(void){	
	audio.reproducir=0;
	audio.posicionActual=0;
}