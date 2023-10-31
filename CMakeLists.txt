cmake_minimum_required(VERSION 3.25)
project(Nosmarcal)

set(CMAKE_CXX_STANDARD 17)



add_executable(Nosmarcal Nosmarcal/source/main.cpp Nosmarcal/source/Application/Application.cpp Nosmarcal/source/Application/Application.h Nosmarcal/source/Calculator/Calculator.cpp Nosmarcal/source/Calculator/Calculator.h)
target_include_directories(Nosmarcal PUBLIC Nosmarcal/source/Calculator Nosmarcal/source Nosmarcal/resource)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui UiTools)
target_link_libraries(Nosmarcal Qt6::Core
                                Qt6::Widgets
                                Qt6::Gui
                                Qt::UiTools)
