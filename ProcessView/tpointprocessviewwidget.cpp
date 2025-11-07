#include "ui_tpointprocessviewwidget.h"
#include "tpointprocessviewwidget.h"

TPointProcessViewWidget::TPointProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TPointProcessViewWidgetClass())
	, functionSetting(false)
{
	ui->setupUi(this);

	connect(ui->x, &QDoubleSpinBox::valueChanged, [this](double value)
		{
			if (functionSetting)
				return;

			emit pointChanged({ value, ui->y->value() });
		});
	connect(ui->y, &QDoubleSpinBox::valueChanged, [this](double value)
		{
			if (functionSetting)
				return;

			emit pointChanged({ ui->x->value(), value });
		});
}

TPointProcessViewWidget::~TPointProcessViewWidget()
{
	delete ui;
}

void TPointProcessViewWidget::setPoint(const QPointF& point)
{
	auto [x, y] = point;
	if (ui->x->value() == x && ui->y->value() == y)
		return;

	functionSetting = true;

	ui->x->setValue(x);
	ui->y->setValue(y);

	functionSetting = false;

	emit pointChanged(point);
}

QPointF TPointProcessViewWidget::getPoint()
{
	return { ui->x->value(), ui->y->value() };
}

void TPointProcessViewWidget::setMaximumPoint(const QPointF& point)
{
	ui->x->setMaximum(point.x());
	ui->y->setMaximum(point.y());
}

QPointF TPointProcessViewWidget::getMaximumPoint()
{
	return { ui->x->maximum(), ui->y->maximum() };
}
