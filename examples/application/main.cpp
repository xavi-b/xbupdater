#include <iostream>
#include <QMessageBox>
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

    qDebug() << "checkForUpdates" << a.checkForUpdates();

    return a.exec();
}
