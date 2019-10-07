//el analizador lexicogr�fico de pl0
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "scanner.h"
#include "pl0.h"
#include "lexico.h"
#include "auxiliares.h"


int indiceDeLaMitad;
const char* temp;

int busquedaBinariaRecursiva(const char* arreglo[], char busqueda[], int izquierda, int derecha){
    if (izquierda > derecha) return -1;
    indiceDeLaMitad = floor((izquierda + derecha) / 2);
    //printf("(%i) \n",indiceDeLaMitad);
    const char *elementoDeLaMitad = arreglo[indiceDeLaMitad];
 
    int resultadoDeLaComparacion = strcmp(busqueda, elementoDeLaMitad);
 
    // Si son iguales hemos encontrado el elemento
    if (resultadoDeLaComparacion == 0) {
        token=tokpal[indiceDeLaMitad]; //es palabra reservada
       //printf("(%i) \n",indiceDeLaMitad);
	return indiceDeLaMitad; }
    else
       	token=ident; //es identificador
 
    // Si no, vemos en cuál mitad podría estar
 
    // ¿A la izquierda?
    if (resultadoDeLaComparacion < 0){
        derecha = indiceDeLaMitad - 1;
    }else{
        // A la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    // Recursión justo aquí
    busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

char linea[MAXLINEA];     //buffer de l�neas 
int ll;                   //contador de caracteres
int offset;               //corrimiento en la lectura de los caracteres del programa fuente
int fin_de_archivo;       //bandera de fin de archivo (obtch)   
int ch;                   //�ltimo caracter le�do
char lex[MAXID+1];        //�ltimo lexeme le�do ( +1 para colocar "\0")
long int valor ;          //valor num�rico de una lexeme correspondiene a un n�mero

int obtch(),getline(char s[],int lim); //funciones internas a scanner.cpp

//obtoken: obtiene el siguiente token del programa fuente                   
void obtoken()
{
 char lexid[MAXID+1]; //+1 para colocar el marcador "\0"
 int i;

 //quitar blancos, caracter de cambio de l�nea y tabuladores
 while (ch==' ' || ch=='\n' || ch=='\t') ch=obtch() ;

 //si la lexeme comienza con una letra, es identificador o palabra reservada
 if (isalpha(ch)) {
    lexid[0]=ch;
    i=1;
    while ( isalpha( (ch=obtch()) ) ||  isdigit(ch)   ) 
      if (i<MAXID) lexid[i++]=ch;
    lexid[i]='\0';
  
    //�es identificador o palabra reservada?.buscar en la tabla de palabras reservada
   
     int result;    	
     for ( int pass = 0; pass < MAXPAL - 1 ; ++pass ){	
	for ( int j = 0; j < MAXPAL - 1 - pass; ++j ){		
		result = strcmp (lexpal[j], lexpal[j+1]);		
		if (result > 0)		   
			{temp = lexpal[j];
	                lexpal[j] = lexpal[j+1];
	                lexpal[j+1] = temp;}}}
   	

   busquedaBinariaRecursiva(lexpal,lexid,0,MAXPAL-1);
    strcpy(lex,lexid); //copiar en lex}
 }
 else //si comienza con un d�gito...
    if (isdigit(ch)) {
       lexid[0]=ch;
       i=indiceDeLaMitad=1;
       while ( isdigit( (ch=obtch()))) {
	         if (i<MAXDIGIT) lexid[i++]=ch;
	         indiceDeLaMitad++;
       }
       lexid[i]='\0';
       if (indiceDeLaMitad>MAXDIGIT)
          error(30); //este n�mero es demasiado grande
       token=numero;
       valor=atol(lexid); //valor num�rico de una lexeme correspondiene a un n�mero	        
    }
    else //reconocimiento de s�mbolos especiales, incluyendo pares de simbolos (aplicamos "lookahead symbol technique")
       if (ch=='<') {
          ch=obtch();
          if (ch=='=') {
             token=mei;
             ch=obtch();
          }
          else
             if (ch=='>') {
                token=nig;
                ch=obtch();
             }
             else
                token=mnr;
       }
       else
          if (ch=='>') {
             ch=obtch();
             if (ch=='=') {
                token=mai;
                ch=obtch();
             }
             else 
                token=myr;
          }
          else 
             if (ch=='=') {
                ch=obtch();
                if (ch=='=') {
	               token=igl;
	               ch=obtch();
                }
               else
	               token=asignacion;
             }
	  else
             if (ch=='+') {
                ch=obtch();
                if (ch=='+') {
                    token=masmas;
                    ch=obtch();
             }
                else 
                   token=mas;}
	  else
             if (ch=='-') {
                ch=obtch();
                if (ch=='-') {
                    token=menosmenos;
                    ch=obtch();
             }
                else 
                   token=menos;}
             else {
                token=espec[ch]; //hashing directo en la tabla de tokens de s�mbolos especiales del lenguaje
                ch=obtch();
             }
}

//obtch: obtiene el siguiente caracter del programa fuente
int obtch()
{ 

 if (fin_de_archivo==1) {
	fclose(fp);//cerrar el programa fuente
    printf("Analisis lexicografico finalizado.");
    exit(1); //salir...
 }
  
 if (offset==ll-1) {
    ll=getline(linea,MAXLINEA); //trae una l�nea del programa fuente al buffer de l�neas
    if (ll==0) 	   
       fin_de_archivo=1; //se retrasa en un blanco la deteccion de EOF, porque obtoken lleva un caracter adelantado. si no, en 
						 //algunos casos tendr�amos problemas, por ejemplo: no se reconoceria el punto final del programa (...end.)

    printf("\n%s",linea);
    offset=-1;
 }

 ++offset;

 if ( (linea[offset]=='\0') || (fin_de_archivo==1) )   
    return(' '); 
 else  
    return(toupper(linea[offset])); //de esto depende si el lenguaje es sensitivo de may�sculas o no.

}

//getline: lee la siguiente l�nea del fuente y regresa su tama�o (incluyendo '\n') o 0 si EOF. (por ejemplo: para VAR regresa 4)
//es probablemente la rutina de m�s bajo nivel del compilador
//tomada de "El Lenguaje de programaci�n C" - Kernighan & Ritchie - pag 28                        
int getline(char s[],int lim)
{
 int c,i;

 for (i=0;i<lim-1 && (c=getc(fp))!=EOF && c!='\n';++i)
     s[i]=c;

 if (c=='\n') {
    s[i]=c;
    ++i;
 }

 s[i]='\0';
 return (i);
}


