/****************************************************************************/
#ifndef	Teclas_h
#define	Teclas_h
/****************************************************************************/
//------------------------------------------
// Cabecera de Teclas.h
//
// Autores: Jorge Coca y Daniela Zapata
//------------------------------------------

typedef struct{
	int teclaPulsada; //tecla pulsada durante el modo competición.
	int teclaAcertada;	//flag de acierto de tecla
}TTeclado;
extern TTeclado teclas;

char teclado(void);
int tecladoJuego(void);
void compruebaTeclaAcertada(int teclaPulsada);
void teclas__init(void);
void teclasReset(void);

/****************************************************************************/
#endif	/* Teclas_h */
