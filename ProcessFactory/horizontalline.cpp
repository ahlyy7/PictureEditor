#include "ui_horizontalline.h"
#include "horizontalline.h"

HorizontalLine::HorizontalLine(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::HorizontalLineClass())
{
	ui->setupUi(this);

	setFixedHeight(ui->line->height());
}

HorizontalLine::~HorizontalLine()
{
	delete ui;
}
