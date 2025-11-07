// QtOpenCVPictureSupport.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "qtopencvpicturesupport.h"

#if QTOPENCVPICTURESUPPORT_VERSION == 1

cv::Mat toOpenCVPicture(const QImage& image)
{
    if (image.isNull())
        return cv::Mat();

    // 统一转换为 RGB888 格式
    QImage convertedImage = image;
    if (image.format() != QImage::Format_RGB888)
        convertedImage = image.convertToFormat(QImage::Format_RGB888);

    // 创建 cv::Mat（浅拷贝）
    cv::Mat cvMat(
        convertedImage.height(),
        convertedImage.width(),
        CV_8UC3,
        const_cast<uchar*>(convertedImage.bits()),
        static_cast<size_t>(convertedImage.bytesPerLine())
    );

    // 调整颜色通道顺序（RGB → BGR）
    cv::cvtColor(cvMat, cvMat, cv::COLOR_RGB2BGR);

    // 深拷贝数据（避免 QImage 释放后数据失效）
    cv::Mat cvMatCopy;
    cvMat.copyTo(cvMatCopy);

    return cvMatCopy;
}

QImage toQtPicture(const cv::Mat& mat)
{
    if (mat.empty())
        return {};

    // 处理数据深度和颜色转换
    cv::Mat rgbMat;
    switch (mat.type())
    {
    case CV_8UC3: // BGR彩色图
        cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2RGB);
        break;
    case CV_8UC1: // 灰度图
        rgbMat = mat;
        break;
    case CV_32FC3: // 浮点型数据（需归一化到0-255）
        mat.convertTo(rgbMat, CV_8UC3, 255.0);
        cv::cvtColor(rgbMat, rgbMat, cv::COLOR_BGR2RGB);
        break;
    default:
        return QImage(); // 不支持的类型
    }

    // 创建QImage
    QImage image(
        rgbMat.data,
        rgbMat.cols,
        rgbMat.rows,
        static_cast<int>(rgbMat.step),
        (rgbMat.channels() == 3) ? QImage::Format_RGB888 : QImage::Format_Grayscale8
    );

    // 深拷贝数据（避免Mat释放后数据失效）
    return image.copy();
}

#endif // QTOPENCVPICTURESUPPORT_VERSION == 1
