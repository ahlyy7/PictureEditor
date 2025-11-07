#include "ui_tinpaintprocessviewwidget.h"
#include "tinpaintprocessviewwidget.h"
#include "tnormalinpaintmaskfunction.h"
#include "tgrabcutinpaintmaskfunction.h"
#include <opencv2/opencv.hpp>
#include "inpaintprocess.h"

TInpaintProcessViewWidget::TInpaintProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TInpaintProcessViewWidgetClass())
{
	ui->setupUi(this);

	ui->undoButton->setDefaultAction(ui->undo);
	ui->redoButton->setDefaultAction(ui->redo);

	connect(ui->penWidthSpinBox, &QDoubleSpinBox::valueChanged, [this](double width)
		{
			emit widthChanged(width);
		});
	connect(ui->manual, &QRadioButton::toggled, [this](bool checked)
		{
			if (checked)
				inpaintMaskFunction = []()
				{
					return new TNormalInpaintMaskFunction();
				};
			else
				inpaintMaskFunction = []()
				{
					return new TGrabCutInpaintMaskFunction();
				};

			emit regionSelectionChanged();
		});
	connect(ui->NS, &QRadioButton::toggled, [this](bool checked)
		{
			if (checked)
			{
				ui->TELEA->setChecked(false);
				emit inpaintFunctionChanged(cv::INPAINT_NS);
			}
			else if (!ui->TELEA->isChecked())
				emit inpaintFunctionChanged(InpaintProcess::initializeInpaintFlag);
		});
	connect(ui->TELEA, &QRadioButton::toggled, [this](bool checked)
		{
			if (checked)
			{
				ui->NS->setChecked(false);
				emit inpaintFunctionChanged(cv::INPAINT_TELEA);
			}
			else if (!ui->NS->isChecked())
				emit inpaintFunctionChanged(InpaintProcess::initializeInpaintFlag);
		});



	ui->penWidthSpinBox->setValue(10.0);
	ui->manual->click();
}

TInpaintProcessViewWidget::~TInpaintProcessViewWidget()
{
	delete ui;
}

QAction* TInpaintProcessViewWidget::getUndoAction()
{
	return ui->undo;
}

QAction* TInpaintProcessViewWidget::getRedoAction()
{
	return ui->redo;
}

TInpaintMaskFunctionAbstract* TInpaintProcessViewWidget::createInpaintMaskFunction()
{
	return inpaintMaskFunction();
}

void TInpaintProcessViewWidget::setInpaintFunction(int inpaintFlag)
{
	switch (inpaintFlag)
	{
	case cv::INPAINT_NS:
		ui->NS->setChecked(true);
		break;

	case cv::INPAINT_TELEA:
		ui->TELEA->setChecked(true);
		break;

	default:
		ui->NS->setChecked(false);
		ui->TELEA->setChecked(false);
		break;
	}
}

int TInpaintProcessViewWidget::getInpaintFunction() const
{
	if (ui->NS->isChecked())
		return cv::INPAINT_NS;

	if (ui->TELEA->isChecked())
		return cv::INPAINT_TELEA;

	return InpaintProcess::initializeInpaintFlag;
}
