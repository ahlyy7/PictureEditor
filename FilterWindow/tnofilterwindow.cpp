#include "ui_tnofilterwindow.h"
#include "tnofilterwindow.h"

void TNoFilterWindow::paintEvent(QPaintEvent* event)
{
}

TNoFilterWindow::TNoFilterWindow(QWidget *parent)
	: TFilterWindowAbstract(parent)
	, ui(new Ui::TNoFilterWindowClass())
{
	ui->setupUi(this);
}

TNoFilterWindow::~TNoFilterWindow()
{
	delete ui;
}
