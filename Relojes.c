//----------------------------------------------------
// Relojes.c
//
// Descripcion:
// Objeto que controla todo lo relacionado con la 
// temporización del juego.
//
// Autores: Daniela Zapata y Jorge Coca
//-----------------------------------------------------

#include "Relojes.h"

#define FREC_INT 8000				  // Frecuencia de interrupción a 8000Hz=8kHz
#define V_BASE 0x40				  // Dirección de inicio de los vectores de interrupción
#define DIR_VTMR0 4*(V_BASE+5)			  // Dirección del vector de TMR0
#define DIR_VTMR1 4*(V_BASE+6)			  // Dirección del vector de TMR1
#define PERIODO_INTERR 2			  // Periodo de interrupción de TMR1
#define CNT_INT1 MCF_CLK/(FREC_INT*0x01*16) 	  // Valor de precarga del temporizador de interrupciones TRR1
#define BORRA_CAP 0x0001			  // Valor de borrado de interr. pendientes de tout1 para TER1
#define BORRA_REF 0x0002			  // Valor de borrado del bit REF.

Trelojes relojes;


//------------------------------------------------------
// void relojes__init(void)
//
// Descripcion:
// función encargada de inicializar las interrupciones y las variables
// del objeto Relojes. Las interrupciones se configuran a 8kHz de
// frecuencia de interrupción, válido para el temporizador 0,
// que será el único usado durante toda la ejecución.
//------------------------------------------------------
void relojes__init(void){
		
        mbar_writeByte(MCFSIM_PIVR,V_BASE); // Fija comienzo de vectores de interrupción en V_BASE.
	ACCESO_A_MEMORIA_LONG(DIR_VTMR0)= (ULONG)_prep_TOUT0; // Escribimos la dirección de la función para TMR0
	mbar_writeShort(MCFSIM_TMR0, 0x003D); // TMR0: PS=0x00 CE=00 OM=1 ORI=1 FRR=1 CLK=10 RST=1
	mbar_writeShort(MCFSIM_TCN0, 0x0000); // Ponemos a 0 el contador del TIMER0
	mbar_writeShort(MCFSIM_TRR0, CNT_INT1); // Fijamos la cuenta final del contador
	mbar_writeLong(MCFSIM_ICR1, 0x8888C888); // Marca la interrupción del TIMER0 como no pendiente
						 // y de nivel 4.
	sti(); //habilita las interrupciones
	relojes.iLedsRefresco=0;
	relojes.iTiempoNota=0;
	relojes.contadorInterrupciones=0;
	relojes.contadorPulsacion=0;
						
}

//------------------------------------------------------
// void relojesReset(void)
//
// Descripción:
// reinicializa las variables del objeto Relojes.
//------------------------------------------------------

void relojesReset(void){
		
	relojes.contadorInterrupciones=0;
	relojes.iLedsRefresco=0;
	relojes.iTiempoNota=0;
	relojes.contadorPulsacion=0;
}