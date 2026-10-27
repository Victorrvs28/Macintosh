cmake_minimum_required(VERSION 3.16)

project(Macintosh
    VERSION 1.0.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SOURCES
    src/main.c
    src/lexer/lexer.c
    src/parser/parser.c
    src/transpiler/transpiler.c
)

add_executable(macintosh ${SOURCES})
target_include_directories(macintosh PRIVATE include)
