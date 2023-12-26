//
// Created by m on 11/23/2023.
//

#ifndef NOSMARCAL_LEXER_H
#define NOSMARCAL_LEXER_H

#include <vector>


#include <string>
#include "Token.h"

class Lexer
{
public:
    std::vector<Token>&& tokenize(const std::string &target);
    void printTokens();

private:
    std::vector<Token> tokens;

    std::string source;

    size_t current_position = 0;

    void addToken(Token::Type type, const std::string& content);
    void addToken(Token::Type type);

    void addNumber();
    void addName();

    bool isDigit();
    bool isAvailableSymbol();
    bool isSpaces();
};


#endif //NOSMARCAL_LEXER_H
