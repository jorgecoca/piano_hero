
/****************************************************************************/
#ifndef	Resultados_h
#define	Resultados_h
/****************************************************************************/

//------------------------------------------------------
// Cabecera de Resultados.h
//
// Autores: Jorge Coca y Daniela Zapata
//------------------------------------------------------

typedef struct{
	int pulsacionesCorrectas;  //contador de pulsaciones correctas durante el modo
				   //competicion
	int totalPulsaciones;	   //contador del total de pulsaciones en modo competici�n
	int totalNotas;		   //variable que guarda el n�mero de teclas de una canci�n
	int eficiencia;		   //medidor de eficiencia 
	int aciertos;		   //medidor del porcentaje de aciertos
	
}Tresultados;

extern Tresultados resultados;
void mostrarResultados(void);
void calcularResultados(void);
void resultados__init(void);
void resultadosReset(void);




/****************************************************************************/
#endif	/* Resultados_h*/
