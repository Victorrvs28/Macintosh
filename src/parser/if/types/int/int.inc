if (token->type == TOKEN_INT_TYPE) {
        lexer_free_token(token);

        token = lexer_next_token(&lexer);
        if (token->type != TOKEN_VARIABLE_PREFIX) {
            printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
                   token->line, token->value ? token->value : "end of file");
            lexer_free_token(token);
            return 1;
        }
        lexer_free_token(token);

        token = lexer_next_token(&lexer);
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
        // ADD VARIABLES SUPPORT HERE!----------------------------------------------------------
        if (token->type != TOKEN_INTEGER_LITERAL) {
            printf("\033[31mError on line %d: '%s' is not a valid word.\033[0m\n",
                   token->line, token->value ? token->value : "end of file");
            lexer_free_token(token);
            return 1;
        }
        lexer_free_token(token);

        token = lexer_next_token(&lexer);
        if (token->type != TOKEN_SEMICOLON) {
            printf("\033[31mError on line %d: missing ';'\033[0m\n", token->line);
            lexer_free_token(token);
            return 1;
        }
        lexer_free_token(token);

        goto loop;
    }