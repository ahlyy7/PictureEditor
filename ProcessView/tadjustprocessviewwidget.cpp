#include "ui_tadjustprocessviewwidget.h"
#include "tadjustprocessviewwidget.h"

TAdjustProcessViewWidget::TAdjustProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TAdjustProcessViewWidgetClass())
{
	ui->setupUi(this);

	connect(ui->horizontalSlider, &QSlider::valueChanged, [this](int value)
		{
			ui->spinBox->setValue(value);
			emit adjustChanged(value);

			ui->spinBox->setPrefix(
				value >= 0 ?
				"+" :
				""
			);
		});
	connect(ui->spinBox, &QSpinBox::valueChanged, ui->horizontalSlider, &QSlider::setValue);
}

TAdjustProcessViewWidget::~TAdjustProcessViewWidget()
{
	delete ui;
}

void TAdjustProcessViewWidget::setAdjust(int adjustValue)
{
	ui->horizontalSlider->setValue(adjustValue);
}

int TAdjustProcessViewWidget::getAdjust()
{
	return ui->horizontalSlider->value();
}
