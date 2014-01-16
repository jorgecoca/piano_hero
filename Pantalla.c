//--------------------------------------------------------------
// Pantalla.c 
//
// Descripción:
// Objeto encargado de sacar el mensaje de bienvenida al 
// Piano Hero
//
// Autores: Jorge Coca Ramos y Daniela Zapata Riesco.
//---------------------------------------------------------------

#include "Pantalla.h"

//------------------------------------------------------
// void mensajeBienvenida(void)
//
// Descripcion:
// Función encargada mostrar por pantalla
// el mensaje de bienvenida al juego al inicializar
// el Coldfire.
//------------------------------------------------------


void mensajeBienvenida(void){

	output("Bienvenido a.........\n \n \r");      		
	output("\n \n \r
                                                                 
		P)ppppp  I)iiii   A)aa   N)n   nn  O)oooo  
		P)    pp   I)    A)  aa  N)nn  nn O)    oo 
		P)ppppp    I)   A)    aa N) nn nn O)    oo 
		P)         I)   A)aaaaaa N)  nnnn O)    oo 
		P)         I)   A)    aa N)   nnn O)    oo 
		P)       I)iiii A)    aa N)    nn  O)oooo  
                                           
                                           
		H)    hh E)eeeeee R)rrrrr   O)oooo     X)    xx T)tttttt         7)&&&&& 
		H)    hh E)       R)    rr O)    oo     X)  xx     T)                7)  
		H)hhhhhh E)eeeee  R)  rrr  O)    oo      X)xx      T)               7)   
		H)    hh E)       R) rr    O)    oo      X)xx      T)    #######   7)    
		H)    hh E)       R)   rr  O)    oo     X)  xx     T)             7)     
		H)    hh E)eeeeee R)    rr  O)oooo     X)    xx    T)            7)      
                                                                         

 		\n \n \r");
	output("\n \n \r ¿Estás preparado? \n \n \r");
}