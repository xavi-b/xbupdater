#ifndef EXAMPLEUPDATABLEAPPLICATION_H
#define EXAMPLEUPDATABLEAPPLICATION_H

#include "updatableapplication.h"

class ExampleUpdatableApplication : public XB::UpdatableApplication
{
    Q_OBJECT
protected:
    virtual bool shouldUpdate(QUrl const& updateUrl) const override;

public:
    ExampleUpdatableApplication(QString const& applicationName,
                                QString const& organizationDomain,
                                QString const& organizationName,
                                int argc, char *argv[]);

    virtual void processArguments(QStringList const& args) override;
};

#endif // EXAMPLEUPDATABLEAPPLICATION_H
