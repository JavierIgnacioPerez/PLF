// Librerias Utilizadas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constantes Definidas.

#define CANTIDAD_COMPONENTES 54
#define LARGO_COMPONENTE 8

//////////////////////////////////////////////////////////////////////////

// Procedimiento que permite verificar los parametros de entrada.
// 0 -> Indica que los parametros son demasiados.
// 1 -> Indica que los parametros son muy pocos.
// 2 -> Indica que falta un parametro.
// 3 -> Indica que el archivo de entrada no existe.
// 4 -> Indica que el archivo de salida ya existe.
// 5 -> Indica que no hay problemas con los parametros de entrada.
// Entrada: Un arreglo de char* (argc) y un entero que representa la cantidad de parametros (argv)
// Salida: Entero que representa el tipo del error.
int verificarParametros(int argc, char *argv[]){

    FILE *archivoEntrada;
    FILE *archivoSalida;

    if(argc == 3){
        
        archivoEntrada = fopen(argv[1],"r");
        archivoSalida = fopen(argv[2],"r");

        if(archivoEntrada == NULL){
            return 3;
        }
        else if(archivoSalida != NULL){
            fclose(archivoSalida);
            return 4;
        }
        else{
            return 5;
        }
    }
    else if(argc > 3){
        return 0;
    }
    else if(argc <= 1){
        return 1;
    }
    else if(argc == 2){
        return 2;
    }
    else{
        return 4;
    }

}

// Procedimiento que dado un identificador de error, imprime el error necesario y retorna un entero que funcionará como bandera.
// 0 -> El programa debe parar su curso.
// 1 -> EL programa puede continuar su curso.
// Entrada: Entero que representa el error.
// Salida: Entero que funciona como bandera para saber si el programa debe seguir su funcionamiento.
int imprimirError(int error){

    if(error == 0){
        printf("Error: Demasiados parámetros.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    if(error == 1){
        printf("Error: Faltan parámetros.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    if(error == 2){
        printf("Error: Falta parámetro.\nUso: lexico.exe archivo_entrada archivo_salida\n\n");
        return 0;
    }
    if(error == 3){
        printf("Error: El archivo de entrada no existe.\n\n");
        return 0;
    }
    if(error == 4){
        printf("Error: El archivo de salida ya existe.\n\n");
        return 0;
    }
    else{
        return 1;
    }
    
}

// Procedimiento que dado un arreglo de char**, rellena dicho arreglo con los compenentes lexicos de largo 1.
// Entrada: Arreglo de char**.
// Salida: Arreglo de char** actualizado
char** crearArregloPalabras(char** arregloPalabras){

    arregloPalabras = (char**)malloc(sizeof(char*) * CANTIDAD_COMPONENTES);
    for(int i = 0 ; i <= LARGO_COMPONENTE; i++){
        arregloPalabras[i] = (char*)malloc(sizeof(char));
    }

    arregloPalabras[0] = "("; 
    arregloPalabras[1] = ")";
    arregloPalabras[2] = "{";
    arregloPalabras[3] = "}";
    arregloPalabras[4] = ",";
    arregloPalabras[5] = ";";
    arregloPalabras[6] = "*";
    arregloPalabras[7] = "=";
    arregloPalabras[8] = ":";
    arregloPalabras[9] = "&";
    arregloPalabras[10] = "-";
    arregloPalabras[11] = "~";
    arregloPalabras[12] = "|";
    arregloPalabras[13] = "<";
    arregloPalabras[14] = ">";
    arregloPalabras[15] = "!";
    arregloPalabras[16] = "?";
    arregloPalabras[17] = "";
    arregloPalabras[18] = "+";
    arregloPalabras[19] = "/";
    arregloPalabras[20] = "%";
    arregloPalabras[21] = "^";
    arregloPalabras[22] = "do";
    arregloPalabras[23] = "if";
    arregloPalabras[24] = "==";
    arregloPalabras[25] = "!=";
    arregloPalabras[26] = "<=";
    arregloPalabras[27] = ">=";
    arregloPalabras[28] = "&&";
    arregloPalabras[29] = "||";
    arregloPalabras[30] = ">>";
    arregloPalabras[31] = "<<";
    arregloPalabras[32] = "++";
    arregloPalabras[33] = "--";
    arregloPalabras[34] = "main";
    arregloPalabras[35] = "else";
    arregloPalabras[36] = "goto";
    arregloPalabras[37] = "long";
    arregloPalabras[38] = "float";
    arregloPalabras[39] = "char";
    arregloPalabras[40] = "auto";
    arregloPalabras[41] = "while";
    arregloPalabras[42] = "break";
    arregloPalabras[43] = "double";
    arregloPalabras[44] = "short";
    arregloPalabras[45] = "default";
    arregloPalabras[46] = "continue";
    arregloPalabras[47] = "return";
    arregloPalabras[48] = "sizeof";
    arregloPalabras[49] = "unsigned";
    arregloPalabras[50] = "extern";
    arregloPalabras[51] = "register";
    arregloPalabras[52] = "static";
    arregloPalabras[53] = "for";
    arregloPalabras[54] = "int";

    return arregloPalabras;

}

// Procedimiento que permite leer el archivo de texto y guardar la cantidad de palabras que posee.
// Entrada: char* que representa el nombre del archivo de entrada y un entero que contendra la cantidad de palabras en el archivo.
// Salida: int actualizado con la información de la cantidad de palabras.
int leerCantidadPalabras(char* fileName, int cantidadPalabras){
    
    FILE* file;
    cantidadPalabras = 0;
    char wordAux[50];
    
    file = fopen(fileName,"r");
    while(!feof(file)){
        fscanf(file," %[^ \n]",wordAux);
        cantidadPalabras += 1;
    }  
    fclose(file);

    return cantidadPalabras;
    
}

// Procedimiento que dado un char*, retorna dicho char* pero en mayusculas.
// Entrada: Char* que representa la palabra que se quiere poner en mayusculas.
// Salida: Char* en mayuscula.
char* aMayuscula(char* palabra){
    int contador = 0;
   
    while (palabra[contador] != '\0') {
        if (palabra[contador] >= 'a' && palabra[contador] <= 'z') {
            palabra[contador] = palabra[contador] - 32;
        }
        contador++;
    }

    return palabra;
}

// Procedimiento que calcula el factorial dado un numero.
// Entrada: Un entero.
// Salida: Un entero que representa el factorial del numero ingresado como parametro.
int factorial(int numero){
    int count = 1;
    while(numero != 0){
        count = numero * count;
        numero -= 1;
    } 
    return count;
}

// Procedimiento que dado un char*, el array de los componentes lexicos, verifica si dicho char* está dentro de los componentes.
// En caso de estar en los componentes lexicos, se escribira en el archivo de salida.
// Entrada: char* que es el string que se busca dentro de los componentes, char** que representa a los componentes lexicos.
// Salida: Vacia.
void escribirArchivo(char* palabra, char** componentesLexicos,FILE* fileSalida){

    for(int i = 0; i <= CANTIDAD_COMPONENTES; i++){
        if(strcmp(palabra,componentesLexicos[i]) == 0 && strcmp(palabra,"") != 0){
            if(strlen(palabra) == 1){
                fputs(palabra,fileSalida);
                fputs("\n",fileSalida);
            }
            else{
                fputs(aMayuscula(palabra),fileSalida);
                fputs("\n",fileSalida);
            }
        }
    }
}

// Procedimiento que dado un char*, retorna un char** que contiene todas las posibles palabras contenidas en dicho string.
// Entrada: char* printf("%s\n",palabraAux2);que representa el string con el que se trabajara.
// Salida: char* que representa las posibles palabras que contiene dicho string.
void subPalabras(char* palabra, char** componentesLexicos, FILE* fileSalida){

    int contadorLargo;
    int fact;
    char* palabraAux = (char*)malloc(sizeof(char) * 100);
    char* palabraAux2 = (char*)malloc(sizeof(char) * 100);

    for(contadorLargo = 0; palabra[contadorLargo] != '\0'; contadorLargo++);
    fact = factorial(contadorLargo);

    strcpy(palabraAux,palabra);
    strcpy(palabraAux2,palabraAux);

    for(int j = 0; j < contadorLargo; j++){
        strcpy(palabraAux2,palabraAux);
        for(int i = j; i < contadorLargo; i++){
            palabraAux2[contadorLargo - i] = 0;
            if(strlen(palabraAux2) == 1){
                escribirArchivo(palabraAux2,componentesLexicos,fileSalida);
                palabraAux2++;
            }
            else{
                if(strcmp(palabraAux2,"") != 0){
                    escribirArchivo(palabraAux2,componentesLexicos,fileSalida);
                }
                if(strcmp(palabraAux2,"==") == 0 || strcmp(palabraAux2,"!=") == 0 || strcmp(palabraAux2,"<=") == 0 || strcmp(palabraAux2,">=") == 0 || strcmp(palabraAux2,"&&") == 0 || strcmp(palabraAux2,"||") == 0 || strcmp(palabraAux2,">>") == 0 || strcmp(palabraAux2,"<<") == 0 || strcmp(palabraAux2,"++") == 0 || strcmp(palabraAux2,"--") == 0){
                    palabraAux++;
                    break;
                }
            }
        }
        palabraAux++;
    }
    
    palabraAux[0] = 0;
    palabraAux2[0] = 0;

}

// Procedimiento que permite leer el archivo de texto y guardar su contenido.
// Entrada: char* que representa el nombre del archivo de entrada, char** en donde se guardará la información del archivo de entrada y un entero que representa la cantidad de palabras.
// Salida: char** actualizado con la información del archivo de entrada.
void leerPalabras(char* archivoEntrada, char* archivoSalida, int cantidadPalabras, char** componentesLexicos){
    
    FILE* fileEntrada;
    FILE* fileSalida;
    char wordAux[50];
    char* palabra;
    
    fileEntrada = fopen(archivoEntrada,"r");
    fileSalida = fopen(archivoSalida,"wt");

    while(!feof(fileEntrada)){
        fscanf(fileEntrada," %[^\n]",wordAux);
        palabra = strtok (wordAux," ");
        while (palabra != NULL){
            subPalabras(palabra,componentesLexicos,fileSalida);
            palabra = strtok (NULL, " ");
        }
    } 

    fclose(fileEntrada);
    fclose(fileSalida);
}

//Procedimiento Main que da el inicio al programa.
//Entrada: Vacia.
//Salida: Entero 0 que representa que se termino la ejecucion del programa.
int main(int argc, char *argv[]){

    int error;
    int bandera;
    int cantidadPalabras;
    char** arregloPalabras;
    
    error = verificarParametros(argc,argv);
    bandera = imprimirError(error);

    if(bandera == 1){
        
        arregloPalabras = crearArregloPalabras(arregloPalabras);
        cantidadPalabras = leerCantidadPalabras(argv[1],cantidadPalabras);
        leerPalabras(argv[1],argv[2],cantidadPalabras,arregloPalabras);
    }

    return 0;
}
