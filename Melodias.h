/****************************************************************************/
#ifndef	Melodias_h
#define	Melodias_h
/****************************************************************************/

//--------------------------------------------
// Cabecera de Melodias.h
//
// Autores: Jorge Coca y Daniela Zapata
//--------------------------------------------

#define LONG_SMOKE 22  //longitud de la cancion "Smoke on the water"
#define LONG_SIMPSON 23 //longitud de "The Simposons"
#define LONG_MOONRIVER 35 //longitud de "Moonriver"
#define TAM_MAX 100		//tamaño máximo de inicialización genérico

int teclaSmoke[LONG_SMOKE]= {4,0,4,0,1,0,4,0,7,0,1,1,0,4,0,4,0,1,0,4,0,4};
int duracionSmoke[LONG_SMOKE]= {187,187,187,187,187,375,187,187,187,187,187,187,375,187,187,187,187,187,375,187,187,187};
int frecuenciaSmoke[LONG_SMOKE]= {523,0,622,0,699,0,523,0,659,0,699,699,0,523,0,622,0,699,0,622,0,523};

int teclaSimpson[LONG_SIMPSON]={4,7,4,4,7,7,4,4,4,4,4,7,0,0,4,4,4,7,7,4,4,4,4};
int duracionSimpson[LONG_SIMPSON]={562,375,375,187,562,375,375,187,187,187,187,750,187,187,187,187,187,187,562,187,187,187,375};
int frecuenciaSimpson[LONG_SIMPSON]={1047,1319,1480,1760,1568,1319,1047,880,740,740,740,784,0,0,740,740,740,784,932,1047,1047,1047,1047};

int teclaMoonriver[LONG_MOONRIVER]= {7,1,4,1,4,7,1,7,1,4,7,1,7,7,1,0,1,4,7,7,1,4,7,7,1,4,7,7,4,1,4,1,4,7,4};
int duracionMoonriver[LONG_MOONRIVER]= {1333,499,999,999,249,333,333,1333,999,333,333,333,1333,499,1999,666,333,1333,666,999,333,1999,666,999,499,499,666,666,666,666,333,666,666,499,1999};
int frecuenciaMoonriver[LONG_MOONRIVER]= {784,1175,1047,988,880,784,699,784,988,880,784,699,784,659,587,0,587,523,784,659,587,523,784,659,587,523,659,784,1047,988,880,988,880,784,880};

typedef struct{
	int frecuencias[TAM_MAX];  //alamcen de frecuencias
	int duraciones[TAM_MAX];   //almacen de duraciones de nota
	int teclas[TAM_MAX];       //almacen de teclas
}Tmelodias;


extern Tmelodias cancionElegida;


typedef struct{
	int seleccionada;  //indicativo de qué canción hemos seleccionado
	int longitudCancion; //longitud de la canción elegida
}Tmelodia;




void melodias__init();
void actualizarMelodiaSeleccionada(int melodiaSeleccionada);
void resetCancionElegida(void);


/****************************************************************************/
#endif	/* Melodias_h */


