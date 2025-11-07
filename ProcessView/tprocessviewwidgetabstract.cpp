#include "ui_tprocessviewwidgetabstract.h"
#include "tprocessviewwidgetabstract.h"

TProcessViewWidgetAbstract::TProcessViewWidgetAbstract(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ProcessViewWidgetAbstractClass())
{
	ui->setupUi(this);
}

TProcessViewWidgetAbstract::~TProcessViewWidgetAbstract()
{
	delete ui;
}
