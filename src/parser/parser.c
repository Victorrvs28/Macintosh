










#include "parser/parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>

    //    TOKEN_INT_TYPE,
    //    TOKEN_VARIABLE_PREFIX,
      //  TOKEN_IDENTIFIER,
      //  TOKEN_ASSIGN,
      //  TOKEN_INTEGER_LITERAL,
      //  TOKEN_SEMICOLON,
      //  TOKEN_EOF,
      //  TOKEN_INVALID













#include "parser/parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>

    //    TOKEN_INT_TYPE,
    //    TOKEN_VARIABLE_PREFIX,
      //  TOKEN_IDENTIFIER,
      //  TOKEN_ASSIGN,
      //  TOKEN_INTEGER_LITERAL,
      //  TOKEN_SEMICOLON,
      //  TOKEN_EOF,
      //  TOKEN_INVALID






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
    #include "if/types/int/int.inc"
    else {
        printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
               token->line, token->value ? token->value : "end of file");
        lexer_free_token(token);
        return 1;
    }
}
