#include "exampleupdatableapplication.h"
#include <QDebug>

bool ExampleUpdatableApplication::shouldUpdate(const QUrl& updateUrl) const
{
    return this->arguments().length() == 1;
}

bool ExampleUpdatableApplication::applyUpdate(QByteArray const& data)
{
    QDir dir = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::TempLocation);
    QFile updater(dir.filePath("updater.zip"));
    updater.remove();
    if(updater.open(QIODevice::ReadWrite))
    {
        updater.write(data);
        updater.close();
        QStringList args = this->arguments();
        args[0] = QCoreApplication::applicationFilePath();

        if(dir.cd("updater"))
        {
            bool removed = dir.removeRecursively();
            qDebug() << "previous tmpdir removed:" << removed;
            dir.cdUp();
        }

        QProcess unzipProcess;
        unzipProcess.setProgram("unzip");
        unzipProcess.setArguments({ QFileInfo(updater).filePath(), "-d", dir.filePath("updater") });
        unzipProcess.start();
        unzipProcess.waitForStarted();
        unzipProcess.waitForFinished();

        QFile file(dir.filePath("updater/updater"));
        if(file.open(QIODevice::ReadWrite))
        {
            file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner | QFileDevice::ExeOwner);
            QProcess proc;
            proc.setProgram(QFileInfo(file).filePath());
            proc.setArguments(args);
            proc.start();
            proc.waitForFinished();
            this->quit();
            return true;
        }
        return false;
    }

    return false;
}

ExampleUpdatableApplication::ExampleUpdatableApplication(QString const& applicationName,
                                                         QString const& organizationDomain,
                                                         QString const& organizationName,
                                                         int& argc, char *argv[])
    : XB::UpdatableApplication(applicationName,
                               organizationDomain,
                               organizationName,
                               argc, argv)
{

}

void ExampleUpdatableApplication::processArguments(const QStringList& args)
{
    qDebug() << __FUNCTION__ << args;
}
