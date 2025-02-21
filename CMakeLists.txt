cmake_minimum_required(VERSION 3.27)
project(tema3)

set(CMAKE_CXX_STANDARD 17)

add_executable(tema3 main.cpp
        spectacol.h
        circ.h
        opera.h
        teatru.h
        Spectator.h
        verificare_pofte_exigente.h
)
