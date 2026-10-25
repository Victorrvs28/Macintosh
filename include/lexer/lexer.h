#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>

typedef enum TokenType
{
} TokenType;

typedef struct Token
{
    TokenType type;
    const char *value;
    uint32_t line;
    uint32_t column;
} Token;

typedef struct Lexer
{
    const char *source;
    char *current_char;
    uint32_t position;
    uint32_t line;
    uint32_t column;
} Lexer;

void lexer_init(Lexer *lexer, const char *source);
Token *lexer_next_token(Lexer *lexer);
void lexer_free_token(Token *token);

#endif // LEXER_H
