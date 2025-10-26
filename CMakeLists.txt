cmake_minimum_required(VERSION 4.0)
project(Snake C)

set(CMAKE_C_STANDARD 11)

add_executable(Snake main.c
        src/grafica.c
        src/mappa.c
        src/serpente.c)

# include il file di risorse Windows (.rc) per incorporare icona e informazioni di versione nell'eseguibile finale
set_source_files_properties(resources/resource.rc PROPERTIES LANGUAGE RC)
target_sources(Snake PRIVATE resources/resource.rc)

# aggiunge la cartella degli header ai search paths
target_include_directories(Snake PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)