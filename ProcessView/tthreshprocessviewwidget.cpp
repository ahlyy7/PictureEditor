#include "ui_tthreshprocessviewwidget.h"
#include "tthreshprocessviewwidget.h"

TThreshProcessViewWidget::TThreshProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TThreshProcessViewWidgetClass())
{
	ui->setupUi(this);

	connect(ui->horizontalSlider, &QSlider::valueChanged, [this](int value)
		{
			ui->spinBox->setValue(value);

			emit threshChanged(value);
		});
	connect(ui->spinBox, &QSpinBox::valueChanged, ui->horizontalSlider, &QSlider::setValue);
}

TThreshProcessViewWidget::~TThreshProcessViewWidget()
{
	delete ui;
}

void TThreshProcessViewWidget::setThresh(int thresh)
{
	ui->horizontalSlider->setValue(thresh);
}

int TThreshProcessViewWidget::getThresh()
{
	return ui->horizontalSlider->value();
}
