cmake_minimum_required(VERSION 3.10)
project(ListaLigada C)

set(CMAKE_C_STANDARD 99)

# Add all source files
add_executable(ListaLigada main.c ListaLigada.c ListaLigada.h)

# Add debug flags
set(CMAKE_BUILD_TYPE Debug)
lear