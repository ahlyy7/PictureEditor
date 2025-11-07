#include "pch.h"
#include "tbilateralblurprocessfactory.h"
#include "bilateralblurprocess.h"
#include "ui_bilateralblursigma.h"
#include "tlistprocessviewwidget.h"

TBilateralBlurProcessFactory::TBilateralBlurProcessFactory(QObject *parent)
	: TBlurProcessFactoryAbstract(parent)
	, bilateralBlurProcess(new BilateralBlurProcess())
{
	auto bilateralBlurProcess = this->bilateralBlurProcess;
	auto bilateralBlurProcessCopy = new BilateralBlurProcess();

	setBlurImageProcess(bilateralBlurProcess, bilateralBlurProcessCopy);

	connect(bilateralBlurProcess, &AbstractImageBlurProcess::reJudged, [bilateralBlurProcess, bilateralBlurProcessCopy]()
		{
			bilateralBlurProcessCopy->setSigmaColor(bilateralBlurProcess->getSigmaColor());
			bilateralBlurProcessCopy->setSigmaSpace(bilateralBlurProcess->getSigmaSpace());
		});
}

TBilateralBlurProcessFactory::~TBilateralBlurProcessFactory()
{}

void TBilateralBlurProcessFactory::initializeProcess()
{
	TBlurProcessFactoryAbstract::initializeProcess();

	//	processViewWidget
	auto bilateralBlurSigma = new QWidget();
	Ui::BilateralBlurSigma bilateralBlurSigmaUi;
	bilateralBlurSigmaUi.setupUi(bilateralBlurSigma);

	auto widget = getProcessViewWidget();
	widget->setParent(bilateralBlurSigmaUi.sizeWidget);
	bilateralBlurSigmaUi.sizeWidget->layout()->addWidget(widget);

	auto listProcessViewWidget = new TListProcessViewWidget();
	listProcessViewWidget->addProcessViewWidget(bilateralBlurSigma);

	setProcessViewWidget(listProcessViewWidget);



	auto bilateralBlurProcess = this->bilateralBlurProcess;
	//	connect
	connect(bilateralBlurSigmaUi.sigmaColor, &QDoubleSpinBox::valueChanged, [bilateralBlurProcess](double value)
		{
			bilateralBlurProcess->setSigmaColor(value);
		});
	connect(bilateralBlurSigmaUi.sigmaSpace, &QDoubleSpinBox::valueChanged, [bilateralBlurProcess](double value)
		{
			bilateralBlurProcess->setSigmaSpace(value);
		});
	auto sizeChecke = [bilateralBlurProcess](bool checked)
		{
			if (checked)
				return;

			bilateralBlurProcess->setKsize({ 0, 0 });
		};
	connect(bilateralBlurSigmaUi.sizeButton, &QRadioButton::toggled, [bilateralBlurProcess, sizeChecke](bool checked)
		{
			if (checked)
				bilateralBlurProcess->setKsize(BilateralBlurProcess::initializeKsize);
			else
				sizeChecke(false);
		});
	connect(bilateralBlurProcess, &BilateralBlurProcess::ksizeChanged, [bilateralBlurSigmaUi, sizeChecke]()
		{
			sizeChecke(bilateralBlurSigmaUi.sizeButton->isChecked());
		});
	connect(bilateralBlurProcess, &BilateralBlurProcess::sigmaColorChanged, [bilateralBlurSigmaUi](double sigmaColor)
		{
			bilateralBlurSigmaUi.sigmaColor->setValue(sigmaColor);
		});
	connect(bilateralBlurProcess, &BilateralBlurProcess::sigmaSpaceChanged, [bilateralBlurSigmaUi](double sigmaSpace)
		{
			//if (bilateralBlurSigmaUi.sigmaSpace->value() == sigmaSpace)
			//	return;

			bilateralBlurSigmaUi.sigmaSpace->setValue(sigmaSpace);
			//bilateralBlurSigmaUi.sizeButton->setChecked(true);
		});
}
