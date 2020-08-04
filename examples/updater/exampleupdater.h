#ifndef EXAMPLEUPDATER_H
#define EXAMPLEUPDATER_H

#include "updater.h"

class ExampleUpdater : public XB::Updater
{
    Q_OBJECT
protected:
    virtual QString updateUrl() const override;

public:
    ExampleUpdater(QString const& applicationName,
                   QString const& organizationDomain,
                   QString const& organizationName,
                   int argc, char *argv[]);
};

#endif // EXAMPLEUPDATER_H
