#include "tgraffitiprocessfactory.h"
#include "tnormalmultilayerpicturedisplay.h"
#include "tdrawoperationfilterwindow.h"
#include "tgraffitiprocessviewwidget.h"
#include "tlistprocessviewwidget.h"
#include <QToolButton>
#include "tgraphicsstackfilterwindow.h"
#include "tgraffitifilterwindowabstract.h"
#include "graffitiprocess.h"

TGraffitiProcessFactory::TGraffitiProcessFactory(QObject *parent)
	: TProcessFactoryAbstract(parent)
{}

TGraffitiProcessFactory::~TGraffitiProcessFactory()
{}

void TGraffitiProcessFactory::initializeProcess()
{
	//	picturedisplay
	setPictureDisplay(new TNormalMultilayerPictureDisplay());



	//	filterWindow
	auto drawOperationFilterWindow = new TDrawOperationFilterWindow();

	setFilterWindow(drawOperationFilterWindow);



	//	processViewWidget
	auto graffitiProcessViewWidget = new TGraffitiProcessViewWidget();

	auto listProcessViewWidget = new TListProcessViewWidget();
	listProcessViewWidget->addProcessViewWidget(graffitiProcessViewWidget);

	setProcessViewWidget(listProcessViewWidget);



	//	imageProcess
	auto graffitiProcess = new GraffitiProcess();

	graffitiProcess->setGraphicsStackFilterWindow(drawOperationFilterWindow->getGraphicsStackFilterWindow());

	setImageProcess(graffitiProcess);



	//	connect
	auto undo = graffitiProcessViewWidget->getUndoAction(), redo = graffitiProcessViewWidget->getRedoAction();

	connect(graffitiProcessViewWidget, &TGraffitiProcessViewWidget::graffitiChanged, [drawOperationFilterWindow, graffitiProcessViewWidget]()
		{
			auto graffitiFilterWindow = graffitiProcessViewWidget->createGraffitiFilterWindow();

			drawOperationFilterWindow->setGraffitiFilterWindow(graffitiFilterWindow);
		});
	connect(graffitiProcessViewWidget, &TGraffitiProcessViewWidget::penChanged, drawOperationFilterWindow->getGraffitiFilterWindow(), &TGraffitiFilterWindowAbstract::setPen);
	connect(graffitiProcessViewWidget, &TGraffitiProcessViewWidget::brushChanged, drawOperationFilterWindow->getGraffitiFilterWindow(), &TGraffitiFilterWindowAbstract::setBrush);
	connect(drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::arrivedBack, [undo](bool arrived)
		{
			undo->setEnabled(!arrived);
		});
	connect(drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::arrivedFront, [redo](bool arrived)
		{
			redo->setEnabled(!arrived);
		});
	connect(undo, &QAction::triggered, drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::fallbackGraphicsItem);
	connect(redo, &QAction::triggered, drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::forwardGraphicsItem);
	connect(graffitiProcess, &GraffitiProcess::processed, drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::clear);
}
