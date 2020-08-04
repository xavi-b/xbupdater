#include "exampleupdatableapplication.h"

bool ExampleUpdatableApplication::shouldUpdate(const QUrl& updateUrl) const
{
    return true; //TODO
}

ExampleUpdatableApplication::ExampleUpdatableApplication(QString const& applicationName,
                                                         QString const& organizationDomain,
                                                         QString const& organizationName,
                                                         int argc, char *argv[])
    : XB::UpdatableApplication(applicationName,
                               organizationDomain,
                               organizationName,
                               argc, argv)
{

}

void ExampleUpdatableApplication::processArguments(const QStringList& args)
{
    //TODO
}
