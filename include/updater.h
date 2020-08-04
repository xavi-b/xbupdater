#ifndef UPDATER_H
#define UPDATER_H

#include <QMessageBox>
#include <QUrl>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStandardPaths>
#include <QProcess>
#include "application.h"
#include "updaterwidget.h"

namespace XB
{

class Updater : public Application
{
    Q_OBJECT
private:
    UpdaterWidget* widget;
    QNetworkAccessManager downloadManager;
    int transferTimeout = 30000;

    void downloadProgressHandler(qint64 bytesReceived, qint64 bytesTotal);
    void updateDownloadedHandler(QNetworkReply* reply);

protected:
    virtual QString updateUrl() const = 0;
    virtual void update();
    virtual void updateFinished(QByteArray const&);

public:
    Updater(QString const& applicationName,
            QString const& organizationDomain,
            QString const& organizationName,
            int argc, char *argv[]);

    virtual void processArguments(QStringList const& args) override;

    void setTransferTimeout(int i) { this->transferTimeout = i; }
    int getTransferTimeout() const { return this->transferTimeout; }
};

}

#endif // UPDATER_H
