#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDateTime>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->MainWindow->setWindowTitle(QString("我的窗体标题"));

    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->dateTimeEdit_2->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->dateTimeEdit_3->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *time_clock=new QTimer(parent);

    connect(time_clock,SIGNAL(timeout()),this,SLOT(cl()));
    time_clock->start(1000);

    //setTabel();
}

void MainWindow::cl()
{
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString strtime = ui->dateTimeEdit->text();
    QString strbegin = ui->dateTimeEdit_2->text();
    QString strend = ui->dateTimeEdit_3->text();

    if(strbegin > strtime && strend > strtime)
    {
        QMessageBox::about(NULL, "question", "开始和结束日期都超时，请重新输入");
        return;
    }
    else if(strend > strtime)
    {
        QMessageBox::about(NULL, "question", "结束日期，请重新输入");
        return;
    }
    else if(strbegin > strtime)
    {
        QMessageBox::about(NULL, "question", "开始日期，请重新输入");
        return;
    }

    if(strbegin >= strend)       //解决日期错误输入问题
    {
        //qDebug() << "请重新输入" << endl;
        QMessageBox::about(NULL, "question", "日期无效，请重新输入");
        return;
    }
    else
        qDebug() << strbegin << " " << strend << endl;
//    QString tab_name = "work3";
//    QString check = QString("select id,date,name,state from %1 where TIME>'%2' and TIME<'%3'").arg(tab_name).arg(strbegin).arg(strend);
//   // QString checkz = QString("select state from %1 where TIME>'%3' and TIME<'%4'").arg(tab_name).arg(strbegin).arg(strend);


//    qDebug()<<"check:"<<check<<endl;

//    QSqlQuery query;//queryz;
//    query.exec(check);
//    //queryz.exec(checkz);
//      QElapsedTimer t;

//    int data_num = query.size();
//    qDebug()<<"Number of rows:"<<data_num;

//    QString head = QString::number(data_num);
//    tcp_socket_hui->write(head.toStdString().c_str(),strlen(head.toStdString().c_str()));
//    tcp_socket_hui->flush();
//        t.start();
//        while(t.elapsed()<300);

    setTabelH();
//    int i=0,j = 0;
//    int send_time = 0;
    int n = 5;
    while(n--){

    //分别获取数据和TIME的数据
   // QVariant id = query.value(0);
//        qDebug()<<"QVariant_data:"<<info;
//    QByteArray info_array("");
//    info_array = info.toByteArray();

//    QString info_data = info_array;
//    QByteArray str2arr = info_data.toLatin1();
//    qDebug()<<"QByteArray_data:"<<info_array.toHex();
//    qDebug()<<"QString_data:"<<info_data;
//    qDebug()<<"QString to QByteArray:"<<str2arr<<endl;

   // QByteArray info_all("");
//    QString id = query.value(0).toString();
//    QString date = query.value(1).toString();
//    QString name = query.value(2).toString();
//    QString state = query.value(3).toString();

    setTabel();

//        QString info_temp;
//        info_temp = info_data+"**"+info_time+"!";
//        info_all = info_temp.toLatin1();

    //info_all = info_array.append("**").append(info_time).append("!");

    //int j2 = i;
    //i+=info_all.length();

    //将查询的结果集字符串发送给手持客户端
    //send_time ++;
//    if(send_time == data_num)
//    {
//            QString endsum = QString::number(i);
//        info_all = info_all.append(QByteArray::number(i,16));
//        qDebug()<<"Hex:"<<QByteArray::number(i,16)<<endl;
//        j2 +=info_all.size();
//        qDebug()<<"info_all's size:"<<j2<<endl;
//        tcp_socket_hui->write(info_all.data(),info_all.length());
//        tcp_socket_hui->flush();
//        send_time = 0;
//    }
//    else {
//        tcp_socket_hui->write(info_all.data(),info_all.length());
//        tcp_socket_hui->flush();
//    }

//        t.start();
//        while(t.elapsed()<300);

//    if(info_all.isEmpty()){
//        qDebug()<<QString("select %1 is Empty!").arg(str)<<endl;
//    }
//    else {
//        j++;
//        qDebug()<<QString("selected info-%1 is:").arg(j)<<info_all<<endl;
//        info_all.clear();
//    }

}
//qDebug()<<"Size_sum"<<i<<endl;

//ui->tableWidget->show();
}


void MainWindow::setTabelH()    //设置表头
{
    ui->tableWidget->setRowCount(0);        //解决了多次重复点击按钮查询得到的结果重复增加行插入问题。
    ui->tableWidget->clearContents();
    ui->tableWidget->clear();
    //ui->tableWidget->clearContents();
    ui->tableWidget->setWindowTitle("QTableWidget");
    ui->tableWidget->setColumnCount(4); //设置列数
    //ui->tableWidget->horizontalHeader()->setDefaultSectionSize(123.99);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //表头自适应表的大小
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);// 第 0 列自适应内容宽度
    QStringList header;
    header<<tr("姓名")<<tr("id")<<tr("状态")<<tr("日期");
    ui->tableWidget->setHorizontalHeaderLabels(header);

}
void MainWindow::setTabel()
{
//       ui->tableWidget->setWindowTitle("QTableWidget");
//       ui->tableWidget->setColumnCount(4); //设置列数
//       ui->tableWidget->horizontalHeader()->setDefaultSectionSize(150);
//       QStringList header;
//       header<<tr("id")<<tr("姓名")<<tr("日期")<<tr("状态");
//       ui->tableWidget->setHorizontalHeaderLabels(header);
       //ui->tableWidget->horizontalHeader()->setClickable(false);
//       ui->tableWidget->setFixedHeight(50);
//       ui->tableWidget->resize(350, 250);
 //     ui->tableWidget->setColumnCount(4);
   /*
       QStringList header;
       header.append("One");
       header.append("Two");
       tableWidget->setHorizontalHeaderLabels(header);
   */

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    db = QSqlDatabase::database("qt_sql_default_connection");
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("attence");
        db.setUserName("root");
        db.setPassword("root");
    }

    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open";


    insName = insertName;
    QString tab_name = "user";
    QString check = QString("select user_name,user_id from %1").arg(tab_name);
    query.exec(check);
    int qid;
    while(query.next()){
        usrname = query.value(0).toString();
        id = query.value(1).toInt();
        if(usrname == insName)
        {
            qid = id;
            break;
        }
    }

//    date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString nowdate = QTime::currentTime().toString();
    qDebug() << insName << usrname << qid  << nowdate << endl;

     int i = 0, j = 0, nColumn, nRow;
    QString str = QString("select count(*) as row from atwork where user_id = '%1'").arg(qid);
    query.exec(str);
    if(query.first())
    {
        nRow = query.value(0).toInt();
        ui->tableWidget->setRowCount(nRow);
    }
    qDebug() << "nw" << nRow;

    nColumn = ui->tableWidget->columnCount();

    QString sql = QString("select * from atwork where user_id = '%1'").arg(qid);
    query.exec(sql);
    for(int i = 0; query.next(); i++)
    {
        for(int j = 0; j < nColumn; j++)
        {
            if(j == 2 && query.value(j).toInt() == 0)
                ui->tableWidget->setItem(i,j, new QTableWidgetItem("未打卡"));
            else if(j == 2 && query.value(j).toInt() == 1)
                ui->tableWidget->setItem(i,j, new QTableWidgetItem("已打卡"));
            else if(j == 3)
            {
                QString str = query.value(j).toString();
                for(int i = 0;i < str.size();i++)
                {
                    if(str[i] == 'T')
                        str[i] = ' ';
                }
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(str));   //去'T'
            }
            else
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(query.value(j).toString()));


            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);    //内容居中显示
        }
    }

    /*设置表格是否充满，即行末不留空*/    // 最后一列拉伸
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // 全部列自适应表格宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //禁止编辑

    /*设置tablewidget等宽*/
//            QHeaderView* headerView = ui->tableWidget->horizontalHeader();
//            headerView->setSectionResizeMode(QHeaderView::Stretch);
    /*或者下面的代码*/
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//    qDebug() << "nrow" << nRow << "ncolumn" << nColumn;
//    query.first();
//    while(j < nRow)

//    {
//        for (i = 0; i< nColumn; i++)
//            ui->tableWidget->setItem(j, i, new QTableWidgetItem(query.value(i).toString()));
//        j++;
//        query.next();
//    }
//    dbconn.close();
//    while(query.next()){
//        usrname = query.value(0).toString();
//        id = query.value(1).toInt();

//    }




       //ui->tableWidget->SetRowColItemText(0, 0, QStringLiteral("公里"));
//       int rowCount = ui->tableWidget->rowCount();
//       ui->tableWidget->insertRow(rowCount);
//       int id = 1,state = 1;
//       QString name = "zs",date = "1234";
//       ui->tableWidget->setItem(rowCount,0, new QTableWidgetItem(QString::number(id)));
//       ui->tableWidget->setItem(rowCount,1, new QTableWidgetItem(name));
//       ui->tableWidget->setItem(rowCount,2, new QTableWidgetItem(date));
//       ui->tableWidget->setItem(rowCount,3, new QTableWidgetItem(QString::number(state)));
//       ui->tableWidget->setItem(0,1, new QTableWidgetItem(QIcon("images/data.png"), "data"));
//       ui->tableWidget->setItem(1,1, new QTableWidgetItem(QIcon("images/decision.png"), "decision"));
//       ui->tableWidget->setItem(2,1, new QTableWidgetItem(QIcon("images/document.png"), "document"));
//       ui->tableWidget->setItem(3,1, new QTableWidgetItem(QIcon("images/printer.png"), "printer"));
//       ui->tableWidget->setItem(4,1, new QTableWidgetItem(QIcon("images/process.png"), "process"));
       ui->tableWidget->show();

}


