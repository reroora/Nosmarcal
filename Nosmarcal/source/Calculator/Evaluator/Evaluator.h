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
    double evaluate(const std::vector<Expression_ptr> &expressions);

private:
    std::map<std::string, double> context;

    inline double evaluate(const Expression& expression);
    inline double evaluate(const Unary& unary);
    inline double evaluate(const Binary& binary);
    inline double evaluate(const Numeric& numeric);
    inline double evaluate(const Ident& ident);
    inline double evaluate(const Application& application);
    inline double evaluate(const Assign& assign);
};


#endif //NOSMARCAL_EVALUATOR_H
