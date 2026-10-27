







#include "parser/parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>




int Parse(const char *code){
    Lexer lexer;
    lexer_init(&lexer, code);
    Token *token;
loop:
    token = lexer_next_token(&lexer);
    if (token == NULL) {
        fprintf(stderr, "error on creating the token.\n");
        return 1;
    }
    if (token->type == TOKEN_EOF) {
        lexer_free_token(token);
        return 0;
    }
    if (token->type == TOKEN_SEMICOLON) {   /* linha em branco */
        lexer_free_token(token);
        goto loop;
    }
   #include "inc/vardeclare|assign/inc.inc"
    lexer_free_token(token);
    goto loop;
}