#include <iostream>
#include <QMessageBox>
#include "exampleupdater.h"

int main(int argc, char *argv[])
{
    ExampleUpdater a("ExampleUpdater",
                     "xavi-b.fr",
                     "xavi-b",
                     argc, argv);

    std::cout << "ExampleUpdater" << std::endl;

    if(!a.checkUniqueInstance())
    {
        QMessageBox::warning(nullptr,
                             "Updater already started",
                             "There currently is a started update, this instance will close.");
        return 1;
    }

    a.processArguments(a.arguments());

    return a.exec();
}
