//
// Created by m on 12/6/2023.
//

#include "Parser.h"
#include "Error/Error.h"

#include <algorithm>
#include <memory>
#include <iostream>

std::vector<Expression_ptr> Parser::parse(std::vector<Token> &&p_tokens)
{
    this->tokens = std::move(p_tokens);

    std::vector<Expression_ptr> result;
    do
    {
        while(match(Token::Eol));

        result.push_back(std::move(expression()));
        require(Token::Eol);

    } while(tokens[current_token].type != Token::Eof);

    return result;
}

Expression_ptr Parser::expression()
{
    return application();
}

Expression_ptr Parser::application() // todo: do it
{
    auto left = term();

    if (tokens[current_token - 1].type == Token::Type::Name && /*tokens[current_token].type == Token::Type::OpeningParen*/ match(Token::Type::OpeningParen))
    {
        std::string name = tokens[current_token - 2].content;
        std::vector<Expression_ptr> args;
        //current_token++;
        while(true)
        {
            auto arg = expression();
            args.emplace_back(std::move(arg));

            if (!match(Token::Type::Comma))
                break;
        }

        require(Token::Type::ClosingParen);
        //Binary bin =
//        std::cout << "name - " << name << std::endl;
        left = std::make_shared<Application>(name, args);
        return left;
    }

    return left;
}

Expression_ptr Parser::term()
{
    auto left = factor();

    while(match(Token::Plus, Token::Minus))
    {
        auto op = tokens[current_token - 1].type;
        auto right = factor();
        left = std::make_shared<Binary>(op, std::move(left), std::move(right));
    }

    return left;
}

Expression_ptr Parser::factor()
{
    auto left = power();

    while(match(Token::Asterisk, Token::Slash))
    {
        auto op = tokens[current_token - 1].type;
        auto right = power();
        left = std::make_shared<Binary>(op, std::move(left), std::move(right));
    }

    return left;
}

Expression_ptr Parser::power()
{
    auto left = assign();

    while(match(Token::Caret))
    {
        auto op = tokens[current_token - 1].type;
        auto right = unary();
        left = std::make_shared<Binary>(op, std::move(left), std::move(right));
    }

    return left;
}

Expression_ptr Parser::assign()
{
    auto left = unary();

    while(match(Token::Equal))
    {
        if(left->getType() == Expression::Type::Ident)
        {
            auto right = expression();
            left = std::make_shared<Assign>(tokens[current_token - 1].content, std::move(right));
        }
        else
            throw Error("Invalid assignment");
    }

    return left;
}

Expression_ptr Parser::unary()
{
    if(match(Token::Plus, Token::Minus)){
        auto op = tokens[current_token - 1].type;
        auto expr = primary();
        return std::make_shared<Unary>(op, std::move(expr));
    }

    return primary();
}

Expression_ptr Parser::primary()
{
    auto token = tokens[current_token];

    if(match(Token::Number))
    {
        return std::make_shared<Numeric>(stod(token.content));
    }
    else if(match(Token::Name))
    {
        return std::make_shared<Ident>(token.content);
    }
    else if(match(Token::OpeningParen))
    {
        auto expr = expression();
        require(Token::ClosingParen);
        return expr;
    }
    else if(match(Token::Type::Eol)) {}

    throw Error("Unexpected token error"); // todo: do normal exceptions
}

void Parser::require(Token::Type type)
{
    if(!match(type)){
        throw Error("Unexpected token error"); //todo: do normal exceptions
    }
}

template<typename... Types>
bool Parser::match(Types... types)
{
    auto unpack = {types...};
    auto search = tokens[current_token].type;

    if(std::ranges::any_of(unpack,
                           [search](auto type){ return type == search; })){
        ++current_token;
        return true;
    }
    return false;
}
