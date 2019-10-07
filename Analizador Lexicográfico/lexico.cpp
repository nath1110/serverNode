#include "lexico.h"


//se define e inicializa la tabla de lexemes correspondientes a las palabras reservadas
const char* lexpal[MAXPAL]={"INT","FLOAT","CHAR","BOOLEAN","STRING","ARRAY","VAR","IF","ELSE","ELSEIF","FUNCTION","OPENFILE","READFILE","CLOSEFILE","TRUE","FALSE","READ","PRINT","RETURN","FOR","WHILE"};

//el token
enum simbolo token;

//se define e inicializa la tabla de tokens de palabras reservadas
enum simbolo tokpal[MAXPAL]={arraytoken,booleantoken,chartoken,closefiletoken,elsetoken,elseiftoken,falsetoken,floattoken,fortoken,functiontoken,iftoken,inttoken,openfiletoken,printtoken,readtoken,readfiletoken,returntoken,stringtoken,truetoken,vartoken,whiletoken};

//tabla de tokens correspondientes a operadores y símbolos especiales
enum simbolo espec[255] ;
