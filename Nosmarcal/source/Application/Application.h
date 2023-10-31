//
// Created by m on 10/26/2023.
//

#ifndef NOSMARCAL_APPLICATION_H
#define NOSMARCAL_APPLICATION_H

#include <QApplication>
#include <QWidget>

class Application
{
public:
    Application(int argc, char* argv[]);
    ~Application();
    void run();

private:
    QApplication *application;
    QWidget *window;
};


#endif //NOSMARCAL_APPLICATION_H
