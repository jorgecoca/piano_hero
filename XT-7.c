//------------------------------------------------------------------------------
// XT-7.c
//
// Objeto principal del juego Piano Hero.
//
// Autores: Daniela Zapata y Jorge Coca
//-------------------------------------------------------------------------------

#include "m5272lib.c"
#include "m5272gpio.c"
#include "m5272adc_dac.c"
#include "seno.c"		// Incluye la sinusoide de 1Hz proporcionada.
#include "Audio.c"		
#include "Melodias.c"
#include "Puerto.c"
#include "Teclas.c"
#include "Estado.c"
#include "Relojes.c"
#include "Leds.c"
#include "Resultados.c"
#include "Pantalla.c"


#define DIEZ_MILISEGUNDOS 80  	         // En 10 ms se producen 80 interrupciones. 
					 // Sirve para el parpadeo de los displays.
					
#define UN_MILISEGUNDO 8  		 // En un milisegundo se producen 8 interrupciones. 
					 // Utilizado para contar los tiempos de nota.


//------------------------------------------------------
// void bucleMain(void)
//
// Descripción:
// Función del programa principal. Esta función se encarga del control
// del menú y del control de la pulsación de teclas durante el modo
// competición.
//------------------------------------------------------

	void bucleMain(void){			

		if(estado.reproduciendo==0){    // Si todavía no se ha empezado a jugar (o en automático) o ya 
						// se ha terminado una partida se vuelve al menú de opciones.
			menu();
		}
		else{
			if(estado.modoCompeticion==1){	
				teclas.teclaPulsada=tecladoJuego();	     // En modo competicion reconoce cada tecla pulsada.
				compruebaTeclaAcertada(teclas.teclaPulsada); // Luego comprueba si es correcta.
			}	
		  }
	}

//------------------------------------------------------
// void __init(void)
//
// Descripción:
// Función por defecto de inicialización de software y hardware
// del sistema. 
//------------------------------------------------------

	void __init(void){
		mensajeBienvenida();	//saca por pantalla el mensaje de bienvenida.
		puerto_init();		//inicializa la variable del puerto de salida.
		resultados__init();	//inicializa los últimos resultados del juego.
		Leds__init();		//inicializa las variables de leds
		DAC_ADC_init();		//inicializa el DAC del sistema
		melodias__init();	//inicializa las melodias
		estado__init();		//inicializa las variables de estado
		relojes__init();	//configura las interrupciones e inicializa los 						
					//contadores
		audio__init();		//inicializa las variables de audio
	}


//------------------------------------------------------
// Definición de rutinas de atención a la interrupción
// Es necesario definirlas aunque estén vacías

void rutina_int1(void){}
void rutina_int2(void){}
void rutina_int3(void){}
void rutina_int4(void){}

//------------------------------------------------------
//void rutina_tout0(void)
//
//Descripción:
// Rutina de interrupción de TOUT0. El programa entra
// automáticamente según la configuración de 
// interrupciones establecida en Relojes.c, que es de
// 1 interrupción cada 0.125ms u 8 interrupciones/ms
// Es decir, frecuencia de interrupción=8kHz
//------------------------------------------------------

void rutina_tout0(void){		
	if(estado.reproduciendo==1){ // Al terminar con el menú se atienden las interrupciones periódicas.

		if(relojes.contadorInterrupciones==UN_MILISEGUNDO){
		        if(relojes.iTiempoNota==cancionElegida.duraciones[audio.posicionActual-1]){ 
					//la nota que marca el "timing" de Leds es la que sale de la pantalla.
				actualizarPantalla();
				audio.posicionActual++;
				relojes.iTiempoNota=-1;	
			}
			relojes.iTiempoNota++;
	        	relojes.contadorInterrupciones=0;
			relojes.contadorPulsacion++;
		}
		
		if(relojes.iLedsRefresco==DIEZ_MILISEGUNDOS){ //el barrido de leds se produce cada 10ms.
			columnasBarrer();
			relojes.iLedsRefresco=0;
        	}

		if(estado.modoAutomatico==1){ //en modo automático no se tiene en cuenta las teclas
			reproducirAudio(cancionElegida.frecuencias[audio.posicionActual-1]);
		}
		if(estado.modoCompeticion==1){
			comprobarAudio();
			if(audio.reproducir==1){ //si se ha pulsado correctamente la tecla, se reproduce
				reproducirAudio(cancionElegida.frecuencias[audio.posicionActual-1]);
			}	
		}
 
		relojes.contadorInterrupciones++;
		relojes.iLedsRefresco++;
		
		if(audio.posicionActual==melodia.longitudCancion+9){     // Se ha enviado la última muestra.Ha terminado el juego y 
								      // se calculan los resultados.
			mostrarResultados();		              
			softwareReset();
		}
	}
	mbar_writeShort(MCFSIM_TER0, BORRA_REF);   // Reset del bit de fin de cuenta
}

void rutina_tout1(void){}
void rutina_tout2(void){}
void rutina_tout3(void){}
