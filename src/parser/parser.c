










#include "parser/parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>

int Parse(){
     const char *test_string =  "int $contador := 42;str $x = y;";
    Lexer lexer;
    lexer_init(&lexer, test_string);

     Token *token;
    while ((token = lexer_next_token(&lexer)) != NULL)
    {
    
        int is_eof = token->type == TOKEN_EOF;
        lexer_free_token(token);
        if (is_eof)
        {
            break;
        }
    }

    if (token == NULL)
    {
        fprintf(stderr, "error on creating the token.\n");
        return 1;
    }
return 0;
}