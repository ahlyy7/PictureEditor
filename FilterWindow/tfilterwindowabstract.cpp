#include "ui_tfilterwindowabstract.h"
#include "tfilterwindowabstract.h"

double TFilterWindowAbstract::getScale() const
{
	return scale;
}

void TFilterWindowAbstract::resizeEvent(QResizeEvent* event)
{
	auto [imageWidth, imageHeight] = imageSize;
	auto [width, height] = size();

	scale = double(width) / imageWidth + double(height) / imageHeight;
	scale /= 2.0;
}

TFilterWindowAbstract::TFilterWindowAbstract(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TFilterWindowAbstractClass())
{
	ui->setupUi(this);
}

TFilterWindowAbstract::~TFilterWindowAbstract()
{
	delete ui;
}

void TFilterWindowAbstract::setImageSize(QSize imageSize)
{
	this->imageSize = imageSize;
}

QSize TFilterWindowAbstract::getImageSize() const
{
	return imageSize;
}
