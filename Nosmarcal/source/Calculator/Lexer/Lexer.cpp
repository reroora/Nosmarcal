//
// Created by m on 11/23/2023.
//

#include "Lexer.h"

#include "iostream"
#include "Error/Error.h"

std::vector<Token>&& Lexer::tokenize(const std::string &target)
{
    size_t size = target.size();
    this->source = target;

    while(current_position < size)
    {
        switch (source[current_position])
        {
            case '\n':
                addToken(Token::Eol);
                current_position++;
                break;

            case '\0':
                addToken(Token::Eol);
                addToken(Token::Eof);
                goto exit;

            case '=':
                addToken(Token::Equal);
                current_position++;
                break;

            case '.':
                addToken(Token::Dot);
                current_position++;
                break;

            case ',':
                addToken(Token::Comma);
                current_position++;
                break;

            case '+':
                addToken(Token::Plus);
                current_position++;
                break;

            case '-':
                addToken(Token::Minus);
                current_position++;
                break;

            case '*':
                addToken(Token::Asterisk);
                current_position++;
                break;

            case '/':
                addToken(Token::Slash);
                current_position++;
                break;

            case '^':
                addToken(Token::Caret);
                current_position++;
                break;

            case '(':
                addToken(Token::OpeningParen);
                current_position++;
                break;

            case ')':
                addToken(Token::ClosingParen);
                current_position++;
                break;

            default:
                while(isSpaces())
                    current_position++;

                if(isDigit())
                {
                    addNumber();
                }
                else if(isAvailableSymbol())
                {
                    addName();
                }
                else
                {
                    throw Error("Lexer exception"); // todo: create exceptions
                }



        }
    }

exit:
    return std::move(this->tokens);
}

void Lexer::printTokens()
{
    std::cout << "Tokens: " << std::endl;
    for (auto & token : tokens)
    {
        std::cout << "Name - " << token.content <<
                  "  type - " << token.type << std::endl;
    }
}

bool Lexer::isDigit()
{
    return (source[current_position] >= '0' &&
            source[current_position] <= '9');
}


bool Lexer::isAvailableSymbol()
{
    return (source[current_position] >= 'a' && source[current_position] <= 'z') ||
           (source[current_position] >= 'A' && source[current_position] <= 'Z') ||
           source[current_position] == '_';
}

bool Lexer::isSpaces()
{
    return  source[current_position] == '\t' ||
            source[current_position] == '\r' ||
            source[current_position] == '\n' ||
            source[current_position] == '\0' ||
            source[current_position] == ' ';
}

void Lexer::addToken(Token::Type type, const std::string& content)
{
    Token token(type, content);
    tokens.push_back(token);
}

void Lexer::addToken(Token::Type type)
{
    Token token(type);
    tokens.push_back(token);
}

void Lexer::addNumber()
{
    std::string content;

    while(isDigit())
    {
        content += source[current_position++];
    }
    addToken(Token::Number, content);
}

void Lexer::addName()
{
    std::string content;

    while(isAvailableSymbol() || isDigit())
    {
        content += source[current_position++];
    }

    addToken(Token::Name, content);
}
