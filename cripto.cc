/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  * @file funciones_cripto.cc
  * @author Carlos Ravina
  * @date 11 Dec 2020
  * @brief Nos encontramos con un programa 
  *        cuya finalidad será encriptar y / o desencriptar archivos de texto. 
  *        Si el programa se ejecuta sin pasar parámetros en la línea de comandos.
  * @bug No hay bugs conocidos
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include "funciones_cripto.h"

/**
 * Nos encontramos con la función main que es la encargada de ejecutar la práctica.
 */
int main(int argc, char *argv[]){
    
    if(argc < 6 ){
        if(argc == 2){
            std::string help = "--help";
            std::string aux= argv[1];
            if(aux.compare(help) == 0){
                std:: cout << "./cripto -- Cifrado de ficheros \n";
                std:: cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación \n \n";
                std:: cout << "fichero_entrada:  Fichero a codificar \n";
                std:: cout << "fichero_salida:  Fichero codificado \n";
                std:: cout << "método:          Indica el método de encriptado \n";
                std:: cout << "                   1: Cifrado xor \n";
                std:: cout << "                   2: Cifrado de César \n";
                std:: cout << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2 \n";
                std:: cout << "operación:       Operación a realizar en el fichero \n";
                std:: cout << "                   +: encriptar el fichero \n";
                std:: cout << "                   -: desencriptar el fichero \n";
                return 0;
            }else{
                std:: cout << "./cripto -- Cifrado de ficheros \n";
                std:: cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación \n";
                std:: cout << "Pruebe ./ --help para mas información \n";
                return 0;
            }
        }else{
            std:: cout << "./cripto -- Cifrado de ficheros \n";
            std:: cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación \n";
            std:: cout << "Pruebe ./ --help para mas información \n";
            return 0;
        } 
    }
      
        int metodo = atoi(argv[3]);
        std::string op = argv[5];
        std::string key = argv[4];
        FILE *f_in;
        FILE *f_out;


        switch (metodo)
        {
        case 1:
            cifrado_xor(argv[1],argv[2],key);
            break;
        case 2:  
            cifrado_cesar(argv[1],argv[2],op);
            break;
        default:
            std:: cout << "El metodo que has introducido no es correcto \n";
            std:: cout << "Pruebe ./ --help para mas información \n";
            break;
        }
    return 0;
}
