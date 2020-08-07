#include "updater.h"

namespace XB
{

void Updater::downloadProgressHandler(qint64 bytesReceived, qint64 bytesTotal)
{
    this->widget->setProgress(bytesReceived, bytesTotal);
}

void Updater::updateDownloadedHandler(QNetworkReply* reply)
{
    this->widget->close();
    reply->deleteLater();
    this->updateFinished(reply->readAll());
}

void Updater::update()
{
    this->widget->show();
    QUrl updateUrl = this->updateUrl();
    connect(&this->downloadManager, &QNetworkAccessManager::finished, this, &Updater::updateDownloadedHandler);
    QNetworkRequest request(updateUrl);
    request.setTransferTimeout(this->transferTimeout);
    QNetworkReply* reply = this->downloadManager.get(request);
    connect(reply, &QNetworkReply::downloadProgress, this, &Updater::downloadProgressHandler);
}

Updater::Updater(QString const& applicationName,
                 QString const& organizationDomain,
                 QString const& organizationName,
                 int& argc, char *argv[])
    : Application(applicationName,
                      organizationDomain,
                      organizationName,
                      argc, argv)
{
    this->widget = new UpdaterWidget();
}

void Updater::processArguments(QStringList const& args)
{
    if(args.length() == 0)
    {
        QMessageBox::warning(nullptr,
                             "Argument error",
                             "No argument given to updater");
        this->quit();
        return;
    }

    QFileInfo executable = args[0];

    if(!executable.exists())
    {
        QMessageBox::warning(nullptr,
                             "Executable error",
                             "Executable given does not exists");
        this->quit();
        return;
    }

    if(!executable.isWritable())
    {
        QMessageBox::warning(nullptr,
                             "Executable error",
                             "Executable dir given is not writable");
        this->quit();
        return;
    }

    if(!executable.isExecutable())
    {
        QMessageBox::warning(nullptr,
                             "Executable error",
                             "Executable given is not executable");
        this->quit();
        return;
    }

    this->update();
}

}
