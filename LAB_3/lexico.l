%{
#include "sintactico.tab.h"
%}

%option yylineno
%option noyywrap

ENTERO [0-9]+
EXPONENTE \E("+"|"-")?{entero}
REAL {entero}*\.{entero}*{exponente}*
IDENTIFICADOR ("_"([a-zA-Z]|[0-9])*|[a-zA-Z]([a-zA-Z]|[0-9])*)
CARACTER \'.\'
CADENA \"(.)+\" 

%%

\n {;}
(\t|" ")* {;}
"(" {return PIZQUIERDO;}
")" {return PDERECHO;}
"{" {return LLIZQUIERDA;}
"}" {return LLDERECHA;}
"," {return COMA;}
";" {return PUNTOCOMA;}
"*" {return ASTERISCO;}
"=" {return IGUAL;}
":" {return DOSPUNTO;}
"&" {return AMPERSAN;}
"-" {return MENOS;}
"~" {return CONGRUENTE;}
"|" {return BARRA;}
"<" {return MENOR;}
">" {return MAYOR;}
"!" {return NEGACION;}
"?" {return PERTENECE;}
"+" {return SUMA;}
"/" {return DIVISION;}
"%" {return RESTO;}
"^" {return EXPONENTE;}
"do" {return DO;}
"if" {return IF;}
"==" {return COMPARACION;}
"!=" {return DISTINTO;}
"<=" {return MENORIGUAL;}
">=" {return MAYORIGUAL;}
"&&" {return Y;}
"||" {return O;}
">>" {return SIGUIENTE;}
"<<" {return ANTERIOR;}
"++" {return AUTOINCREMENTO;}
"--" {return AUTODECREMENTO;}
"for" {return FOR;}
"int" {return INT;}
"main" {return MAIN;}
"else" {return ELSE;}
"goto" {return GOTO;}
"long" {return LONG;}
"char" {return CHAR;}
"auto" {return AUTO;}
"while" {return WHILE;}
"break" {return BREAK;}
"short" {return SHORT;}
"float" {return FLOAT;}
"return" {return RETURN;}
"sizeof" {return SIZEOF;}
"extern" {return EXTERN;}
"static" {return STATIC;}
"double" {return DOUBLE;}
"default" {return DEFAULT;}
"continue" {return CONTINUE;}
"unsigned" {return UNSIGNED;}
"register" {return REGISTER;}
"ENTERO" {return ENTERO;}
"EXPONENTE" {return EXPONENTE;}
"REAL" {return REAL;}
"IDENTIFICADOR" {return IDENTIFICADOR;}
"CARACTER" {return CARACTER;}
"CADENA" {return CADENA;}
. {return CARACTER;}

%%