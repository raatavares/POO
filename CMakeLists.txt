cmake_minimum_required(VERSION 3.23)
project(POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(POO
        Alimento.cpp
        Alimento.h
        Animal.cpp
        Animal.h
        Coord.cpp
        Coord.h
        main_teste_classes.cpp
        Reserva.cpp
        Reserva.h Coelho.cpp Coelho.h Ovelha.cpp Ovelha.h Lobo.cpp Lobo.h Canguru.cpp Canguru.h Misterio.cpp Misterio.h)
