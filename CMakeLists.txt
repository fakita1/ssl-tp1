cmake_minimum_required(VERSION 3.21)
project(ssl_tp1 C)

set(CMAKE_C_STANDARD 99)

add_executable(ssl_tp1 main.c main.h decimal.h decimal.c esPalabra.h esPalabra.c octal.h hexa.h hexa.c octal.c charToInt.c charToInt.h esOperacionValida.h esOperacionValida.c realizarOperacion.c realizarOperacion.h)
