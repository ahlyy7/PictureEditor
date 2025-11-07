#include "ui_tsolidcolorfilterwindow.h"
#include "tsolidcolorfilterwindow.h"
#include <QPainter>

void TSolidColorFilterWindow::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	painter.setPen(Qt::NoPen);

	QColor color(red, green, blue, alpha);
	painter.setBrush(color);

	painter.drawRect(QRect({ 0, 0 }, size()));
}

void TSolidColorFilterWindow::setRgb(int red, int green, int blue, int alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;

	this->alpha = alpha;
}

void TSolidColorFilterWindow::setAlpha(int alpha)
{
	this->alpha = alpha;
}

TSolidColorFilterWindow::TSolidColorFilterWindow(QWidget *parent)
	: TFilterWindowAbstract(parent)
	, ui(new Ui::TNormalFilterWindowClass())
{
	ui->setupUi(this);

	setRgb(0, 0, 0);
}

TSolidColorFilterWindow::~TSolidColorFilterWindow()
{
	delete ui;
}
