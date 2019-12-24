#ifndef ARMFACE_H
#define ARMFACE_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "face.hpp"
#include <fstream>
#include <sstream>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlTableModel>
using namespace cv;
namespace Ui {
class ArmFace;
}

class ArmFace : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmFace(QWidget *parent = nullptr);
    ~ArmFace();

    QPixmap PixmapToRound(const QPixmap &src, int radius);
    int Predict(Mat src_image);
    void run_time();
    void show_time(int mm, QString dd,QString hhmm, QString dddd);
protected slots:
    void run();
    void run_message();
private slots:
    void on_openbt_clicked();

private:
    Ui::ArmFace *ui;
    QTimer mtimer,timer,messtimer;
    Mat cap,gray;
    VideoCapture capture;

    Ptr<face::FaceRecognizer> model;
    CascadeClassifier cascade;
    //检测的标签
    int detection,num,flag;
    QString time;

};

#endif // ARMFACE_H
