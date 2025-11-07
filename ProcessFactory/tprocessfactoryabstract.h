#pragma once

#ifndef _PROCESSFACTORYABSTRACT_H_
#define _PROCESSFACTORYABSTRACT_H_

#include "processfactory_global.h"
#include <QObject>

class TMultilayerPictureDisplayAbstract;
class TFilterWindowAbstract;
class TProcessViewWidgetAbstract;
class AbstractImageProcess;

class /*PROCESSFACTORY_EXPORT*/ TProcessFactoryAbstract : public QObject
{
    Q_OBJECT

private:
    TMultilayerPictureDisplayAbstract* pictureDisplay;
    TFilterWindowAbstract* filterWindow;
    TProcessViewWidgetAbstract* processViewWidget;
    AbstractImageProcess* imageProcess;

protected:
    void setPictureDisplay(TMultilayerPictureDisplayAbstract* pictureDisplay);
    void setFilterWindow(TFilterWindowAbstract* filterWindow);
    void setProcessViewWidget(TProcessViewWidgetAbstract* processViewWidget);
    void setImageProcess(AbstractImageProcess* imageProcess);

public:
    virtual void initializeProcess() = 0;

    TMultilayerPictureDisplayAbstract* getPictureDisplay();
    TFilterWindowAbstract* getFilterWindow();
    TProcessViewWidgetAbstract* getProcessViewWidget();
    AbstractImageProcess* getImageProcess();

    TProcessFactoryAbstract(QObject* parent = nullptr);
    virtual ~TProcessFactoryAbstract() = 0;
};

#endif // !_PROCESSFACTORYABSTRACT_H_
