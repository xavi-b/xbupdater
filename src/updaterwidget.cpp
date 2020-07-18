#include "updaterwidget.h"

namespace XB
{

UpdaterWidget::UpdaterWidget(QWidget* parent)
    : QWidget(parent)
{
    this->progressBar = new QProgressBar;
}

void UpdaterWidget::setProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    this->progressBar->setRange(0, bytesTotal);
    this->progressBar->setValue(bytesReceived);
}

}
