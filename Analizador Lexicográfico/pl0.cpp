
#include "pl0.h"
#include "auxiliares.h"
#include "scanner.h"
#include "lexico.h"
#include <iostream>
#include <fstream>
using namespace std;

ofstream fe("algo.txt",ios::trunc);


FILE *fp; //apuntador a archivo conteniendo el programa fuente

//main: inicia el compilador...solo scanner
int main (int argc,char *argv[]) { 

 //verificar si hay archivo fuente
	fp=fopen("codigo.guat","r"); //abrir el fuente solo para lectura
	if (fp==NULL) 
	   printf("\nNo se encontro el programa fuente indicado");
	else {
	     printf("\n\nCompilador de pl0 version 3.0/Solo scanner --- agosto de 2012 --- A2\n");
	     //inicializacion de tokens de s�mbolos especiales (en auxiliares.cpp)
	     inicializar_espec() ; 

	     //inicializacion de otras variables (en scanner.h)
	     ch=' ';
	     fin_de_archivo=0;
	     offset=-1;ll=0;

		 //tokenizar el programa fuente
	     while (1) {
               obtoken();        //en scanner.cpp
               imprime_token();  //en auxiliares.cpp
         }
	 	}
 
 return (0);
}


 

