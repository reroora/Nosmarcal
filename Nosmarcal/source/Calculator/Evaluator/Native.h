//
// Created by m on 12/22/2023.
//

#ifndef NOSMARCAL_NATIVE_H
#define NOSMARCAL_NATIVE_H

#include <string>
#include "Window/Window.h"

class Native : public Window
{
private:
    void nativePrint(std::string text);

public:

    enum Function
    {
        Print,
    };

    void execute(Function function, std::string content);
};


#endif //NOSMARCAL_NATIVE_H
