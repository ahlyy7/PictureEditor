#include "tinpaintprocessfactory.h"
#include "tnormalmultilayerpicturedisplay.h"
#include "tdrawoperationfilterwindow.h"
#include "tpolylinesgraffitifilterwindow.h"
#include "tinpaintprocessviewwidget.h"
#include "tlistprocessviewwidget.h"
#include "inpaintprocess.h"
#include "tinpaintmaskfunctionabstract.h"
#include "tgraphicsstackfilterwindow.h"

TInpaintProcessFactory::TInpaintProcessFactory(QObject *parent)
	: TProcessFactoryAbstract(parent)
{}

TInpaintProcessFactory::~TInpaintProcessFactory()
{}

void TInpaintProcessFactory::initializeProcess()
{
	//	picturedisplay
	setPictureDisplay(new TNormalMultilayerPictureDisplay());



	//	filterWindow
	auto drawOperationFilterWindow = new TDrawOperationFilterWindow();

	auto polylinesGraffitiFilterWindow = new TPolylinesGraffitiFilterWindow();
	QPen pen;

	QColor color(Qt::yellow);
	color.setAlpha(64);
	pen.setColor(color);

	pen.setStyle(Qt::SolidLine);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);

	polylinesGraffitiFilterWindow->setPen(pen);

	drawOperationFilterWindow->setGraffitiFilterWindow(polylinesGraffitiFilterWindow);

	setFilterWindow(drawOperationFilterWindow);



	//	processViewWidget
	auto inpaintProcessViewWidget = new TInpaintProcessViewWidget();

	auto listProcessViewWidget = new TListProcessViewWidget();
	listProcessViewWidget->addProcessViewWidget(inpaintProcessViewWidget);

	setProcessViewWidget(listProcessViewWidget);



	//	imageProcess
	auto inpaintProcess = new InpaintProcess();

	setImageProcess(inpaintProcess);



	//	connect
	auto undo = inpaintProcessViewWidget->getUndoAction(), redo = inpaintProcessViewWidget->getRedoAction();

	auto widthSlot = [drawOperationFilterWindow](double width)
		{
			auto graffitiFilterWindow = drawOperationFilterWindow->getGraffitiFilterWindow();

			auto pen = graffitiFilterWindow->getPen();
			pen.setWidthF(width);

			graffitiFilterWindow->setPen(pen);
		};
	widthSlot(10.0);
	connect(inpaintProcessViewWidget, &TInpaintProcessViewWidget::widthChanged, widthSlot);
	auto regionSelectionSlot = [inpaintProcessViewWidget, drawOperationFilterWindow, inpaintProcess]()
		{
			auto inpaintMaskFunction = inpaintProcessViewWidget->createInpaintMaskFunction();
			inpaintMaskFunction->setGraphicsStackFilterWindow(drawOperationFilterWindow->getGraphicsStackFilterWindow());

			inpaintProcess->setInpaintMaskFunction(inpaintMaskFunction);
		};
	regionSelectionSlot();
	connect(inpaintProcessViewWidget, &TInpaintProcessViewWidget::regionSelectionChanged, regionSelectionSlot);
	connect(inpaintProcessViewWidget, &TInpaintProcessViewWidget::inpaintFunctionChanged, inpaintProcess, &InpaintProcess::setInpaintFlag);
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
	connect(inpaintProcess, &InpaintProcess::inpaintFlagChanged, inpaintProcessViewWidget, &TInpaintProcessViewWidget::setInpaintFunction);
	connect(inpaintProcess, &InpaintProcess::processed, drawOperationFilterWindow->getGraphicsStackFilterWindow(), &TGraphicsStackFilterWindow::clear);
}
