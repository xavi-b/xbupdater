#include "exampleupdater.h"

QUrl ExampleUpdater::updateUrl() const
{
    auto dir = QFileInfo(this->arguments()[0]).dir();
    dir.cdUp();
    dir.cd("application");

    QMessageBox::information(nullptr,
                             "ExampleUpdater::updateUrl",
                             dir.filePath("application2"));

    return QUrl::fromLocalFile(dir.filePath("application2"));
}

ExampleUpdater::ExampleUpdater(QString const& applicationName,
                               QString const& organizationDomain,
                               QString const& organizationName,
                               int& argc, char *argv[])
    : XB::Updater(applicationName,
                  organizationDomain,
                  organizationName,
                  argc, argv)
{

}

void ExampleUpdater::updateFinished(QByteArray const& data)
{
    QFileInfo executable = this->arguments()[1];
    QFile file(executable.filePath());
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
        QMessageBox::information(nullptr,
                                 "Update finished",
                                 "Update has finished, your application should start in a few moments.");
        QStringList arguments = this->arguments();
        arguments.removeAt(0);
        arguments.removeAt(1);
        arguments.prepend("false");
        this->quit();
        QProcess::startDetached(executable.filePath(), arguments);
    }
    else
    {
        QMessageBox::critical(nullptr,
                              "Error updating",
                              "Updater could not replace existing executable !");
        this->quit();
    }
}
