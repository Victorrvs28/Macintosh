#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"
#include "parser/parser.h"

int main()
{
  const char* code =    
        "contador = 42\n"
        "\n"
        "x = 12\n"
        "counter = 12\n";
  Parse(code);
    return EXIT_SUCCESS;
}