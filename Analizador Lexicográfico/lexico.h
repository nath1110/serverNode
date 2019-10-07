#include "parametros.h"

//lexemes de las palabras reservadas
extern const char *lexpal[MAXPAL];

//lista de tokens de pl0
enum simbolo {nulo,ident,numero,mas,menos,por,barra,igl,nig,mnr,mei,myr,mai,parena,parenc,coma,puntoycoma,llaveI,llaveDe,masmas,menosmenos,modulo,corcheI,corcheDe,comilla,	          punto,asignacion,inttoken,floattoken,chartoken,booleantoken,stringtoken,arraytoken,vartoken,iftoken,elsetoken,elseiftoken,functiontoken,openfiletoken,readfiletoken,closefiletoken,truetoken,falsetoken,readtoken,printtoken,returntoken,fortoken,whiletoken}; //definido aquí en el encabezado

extern enum simbolo token;

//tabla de tokens de palabras reservadas
extern enum simbolo tokpal [MAXPAL]; 

//tabla de tokens correspondientes a operadores y símbolos especiales
extern enum simbolo espec[255] ;
