#include "tequalizehistprocessfactory.h"
#include "tnormalmultilayerpicturedisplay.h"
#include "tnofilterwindow.h"
#include "tnoprocessviewwidget.h"
#include "equalizehistimageprocess.h"

TEqualizeHistProcessFactory::TEqualizeHistProcessFactory(QObject *parent)
	: TProcessFactoryAbstract(parent)
{}

TEqualizeHistProcessFactory::~TEqualizeHistProcessFactory()
{}

void TEqualizeHistProcessFactory::initializeProcess()
{
	//	picturedisplay
	setPictureDisplay(new TNormalMultilayerPictureDisplay());

	//	filterWindow
	setFilterWindow(new TNoFilterWindow());

	//	processViewWidget
	auto processViewWidget = new TNoProcessViewWidget();
	setProcessViewWidget(processViewWidget);

	//	imageProcess
	setImageProcess(new EqualizeHistImageProcess());
}
