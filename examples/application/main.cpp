#include <iostream>
#include <QMessageBox>
#include <QLabel>
#include "exampleupdatableapplication.h"

int main(int argc, char *argv[])
{
    ExampleUpdatableApplication a("ExampleUpdatableApplication",
                                  "xavi-b.fr",
                                  "xavi-b",
                                  argc, argv);

    std::cout << "ExampleUpdatableApplication" << std::endl;

    auto dir = QFileInfo(QCoreApplication::applicationFilePath()).dir();
    dir.cdUp();
    dir.cd("updater");
    a.setUpdateUrl(QUrl::fromLocalFile(dir.filePath("updater.zip")));

    a.processArguments(a.arguments());

    if(a.checkForUpdates())
    {
        qDebug() << "checkForUpdates" << true;
        return a.exec();
    }

    QLabel label("ExampleUpdatableApplication");
    label.show();

    QObject::connect(&a, &QApplication::lastWindowClosed, &a, &QApplication::quit);

    return a.exec();
}
