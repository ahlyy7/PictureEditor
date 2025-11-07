#include "ui_tmultilayerpicturedisplayabstract.h"
#include "tmultilayerpicturedisplayabstract.h"
#include <QLayout>

TMultilayerPictureDisplayAbstract::TMultilayerPictureDisplayAbstract(QWidget *parent)
	: TPictureDisplayAbstract(parent)
	, ui(new Ui::TMultilayerPictureDisplayAbstractClass())
	, pictureDisplay(nullptr)
{
	ui->setupUi(this);
}

TMultilayerPictureDisplayAbstract::~TMultilayerPictureDisplayAbstract()
{
	delete ui;
}

void TMultilayerPictureDisplayAbstract::setPictureDisplayWidget(TPictureDisplayAbstract* widget)
{
	if (this->pictureDisplay == widget)
		return;

	delete this->pictureDisplay;
	this->pictureDisplay = widget;

	widget->setParent(this);
	delete layout();
	auto layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->addWidget(widget);
}

TPictureDisplayAbstract* TMultilayerPictureDisplayAbstract::pictureDisplayWidget()
{
	return pictureDisplay;
}
