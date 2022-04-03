#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
//variable global para almacenar el parametro argv
char* parametro;

//funcion para ejecutar el programa y contar los caracteres
void *Ejecucion(void *param){

    //declaracion de variables necesarias para el funcionamiento
    int fichero, contFichero, caracteres = 0, i = 2;
    char cadena[1000];

    //mientras no se llegue al final del "texto" (parametro argv) esta parte del codigo habrira y leerá hasta 1000 caracteres
    do{
        fichero = open(parametro, 0);

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

    }while(parametro != 0);
    
    std::cout<<cadena<<"\n";
    pthread_exit(0);
}

int main(int argc, char *argv[]){

    if(argc < 2){
        return 0;
    }
    
    int  i = 2;

    pthread_t threads[argc - 1];

    /* Crea todos los hilos */
    for (i=0; i < argc - 1; i++) {
        parametro = argv[i];
        pthread_create(&threads[i], NULL, Ejecucion, argv[i+1]);
    }

    /* Para esperar por el término de todos los hilos */
    for (i=0; i< argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    


    return 0;
}