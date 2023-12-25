//
// Created by m on 12/15/2023.
//

#ifndef NOSMARCAL_EXPRESSION_H
#define NOSMARCAL_EXPRESSION_H


#include <cstdint>
#include <memory>
#include <functional>

#include "../Lexer/Token.h"

class Expression
{
    public:
        enum class Type : uint8_t
        {
            Unary,
            Binary,
            Assign,
            Numeric, Ident,
            Application,
        };

    explicit Expression(Type type);

    [[nodiscard]] Type getType() const;

private:
        Type type;
};


using Expression_ptr = std::shared_ptr<Expression>;


class Unary : public Expression
{
    public:
        Unary(Token::Type operation, const Expression_ptr& expression);

        [[nodiscard]] Token::Type getOperation() const;
        [[nodiscard]] const Expression_ptr &getExpression() const;

    private:
            Token::Type operation;
            Expression_ptr expression;
};

class Binary : public Expression
{
    public:
         Binary(Token::Type operation, Expression_ptr left, Expression_ptr right);

        [[nodiscard]] Token::Type getOperation() const;
        [[nodiscard]] const Expression_ptr &getLeftOperand() const;
        [[nodiscard]] const Expression_ptr &getRightOperand() const;

    private:
        Token::Type operation;
        Expression_ptr left_operand, right_operand;
};

class Numeric : public Expression
{
    public:
        explicit Numeric(double value);
        [[nodiscard]] double getValue() const;

    private:
        double value;

};

class Ident : public Expression
{
public:
    explicit Ident(std::string name);
    [[nodiscard]] const std::string &getName() const;

private:
    std::string name;

};

class Application : public Expression
{
public:
    Application(std::string name, std::vector<Expression_ptr> args);

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] std::vector<Expression_ptr>&& moveArgs();

private:
    std::string name;
    std::vector<Expression_ptr> args;
};

class Assign : public Expression
{
private:
    std::string ident;
    Expression_ptr expr;

public:
    Assign(std::string ident, Expression_ptr expr);

    [[nodiscard]] const std::string &getIdent() const;
    [[nodiscard]] const Expression_ptr &getExpr() const;

};


#endif //NOSMARCAL_EXPRESSION_H
