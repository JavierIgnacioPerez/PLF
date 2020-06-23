%{
#include <stdio.h>
#include <stdlib.h> 
extern int yylineno; 
extern FILE* yyin;
extern int yylex () ;
void yyerror(char *s);
%}

%token PIZQUIERDO
%token PDERECHO
%token LLIZQUIERDA
%token LLDERECHA
%token COMA
%token PUNTOCOMA
%token ASTERISCO
%token IGUAL
%token DOSPUNTO
%token AMPERSAN
%token MENOS
%token CONGRUENTE
%token BARRA
%token MENOR
%token MAYOR
%token NEGACION
%token PERTENECE
%token SUMA
%token DIVISION
%token RESTO
%token EXPONENTE
%token DO
%token IF
%token COMPARACION
%token DISTINTO
%token MENORIGUAL
%token MAYORIGUAL
%token Y
%token O
%token SIGUIENTE
%token ANTERIOR
%token AUTOINCREMENTO
%token AUTODECREMENTO
%token FOR
%token INT
%token MAIN
%token ELSE
%token GOTO
%token LONG
%token CHAR
%token AUTO
%token WHILE
%token BREAK
%token SHORT
%token FLOAT
%token RETURN
%token SIZEOF
%token EXTERN
%token STATIC
%token DOUBLE
%token DEFAULT
%token CONTINUE
%token UNSIGNED
%token REGISTER
%token CARACTER
%token REAL
%token ENTERO
%token CADENA
%token IDENTIFICADOR

%%
aux: operador_binario | esp_alm_var;
operador_binario: operador_unario | operador_relacional | operador_aritmetico | operador_logico | operador_nivel_bit;
operador_unario: cast | operador_incremento | operador_decremento | ASTERISCO | AMPERSAN | MENOS | CONGRUENTE | BARRA;
operador_incremento: AUTOINCREMENTO;
operador_decremento: AUTODECREMENTO;
operador_nivel_bit: EXPONENTE | ANTERIOR | SIGUIENTE;
operador_aritmetico: SUMA | DIVISION | RESTO;
operador_logico: Y | O | NEGACION;
operador_relacional: COMPARACION | DISTINTO | MENOR | MAYOR | MENORIGUAL | MAYORIGUAL;
tipo: INT | SHORT tipo_aux1 | UNSIGNED tipo_aux1 | LONG tipo_aux2 | FLOAT | CHAR | DOUBLE ;
tipo_aux1: INT | ;
tipo_aux2: INT | FLOAT | ;
cast: PIZQUIERDO tipo PDERECHO;
esp_alm_var: AUTO | EXTERN | REGISTER | STATIC;


%%

void yyerror(char *s)
{
printf("Error sint%cctico en la l%cnea: %i\n",160,161,yylineno);
exit(1);
}

int main(int argc, char *argv[])
{
    
    FILE *archivoEntrada;

    if(argc == 2){
        
        archivoEntrada = fopen(argv[1],"r");

        if(archivoEntrada == NULL){
            printf("Error: El archivo no existe.\n");
            return 0;
        }
        else{
            yyin = archivoEntrada;

            yyparse();
            
            fclose(yyin);
            printf("An%clisis sint%cctico finalizado.\n,160,160");
            return 0;
        }
    }
    else if (argc > 2){
        printf("Error: Demasiados par%cmetros.\nUso: sintactico.exe archivo\n",160);
        return 0;
    }
    else{
        printf("Error: Falta par%cmetro.\nUso: sintactico.exe archivo\n",160);
        return 0;
    }
    
    
    yyparse();
}