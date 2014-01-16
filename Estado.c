
//---------------------------------------------------------------
// Estado.c
//
// Descripci�n:
// Objeto encargado de controlar
// el men� y el estado del juego.
//
// Autores: Jorge Coca Ramos y Daniela Zapata Riesco.
//---------------------------------------------------------------

#include "Estado.h"
#include "Leds.h"
#include "Resultados.h"
#include "Audio.h"
#include "Relojes.h"
#include "Puerto.h"
#include "Resultados.h"
#include "Teclas.h"

#define MELODIA_SMOKE '1'	//tecla 1 asociada a la melod�a smoke on the water.
#define MELODIA_SIMPSONS '4'	//tecla 4 asociada a the simpsons.
#define MELODIA_MOONRIVER '7'	//tecla 7 asociada a moonriver.
#define FACIL '1'		//el nivel f�cil corresponde a la tecla 1.Usado en void nivel(char tecla2)
#define MEDIO '4'		//el nivel medio se selecciona con la tecla 4
#define DIFICIL '7'		//el nivel dif�cil se escoge con un 7
#define AUTOMATICO 'A'		//el nivel automatico se elige con la tecla 'A'
#define NIVEL_FACIL 1		//nivel 1 de dificultad usado para inicializar el nivel en aplicarNivel.
#define NIVEL_MEDIO 2		//nivel 2 o medio.
#define NIVEL_DIFICIL 3		//nivel 3, dif�cil.
#define NIVEL_AUTOMATICO 4	//nivel autom�tico, en el que la melod�a se reproduce sin
				//tener en cuenta las pulsaciones del usuario.


Estado estado;


//------------------------------------------------------
// void cancion(char tecla)
//
// Descripcion:
// Funci�n encargada de elegir canci�n
// en el juego en funci�n de la tecla pulsada. 
//------------------------------------------------------


void cancion(char tecla){	
		while (tecla == 'A'){	// S�lo se pueden escoger 3 canciones con las teclas 1,4,7
			tecla=teclado();			 //Si se pulsa la tecla A no se escoge ninguna 
			output("Por favor, escoja una canci�n"); //canci�n y salta un mensaje de error.
			}
		switch(tecla){
			//caracterizamos cada melod�a con su tama�o total y con  
			//un n�mero de canci�n
			case MELODIA_SMOKE: 	
				melodia.seleccionada=SMOKE_ON_THE_WATER;
				melodia.longitudCancion= LONG_SMOKE;
				break;				   	
			case MELODIA_SIMPSONS:				   
				melodia.seleccionada=THE_SIMPSONS;
				melodia.longitudCancion= LONG_SIMPSON;
				break;					
			case MELODIA_MOONRIVER:				
				melodia.seleccionada=MOONRIVER;
				melodia.longitudCancion= LONG_MOONRIVER;
				break;					
			default:
				output("Error de selecci�n de canci�n. Por favor, reinicie el sistema");

			}
		actualizarMelodiaSeleccionada(melodia.seleccionada); //Se crean 3 arrays con los datos de la melod�a elegida.
		inicializaPantallaActual(); // Mete en un array las primeras 8 notas de la canci�n.

	}
	
//-----------------------------------------------------
// void aplicarNivel(int dificultad)
//
// Descripcion:
// Ralentiza o no la duraci�n de cada nota de la melod�a
// en funci�n del nivel escogido.
//------------------------------------------------------

void aplicarNivel(int dificultad){
	int n=0;
	for(n=0; n<=melodia.longitudCancion+7;n++){ // Hasta la longitud de la nota m�s 8 ceros iniciales.
		switch(dificultad){
			case NIVEL_FACIL:
				cancionElegida.duraciones[n]=2*cancionElegida.duraciones[n]; // La mitad de velocidad.
				break;
			case NIVEL_MEDIO:
				cancionElegida.duraciones[n]=1.5*cancionElegida.duraciones[n];//1.5 veces m�s lento.
				break;
			case NIVEL_DIFICIL:
				cancionElegida.duraciones[n]=1*cancionElegida.duraciones[n]; //velocidad normal.
				break;    //en dificil se reproduce a la velocidad original
			case NIVEL_AUTOMATICO:
				cancionElegida.duraciones[n]=1*cancionElegida.duraciones[n]; //velocidad normal.
				break;  //en automatico se reproduce a la velocidad original
			default:
				output("Error al aplicar el nivel. Reinicie el equipo");			
			}
	}
}

//------------------------------------------------------
// char nivel(void)
//
// Descripci�n:
// Permite seleccionar el nivel deseado en funci�n de la 
// tecla pulsada. Cuando elegimos un modo distinto del
// autom�tico entramos en modo competici�n, y es cuando
// el usuario debe jugar
//------------------------------------------------------

	void nivel(char tecla2){
		int nivelDificultad=0;
		switch(tecla2){
			
			case FACIL:
				nivelDificultad=NIVEL_FACIL;
				output("Ha seleccionado NIVEL F�CIL \n \n \r");
				output("Pulse A para comenzar a jugar \n \n \r");
				estado.modoCompeticion=1; //activamos modo competicion
				break;
			case MEDIO:
				nivelDificultad=NIVEL_MEDIO;
				output("Ha seleccionado NIVEL MEDIO \n \n \r");
				output("Pulse A para comenzar a jugar \n \n \r");
				estado.modoCompeticion=1; //activamos modo competicion	
				break;
			case DIFICIL:
				nivelDificultad=NIVEL_DIFICIL;
				output("Ha seleccionado NIVEL DIF�CIL \n \n \r"); 
				output("Pulse A para comenzar a jugar \n \n \r");
				estado.modoCompeticion=1; //activamos modo competicion
				break;
			case AUTOMATICO: 
				nivelDificultad=NIVEL_AUTOMATICO;					
 				output("Ha seleccionado MODO AUTOM�TICO \n \n \r"); 
				estado.modoAutomatico=1; //modo autom�tico.
				break;
			default:
				output("Error de selecci�n de nivel. Reinicie el sistema");					
		}		
		while(tecla2 != AUTOMATICO){             //hasta que no se pulsa la tecla "A" no
							 //comienza el juego.
   			tecla2=teclado();
			if(tecla2!= AUTOMATICO){
				output("Por favor, pulse la tecla A para comenzar \n \n \r");
			}	
		}
		aplicarNivel(nivelDificultad); // Aplicamos el nivel, que consiste en cambiar las duraciones de las notas.
		output("Comienza el juego. �Mucha suerte! \n \n \r");
		estado.reproduciendo=1;	// Desde este momento van a empezar a bajar las notas por los displays.    			
	}
	

//------------------------------------------------------
// void menu(void)
//
// Descripcion:
// Funci�n encargada de gestionar los men�s del juego. 
//------------------------------------------------------

void menu(void){
	
	char tecla; 
	char tecla2;
	output("Elija la melod�a:  
		\n 1. Smoke on the water\n 4. The Simpsons\n 7. Moonriver\n \n \r");
   	tecla = teclado();	
	cancion(tecla);  	// Efect�a la selecci�n de canci�n deseada seg�n la tecla pulsada.
     	output("Elija el nivel de dificultad:
		\n 1. F�cil \n 4. Medio \n 7. Dif�cil \n A. Autom�tico \n \n \r");
	tecla2 = teclado();	// La siguiente tecla pulsada determina
	nivel(tecla2);		// el nivel del juego(competici�n) o si se quiere el modo autom�tico.
}
	
//------------------------------------------------------
// void estado__init(void)
//
// Descripcion:
// inicializa los objetos de estado. 
//------------------------------------------------------


void estado__init(void){
	estado.reproduciendo=0;
	estado.modoAutomatico=0;
	estado.modoCompeticion=0;
	}

//------------------------------------------------------
// void softwareReset(void)
//
// Descripci�n:
// esta funci�n hace un reset de las variables oportunas
// para que se pueda seguir jugando despu�s de haber acabado
// una canci�n, una vez que ha terminado el juego.
//------------------------------------------------------
void softwareReset(void){
	resetCancionElegida();
	audioReset();
	estadoReset();
	relojesReset();
	puertoReset();
	resultadosReset();
	teclasReset();	
}


//------------------------------------------------------
// void estadoReset(void)
//
// Descripci�n:
// reinicializa las variables del objeto Estado.
//------------------------------------------------------

void estadoReset(void){
	estado.reproduciendo=0;
	estado.modoAutomatico=0;
	estado.modoCompeticion=0;
}


	