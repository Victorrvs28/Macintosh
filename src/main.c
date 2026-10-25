#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"

static const char *token_type_name(TokenType type)
{
    switch (type)
    {
    case TOKEN_INT_TYPE:
        return "TOKEN_INT_TYPE";
    case TOKEN_VARIABLE_PREFIX:
        return "TOKEN_VARIABLE_PREFIX";
    case TOKEN_IDENTIFIER:
        return "TOKEN_IDENTIFIER";
    case TOKEN_ASSIGN:
        return "TOKEN_ASSIGN";
    case TOKEN_INTEGER_LITERAL:
        return "TOKEN_INTEGER_LITERAL";
    case TOKEN_SEMICOLON:
        return "TOKEN_SEMICOLON";
    case TOKEN_EOF:
        return "TOKEN_EOF";
    case TOKEN_INVALID:
        return "TOKEN_INVALID";
    }

    return "TOKEN_UNKNOWN";
}

int main()
{
    const char *test_string = "int $contador := 42;";
    Lexer lexer;
    lexer_init(&lexer, test_string);

    Token *token;
    while ((token = lexer_next_token(&lexer)) != NULL)
    {
        if (token->type != TOKEN_EOF && token->value == NULL)
        {
            fprintf(stderr, "Erro ao obter o valor do token.\n");
            lexer_free_token(token);
            return EXIT_FAILURE;
        }

        printf("Tipo: %s, Valor: %s\n",
               token_type_name(token->type),
               token->type == TOKEN_EOF ? "<EOF>" : token->value);

        int is_eof = token->type == TOKEN_EOF;
        lexer_free_token(token);
        if (is_eof)
        {
            break;
        }
    }

    if (token == NULL)
    {
        fprintf(stderr, "Erro ao criar token.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}