#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"
#include "parser/parser.h"

int main()
{
  const char* code =    
        "int $contador := 42;\n"
        "\n"
        "int $x := 12;\n"
        "int $counter := 12;\n";
  Parse(code);
    return EXIT_SUCCESS;
}