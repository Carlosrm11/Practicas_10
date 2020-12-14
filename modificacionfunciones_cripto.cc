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
#include "modificacionfunciones_cripto.h"

/**
 * Función para realizar el cifrado xor.
 */

void cifrado_xor(char *file_in,char *file_out,std::string key){
    FILE *f_in;
    FILE *f_out;
    int dato=0;
    int dato_k=0;
    int i= 0;

    if((f_in=fopen(file_in,"rb")) == NULL){
        perror(file_in);
        return ;
    }
    f_out=fopen(file_out,"wb");

    fread(&dato,sizeof(int),1,f_in);

    while(!feof(f_in)){
        dato_k =key[i]^0x80;
        dato=dato^dato_k; // XOR con todos 128 (80 en hexadecimal)
        fwrite(&dato,sizeof(int),1,f_out);
        fread(&dato,sizeof(int),1,f_in);
        if(i<key.size()){
            i++;
        }else{
            i=0;
        }
    }
    fclose(f_in);
    fclose(f_out);

    return;
}

int cifrado_cesar(char *file_in,char *file_out,std::string op){

    FILE *f_in;
    FILE *f_out;
    char c;
    int it=0;
    int k = 3;
    int letras=0;
    int palabras=0;

    if((f_in=fopen(file_in,"r")) == NULL){
        perror(file_in);
        return -1;
    }
    f_out=fopen(file_out,"w");

    fread(&c,sizeof(char),1,f_in);

    while(!feof(f_in)){

        if(op.compare("+") == 0){
            if(c == ' ' || c== '\n'){
                palabras ++;
            }
            c = c + k;
            
        }else{
            c = c - k;
            if(c == ' ' || c== '\n'){
                palabras ++;
            }
        }
        
        fwrite(&c,sizeof(char),1,f_out);
        fread(&c,sizeof(char),1,f_in);
    }
    fclose(f_in);
    fclose(f_out);
    return palabras;
}

