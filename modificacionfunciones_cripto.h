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

void cifrado_xor(char *file_in,char *file_out,std::string key);
int cifrado_cesar(char *file_in,char *file_out,std::string op);