#include <QUiLoader>
#include "Window/Window.h"

int main(int argc, char* argv[])
{
    auto *application = new QApplication(argc, argv);
    Window window;

    window.show();

    return application->exec();
}
