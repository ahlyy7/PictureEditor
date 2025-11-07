#pragma once

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtWidgets/QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class TProcessFactoryAbstract;
class TMultilayerPictureDisplayAbstract;
class TScrollAreaPictureDisplay;
class TFilterPictureDisplay;
class PictureFile;
class ImageCache;
class AbstractImageProcess;

namespace cv
{
    class Mat;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    TProcessFactoryAbstract* processFactory;
    TMultilayerPictureDisplayAbstract* multilayerPictureDisplayWidget;
    TScrollAreaPictureDisplay* scrollAreaPictureWidget;
    TFilterPictureDisplay* filterPictureWidget;
    std::unique_ptr<PictureFile> pictureFile;
    const std::unique_ptr<ImageCache> imageCache;
    AbstractImageProcess* imageProcess;
    const std::unique_ptr<cv::Mat> currentPicture;

    bool areaWidgetChanged;

    void initializeConnect();
    void initializeMenu();

    void setProcessFactory(TProcessFactoryAbstract* processFactory);
    void setPictureWidgetAndImageProcess();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void setCentralWidget(QWidget* widget);
    QWidget* takeCentralWidget(QWidget* widget);

private slots:
    /*
    * 打开文件的情况下：
    * pictureFile != nullptr && !pictureFile->filePath().empty()
    * imageCache != nullptr && !imageCache->empty()
    * !filePathLabel->text().isEmpty()
    */
    void openPictureFile();
    void savePictureFile();
    void saveAsPictureFile();

    //  cache缓存变化
    void cacheEmptyed(bool empty);  //  cache不为空
    void cacheCurrentImageChanged();  //  cache当前图片变化

    void cacheArrivedFront(bool arrived);
    void cacheArrivedBack(bool arrived);

    //  actionButton
    void fallbackClicked();
    void forwardClicked();
    void widthAlignmentClicked();
    void heightAlignmentClicked();
    void resizeAlignmentClicked();
    /*
    * 关闭文件的情况下：
    * 和打开文件的情况相反
    */
    void closeImageClicked();

    //  pushButton
    void okButtonClicked();
    void resetButtonClicked();
    void cancelButtonClicked();

private:
    Ui::MainWindowClass* ui;
};

#endif // !_MAINWINDOW_H_
