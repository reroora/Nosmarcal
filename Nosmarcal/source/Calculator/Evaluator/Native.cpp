//
// Created by m on 12/22/2023.
//

#include "Native.h"

#include <utility>

void Native::nativePrint(std::string text)
{
    emit printSignal(std::move(text));
}

void Native::execute(Function function, std::string content)
{
    switch (function)
    {
        case Function::Print:
            nativePrint(std::move(content));

    }
}
