#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer/lexer.h"

static const struct
{
    const char *text;
    TokenType type;
} keywords[] = {
    {"int", TOKEN_INT_TYPE},
};

static void lexer_advance(Lexer *lexer)
{
    if (lexer->current_char == '\n')
    {
        lexer->line++;
        lexer->column = 0;
    }
    else
    {
        lexer->column++;
    }
    lexer->position++;
    lexer->current_char = lexer->source[lexer->position];
}

static void lexer_skip_whitespace(Lexer *lexer)
{
    while (isspace((unsigned char)lexer->current_char) && lexer->current_char != '\n')
    {
        lexer_advance(lexer);
    }
}

static char *lexer_strdup_range(const char *source, size_t start, size_t length)
{
    char *value = (char *)malloc(length + 1);
    if (value == NULL)
        return NULL;
    memcpy(value, source + start, length);
    value[length] = '\0';
    return value;
}

static Token *lexer_create_token(Lexer *lexer, TokenType type)
{
    Token *token = (Token *)malloc(sizeof(Token));
    if (token == NULL)
        return NULL;
    token->type = type;
    token->value = NULL;
    token->line = lexer->line;
    token->column = lexer->column;
    token->start = lexer->position;
    token->end = lexer->position;
    return token;
}

static Token *lexer_get_identifier(Lexer *lexer)
{
    size_t start_position = lexer->position;
    Token *token = lexer_create_token(lexer, TOKEN_IDENTIFIER);
    if (token == NULL)
        return NULL;

    while (isalnum((unsigned char)lexer->current_char) || lexer->current_char == '_')
    {
        lexer_advance(lexer);
    }

    size_t length = lexer->position - start_position;
    token->end = lexer->position;
    token->value = lexer_strdup_range(lexer->source, start_position, length);

    if (token->value != NULL)
    {
        for (size_t i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        {
            if (strcmp(token->value, keywords[i].text) == 0)
            {
                token->type = keywords[i].type;
                break;
            }
        }
    }

    return token;
}

static Token *lexer_get_number(Lexer *lexer)
{
    size_t start_position = lexer->position;
    Token *token = lexer_create_token(lexer, TOKEN_INTEGER_LITERAL);
    if (token == NULL)
        return NULL;

    while (isdigit((unsigned char)lexer->current_char))
    {
        lexer_advance(lexer);
    }

    size_t length = lexer->position - start_position;
    token->end = lexer->position;
    token->value = lexer_strdup_range(lexer->source, start_position, length);

    return token;
}

void lexer_init(Lexer *lexer, const char *source)
{
    lexer->source = source;
    lexer->current_char = source[0];
    lexer->position = 0;
    lexer->column = 0;
    lexer->line = 1;
}

Token *lexer_next_token(Lexer *lexer)
{
    while (lexer->current_char != '\0')
    {
        if (isspace((unsigned char)lexer->current_char) && lexer->current_char != '\n')
        {
            lexer_skip_whitespace(lexer);
            continue;
        }

        if (isalpha((unsigned char)lexer->current_char) || lexer->current_char == '_')
        {
            return lexer_get_identifier(lexer);
        }

        if (isdigit((unsigned char)lexer->current_char))
        {
            return lexer_get_number(lexer);
        }

            if (lexer->current_char == '=')
        {
            Token *token = lexer_create_token(lexer, TOKEN_ASSIGN);
            if (token == NULL)
                return NULL;
            lexer_advance(lexer);
            token->end = lexer->position;
            token->value = lexer_strdup_range(lexer->source, token->start, 1);
            return token;
        }

        TokenType type;
        switch (lexer->current_char)
        {
        case '\n':
            type = TOKEN_SEMICOLON;
            break;
        default:
            type = TOKEN_INVALID;
            break;
        }

        Token *token = lexer_create_token(lexer, type);
        if (token == NULL)
            return NULL;
        lexer_advance(lexer);
        token->end = lexer->position;
        token->value = lexer_strdup_range(lexer->source, token->start, 1);
        return token;
    }

    return lexer_create_token(lexer, TOKEN_EOF);
}

void lexer_free_token(Token *token)
{
    if (token == NULL)
        return;
    free(token->value);
    free(token);
}