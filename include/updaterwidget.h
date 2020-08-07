#ifndef UPDATERWIDGET_H
#define UPDATERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>

namespace XB
{

class Q_DECL_EXPORT UpdaterWidget: public QWidget
{
    Q_OBJECT
private:
    QProgressBar* progressBar;

public:
    UpdaterWidget(QWidget* parent = nullptr);
    void setProgress(qint64 bytesReceived, qint64 bytesTotal);
};

}

#endif // UPDATERWIDGET_H
