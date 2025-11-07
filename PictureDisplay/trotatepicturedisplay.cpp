#include "ui_trotatepicturedisplay.h"
#include "trotatepicturedisplay.h"
#include "qtopencvpicturesupport.h"
#include "freerotateprocess.h"
#include <QVBoxLayout>

void TRotatePictureDisplay::paintPixmap()
{
	if (interpolationFlags == FreeRotateProcess::initializeInterpolationFlags)
	{
		pictureWidget->setPixmap({});
		return;
	}

	cv::Mat rotatedPixmap;
	pixmap->copyTo(rotatedPixmap);

	FreeRotateProcess::rotate(&rotatedPixmap, angle, scale, size, interpolationFlags, borderColor);

	auto image = toQtPicture(rotatedPixmap);
	pictureWidget->setPixmap(QPixmap::fromImage(image));
}

TRotatePictureDisplay::TRotatePictureDisplay(QWidget *parent)
	: TPictureDisplayAbstract(parent)
	, ui(new Ui::TRotatePictureDisplayClass())
	, pictureWidget(nullptr)
	, pixmap(new cv::Mat())
	, angle(0.0)
	, scale(1.0)
	, interpolationFlags(FreeRotateProcess::initializeInterpolationFlags)
	, borderColor(FreeRotateProcess::initializeBorderColor)
{
	ui->setupUi(this);
}

TRotatePictureDisplay::~TRotatePictureDisplay()
{
	delete ui;
}

void TRotatePictureDisplay::setPictureDisplayWidget(TPictureDisplayAbstract* widget)
{
	if (this->pictureWidget == widget)
		return;

	delete this->pictureWidget;
	this->pictureWidget = widget;
	layout()->addWidget(widget);

	paintPixmap();
}

TPictureDisplayAbstract* TRotatePictureDisplay::pictureDisplayWidget()
{
	return pictureWidget;
}

void TRotatePictureDisplay::setPixmap(const QPixmap& pixmap)
{
	*this->pixmap = toOpenCVPicture(pixmap.toImage());
	paintPixmap();

	emit pixmapChanged(this->pixmap.get());
}

QSize TRotatePictureDisplay::getPixmapSize()
{
	return pictureWidget ? pictureWidget->getPixmapSize() : QSize(0, 0);
}

const cv::Mat* TRotatePictureDisplay::getPixmap()
{
	return pixmap.get();
}

void TRotatePictureDisplay::setSize(cv::Size size)
{
	if (this->size == size)
		return;

	this->size = size;
	paintPixmap();

	emit sizeChanged(size);
}

cv::Size TRotatePictureDisplay::getSize()
{
	return size;
}

void TRotatePictureDisplay::setAngle(double angle)
{
	if (this->angle == angle)
		return;

	this->angle = angle;
	paintPixmap();

	emit angleChanged(angle);
}

double TRotatePictureDisplay::getAngle()
{
	return angle;
}

void TRotatePictureDisplay::setScale(double scale)
{
	if (this->scale == scale)
		return;

	this->scale = scale;
	paintPixmap();

	emit scaleChanged(scale);
}

double TRotatePictureDisplay::getScale()
{
	return scale;
}

void TRotatePictureDisplay::setInterpolationFlags(cv::InterpolationFlags interpolationFlags)
{
	if (this->interpolationFlags == interpolationFlags)
		return;

	this->interpolationFlags = interpolationFlags;
	paintPixmap();

	emit interpolationFlagsChanged(interpolationFlags);
}

cv::InterpolationFlags TRotatePictureDisplay::getInterpolationFlags()
{
	return interpolationFlags;
}

void TRotatePictureDisplay::setBorderColor(cv::Vec4b borderColor)
{
	if (this->borderColor == borderColor)
		return;

	this->borderColor = borderColor;
	paintPixmap();

	emit borderColorChanged(borderColor);
}

cv::Vec4b TRotatePictureDisplay::getBorderColor()
{
	return borderColor;
}
