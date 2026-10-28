#include <stdio.h>
#include <stdlib.h>

#include "lexer/lexer.h"
#include "parser/parser.h"
#include "transpiler/transpiler.h"
#define _POSIX_C_SOURCE 200809L

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <arquivo>\n", argv[0]);
        return 1;
    }

    char* file = argv[1];

    if (file == NULL) {
        perror(argv[1]);
        return 1;
    }

    transpileToBash(file);


    return 0;
}
