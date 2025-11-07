#include "ui_tnormalmultilayerpicturedisplay.h"
#include "tnormalmultilayerpicturedisplay.h"

TNormalMultilayerPictureDisplay::TNormalMultilayerPictureDisplay(QWidget *parent)
	: TMultilayerPictureDisplayAbstract(parent)
	, ui(new Ui::TNormalMultilayerPictureDisplayClass())
{
	ui->setupUi(this);
}

TNormalMultilayerPictureDisplay::~TNormalMultilayerPictureDisplay()
{
	delete ui;
}

void TNormalMultilayerPictureDisplay::setPixmap(const QPixmap& pixmap)
{
	pictureDisplay->setPixmap(pixmap);
}

QSize TNormalMultilayerPictureDisplay::getPixmapSize()
{
	return pictureDisplay->getPixmapSize();
}
