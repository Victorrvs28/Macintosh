if (token->type != TOKEN_IDENTIFIER) {
    printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
           token->line, token->value ? token->value : "end of file");
    lexer_free_token(token);
    return 1;
}
lexer_free_token(token);

token = lexer_next_token(&lexer);
if (token->type != TOKEN_ASSIGN) {
    printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
           token->line, token->value ? token->value : "end of file");
    lexer_free_token(token);
    return 1;
}
lexer_free_token(token);

token = lexer_next_token(&lexer);
if (token->type != TOKEN_INTEGER_LITERAL) {// ADD OTHER TYPES SUPORT HERE!! ----------------------------
    printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
           token->line, token->value ? token->value : "end of file");
    lexer_free_token(token);
    return 1;
}
lexer_free_token(token);

token = lexer_next_token(&lexer);
if (token->type == TOKEN_EOF) {      /* última linha sem '\n' */
    lexer_free_token(token);
    return 0;
}
if (token->type != TOKEN_SEMICOLON) {
    printf("\033[31mError on line %d: expected end of line.\033[0m\n", token->line);
    lexer_free_token(token);
    return 1;
}
lexer_free_token(token);
goto loop;