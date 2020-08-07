#include "exampleupdater.h"

QUrl ExampleUpdater::updateUrl() const
{
    auto dir = QFileInfo(this->arguments()[1]).dir();
    dir.cdUp();
    dir.cd("application");

#ifdef Q_OS_WIN
    QMessageBox::information(nullptr,
                             "ExampleUpdater::updateUrl",
                             dir.filePath("application2.exe"));
    return QUrl::fromLocalFile(dir.filePath("application2.exe"));
#else
    QMessageBox::information(nullptr,
                             "ExampleUpdater::updateUrl",
                             dir.filePath("application2"));
    return QUrl::fromLocalFile(dir.filePath("application2"));
#endif
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
//#ifdef Q_OS_WIN
//        QProcess::startDetached("C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", { });
//#endif
        QProcess proc;
        proc.startDetached(executable.filePath(), { "false" }, executable.dir().path());
        proc.waitForStarted();

        this->quit();
    }
    else
    {
        QMessageBox::critical(nullptr,
                              "Error updating",
                              "Updater could not replace existing executable !");
        this->quit();
    }
}
