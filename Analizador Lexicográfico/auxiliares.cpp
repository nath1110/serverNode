//funciones auxiliares del compilador
#include <stdio.h>
#include <stdlib.h>
#include "pl0.h"
#include "auxiliares.h"
#include "lexico.h"
#include <fstream>
#include <iostream>
using namespace std;
//error: por el momento todo error es fatal          
 int error(int no)
{ 
 printf ("\n^ Error %d: Este numero es demasiado grande",no);
 fclose(fp);//cerrar el programa fuente
 exit(1); //estoy en modo de p�nico...cualquier error es fatal
}

//inicializar_espec
//construcci�n de la tabla de tokens para operadores y s�mboles especiales de pl0
void inicializar_espec()
{
  int i;
  for (i=0;i<=254;++i) 
    espec[i]=nulo;

  espec[42]=por;
  espec[47]=barra;
  espec[40]=parena;
  espec[41]=parenc;
  espec[46]=punto;
  espec[44]=coma;
  espec[59]=puntoycoma;
  espec[123]=llaveI;
  espec[125]=llaveDe;
  espec[37]=modulo;
  espec[91]=corcheI;
  espec[93]=corcheDe;
  espec[34]=comilla;

}

//imprime_token: transforma de enumerado a string. no aparecer� m�s en el compilador
void imprime_token()
{

const char* token_string[]={"nulo","ident","numero","mas","menos","por","barra","igl","nig","mnr","mei","myr","mai","parena","parenc","coma","puntoycoma","llaveI","llaveDe","masmas","menosmenos","modulo","corcheI","corcheDe","comilla","punto","asignacion","inttoken","floattoken","chartoken","booleantoken","stringtoken","arraytoken","vartoken","iftoken","elsetoken","elseiftoken","functiontoken","openfiletoken","readfiletoken","closefiletoken","truetoken","falsetoken","readtoken","printtoken","returntoken","fortoken","whiletoken"};
 printf("(%s) \n",token_string[token]);
 ofstream fs("algo.txt", ios::app);
 fs<<token_string[token]<<endl;
 fs.close();
  
}
