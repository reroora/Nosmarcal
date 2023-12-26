cmake_minimum_required(VERSION 3.25)
project(Nosmarcal)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)

add_executable(
        Nosmarcal Nosmarcal/source/main.cpp
        Nosmarcal/source/Window/Window.cpp
        Nosmarcal/source/Window/Window.h

        Nosmarcal/source/Calculator/Calculator.cpp
        Nosmarcal/source/Calculator/Calculator.h

        Nosmarcal/source/Calculator/Lexer/Token.h
        Nosmarcal/source/Calculator/Lexer/Lexer.cpp
        Nosmarcal/source/Calculator/Lexer/Lexer.h

        Nosmarcal/source/Calculator/Parser/Parser.cpp
        Nosmarcal/source/Calculator/Parser/Parser.h
        Nosmarcal/source/Calculator/Parser/Expression.cpp
        Nosmarcal/source/Calculator/Parser/Expression.h

        Nosmarcal/source/Calculator/Error/Error.cpp
        Nosmarcal/source/Calculator/Error/Error.h

        Nosmarcal/source/Calculator/Evaluator/Evaluator.cpp
        Nosmarcal/source/Calculator/Evaluator/Evaluator.h
        Nosmarcal/source/Calculator/Evaluator/Native.cpp
        Nosmarcal/source/Calculator/Evaluator/Native.h

)
target_include_directories(Nosmarcal PUBLIC
        Nosmarcal/source/Calculator
        Nosmarcal/source
        Nosmarcal/source/Window
        Nosmarcal/resource)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui UiTools)
target_link_libraries(Nosmarcal PRIVATE Qt6::Core
                                        Qt6::Widgets
                                        Qt6::Gui
                                        Qt::UiTools)
