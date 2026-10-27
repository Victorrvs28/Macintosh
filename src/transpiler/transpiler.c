#include "transpiler/transpiler.h"
#include "lexer/lexer.h"
int variables(){

}
int transpile(const char* code){
    Lexer lexer;
    lexer_init(&lexer, code);
    Token *token;
    while (true) {
        token = lexer_next_token(&lexer);
        if (token->type == TOKEN_EOF) {
            lexer_free_token(token);
            return 0;
        }
        if(toke)
        lexer_free_token(token);

    }
}
