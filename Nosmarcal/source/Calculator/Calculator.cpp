//
// Created by m on 10/26/2023.
//

#include <iostream>
#include "Calculator.h"
#include "Parser/Parser.h"
#include "Evaluator/Evaluator.h"
#include "Error/Error.h"

void Calculator::calculate(const std::string& target)
{
    Lexer lexer;
    Parser parser;

    try
    {
        auto tokens = lexer.tokenize(target);
        std::vector<Expression_ptr> expressions = parser.parse(std::move(tokens));
        Evaluator evaluator;
        evaluator.evaluate(expressions);
    }
    catch (Error &e)
    {
        std::cout << "oops, error - " << e.msg << std::endl;
    }
}
