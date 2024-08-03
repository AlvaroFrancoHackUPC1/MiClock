cmake_minimum_required(VERSION 3.10)
project(MiClock)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Añadir los archivos fuente
set(SOURCES
    src/main.cc
    src/alarm.cc
)

# Crear el ejecutable
add_executable(miclock ${SOURCES})
