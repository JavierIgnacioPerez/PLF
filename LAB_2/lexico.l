%{
int componentes = 0;
%}

%option noyywrap

%%

[ \n\t]+ {fprintf(yyout, "");}
"(" {fprintf(yyout,"(\n");}
")" {fprintf(yyout,")\n");}
"{" {fprintf(yyout,"{\n");}
"}" {fprintf(yyout,"}\n");}
"," {fprintf(yyout,",\n");}
";" {fprintf(yyout,";\n");}
"*" {fprintf(yyout,"*\n");}
"=" {fprintf(yyout,"=\n");}
":" {fprintf(yyout,":\n");}
"&" {fprintf(yyout,"&\n");}
"-" {fprintf(yyout,"-\n");}
"~" {fprintf(yyout,"~\n");}
"|" {fprintf(yyout,"|\n");}
"<" {fprintf(yyout,"<\n");}
">" {fprintf(yyout,">\n");}
"!" {fprintf(yyout,"!\n");}
"?" {fprintf(yyout,"?\n");}
"+" {fprintf(yyout,"+\n");}
"/" {fprintf(yyout,"/\n");}
"%" {fprintf(yyout,"%s\n",yytext);}
"^" {fprintf(yyout,"^\n");}
"do" {fprintf(yyout,"DO\n");}
"if" {fprintf(yyout,"IF\n");}
"==" {fprintf(yyout,"==\n");}
"!=" {fprintf(yyout,"!=\n");}
"<=" {fprintf(yyout,"<=\n");}
">=" {fprintf(yyout,">=\n");}
"&&" {fprintf(yyout,"&&\n");}
"||" {fprintf(yyout,"||\n");}
">>" {fprintf(yyout,">>\n");}
"<<" {fprintf(yyout,"<<\n");}
"++" {fprintf(yyout,"++\n");}
"--" {fprintf(yyout,"--\n");}
"for" {fprintf(yyout,"FOR\n");}
"int" {fprintf(yyout,"INT\n");}
"main" {fprintf(yyout,"MAIN\n");}
"else" {fprintf(yyout,"ELSE\n");}
"goto" {fprintf(yyout,"GOTO\n");}
"long" {fprintf(yyout,"LONG\n");}
"char" {fprintf(yyout,"CHAR\n");}
"auto" {fprintf(yyout,"AUTO\n");}
"while" {fprintf(yyout,"WHILE\n");}
"break" {fprintf(yyout,"BREAK\n");}
"short" {fprintf(yyout,"SHORT\n");}
"float" {fprintf(yyout,"FLOAT\n");}
"return" {fprintf(yyout,"RETURN\n");}
"sizeof" {fprintf(yyout,"SIZEOF\n");}
"extern" {fprintf(yyout,"EXTERN\n");}
"static" {fprintf(yyout,"STATIC\n");}
"double" {fprintf(yyout,"DOUBLE\n");}
"default" {fprintf(yyout,"DEFAULT\n");}
"continue" {fprintf(yyout,"CONTINUE\n");}
"unsigned" {fprintf(yyout,"UNSIGNED\n");}
"register" {fprintf(yyout,"REGISTER\n");}
. {;}

%%

int main(int argc, char *argv[])
{

    FILE *archivoEntrada;
    FILE *archivoSalida;

    if(argc == 3){
        
        archivoEntrada = fopen(argv[1],"r");
        archivoSalida = fopen(argv[2],"r");

        if(archivoEntrada == NULL){
            printf("Error: El archivo de entrada no existe.\n");
            return 0;
        }
        else if(archivoSalida != NULL){
            fclose(archivoSalida);
            printf("Error: El archivo de salida ya existe.\n");
            return 0;
        }
        else{

            archivoSalida = fopen(argv[2],"w");

            yyin = archivoEntrada;
            yyout = archivoSalida;

            yylex();
            
            fclose(yyin);
            fclose(yyout);

            return 0;
        }
    }
    else if(argc > 3){
        printf("Error: Demasiados parametros.\nUso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    else if(argc <= 1){
        printf("Error: Faltan parametros.\nUso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    else{
        printf("Error: Falta parametro.\nUso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
}