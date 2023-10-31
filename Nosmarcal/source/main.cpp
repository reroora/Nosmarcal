#include <QUiLoader>
#include <QFile>
#include "Application/Application.h"

int main(int argc, char* argv[])
{
//    QApplication *application = new QApplication(argc, argv);
//
//    QUiLoader loader;
//    QFile file(R"(C:\MyProjects\BSUIR\SDLC\Nosmarcal\resource\calculatorform.ui)");
//    file.open(QFile::ReadOnly);
//    QWidget *window = loader.load(&file, window);
//    file.close();
//
//    window->show();
//
//    application->exec();
//
    Application application(argc, argv);
    application.run();

    return 0;
}
