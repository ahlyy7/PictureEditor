#include "ui_tsizeprocessviewwidget.h"
#include "tsizeprocessviewwidget.h"
#include <QSpinBox>

QSpinBox* getSpinBox();

TSizeProcessViewWidget::TSizeProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TSizeProcessViewWidgetClass())
	, equal(false)
{
	ui->setupUi(this);

	widthSpinBox = getSpinBox();
	heightSpinBox = getSpinBox();

	connect(widthSpinBox, &QSpinBox::valueChanged, [this](int width)
		{
			if (equal)
				heightSpinBox->setValue(width);

			emit widthChanged(width);
		});
	connect(heightSpinBox, &QSpinBox::valueChanged, [this](int height)
		{
			if (equal)
				widthSpinBox->setValue(height);

			emit heightChanged(height);
		});

	ui->formProceViewWidget->setFormList(
		{
			{ "width", widthSpinBox },
			{ "height", heightSpinBox }
		}
	);

	setReadOnly(false);
}

TSizeProcessViewWidget::~TSizeProcessViewWidget()
{
	delete ui;
}

void TSizeProcessViewWidget::setWidth(int width)
{
	widthSpinBox->setValue(width);
}

int TSizeProcessViewWidget::getWidth()
{
	return widthSpinBox->value();
}

void TSizeProcessViewWidget::setHeight(int height)
{
	heightSpinBox->setValue(height);
}

int TSizeProcessViewWidget::getHeight()
{
	return heightSpinBox->value();
}

void TSizeProcessViewWidget::setSize(QSize size)
{
	setWidth(size.width());
	setHeight(size.height());
}

QSize TSizeProcessViewWidget::getSize()
{
	return { getWidth(), getHeight() };
}

void TSizeProcessViewWidget::setMinimumWidth(int width)
{
	widthSpinBox->setMinimum(width);
}

int TSizeProcessViewWidget::getMinimumWidth()
{
	return widthSpinBox->minimum();
}

void TSizeProcessViewWidget::setMaximumWidth(int width)
{
	widthSpinBox->setMaximum(width);
}

int TSizeProcessViewWidget::getMaximumWidth()
{
	return widthSpinBox->maximum();
}

void TSizeProcessViewWidget::setMinimumHeight(int height)
{
	heightSpinBox->setMinimum(height);
}

int TSizeProcessViewWidget::getMinimumHeight()
{
	return heightSpinBox->minimum();
}

void TSizeProcessViewWidget::setMaximumHeight(int height)
{
	heightSpinBox->setMaximum(height);
}

int TSizeProcessViewWidget::getMaximumHeight()
{
	return heightSpinBox->maximum();
}

void TSizeProcessViewWidget::setMinimumSize(QSize size)
{
	setMinimumWidth(size.width());
	setMinimumHeight(size.height());
}

QSize TSizeProcessViewWidget::getMinimumSize()
{
	return { minimumWidth(), minimumHeight() };
}

void TSizeProcessViewWidget::setMaximumSize(QSize size)
{
	setMaximumWidth(size.width());
	setMaximumHeight(size.height());
}

QSize TSizeProcessViewWidget::getMaximumSize()
{
	return { maximumWidth(), maximumHeight() };
}

void TSizeProcessViewWidget::setReadOnly(bool readOnly)
{
	widthSpinBox->setReadOnly(readOnly);
	heightSpinBox->setReadOnly(readOnly);

	widthSpinBox->setButtonSymbols(readOnly ? QAbstractSpinBox::NoButtons : QAbstractSpinBox::UpDownArrows);
	heightSpinBox->setButtonSymbols(readOnly ? QAbstractSpinBox::NoButtons : QAbstractSpinBox::UpDownArrows);
}

void TSizeProcessViewWidget::setWidthAndHeightEqual(bool equal)
{
	this->equal = equal;
}

void TSizeProcessViewWidget::setSingleStep(QSize singleStep)
{
	setWidthSingleStep(singleStep.width());
	setHeightSingleStep(singleStep.height());
}

void TSizeProcessViewWidget::setWidthSingleStep(int singleStep)
{
	widthSpinBox->setSingleStep(singleStep);
}

void TSizeProcessViewWidget::setHeightSingleStep(int singleStep)
{
	heightSpinBox->setSingleStep(singleStep);
}

QSpinBox* getSpinBox()
{
	auto spinBox = new QSpinBox();
	spinBox->setSuffix(" px");
	spinBox->setRange(0, INT_MAX);

	return spinBox;
}
