//
// Created by m on 12/6/2023.
//

#ifndef NOSMARCAL_PARSER_H
#define NOSMARCAL_PARSER_H


#include <vector>
#include "../Lexer/Token.h"
#include "Expression.h"


class Parser
{
    public:
        std::vector<Expression_ptr> parse(std::vector<Token> &&tokens);

    private:
        std::vector<Token> tokens;

        size_t current_token = 0;

        Expression_ptr expression();
        Expression_ptr application(); // call function
        //Expression_ptr comparison();
        Expression_ptr term(); // Plus, Minus
        Expression_ptr factor(); // multiplication, division
        Expression_ptr power(); // exponentiation
        Expression_ptr assign();
        Expression_ptr unary();
        Expression_ptr primary();

        template<typename... Types>
        bool match(Types... types);

        void require(Token::Type type);
};


#endif //NOSMARCAL_PARSER_H
