#include "ui_tnormalpicturedisplay.h"
#include "tnormalpicturedisplay.h"
#include <qevent.h>

TNormalPictureDisplay::TNormalPictureDisplay(QWidget *parent)
	: TPictureDisplayAbstract(parent)
	, ui(new Ui::normalPictureDisplayClass())
	, pixmapSize(0, 0)
{
	ui->setupUi(this);
}

TNormalPictureDisplay::~TNormalPictureDisplay()
{
	delete ui;
}

void TNormalPictureDisplay::setPixmap(const QPixmap& pixmap)
{
	ui->label->setPixmap(pixmap);
	pixmapSize = pixmap.size();
}

QSize TNormalPictureDisplay::getPixmapSize()
{
	return pixmapSize;
}
