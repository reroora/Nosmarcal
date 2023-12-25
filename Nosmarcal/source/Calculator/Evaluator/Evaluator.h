//
// Created by m on 12/22/2023.
//

#ifndef NOSMARCAL_EVALUATOR_H
#define NOSMARCAL_EVALUATOR_H

#include <vector>
#include <map>

#include "Parser/Expression.h"


class Evaluator
{
public:
    double evaluate(std::vector<Expression_ptr> &&expressions);

private:
    std::map<std::string, double> context;

    inline double evaluate(Expression expression);
    inline double evaluate(Unary& unary);
    inline double evaluate(Binary& binary);
    inline double evaluate(Numeric& numeric);
    inline double evaluate(Ident& ident);
    inline double evaluate(Application& application);
    inline double evaluate(Assign& assign);
};


#endif //NOSMARCAL_EVALUATOR_H
