//
// Created by m on 12/15/2023.
//

#include "Expression.h"

#include <utility>

Token::Type Unary::getOperation() const
{
    return operation;
}

const Expression_ptr &Unary::getExpression() const
{
    return expression;
}

Unary::Unary(Token::Type operation, const Expression_ptr& expr)  : Expression(Type::Unary)
{
    this->operation = operation;
    this->expression = std::move(expression);
}

Expression::Type Expression::getType() const
{
    return type;
}

Expression::Expression(Expression::Type type) : type(type)
{}

Binary::Binary(Token::Type operation, Expression_ptr left, Expression_ptr right) : Expression(Expression::Type::Binary)
{
    this->operation = operation;
    this->left_operand = std::move(left);
    this->right_operand = std::move(right);
}

Token::Type Binary::getOperation() const
{
    return operation;
}

const Expression_ptr &Binary::getLeftOperand() const
{
    return left_operand;
}

const Expression_ptr &Binary::getRightOperand() const
{
    return right_operand;
}

Numeric::Numeric(double value) : Expression(Expression::Type::Numeric)
{
    this->value = value;
}

double Numeric::getValue() const
{
    return value;
}

Ident::Ident(std::string name) : Expression(Expression::Type::Ident)
{
    this->name = std::move(name);
}

const std::string &Ident::getName() const
{
    return name;
}

Application::Application(std::string name, std::vector<Expression_ptr> args) : Expression(Expression::Type::Application)
{
    this->name = std::move(name);
    this->args = std::move(args);
}

const std::string &Application::getName() const
{
    return name;
}

const std::vector<Expression_ptr> &Application::getArgs() const
{
    return args;
}

const std::string &Assign::getIdent() const
{
    return ident;
}

const Expression_ptr &Assign::getExpr() const
{
    return expr;
}

Assign::Assign(std::string ident, Expression_ptr expr) : Expression(Expression::Type::Assign)
{
    this->ident = std::move(ident);
    this->expr = std::move(expr);
}
