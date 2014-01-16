//------------------------------------------------------------------------
// Resultados.c
//
// Descripcion:
// Objeto encargado de calcular los resultados del juego
// y mostrarlos por pantalla.
//
// Autores: Daniela Zapata y Jorge Coca
//------------------------------------------------------------------------


#include "Resultados.h"

Tresultados resultados;


//-----------------------------------------------------------------------------
// void calcularResultados(void)
//
// Descripcion:
// esta funcion calcula los resultados finales del juego (s�lo en modo 
// competici�n).
//-----------------------------------------------------------------------------
void calcularResultados(void){
		//calculamos el porcentaje de aciertos
	resultados.aciertos=(resultados.pulsacionesCorrectas*100)/(resultados.totalNotas);
		//calculamos el porcentaje de eficiencia
	if(resultados.totalPulsaciones==0){ 
		resultados.eficiencia=0;
	}else{
		resultados.eficiencia=(resultados.pulsacionesCorrectas*100)/(resultados.totalPulsaciones);
	}
}	
		
//-----------------------------------------------------------------------------
// void mostrarResultados(void)
//
// Descripcion:
// Funci�n encargada de mostrar el resultado
// por pantalla, en funci�n de los datos obtenidos
// por la funci�n "calcularResultados".
//-----------------------------------------------------------------------------

void mostrarResultados(void){

	if(estado.modoAutomatico==1){
		output("\n \n \r�Por qu� no pruebas ahora el modo Competici�n?\n \n \r");
	}else{
		char teclaRetorno='0';
		calcularResultados();
		output("\n \n \r Resultados finales........\n \n \r");
		output("\n \n \r N�mero total de teclas pulsadas: ");
		outNum(10, resultados.totalPulsaciones, 10);
		output("\n \n \r N�mero de notas acertadas: ");
		outNum(10, resultados.pulsacionesCorrectas, 10);
		output(" de un total de: ");
		outNum(10, resultados.totalNotas, 10);
		output("\n \n \r Tasa de Aciertos = ");
		outNum(10, resultados.aciertos, 10);
		output("%\n \n \r Tasa de Pulsaciones Efectivas = ");
		outNum(10, resultados.eficiencia, 10);
		output("%\n \n \r Fin de la partida. Pulse la tecla A para volver a jugar \n \n \r");
		teclaRetorno=teclado();
		while(teclaRetorno!='A'){
			teclaRetorno=teclado();  //hasta que no se pulse la tecla "A" no salimos de la 
						 //pantalla de resultados
		}
	}
}


//-----------------------------------------------------------------------------
// void resultados__init(void)
//
// Descripcion:
// funci�n que inicializa las variables del objeto resultados
//-----------------------------------------------------------------------------

void resultados__init(void){
	resultados.pulsacionesCorrectas=0;
	resultados.totalPulsaciones=0;
	resultados.totalNotas=0;
	resultados.aciertos=0;
	resultados.eficiencia=0;
	}


//------------------------------------------------------
// void resultadosReset(void)
//
// Descripci�n:
// reinicializa las variables del objeto Resultados
//------------------------------------------------------
void resultadosReset(void){
	resultados.totalPulsaciones=0;
	resultados.pulsacionesCorrectas=0;
	resultados.totalNotas=0;
	resultados.aciertos=0;
	resultados.eficiencia=0;
}