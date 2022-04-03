#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]){

    if(argc < 2){
        return 0;
    }

    //declaracion de variables necesarias para el funcionamiento
    char cadena[1000];
    int fichero, contFichero, caracteres = 0, i = 2;

    //mientras no se llegue al final del "texto" (parametro argv) esta parte del codigo habrira y leerá hasta 1000 caracteres
    do{
        fichero = open(argv[i], 0);

        //en caso de no encontrar la ruta del texto se emitirá un error
        if(fichero == -1){
            perror("Error no hay nada que leer");
            exit(EXIT_FAILURE);
        }

        while(caracteres != 0){
            caracteres = read(fichero, cadena, 1000);
        }

        //mostramos la cantidad de caracteres y el numero del texto
        std::cout<<"fichero: " <<i<<"\n";
        std::cout<<"caracteres: "<<caracteres<<"\n";
        
        //cerramos todo para finalizar
        close(fichero);
        cadena[1000] = 0;
        i++;

    }while(argv[i] != 0);
    
    std::cout<<cadena<<"\n";


    return 0;
}


