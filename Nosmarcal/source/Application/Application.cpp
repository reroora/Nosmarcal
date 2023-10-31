//
// Created by m on 10/26/2023.
//

#include <QUiLoader>
#include <QFile>
#include "Application.h"

Application::Application(int argc, char **argv)
{
    this->application = new QApplication(argc, argv);
    this->window = new QWidget;

    // load ui
    QUiLoader loader;
    QFile file("..\\..\\Nosmarcal\\Nosmarcal\\resource\\calculator.ui");
    file.open(QFile::ReadOnly);
    this->window = loader.load(&file, this->window);
    file.close();

    // signal connect
}

Application::~Application()
{

}

void Application::run()
{
    this->window->show();
    QApplication::exec();
}


