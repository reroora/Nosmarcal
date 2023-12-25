//
// Created by m on 12/22/2023.
//

#include "Evaluator.h"
#include "Native.h"
#include "Error/Error.h"

#include <cmath>

double Evaluator::evaluate(std::vector<Expression_ptr> &&expressions)
{
//    for (auto& e: expressions)
//    {
//        evaluate(*e);
//    }

    for (int i = 0; i < expressions.size(); ++i)
    {
        evaluate(*expressions[i]);
    }


    return 0;
}

double Evaluator::evaluate( Expression expression)
{
    auto type = expression.getType();
    switch (type)
    {
        case Expression::Type::Unary:
            return evaluate((Unary&) expression);

        case Expression::Type::Binary:
            return evaluate((Binary&) expression);

        case Expression::Type::Numeric:
            return evaluate((Numeric&) expression);

        case Expression::Type::Ident:
            return evaluate((Ident&) expression);

        case Expression::Type::Application:
            return evaluate(std::move((Application&) expression));

        case Expression::Type::Assign:
            return evaluate((Assign&) expression);
    }
}

double Evaluator::evaluate( Unary &unary)
{
    double val = evaluate(*unary.getExpression());
    switch (unary.getOperation())
    {
        case Token::Type::Plus:
            return +val;

        case Token::Type::Minus:
            return -val;
    }
}

double Evaluator::evaluate( Binary &binary)
{
    //std::string Name = evaluate(*binary.getLeftOperand())
    double left = evaluate(*binary.getLeftOperand());
    double right = evaluate(*binary.getRightOperand());

    switch (binary.getOperation())
    {
        case Token::Type::Plus:
            return left + right;

        case Token::Type::Minus:
            return left - right;

        case Token::Type::Asterisk:
            return left * right;

        case Token::Type::Slash:
            return left / right;

        case Token::Type::Caret:
            return pow(left, right);
    }
}

double Evaluator::evaluate( Numeric &numeric)
{
    auto v = numeric.getValue();
    return v;
}

double Evaluator::evaluate( Ident &ident)
{
    return context[ident.getName()];
}

double Evaluator::evaluate(Application& application)
{
    const auto& name = application.getName();
    auto args = application.moveArgs();

    if (name == "Print")
    {
        if (args.size() == 1)
        {
            double result = evaluate(*args[0]);

            std::ostringstream strs;
            strs << result;
            std::string str = strs.str();

            Native native;
            native.execute(Native::Function::Print, str);

            return 0;
        }
        throw Error("Print invalid args");
    }
    else
    {
        Native native;
        native.execute(Native::Function::Print, "Native::Function::Print, str");
        return 10;
    }
}

double Evaluator::evaluate( Assign &assign)
{
    std::string name = assign.getIdent();
    double value = evaluate(*assign.getExpr());

    context.insert({name, value});

    return value;
}
