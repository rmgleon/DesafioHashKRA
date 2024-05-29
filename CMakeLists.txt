# entrar a build
# cmake ..
# cmake --build .

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(DesafioHashKRA)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(headers)

# Specify the source files
set(SOURCES
    app.c
    arbol_binario.c
    tabla_hash.c
    tabla_hash_mod.c
    arreglo_binario.c
)

# Add the executable
add_executable(DesafioHashKRA ${SOURCES})
