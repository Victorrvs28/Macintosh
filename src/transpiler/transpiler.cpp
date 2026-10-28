#include "transpiler/transpiler.h"
#include "lexer/lexer.h"

#include <fstream>
#include <iostream>
#include <string>

std::string finalcontent;

void variables(Lexer& lexer)
{
    Token* nameToken = lexer_next_token(&lexer);

    if (nameToken == nullptr) {
        return;
    }

    std::string name = nameToken->value
        ? nameToken->value
        : "";

    lexer_free_token(nameToken);

    Token* assignToken = lexer_next_token(&lexer);

    if (assignToken == nullptr) {
        return;
    }

    lexer_free_token(assignToken);

    Token* valueToken = lexer_next_token(&lexer);

    if (valueToken == nullptr) {
        return;
    }

    std::string value = valueToken->value
        ? valueToken->value
        : "";

    lexer_free_token(valueToken);

    finalcontent += name + "=" + value + "\n";
}

extern "C" int transpileToBash(const char* filename)
{
    if (filename == nullptr) {
        return 1;
    }

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: could not open input file.\n";
        return 1;
    }

    finalcontent.clear();

    std::string line;

    while (std::getline(file, line)) {
        Lexer lexer;
        lexer_init(&lexer, line.c_str());

        variables(lexer);
    }


    return 0;
}
