#ifndef LEXER_H
#define LEXER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum TokenType
{
    TOKEN_INT_TYPE,
    TOKEN_VARIABLE_PREFIX,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN,
    TOKEN_INTEGER_LITERAL,
    TOKEN_SEMICOLON,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

typedef struct Token
{
    TokenType type;
    char *value;
    uint32_t line;
    uint32_t column;
    uint32_t start;
    uint32_t end;
} Token;

typedef struct Lexer
{
    const char *source;
    char current_char;
    uint32_t position;
    uint32_t line;
    uint32_t column;
} Lexer;

void lexer_init(Lexer *lexer, const char *source);
Token *lexer_next_token(Lexer *lexer);
void lexer_free_token(Token *token);

#ifdef __cplusplus
}
#endif

#endif
