//-----------------
// Melodías.c
//
// Descripcion:
// Objeto encargado de almecenar las melodías
// completas.
//
// Autores: Daniela Zapata y Jorge Coca
//-----------------


#include "Melodias.h"
#include "Resultados.h"

#define SMOKE_ON_THE_WATER 1	//selección de canción: Smoke on the water
#define THE_SIMPSONS 2		//selección de canción: The Simpsons
#define MOONRIVER 3		//selección de canción: Moonriver

Tmelodias smoke;  
Tmelodias simpsons;
Tmelodias moonriver;
Tmelodias cancionElegida;
Tmelodia melodia;

//---------------------------------------------------------------------------
// void actualizarMelodiaSeleccionada(int melodiaSeleccionada)
//
// Descripcion:
// función que se encarga de copiar los datos de la melodia seleccionada
// a una melodia genérica, que facilitara la programación.
//---------------------------------------------------------------------------
void actualizarMelodiaSeleccionada(int melodiaSeleccionada){
	int i,j,k=0;
	switch(melodiaSeleccionada){
		case SMOKE_ON_THE_WATER:
			output("Ha seleccionado SMOKE ON THE WATER \n \n \r");
			for(i=0; i<=melodia.longitudCancion+7; i++){
				cancionElegida.teclas[i]=smoke.teclas[i];
				cancionElegida.duraciones[i]=smoke.duraciones[i];
				cancionElegida.frecuencias[i]=smoke.frecuencias[i];
				if(smoke.teclas[i]!=0){
					resultados.totalNotas++;
				}
			}break;
		case THE_SIMPSONS:
			output("Ha seleccionado THE SIMPSONS \n \n \r");
			for(j=0; j<=melodia.longitudCancion+7; j++){
				cancionElegida.teclas[j]=simpsons.teclas[j];
				cancionElegida.duraciones[j]=simpsons.duraciones[j];
				cancionElegida.frecuencias[j]=simpsons.frecuencias[j];
				if(simpsons.teclas[j]!=0){
					resultados.totalNotas++;
				}
			}break;
		case MOONRIVER:
			output("Ha seleccionado MOONRIVER \n \n \r");
			for(k=0; k<=melodia.longitudCancion+7; k++){
				cancionElegida.teclas[k]=moonriver.teclas[k];
				cancionElegida.duraciones[k]=moonriver.duraciones[k];
				cancionElegida.frecuencias[k]=moonriver.frecuencias[k];
				if(moonriver.teclas[k]!=0){
					resultados.totalNotas++;
				}
			}break;
		default:
			output("Error de melodía actualizada");
	}
}

//---------------------------------------------------------------------------
// void melodias__init(void)
//
// Descripcion:
// inicializa el contenido necesario para poder reproducir y
// visualizar las melodías durante el transcurso del juego.
// Se rellenarán las matrices de notas y duraciones con ocho ceros
// en las primeras ocho posiciones, y con 300ms. en las primeras 
// ocho posiciones del array de frecuencias para facilitar la programación.
//---------------------------------------------------------------------------
void melodias__init(void){
	int l,m,n=0;	
	melodia.seleccionada=0;  //aun no seleccionamos ninguna cancion	
	melodia.longitudCancion=0;
	for(l=0; l<=LONG_SMOKE+7; l++){
		if(l<=7){
		        smoke.teclas[l]=0;
			smoke.duraciones[l]=300;                  
			smoke.frecuencias[l]=0;			  
		}else{
			smoke.duraciones[l]=duracionSmoke[l-8];
			smoke.frecuencias[l]=frecuenciaSmoke[l-8];
			smoke.teclas[l]=teclaSmoke[l-8];
		}
	}		
	for(m=0; m<=LONG_SIMPSON+7; m++){
		if(m<=7){
		        simpsons.teclas[m]=0;
			simpsons.duraciones[m]=300;
			simpsons.frecuencias[m]=0;
		}else{
			simpsons.teclas[m]=teclaSimpson[m-8];
			simpsons.duraciones[m]=duracionSimpson[m-8];
			simpsons.frecuencias[m]=frecuenciaSimpson[m-8];
		}
	}		
	for(n=0; n<=LONG_MOONRIVER+7; n++){
		if(n<=7){
		        moonriver.teclas[n]=0;
			moonriver.duraciones[n]=300;
			moonriver.frecuencias[n]=0;
		}else{
			moonriver.teclas[n]=teclaMoonriver[n-8];
			moonriver.duraciones[n]=duracionMoonriver[n-8];
			moonriver.frecuencias[n]=frecuenciaMoonriver[n-8];
		}
	}	
}


//---------------------------------------------------------------------------
// void resetCancionElegida(void)
// Descripción:
// Función que borra todos los datos de la última canción seleccionada.
//---------------------------------------------------------------------------
void resetCancionElegida(void){
	int i=0;
	for(i=0; i<TAM_MAX; i++){
		cancionElegida.teclas[i]=0;
		cancionElegida.duraciones[i]=0;
		cancionElegida.frecuencias[i]=0;
	}
}

