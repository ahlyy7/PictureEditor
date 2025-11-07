#include "tprocessfactoryabstract.h"

void TProcessFactoryAbstract::setPictureDisplay(TMultilayerPictureDisplayAbstract* pictureDisplay)
{
	this->pictureDisplay = pictureDisplay;
}

void TProcessFactoryAbstract::setFilterWindow(TFilterWindowAbstract* filterWindow)
{
	this->filterWindow = filterWindow;
}

void TProcessFactoryAbstract::setProcessViewWidget(TProcessViewWidgetAbstract* processViewWidget)
{
	this->processViewWidget = processViewWidget;
}

void TProcessFactoryAbstract::setImageProcess(AbstractImageProcess* imageProcess)
{
	this->imageProcess = imageProcess;
}

TMultilayerPictureDisplayAbstract* TProcessFactoryAbstract::getPictureDisplay()
{
	return pictureDisplay;
}

TFilterWindowAbstract* TProcessFactoryAbstract::getFilterWindow()
{
	return filterWindow;
}

TProcessViewWidgetAbstract* TProcessFactoryAbstract::getProcessViewWidget()
{
	return processViewWidget;
}

AbstractImageProcess* TProcessFactoryAbstract::getImageProcess()
{
	return imageProcess;
}

TProcessFactoryAbstract::TProcessFactoryAbstract(QObject* parent)
	: QObject(parent)
	, pictureDisplay(nullptr)
	, filterWindow(nullptr)
	, processViewWidget(nullptr)
	, imageProcess(nullptr)
{
}

TProcessFactoryAbstract::~TProcessFactoryAbstract()
{
}
