//
// Created by m on 12/17/2023.
//

#ifndef NOSMARCAL_ERROR_H
#define NOSMARCAL_ERROR_H

#include <string>
#include <exception>

class Error : public std::exception
{
public:
    explicit Error(std::string message);
    std::string msg;
};


#endif //NOSMARCAL_ERROR_H
