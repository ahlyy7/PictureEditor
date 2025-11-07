#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QFileDialog>
#include "picturefilesupport.h"
#include "tscrollareapicturedisplay.h"
#include "qtopencvpicturesupport.h"
#include "picturefile.h"
#include <QMessageBox>
#include "qtstdstringsupport.h"
#include "tfilterpicturedisplay.h"
#include "tnormalpicturedisplay.h"
#include "tfilterwindowabstract.h"
#include "tnoprocessfactory.h"
#include "tgrayscaleprocessfactory.h"
#include "tbinarizationprocessfactory.h"
#include "tsimpeblurprocessfactory.h"
#include "tmedianblurprocessfactory.h"
#include "tgaussianblurprocessfactory.h"
#include "tbilateralblurprocessfactory.h"
#include "tflipprocessfactory.h"
#include "tfastcompressionprocessfactory.h"
#include "tfreecompressionprocessfactory.h"
#include "tsimplerotateprocessfactory.h"
#include "tfreerotateprocessfactory.h"
#include "tnormalcropprocessfactory.h"
#include "tanycropprocessfactory.h"
#include "tlightnessadjustprocessfactory.h"
#include "tcontrastadjustprocessfactory.h"
#include "tequalizehistprocessfactory.h"
#include "tsaturationadjustprocessfactory.h"
#include "tsharpnessadjustprocessfactory.h"
#include "tbrightthreshscaleadjustprocessfactory.h"
#include "tdarkthreshscaleadjustprocessfactory.h"
#include "tgraffitiprocessfactory.h"
#include "tinpaintprocessfactory.h"
#include "tprocessviewwidgetabstract.h"
#include "abstractimageprocess.h"
#include "imagecache.h"
#include <opencv2/opencv.hpp>
#include "ui_extendtoolbar.h"
#include "ui_filtermenu.h"
#include "ui_compressionmenu.h"
#include "ui_trimmenu.h"
#include "ui_adjustmenu.h"
#include "ui_alteredmenu.h"
#include <numeric>

const QString allFileSuffix = "全部文件(*.*)";

QString getFileSuffix();

void MainWindow::initializeConnect()
{
    connect(ui->openPicture, &QAction::triggered, this, &MainWindow::openPictureFile);
    connect(ui->notOpenWidget, &TNotOpenWidget::clicked, this, &MainWindow::openPictureFile);

    connect(ui->savePicture, &QAction::triggered, this, &MainWindow::savePictureFile);

    connect(ui->saveAsPicture, &QAction::triggered, this, &MainWindow::saveAsPictureFile);

    //  imageCache
    connect(imageCache.get(), &ImageCache::emptyed, this, &MainWindow::cacheEmptyed);
    connect(imageCache.get(), &ImageCache::currentImageChanged, this, &MainWindow::cacheCurrentImageChanged);
    connect(imageCache.get(), &ImageCache::arrivedFront, this, &MainWindow::cacheArrivedFront);
    connect(imageCache.get(), &ImageCache::arrivedBack, this, &MainWindow::cacheArrivedBack);

    //  actionButton
    connect(ui->fallback, &QAction::triggered, this, &MainWindow::fallbackClicked);
    connect(ui->forward, &QAction::triggered, this, &MainWindow::forwardClicked);
    connect(ui->widthAlignment, &QAction::triggered, this, &MainWindow::widthAlignmentClicked);
    connect(ui->heightAlignment, &QAction::triggered, this, &MainWindow::heightAlignmentClicked);
    connect(ui->resizeAlignment, &QAction::triggered, this, &MainWindow::resizeAlignmentClicked);
    connect(ui->closeImage, &QAction::triggered, this, &MainWindow::closeImageClicked);

    //  pushButton
    connect(ui->okButton, &QPushButton::clicked, this, &MainWindow::okButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &MainWindow::cancelButtonClicked);
}

void MainWindow::initializeMenu()
{
    //  filterMenu
    QMenu* menu = new QMenu(ui->menuBar);
    Ui::FilterMenu filterMenu;
    filterMenu.setupUi(menu);

    //  filterMenu.connect
    connect(filterMenu.grayscale, &QAction::triggered, [this]()
        {
            setProcessFactory(new TGrayscaleProcessFactory());
        });
    connect(filterMenu.binarization, &QAction::triggered, [this]()
        {
            setProcessFactory(new TBinarizationProcessFactory());
        });
    connect(filterMenu.simpeBlur, &QAction::triggered, [this]()
        {
            setProcessFactory(new TSimpeBlurProcessFactory());
        });
    connect(filterMenu.medianBlur, &QAction::triggered, [this]()
        {
            setProcessFactory(new TMedianBlurProcessFactory());
        });
    connect(filterMenu.gaussianBlur, &QAction::triggered, [this]()
        {
            setProcessFactory(new TGaussianBlurProcessFactory());
        });
    connect(filterMenu.bilateralBlur, &QAction::triggered, [this]()
        {
            setProcessFactory(new TBilateralBlurProcessFactory());
        });

    ui->menuBar->addMenu(menu);



    //  compressionMenu
    menu = new QMenu(ui->menuBar);
    Ui::CompressionMenu compressionMenu;
    compressionMenu.setupUi(menu);

    //  compressionMenu.connect
    connect(compressionMenu.fastCompression, &QAction::triggered, [this]()
        {
            setProcessFactory(new TFastCompressionProcessFactory());
        });
    connect(compressionMenu.freeCompression, &QAction::triggered, [this]()
        {
            setProcessFactory(new TFreeCompressionProcessFactory());
        });

    ui->menuBar->addMenu(menu);



    //  trimMenu
    menu = new QMenu(ui->menuBar);
    Ui::TrimMenu trimMenu;
    trimMenu.setupUi(menu);

    //  trimMenu.connect
    connect(trimMenu.flip, &QAction::triggered, [this]()
        {
            setProcessFactory(new TFlipProcessFactory());
        });
    connect(trimMenu.simpleRotate, &QAction::triggered, [this]()
        {
            setProcessFactory(new TSimpleRotateProcessFactory());
        });
    connect(trimMenu.freeRotate, &QAction::triggered, [this]()
        {
            setProcessFactory(new TFreeRotateProcessFactory());
        });
    connect(trimMenu.normalCropping, &QAction::triggered, [this]()
        {
            setProcessFactory(new TNormalCropProcessFactory());
        });
    connect(trimMenu.anyCropping, &QAction::triggered, [this]()
        {
            setProcessFactory(new TAnyCropProcessFactory());
        });

    ui->menuBar->addMenu(menu);



    //  adjustMenu
    menu = new QMenu(ui->menuBar);
    Ui::AdjustMenu adjustMenu;
    adjustMenu.setupUi(menu);

    //  adjustMenu.connect
    connect(adjustMenu.lightnessAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TLightnessAdjustProcessFactory());
        });
    connect(adjustMenu.contrastAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TContrastAdjustProcessFactory());
        });
    connect(adjustMenu.equalizeHist, &QAction::triggered, [this]()
        {
            setProcessFactory(new TEqualizeHistProcessFactory());
        });
    connect(adjustMenu.saturationAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TSaturationAdjustProcessFactory());
        });
    connect(adjustMenu.sharpnessAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TSharpnessAdjustProcessFactory());
        });
    connect(adjustMenu.brightAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TBrightThreshScaleAdjustProcessFactory());
        });
    connect(adjustMenu.darkAdjust, &QAction::triggered, [this]()
        {
            setProcessFactory(new TDarkThreshScaleAdjustProcessFactory());
        });

    ui->menuBar->addMenu(menu);



    //  alteredMenu
    menu = new QMenu(ui->menuBar);
    Ui::AlteredMenu alteredMenu;
    alteredMenu.setupUi(menu);

    //  alteredMenu.connect
    connect(alteredMenu.graffiti, &QAction::triggered, [this]()
        {
            setProcessFactory(new TGraffitiProcessFactory());
        });
    connect(alteredMenu.inpaint, &QAction::triggered, [this]()
        {
            setProcessFactory(new TInpaintProcessFactory());
        });

    ui->menuBar->addMenu(menu);



    for (auto& menu : ui->menuBar->findChildren<QMenu*>(Qt::FindDirectChildrenOnly))
    {
        if (menu == ui->menuFile)
            continue;

        menu->setEnabled(false);
    }
}

void MainWindow::setProcessFactory(TProcessFactoryAbstract* processFactory)
{
    if (this->processFactory == processFactory)
        return;

    delete this->processFactory;

    processFactory->setParent(this);
    processFactory->initializeProcess();



    //	picturedisplay
    //filterPictureWidget->setPictureDisplayWidget(processFactory->getPictureDisplay());
    scrollAreaPictureWidget->setParent(nullptr);
    delete multilayerPictureDisplayWidget;
    multilayerPictureDisplayWidget = processFactory->getPictureDisplay();
    if (!centralWidget())
        setCentralWidget(multilayerPictureDisplayWidget);
    multilayerPictureDisplayWidget->setPictureDisplayWidget(scrollAreaPictureWidget);

    //  filterWindow
    filterPictureWidget->setBeforeFilterWindow(processFactory->getFilterWindow());

    //  processViewWidget
    delete ui->scrollAreaWidgetContents->findChild<QWidget*>(Qt::FindDirectChildrenOnly);
    auto processViewWidget = processFactory->getProcessViewWidget();
    processViewWidget->setParent(this);
    auto width = processViewWidget->sizeHint().width() + 72;
    ui->dockWidget->setFixedWidth(width);
    ui->scrollAreaWidgetContents->layout()->addWidget(processViewWidget);

    //  imageProcess
    delete imageProcess;
    imageProcess = processFactory->getImageProcess();
    imageProcess->setParent(this);

    //  connect
    auto setOkButtonEnable = [this](bool enable)
        {
            ui->okButton->setEnabled(enable);
        };
    connect(imageProcess, &AbstractImageProcess::processableChanged, this, setOkButtonEnable);
    connect(imageProcess, &AbstractImageProcess::processed, this, [this]()
        {
            imageCache->pushImage(*currentPicture);
        });
    auto setResetButtonEnable = [this](bool reset)
        {
            ui->resetButton->setEnabled(reset);
        };
    connect(imageProcess, &AbstractImageProcess::resetableChanged, setResetButtonEnable);

    //  initialize
    if (!currentPicture->empty())
        setPictureWidgetAndImageProcess();
    setOkButtonEnable(imageProcess->processable());
    setResetButtonEnable(imageProcess->resetable());

    //  ui->dockWidget设置标题为操作名
    ui->dockWidget->setWindowTitle(imageProcess->processName());
    //  ui->cancelButton
    ui->cancelButton->setEnabled(typeid(*processFactory) != typeid(TNoProcessFactory));



    this->processFactory = processFactory;
}

void MainWindow::setPictureWidgetAndImageProcess()
{
    //  pictureWidget
    auto image = toQtPicture(*currentPicture);
    QPixmap pixmap = QPixmap::fromImage(image);
    multilayerPictureDisplayWidget->setPixmap(pixmap);

    //  imageProcess
    imageProcess->setImage(currentPicture.get());
    filterPictureWidget->getBeforeFilterWindow()->setImageSize(pixmap.size());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClass())
    , processFactory(nullptr)
    , multilayerPictureDisplayWidget(nullptr)
    , scrollAreaPictureWidget(nullptr)
    , filterPictureWidget(nullptr)
    , pictureFile(nullptr)
    , imageCache(new ImageCache())
    , imageProcess(nullptr)
    , currentPicture(new cv::Mat())
{
    ui->setupUi(this);

    //  设置中心组件位notOpenWidget
    setCentralWidget(ui->notOpenWidget);

    //  mainToolBar
    auto closeWidget = new QWidget();
    Ui::ExtendToolBarClass ExtendToolBarClassUi;
    ExtendToolBarClassUi.setupUi(closeWidget);
    ExtendToolBarClassUi.toolButton->setDefaultAction(ui->closeImage);
    ui->mainToolBar->addWidget(closeWidget);

    //  menuBar
    initializeMenu();

    //  初始化连接
    initializeConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCentralWidget(QWidget* widget)
{
    QMainWindow::setCentralWidget(widget);
    ui->centralWidget = widget;
}

QWidget* MainWindow::takeCentralWidget(QWidget* widget)
{
    auto result = QMainWindow::takeCentralWidget();
    if (result)
    {
        result->setParent(this);
        result->hide();
    }

    setCentralWidget(widget);
    widget->show();

    return result;
}

void MainWindow::savePictureFile()
{
    if (!pictureFile || pictureFile->filePath().empty())
        return;

    bool ok = pictureFile->save(*currentPicture);
    auto fileName = toQtString(pictureFile->filePath());

    if (!ok)
    {
        QMessageBox::critical(this, "错误", "图片：\n" + fileName + " 保存失败");
        return;
    }

    ui->statusBar->showMessage("文件已保存", 3000);
}

void MainWindow::saveAsPictureFile()
{
    if (!pictureFile || pictureFile->filePath().empty())
        return;

    auto fileName = QFileDialog::getSaveFileName(this, "另存为", QDir::homePath(), getFileSuffix());
    if (fileName.isEmpty())
        return;

    PictureFile pictureFile(toStdString(fileName));

    bool ok = pictureFile.save(*currentPicture);

    if (!ok)
    {
        QMessageBox::critical(this, "错误", "图片：\n" + fileName + "保存失败");
        return;
    }

    ui->statusBar->showMessage("文件已保存", 3000);
}

void MainWindow::cacheEmptyed(bool empty)
{
    if (empty)
    {
        takeCentralWidget(ui->notOpenWidget);
        pictureFile->setFilePath("");

        //  ExtendToolBarClass
        auto filePathLabel = ui->mainToolBar->findChild<QLineEdit*>("filePathLabel");
        filePathLabel->setText("");
    }
    else
    {
        takeCentralWidget(multilayerPictureDisplayWidget);
    }

    ui->mainToolBar->setEnabled(!empty);
    ui->dockWidgetContents->setEnabled(!empty);

    for (auto menu : ui->menuBar->findChildren<QMenu*>(Qt::FindDirectChildrenOnly))
    {
        if (menu == ui->menuFile)
            continue;

        menu->setEnabled(!empty);
    }
}

void MainWindow::cacheCurrentImageChanged()
{
    *currentPicture = imageCache->getCurrentImage();

    setPictureWidgetAndImageProcess();
}

void MainWindow::cacheArrivedFront(bool arrived)
{
    ui->forward->setEnabled(!arrived);
}

void MainWindow::cacheArrivedBack(bool arrived)
{
    ui->fallback->setEnabled(!arrived);
}

void MainWindow::fallbackClicked()
{
    imageCache->fallbackImage();
}

void MainWindow::forwardClicked()
{
    imageCache->forwardImage();
}

void MainWindow::widthAlignmentClicked()
{
    auto scale = double(scrollAreaPictureWidget->getChangeSize().width()) / scrollAreaPictureWidget->getPixmapSize().width();
    auto width = scrollAreaPictureWidget->width();
    scrollAreaPictureWidget->scaleToWidth(lround(width * scale));
}

void MainWindow::heightAlignmentClicked()
{
    auto scale = double(scrollAreaPictureWidget->getChangeSize().height()) / scrollAreaPictureWidget->getPixmapSize().height();
    auto height = scrollAreaPictureWidget->height();
    scrollAreaPictureWidget->scaleToHeight(lround(height * scale));
}

void MainWindow::resizeAlignmentClicked()
{
    scrollAreaPictureWidget->setScale(1.0F);
}

void MainWindow::closeImageClicked()
{
    imageCache->clear();
}

void MainWindow::okButtonClicked()
{
    imageProcess->tryProcess();
}

void MainWindow::resetButtonClicked()
{
    imageProcess->resetArg();
}

void MainWindow::cancelButtonClicked()
{
    setProcessFactory(new TNoProcessFactory());
}

void MainWindow::openPictureFile()
{
    using std::string;

    QString pictureFileSuffix = getFileSuffix();

    QString fileName;
    if (pictureFile)
    {
        QFileInfo fileInfo(toQtString(pictureFile->filePath()));
        fileName = fileInfo.path();
    }
    else
        fileName = QDir::homePath();
    fileName = QFileDialog::getOpenFileName(this, "打开图片", fileName, pictureFileSuffix + ";; " + allFileSuffix);
    if (fileName.isEmpty())
        return;

    //  加载功能
    if (!pictureFile)
        pictureFile = std::unique_ptr<PictureFile>(new PictureFile());

    auto oldFileName = pictureFile->filePath();
    pictureFile->setFilePath(toStdString(fileName));
    bool loaded = pictureFile->load();
    if (!loaded)
    {
        //  打不开的情况下设置回原来的地址
        pictureFile->setFilePath(oldFileName);
        QMessageBox::critical(this, "错误", "图片文件：\n" + fileName + "无法打开");
        return;
    }



    //  打开功能
    if (!scrollAreaPictureWidget)
    {
        filterPictureWidget = new TFilterPictureDisplay(this);
        filterPictureWidget->setPictureDisplayWidget(new TNormalPictureDisplay());
        /*auto filterWindow = new TRectHollowFilterWindow(this);
        filterWindow->setFrameRect({ 100, 100, 600, 400 });
        QPen pen;
        pen.setJoinStyle(Qt::PenJoinStyle::RoundJoin);
        pen.setColor({ 255, 0, 0 });
        pen.setWidth(3);
        filterWindow->setFramePen(pen);
        filterWindow->setInRgb(0, 0, 0, 0);
        filterWindow->setOutRgb(0, 255, 255, 64);*/



        scrollAreaPictureWidget = new TScrollAreaPictureDisplay(this);
        scrollAreaPictureWidget->setPictureDisplayWidget(filterPictureWidget);

        scrollAreaPictureWidget->setMinScale(0.1F);
        scrollAreaPictureWidget->setMaxScale(2.0F);

        connect(scrollAreaPictureWidget, &TScrollAreaPictureDisplay::scaleChanged, this, [this](double scale)
            {
                ui->resizeAlignment->setEnabled(scale != 1.0);
            });
        auto displaySizeChanged = [this](QSize size)
            {
                Q_UNUSED(size);

                auto [width, height] = scrollAreaPictureWidget->size();
                auto [imageWidth, imageHeight] = scrollAreaPictureWidget->scaleSize();

                ui->widthAlignment->setEnabled(width != imageWidth);
                ui->heightAlignment->setEnabled(height != imageHeight);
            };
        connect(scrollAreaPictureWidget, &TScrollAreaPictureDisplay::displaySizeChanged, this, displaySizeChanged);
        connect(scrollAreaPictureWidget, &TScrollAreaPictureDisplay::sizeChanged, this, displaySizeChanged);
    }

    setProcessFactory(new TNoProcessFactory(this));

    imageCache->clear();
    imageCache->pushImage(pictureFile->getPicture());

    //  打开成功
    //  设置新文件名
    pictureFile->setFilePath(toStdString(fileName));
    //  ExtendToolBarClass
    auto filePathLabel = ui->mainToolBar->findChild<QLineEdit*>("filePathLabel");
    filePathLabel->setText(fileName);
}

QString getFileSuffix()
{
    auto suffixList = getPictureFileSupport();
    
    QString pictureFileSuffix = "图片文件(";
    for (const auto& suffix : suffixList)
        pictureFileSuffix.append(suffix).append(' ');
    if (suffixList.empty())
        pictureFileSuffix.push_back(')');
    else
        pictureFileSuffix.back() = ')';

    return pictureFileSuffix;
}
