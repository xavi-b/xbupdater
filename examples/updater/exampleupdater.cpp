#include "exampleupdater.h"

QString ExampleUpdater::updateUrl() const
{
    return QString(); //TODO
}

ExampleUpdater::ExampleUpdater(QString const& applicationName,
                               QString const& organizationDomain,
                               QString const& organizationName,
                               int argc, char *argv[])
    : XB::Updater(applicationName,
                  organizationDomain,
                  organizationName,
                  argc, argv)
{

}
