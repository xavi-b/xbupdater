#include <QMessageBox>
#include "updater.h"

int main(int argc, char *argv[])
{
    XB::Updater a("Updater",
                  "xavi-b.fr",
                  "xavi-b",
                  argc, argv);

    if(!a.checkUniqueInstance())
    {
        QMessageBox::warning(nullptr,
                             "Updater already started",
                             "There currently is a started update, this instance will close.");
        return 1;
    }

    return a.exec();
}
