#include "armface.h"
#include "ui_armface.h"

#include <QBitmap>
#include <QPainter>
#include <QLine>
#include <QDebug>
#include <QMessageBox>

//12个月的缩写
QString mouth[12] = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};


ArmFace::ArmFace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmFace)
{
    ui->setupUi(this);
    int flag = 0;
    num = 0;
    detection = 0;
    this->setStyleSheet("QMainWindow{ background-color:rgb(32, 54, 62);}");
    connect(&mtimer,&QTimer::timeout,this,&ArmFace::run);
    ui->openbt->setStyleSheet("border-image:url(:/close.png)");

    connect(&timer,&QTimer::timeout,this,&ArmFace::run_time);
    timer.start(1000);

    //添加数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名
    db.setDatabaseName("F:\\video\\stuface.db");
    //打开数据库
    if(!db.open())
    {
        qDebug()<<"open error";
    }

    run_message();
    connect(&messtimer,&QTimer::timeout,this,&ArmFace::run_message);
    //每隔5分钟更新通知栏消息
    messtimer.start(1000*60*5);

    //获取今天日期
    time = QDateTime::currentDateTime().toString("MM-dd");


}

ArmFace::~ArmFace()
{
    delete ui;
    messtimer.stop();
}

//查询通知消息
void ArmFace::run_message()
{
    flag = 0;
    QString sql_select = QString("select * from Release ");
    QSqlQuery query_select(sql_select);

    while(query_select.next())
    {
       flag++;
       qDebug()<<flag;
    }
    int m = flag-1;
    flag = 0;
    QSqlQuery query(sql_select);
    while (query.next()) {

        if(flag == m)
        {
            QString title = query.value(0).toString();
            QString content = query.value(1).toString();
            qDebug()<<title<<content;
            ui->titlelabel->setText(title);
            ui->contentlabel->setText(content);
            ui->datalabel->setText(query.value(2).toString());

        }
        flag++;
    }
}

//将时间改变相应的格式显示在相应的label中
void ArmFace::show_time(int mm,QString dd, QString hhmm,QString dddd)
{
    //显示时间
    ui->label_4->setText(hhmm);
    QString week;
    if(dddd == "星期一") week = "Monday";
    else if(dddd == "星期二") week = "Tuesday";
    else if(dddd == "星期三") week = "Wednesday";
    else if(dddd == "星期四") week = "Thursday";
    else if(dddd == "星期五") week = "Friday";
    else if(dddd == "星期六") week = "Saturday";
    else if(dddd == "星期天") week = "Sunday";
    QString data = week+" "+mouth[mm-1]+" "+dd;
    ui->label_5->setText(data);

}
void ArmFace::run_time()
{
    //获取当前时间
    QString time = QDateTime::currentDateTime().toString("MM dd hh:mm dddd");
    int mm = time.mid(0,2).toInt();
    QString dd = time.mid(3,2);
    QString hhmm = time.mid(6,5);
    QString dddd  = time.mid(12,4);
    show_time(mm,dd,hhmm,dddd);
    /*qDebug()<<mm;
    qDebug()<<hhmm;
    qDebug()<<dddd;
    qDebug()<<time;*/
}

void ArmFace::on_openbt_clicked()
{
    capture.open(0);
    //训练好的文件名称，放置在可执行文件同目录下
    cascade.load("haarcascade_frontalface_alt2.xml");
    model = face::FisherFaceRecognizer::create();
    //1.加载训练好的分类器
    model->read("F:\\video\\AdminFace\\MyFaceFisherModel.xml");

    ui->openbt->setStyleSheet("border-image:url(:/open.png)");
    mtimer.start(20);
}
QPixmap ArmFace::PixmapToRound(const QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 150, 150);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}
int ArmFace::Predict(Mat src_image)
{
    Mat face_test;
       int predict = 0;
       //截取的ROI人脸尺寸调整
       if (src_image.rows >= 120)
       {
           //改变图像大小，使用双线性差值
           ::resize(src_image, face_test, Size(92, 112));

       }
       //判断是否正确检测ROI
       if (!face_test.empty())
       {
           //测试图像应该是灰度图
           predict = model->predict(face_test);
       }
       return predict;
}

void ArmFace::run()
{
    capture>>cap;
    std::vector<Rect> faces(0);//建立用于存放人脸的向量容器
    cvtColor(cap, gray, CV_RGB2GRAY);//测试图像必须为灰度图
    equalizeHist(gray, gray); //变换后的图像进行直方图均值化处理
    //检测人脸
    cascade.detectMultiScale(gray, faces,
        1.1, 4, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        | CV_HAAR_DO_ROUGH_SEARCH,
        //| CV_HAAR_SCALE_IMAGE,
        Size(30, 30), Size(500, 500));
    Mat* pImage_roi = new Mat[faces.size()];    //定以数组
    Mat face;
    Point text_lb;//文本写在的位置
    //框出人脸
    String str;
    if(faces.size()==1){
    for (int i = 0; i < faces.size(); i++)
    {
        pImage_roi[i] = gray(faces[i]); //将所有的脸部保存起来
        text_lb = Point((faces[i].x+faces[i].width)/2, faces[i].y);
        if (pImage_roi[i].empty())
            continue;

        //根据编号查询数据库
        qDebug()<<"dect"<<detection<<"pre"<<Predict(pImage_roi[i]);

        if(detection == Predict(pImage_roi[i]))
        {
             num++;
             qDebug()<<"num"<<num;
             if(num == 5 || flag ==1)
             {
                 //判断是否打卡，已打则不进行打卡
                 QString Time = time+"%";
                 QString sql_select = QString("select * from Attend where Sno='%1'and Time like '%2'").arg(Predict(pImage_roi[i])).arg(Time);
                 QSqlQuery query_select(sql_select);
                 while(query_select.next())
                 {
                     QString sql = QString("select * from Stu where Sno='%1'").arg(Predict(pImage_roi[i]));
                     QSqlQuery query(sql);
                     while(query.next())
                     {
                         num = 0;
                         flag = 0;
                         detection = 0;
                         qDebug()<<query.value(0).toInt()<<query.value(1).toString()<<query.value(2).toString();
                         QString message = query.value(2).toString()+"，您已打卡";
                         QMessageBox::about(this,"提示",message);

                         mtimer.stop();
                         capture.release();
                         ui->openbt->setStyleSheet("border-image:url(:/close.png)");
                         return ;
                     }
                    qDebug()<<"您已打卡";
                    return ;
                 }

                 //根据编号查询数据库
                 QString sql = QString("select * from Stu where Sno='%1'").arg(Predict(pImage_roi[i]));
                 QSqlQuery query(sql);
                 while(query.next())
                 {
                     num = 0;
                     flag = 0;
                     detection = 0;
                     qDebug()<<query.value(0).toInt()<<query.value(1).toString()<<query.value(2).toString();
                     //qDebug()<<"登录成功";
                     QString message = query.value(2).toString()+": 打卡成功";
                     QMessageBox::about(this,"提示",message);
                     //Menu *w = new Menu();
                     //w->show();
                     mtimer.stop();
                     capture.release();
                     ui->openbt->setStyleSheet("border-image:url(:/close.png)");

                     //ui->label_2->setStyleSheet("background-color: rgb(14, 49, 52);");
                     //ui->label_2->clear();

                     //将打卡信息存在Attend中
                     QString time = QDateTime::currentDateTime().toString("MM-dd hh:mm");
                     QString sql = QString("insert into Attend(Sno,time,State) values(%1,'%2',%3)")
                             .arg(Predict(pImage_roi[i]))
                             .arg(time)
                             .arg(1);
                     //qDebug()<<sql;

                     QSqlQuery query;
                     if(!query.exec(sql))
                     {

                         qDebug()<<"add error";
                     }
                     else
                     {
                         qDebug()<<"添加成功";
                     }

                 }

                 //flag = 1;
                 num =0;
             }
        }
        else {flag =0;qDebug()<<"不等";num = 0;}

       detection = Predict(pImage_roi[i]);

       //绘制边角
       cv::line(cap,Point(faces[i].x, faces[i].y),Point(faces[i].x+60,faces[i].y),Scalar(0,0,255),4);
       cv::line(cap,Point(faces[i].x, faces[i].y),Point(faces[i].x,faces[i].y+40),Scalar(0,0,255),4);

       cv::line(cap,Point(faces[i].x+faces[i].width-60, faces[i].y),Point(faces[i].x+faces[i].width,faces[i].y),Scalar(0,0,255),4);
       cv::line(cap,Point(faces[i].x+faces[i].width, faces[i].y),Point(faces[i].x+faces[i].width,faces[i].y+40),Scalar(0,0,255),4);


       cv::line(cap,Point(faces[i].x, faces[i].y+faces[i].height),Point(faces[i].x+60,faces[i].y+faces[i].height),Scalar(0,0,255),4);
       cv::line(cap,Point(faces[i].x, faces[i].y+faces[i].height-40),Point(faces[i].x,faces[i].y+faces[i].height),Scalar(0,0,255),4);

       cv::line(cap,Point(faces[i].x+faces[i].width-60, faces[i].y+faces[i].height),Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),Scalar(0,0,255),4);
       cv::line(cap,Point(faces[i].x+faces[i].width, faces[i].y+faces[i].height-40),Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),Scalar(0,0,255),4);

        //绘制的图片，利用对角线绘制图形 颜色 线条宽度
        //rectangle(cap, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(255,255,255), 2, 8);//放入缓存

       putText(cap, str, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255),2);//添加文字
    }
    }
    delete[]pImage_roi;
    cvtColor(cap,cap,CV_BGR2RGB);
    QImage image(cap.data, cap.cols, cap.rows, cap.step1() , QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image);
    mmp = mmp.scaled(ui->label_2->size());
    mmp =  PixmapToRound(mmp, 148);
    ui->label_2->setPixmap(mmp);
}
