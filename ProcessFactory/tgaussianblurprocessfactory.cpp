#include "tgaussianblurprocessfactory.h"
#include "gaussianblurprocess.h"
#include "ui_gaussianblursigma.h"
#include "tlistprocessviewwidget.h"
#include "horizontalline.h"

TGaussianBlurProcessFactory::TGaussianBlurProcessFactory(QObject *parent)
	: TBlurProcessFactoryAbstract(parent)
	, gaussianBlurProcess(new GaussianBlurProcess())
	, gaussianBlurProcessCopy(new GaussianBlurProcess())
{
	setBlurImageProcess(gaussianBlurProcess, gaussianBlurProcessCopy);
}

TGaussianBlurProcessFactory::~TGaussianBlurProcessFactory()
{}

void TGaussianBlurProcessFactory::initializeProcess()
{
	TBlurProcessFactoryAbstract::initializeProcess();

	//	processViewWidget
	auto gaussianBlurSigma = new QWidget();
	Ui::GaussianBlurSigma gaussianBlurSigmaUi;
	gaussianBlurSigmaUi.setupUi(gaussianBlurSigma);

	auto listProcessViewWidget = new TListProcessViewWidget();
	listProcessViewWidget->setProcessViewWidgetList(
		{
			gaussianBlurSigma,

			new HorizontalLine(),

			getProcessViewWidget()
		}
	);

	setProcessViewWidget(listProcessViewWidget);



	auto gaussianBlurProcess = this->gaussianBlurProcess;
	auto gaussianBlurProcessCopy = this->gaussianBlurProcessCopy;
	//	connect
	connect(gaussianBlurSigmaUi.doubleSpinBox, &QDoubleSpinBox::valueChanged, [gaussianBlurProcess](double value)
		{
			gaussianBlurProcess->setSigma(value);
		});
	connect(gaussianBlurProcess, &GaussianBlurProcess::sigmaChanged, [gaussianBlurSigmaUi](double sigma)
		{
			gaussianBlurSigmaUi.doubleSpinBox->setValue(sigma);
		});
	connect(gaussianBlurProcess, &GaussianBlurProcess::reJudged, [gaussianBlurProcess, gaussianBlurProcessCopy]()
		{
			gaussianBlurProcessCopy->setSigma(gaussianBlurProcess->getSigma());
		});
}
