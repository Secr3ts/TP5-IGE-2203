cmake_minimum_required(VERSION 3.27)
project(TP5 C)

set(CMAKE_C_STANDARD 11)

add_executable(TP5 main.c
        ex1-pointeurs.h
        ex2-min.h
        ex3-permute-simple.h
        ex4-operateurs.h
        ex5-tableau.h)
