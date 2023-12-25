#pragma once

#include <string>
#include <utility>
#include <inttypes.h>

/*
-----------EXAMPLE--------------

bimbim = 0

cos(bimbim + 1) + log(2, ) int()

*/


class Token
{
    public:
        enum Type : uint16_t
        {
            Number, Name,

            Equal, Dot, Comma,
            Plus, Minus,
            Asterisk, Slash,
            Caret,

            OpeningParen, ClosingParen,

            Eol, Eof,



        } type;

        std::string content;


        Token() = default;

        Token(Token::Type type, std::string content)
        {
            this->type = type;
            this->content = std::move(content);
        }

        explicit Token(Token::Type type)
        {
            this->type = type;
        }
};