#include "tnoprocessfactory.h"
#include "tnormalmultilayerpicturedisplay.h"
#include "tnofilterwindow.h"
#include "tnoprocessviewwidget.h"
#include "noprocess.h"

void TNoProcessFactory::initializeProcess()
{
	setPictureDisplay(new TNormalMultilayerPictureDisplay());
	setFilterWindow(new TNoFilterWindow());
	setProcessViewWidget(new TNoProcessViewWidget());
	setImageProcess(new NoProcess());
}

TNoProcessFactory::TNoProcessFactory(QWidget *parent)
	: TProcessFactoryAbstract(parent)
{
}

TNoProcessFactory::~TNoProcessFactory()
{
}
