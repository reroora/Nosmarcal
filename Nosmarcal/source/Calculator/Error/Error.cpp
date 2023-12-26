//
// Created by m on 12/17/2023.
//

#include "Error.h"

#include <utility>

Error::Error(std::string message)
{
    this->msg = std::move(message);
}
