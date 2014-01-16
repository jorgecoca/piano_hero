/****************************************************************************/
#ifndef	Estado_h
#define	Estado_h
/****************************************************************************/

//--------------------------------------------
// Cabecera de Estado.h
//
// Autores: Jorge Coca y Daniela Zapata
//--------------------------------------------


typedef struct {

	int reproduciendo;  //flag que se activa cuando comienza el juego
	int modoAutomatico; //opcion modo automatico
	int modoCompeticion; //opcion modo competicion
	
} Estado;

extern Estado estado;


void estado__init(void);
void cancion(char tecla);
void nivel(char tecla2);
void aplicarNivel(int dificultad);
void menus(void);
void softwareReset(void);
void estadoReset(void);


/****************************************************************************/
#endif	/* Estado_h*/
