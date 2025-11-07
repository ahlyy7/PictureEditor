#include "ui_tpixelprocessviewwidget.h"
#include "tpixelprocessviewwidget.h"

TPixelProcessViewWidget::TPixelProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TPixelProcessViewWidgetClass())
{
	ui->setupUi(this);

	connect(ui->spinBox, &QSpinBox::valueChanged, [this](int value)
		{
			emit valueChanged(value);
		});
}

TPixelProcessViewWidget::~TPixelProcessViewWidget()
{
	delete ui;
}

void TPixelProcessViewWidget::setValue(int value)
{
	if (getValue() == value)
		return;

	ui->spinBox->setValue(value);
}

int TPixelProcessViewWidget::getValue()
{
	return ui->spinBox->value();
}

void TPixelProcessViewWidget::setMinimumValue(int value)
{
	ui->spinBox->setMinimum(value);
}

int TPixelProcessViewWidget::getMinimumValue()
{
	return ui->spinBox->minimum();
}

void TPixelProcessViewWidget::setMaximumValue(int value)
{
	ui->spinBox->setMaximum(value);
}

int TPixelProcessViewWidget::getMaximumValue()
{
	return ui->spinBox->maximum();
}

void TPixelProcessViewWidget::setReadOnly(bool readOnly)
{
	ui->spinBox->setReadOnly(readOnly);
}
