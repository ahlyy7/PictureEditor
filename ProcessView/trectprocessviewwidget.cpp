#include "ui_trectprocessviewwidget.h"
#include "trectprocessviewwidget.h"

TRectProcessViewWidget::TRectProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TRectProcessViewWidgetClass())
	, settingRect(false)
{
	ui->setupUi(this);

	ui->width->setMinimumValue(10);
	ui->height->setMinimumValue(10);

	connect(ui->x, &TPixelProcessViewWidget::valueChanged, [this](int value)
		{
			emit xChanged(value);
			if (!settingRect)
				emit rectChanged(getRect());
		});
	connect(ui->y, &TPixelProcessViewWidget::valueChanged, [this](int value)
		{
			emit yChanged(value);
			if (!settingRect)
				emit rectChanged(getRect());
		});
	connect(ui->width, &TPixelProcessViewWidget::valueChanged, [this](int value)
		{
			emit widthChanged(value);
			if (!settingRect)
				emit rectChanged(getRect());
		});
	connect(ui->height, &TPixelProcessViewWidget::valueChanged, [this](int value)
		{
			emit heightChanged(value);
			if (!settingRect)
				emit rectChanged(getRect());
		});
}

TRectProcessViewWidget::~TRectProcessViewWidget()
{
	delete ui;
}

void TRectProcessViewWidget::setX(int x)
{
	ui->x->setValue(x);
}

int TRectProcessViewWidget::getX()
{
	return ui->x->getValue();
}

void TRectProcessViewWidget::setY(int y)
{
	ui->y->setValue(y);
}

int TRectProcessViewWidget::getY()
{
	return ui->y->getValue();
}

void TRectProcessViewWidget::setWidth(int width)
{
	ui->width->setValue(width);
}

int TRectProcessViewWidget::getWidth()
{
	return ui->width->getValue();
}

void TRectProcessViewWidget::setMaximumWidth(int maximumWidth)
{
	ui->x->setMaximumValue(maximumWidth);
	ui->width->setMaximumValue(maximumWidth);
}

int TRectProcessViewWidget::getMaximumWidth()
{
	return ui->width->getMaximumValue();
}

void TRectProcessViewWidget::setMinimumWidth(int minimumWidth)
{
	ui->width->setMinimumValue(minimumWidth);
}

int TRectProcessViewWidget::getMinimumWidth()
{
	return ui->width->getMinimumValue();
}

void TRectProcessViewWidget::setMinimumHeight(int minimumHeight)
{
	ui->height->setMinimumValue(minimumHeight);
}

int TRectProcessViewWidget::getMinimumHeight()
{
	return ui->height->getMinimumValue();
}

void TRectProcessViewWidget::setHeight(int height)
{
	ui->height->setValue(height);
}

int TRectProcessViewWidget::getHeight()
{
	return ui->height->getValue();
}

void TRectProcessViewWidget::setMaximumHeight(int maximumHeight)
{
	ui->y->setMaximumValue(maximumHeight);
	ui->height->setMaximumValue(maximumHeight);
}

int TRectProcessViewWidget::getMaximumHeight()
{
	return ui->height->getMaximumValue();
}

void TRectProcessViewWidget::setRect(const QRect& rect)
{
	settingRect = true;

	setX(rect.x());
	setY(rect.y());
	setWidth(rect.width());
	setHeight(rect.height());

	emit rectChanged(getRect());

	settingRect = false;
}

QRect TRectProcessViewWidget::getRect()
{
	return
	{
		getX(),
		getY(),
		getWidth(),
		getHeight()
	};
}
