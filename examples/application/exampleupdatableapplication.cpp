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

#ifdef Q_OS_WIN
        dir.mkdir("updater");
#endif

        QProcess unzipProcess;
#ifdef Q_OS_WIN
        unzipProcess.setProgram("tar");
        unzipProcess.setArguments({ "-xzvf", QFileInfo(updater).filePath(), "-C", dir.filePath("updater") });
#else
        unzipProcess.setProgram("unzip");
        unzipProcess.setArguments({ QFileInfo(updater).filePath(), "-d", dir.filePath("updater") });
#endif
        unzipProcess.start();
        unzipProcess.waitForStarted();
        unzipProcess.waitForFinished();

#ifdef Q_OS_WIN
        QFile file(dir.filePath("updater/updater.exe"));
#else
        QFile file(dir.filePath("updater/updater"));
#endif
        if(file.open(QIODevice::ReadWrite))
        {
            file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner | QFileDevice::ExeOwner);
//#ifdef Q_OS_WIN
//            QProcess::startDetached("C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", { });
//#endif
            QString filePath = QFileInfo(file).filePath();
            QString dirPath = QFileInfo(file).dir().path();
            file.close();

            QProcess proc;
            proc.startDetached(filePath, args, dirPath);
            proc.waitForStarted();
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
