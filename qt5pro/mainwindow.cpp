#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //基础控件
    //setGeometry()只能改变窗口的大小，不能改变控件位置大小。
    //layout 既可以改变窗口大小，又能改变控件位置大小。
//    QLineEdit {background:yellow};
//    QCheckBox {color:red};
//    QPushButton *btn = new QPushButton("Click!",this);
//    btn->setStyleSheet("background-image: url(:/img/a.png);\n" "font-weight:600;\n border:0px; color:white; text-align:center;");

    /*
      Qt控件
      QCheckBox            复选框（CheckBox）控件 （包含TextLabel）
      QcomboBox            单击按钮，可在弹出的选项中选择一个
      QcommandLinkButton   Windows Vista风格的命令链接按钮
      QtimeEdit            编辑或显示时间的控件
      QdateEdit            编辑或显示日期的控件
      QdateTimeEdit        编辑或显式时间和日期的控件
      Qdial                用于描述仪表盘的样式
      QspinBox             整数旋转框（SpinBox)控件
      QdoubleSpinBox       可以使用Double数据类型的旋转框
      QpushButton          普通按钮控件
      QfocusFrame          提供了当前绘画区域的焦点
      QfontComboBox        可使用选择字体的下拉列表框控件
      QLCDNumber           显式LCD风格数字的控件
      Qlabel               显示文本或图片的控件
      QlineEdit            单行（single line）文本框控件
      Qmenu                可以在菜单栏（MenuBar)的菜单控件、Context和弹出菜单中使用的控件
      QprogressBar         水平或垂直进度条
      QradioButton         单选按钮控件（包含TextLabel)
      QscrollArea          可以扩展查看其他控件的滚动（Scroll）控件
      QscrollBar           水平或垂直滚动条
      QsizeGrip            可以改变最上层视窗的大小
      Qslider              水平或垂直滑块
      QtabBar              TabBar控件（在标签对话框中使用）
      QtabWidget           Tab控件
      QtoolBox             成列的Tab控件
      QtoolButton          用于QtoolBox控件中，基于选项或命令可以快速访问的按钮控件
      Qwidget              所有项目的基类


      组合控件
      QButtonGroup         按钮控件的组合容器（Container)
      QGroupBox            带有标题的相同类型的组框（GroupBox Frame）
      QSplitter            具有分割（Splitter）功能的控件
      QSplitterHandle      可以控制分割功能的控件
      QStackedWidget       可以使屏幕上同时显示多个控件
      QTabWidget           Tab控件

      抽象控件类
      QAbstractButton      提供普通按钮功能的抽象类
      QAbstractScrollArea  在滚动条中提供必要功能的抽象类
      QAbstractSlider      使用给定范围内的整数值的抽象类
      QAbstractSpinBox     在旋转框和行编辑中显示值的抽象类
      QDialog              对话窗口的基类
      QFrame               存放框架控件的基类

     */

    /*
    //第一个参数是项目文本，第二个可以声明父类 &表示可以使用CheckBox的快捷键 Alt+E
//    QCheckBox  *chk = new QCheckBox("P&rogramming",this);

//    //使用QButtonGroup分为多组
//    QButtonGroup *group = new QButtonGroup(this);

    //QButtonGroup的方法addButton()将CheckBox包含在组内，CheckBox 可以在多个项目中多选，若使用QButtonGroup的setExclusive()只能单选
    QString str1[3] = {
        "Game","Office","Develop"
    };
    QString str2[3] = {"P&rogramming","Q&t","Q&S"};

    int xpos = 30;
    int ypos = 30;



    chk_group[0] = new QButtonGroup(this);
    chk_group[1] = new QButtonGroup(this);

    for(int i = 0;i < 3;i++)
    {
        exclusive[i] = new QCheckBox(str1[i],this);
        exclusive[i]->setGeometry(xpos,ypos,100,30);
        chk_group[0]->addButton(exclusive[i]);      //第一组

        non_exclusive[i] = new QCheckBox(str2[i],this);
        non_exclusive[i]->setGeometry(xpos+120,ypos,100,30);
        chk_group[1]->addButton(exclusive[i]);      //第二组

        connect(exclusive[i],SIGNAL(clicked()),this,SLOT(chkChanged()));

        ypos += 40;
    }

    chk_group[0]->setExclusive(false);      //只能单选
    chk_group[1]->setExclusive(true);       //可以多选

    //QCheckBox 向文本位置添加图像，利用QAbstractButton控件的setIcon()
//    exclusive[0]->setIcon(QIcon("resource/browser.png"));
//    exclusive[1]->setIcon(QIcon("resource/calendar.png"));
//    exclusive[2]->setIcon(QIcon("resource/chat.png"));

//    non_exclusive[0]->setIcon(QIcon("resource/editor.png"));
//    non_exclusive[1]->setIcon(QIcon("resource/mail.png"));
//    non_exclusive[2]->setIcon(QIcon("resource/users.png"));
    */

    /*
    //QComboBox添加项目可以使用文本添加对象或图像与文本一起使用
    combo = new QComboBox(this);
    combo->setGeometry(50,50,200,30);

    combo->addItem("Application");      //添加项目
    combo->addItem("Graphics");
    combo->addItem("Database");
    combo->addItem("Network");

//    combo->addItem(QIcon("resources/brower.png"),"Application");    //添加带图标的项目
//    combo->addItem(QIcon("resources/calendar.png"),"Graphics");

    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(valueChanged()));  //提供返航指定项目索引的信号

    //QString str = combo->currentIndex();
    qDebug("Total Ttems %d",combo->count());
//    combo->removeItem(3);
    */

    //QCommandLinkButton输入按钮显示的标签，添加第二个参数Description，按钮下方会显示描述 基类为QPushButton 可以使用父类的方法。
//    cmmBtn = new QCommandLinkButton("Vision","Vision Project",this);
//    connect(cmmBtn,SIGNAL(clicked()),this,SLOT(clickFunc()));


    /*
    //QDate 显示时间 QDateEdit显示编辑时间
    QDate dt1 = QDate(2013,11,7);
    QDate dt2 = QDate::currentDate();
    dateEdit[0] = new QDateEdit(dt1.addYears(2),this);
    dateEdit[0]->setGeometry(10,10,140,40);
    dateEdit[1] = new QDateEdit(dt1.addMonths(3),this);
    dateEdit[1]->setGeometry(160,10,140,40);
    dateEdit[2] = new QDateEdit(dt1.addDays(10),this);
    dateEdit[2]->setGeometry(310,10,140,40);
    dateEdit[3] = new QDateEdit(dt2,this);
    dateEdit[3]->setGeometry(10,60,140,40);
    qDebug("Day of year : %d",dt2.dayOfYear());
    qDebug("End Day : %d",dt2.daysInMonth());
    qDebug("End Day : %d",dt2.daysInYear());
    qDebug("Day of week : %d",dt2.dayOfWeek());

    //d dd 日   ddd dddd星期几      M MM MMM MMMM 月 yy yyyy年
    QDate dt3 = QDate::fromString("2002.06.26","yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26","MM.dd");

    lb1[0] = new QLabel(dt3.toString(),this);
    lb1[0]->setGeometry(10,110,150,30); //固定位置
    lb1[0]->adjustSize();   //自适应大小
    lb1[1] = new QLabel(dt4.toString(),this);
    lb1[1]->setGeometry(10,150,150,30);
    lb1[1]->adjustSize();

    if(QDate::isValid(2011,6,27))   //查看是否为有效日期
    {
        qDebug("2013.6.27 true");
    }
    else
        qDebug("2013.6.27 false");

    QDate dt5 = QDate(2012,5,26);

    QString LongWeek = dt5.longDayName(dt5.dayOfWeek());    //返回字符表示的日期
    QString LongMonth = dt5.longMonthName(dt5.month());
    QString strDateLong = QString("%1 %2").arg(LongWeek).arg(LongMonth);

    QString ShortWeek = dt5.shortDayName(dt5.dayOfWeek());    //返回字符表示的日期
    QString ShortMonth = dt5.shortMonthName(dt5.month());
    QString strDateShort = QString("%1 %2").arg(ShortWeek).arg(ShortMonth);

    lb1[2] = new QLabel(QString("Long: %1,Short: %2").arg(strDateLong).arg(strDateShort),this);
    lb1[2]->setGeometry(10,190,250,30);
    lb1[2]->adjustSize();

    //Qt::TextDate          0       显示默认类型
    //Qt::ISODate           1       按ISO8601扩展版本显示
    //Qt::SystemLocaleDate   2       按各国表现方式显示

    QDate dt6 = QDate(2012,7,26);
    lb1[3] = new QLabel(dt6.toString(Qt::TextDate),this);
    lb1[3]->setGeometry(10,240,250,30);
    lb1[3]->adjustSize();

    lb1[4] = new QLabel(dt6.toString(Qt::ISODate),this);
    lb1[4]->setGeometry(10,270,250,30);
    lb1[4]->adjustSize();

    lb1[5] = new QLabel(dt6.toString(Qt::SystemLocaleDate),this);
    lb1[5]->setGeometry(10,300,250,30);
    lb1[5]->adjustSize();
    */

    /*
    QTime til = QTime(6,24,55,432); //hour,min,sec,millisecond
    QTimeEdit *qte[4];

//    qte = new QTimeEdit(til,this);
//    qte->setGeometry(10,30,150,30);
//    qte->adjustSize();


//    qte[1] = new QTimeEdit(til.addMSecs(200),this);
//    qte[1]->setGeometry(10,30,150,30);

//    qte[2] = new QTimeEdit(til.addSecs(2),this);
//    qte[2]->setGeometry(10,30,150,30);


//    QTime til2 = QTime::currentTime();
//    qte[3] = new QTimeEdit(til2,this);
//    qte[3]->setGeometry(10,30,150,30);

//    QTime til3;
//    til3.start();
//    for(int i = 0;i < 100000;i++)
//    {
//        for(int j = 0;j < 100000;j++)
//        {

//        }
//    }

//    qDebug("Elapsed Time:%d",til3.elapsed());   //start  和 elapsed 的计算过程，

//    QTime til4 = QTime::fromString("03:32","hh:mm");    //h hh 时，m mm 分钟,s ss 秒，z zzz 毫秒， AP ap 上午下午

//    QLabel *lb1_fromstring = new QLabel(til4.toString(),this);  //fromString()通过多种方法显示时间
//    lb1_fromstring->setGeometry(10,30,150,30);


//    QTime til6 = QTime(7,10,23,122);
//    QLabel *lb1_fromString = new QLabel(til6.toString("AP hh:mm:ss:zzz"),this);
//    lb1_fromString->setGeometry(10,30,150,30);
//    lb1_fromString->adjustSize();
*/

    /*
    QDateTimeEdit *qdel[4];
    qdel[1] = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    qdel[1]->setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");
    qdel[1]->setGeometry(10,30,250,50);
    qdel[1]->adjustSize();

    qdel[0] = new QDateTimeEdit(QDate::currentDate(),this);
    qdel[0]->setMinimumDate(QDate::currentDate().addYears(-3));     //微调按钮指定范围
    qdel[0]->setMaximumDate(QDate::currentDate().addYears(3));
    qdel[0]->setDisplayFormat("yyyy");
    qdel[0]->setGeometry(10,90,100,50);

    qdel[2] = new QDateTimeEdit(QDate::currentDate(),this);
    qdel[2]->setMinimumDate(QDate::currentDate().addMonths(-3));
    qdel[2]->setMaximumDate(QDate::currentDate().addMonths(3));
    qdel[2]->setDisplayFormat("MM");
    qdel[2]->setGeometry(110,90,100,50);

    qdel[3] = new QDateTimeEdit(QDate::currentDate(),this);
    qdel[3]->setMinimumDate(QDate::currentDate().addDays(-3));
    qdel[3]->setMaximumDate(QDate::currentDate().addDays(3));
    qdel[3]->setDisplayFormat("dd");
    qdel[3]->setGeometry(210,90,100,50);
    */

    /*
    //QDial 提供圆形volume调节器，继承于QAbstractSlider

    int xpos = 30;
    for(int i = 0;i < 3;i++,xpos += 110)
    {
        dial[i] = new QDial(this);
        dial[i]->setRange(0,100);   //指定控件范围
        dial[i]->setGeometry(xpos,30,100,100);
    }
    dial[0]->setNotchesVisible(true);   //在控件上显示刻度 通过valueChanged(int)信号得到QDial当前值
    connect(dial[0],SIGNAL(valueChanged(int)),this,SLOT(changedData()));
    */

    /*
    int xpos = 10;
    int ypos = 30;
    int val[3] = {50,100,200};
    double double_val[3] = {50.5,127.32,171.342};
    for(int i = 0;i < 3;i++)
    {
        spin[i] = new QSpinBox(this);
        spin[i]->setMinimum(10);
        spin[i]->setMaximum(300);
        spin[i]->setValue(val[i]);
        spin[i]->setGeometry(xpos,ypos,100,30);
        spin[i]->setPrefix("$ ");   //指定特定字符
        spin[i]->adjustSize();

        doublepin[i] = new QDoubleSpinBox(this);
        doublepin[i]->setMinimum(10.0); //设置控件最小值
        doublepin[i]->setMaximum(300.0);//最大值
        doublepin[i]->setValue(double_val[i]);//设置默认值
        doublepin[i]->setGeometry(xpos+110,ypos,100,30);
        doublepin[i]->setSuffix(" mm");//指定特定字符
        doublepin[i]->adjustSize();

        ypos += 40;
    }

    connect(spin[0],SIGNAL(valueChanged(int)),this,SLOT(valuechange()));
    connect(doublepin[0],SIGNAL(valueChanged(double)),this,SLOT(double_valuechange()));
    */

    /*
    int ypos = 30;

    for(int i = 0;i < 3;i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i),this); //第一个参数输入显示按钮文本，第二个为其父类
        btn[i]->setGeometry(10,ypos,300,40);

        ypos += 50;
    }

    connect(btn[0],SIGNAL(clicked()),this,SLOT(btn_click()));
    connect(btn[0],SIGNAL(pressed()),this,SLOT(btn_pressed()));
    connect(btn[0],SIGNAL(released()),this,SLOT(btn_released()));

    btn_frame = new QFocusFrame(this);

    btn_frame->setWidget(btn[0]);       //使按钮在QFocusFrame内
    btn_frame->setAutoFillBackground(true);
    */

    /*
    for(int i = 0;i < 5;i++)
    {
        fontcombo[i] = new QFontComboBox(this);
    }
    fontcombo[0]->setFontFilters(QFontComboBox::AllFonts);  //设置字体 全部字体
    fontcombo[1]->setFontFilters(QFontComboBox::ScalableFonts); //自动变化扩大和缩小等形态的字体
    fontcombo[2]->setFontFilters(QFontComboBox::NonScalableFonts);//不能自动转换形态的字体
    fontcombo[3]->setFontFilters(QFontComboBox::MonospacedFonts);//固定宽度的字体
    fontcombo[4]->setFontFilters(QFontComboBox::ProportionalFonts);//均衡宽度和幅度的字体

    int ypos = 30;
    for(int i = 0;i < 5;i++)
    {
        fontcombo[i]->setGeometry(10,ypos,300,30);
        ypos += 40;
    }

//    lb = new QLabel("I love Qt programming",this);
//    lb->setGeometry(10,250,200,30);
//    lb->adjustSize();
//    connect(fontcombo[0],SIGNAL(currentIndexChanged(int)),this,SLOT(changedIndex(int)));
    connect(fontcombo[0],SIGNAL(currentFontChanged(QFont)),this,SLOT(changedFont(const QFont &)));
    */

    /*
    lb = new QLabel("I love Qt programming",this);
    lb->setGeometry(10,30,200,30);
    lb->adjustSize();

    QPixmap pix = QPixmap("resources/browser.png");

    lb1[0] = new QLabel(this);
    lb1[0]->setPixmap(pix);     //将图片显示到GUi
    lb1[0]->setGeometry(10,70,100,100);

    QLCDNumber *lcd[3];
    lcd[0] = new QLCDNumber(2,this);
    lcd[0]->display(24);
    lcd[0]->setGeometry(150,30,200,100);

    lcd[1] = new QLCDNumber(5,this);
    lcd[1]->display("10:34");
    lcd[1]->setGeometry(150,140,200,100);

    lcd[0]->setSegmentStyle(QLCDNumber::Outline);   //显示与窗口背景颜色相同
    lcd[1]->setSegmentStyle(QLCDNumber::Filled);    //显示与字体颜色相同
   // lcd[1]->setSegmentStyle(QLCDNumber::Flat);  //不显示字体外框线的风格
   */

    /*
    edit1 = new QLineEdit(" ",this);
    lb = new QLabel("QLineEdit Text: ",this);
    lb->adjustSize();
    edit1->adjustSize();
    edit1->setGeometry(10,100,40,110);
    connect(edit1,SIGNAL(textChanged(QString)),this,SLOT(textchanged(QString)));

    int ypos = 120;
    for(int i = 0;i < 5;i++)
    {
        edit[i] = new QLineEdit("I love MeeGo.",this);
        edit[i]->setGeometry(10,ypos,200,40);
        ypos += 50;
    }
    edit[0]->setEchoMode(QLineEdit::Normal); //默认
    edit[1]->setEchoMode(QLineEdit::NoEcho); //隐藏输入文本 不改变光标位置
    edit[2]->setEchoMode(QLineEdit::Password);   //用*表示文本
    edit[3]->setEchoMode(QLineEdit::PasswordEchoOnEdit); //若编辑文本与默认一致，若移动焦点则显示*
    */




    /*
    QMenuBar *menuBar = new QMenuBar(this); //1.创建菜单栏
    menuBar->setGeometry(0,0,width(),40);   //设置大小

    QMenu *fileMenu = new QMenu("File",this);   //2.创建菜单
    //3.创建行为(Action)
    QAction *fileCreateAction = new QAction("create",this);
    QAction *fileSaveAction = new QAction("save",this);
    QAction *fileImportAction = new QAction("import",this);
    QAction *fileExportAction = new QAction("export",this);
    //4.将行为添加到菜单
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(fileImportAction);
    fileMenu->addAction(fileExportAction);

    fileMenu->addAction(fileCreateAction);
    //5.将菜单添加到菜单栏
    menuBar->addMenu(fileMenu);
    menuBar->setVisible(true);
    */

    /*
    QMenuBar *mbar=new  QMenuBar(0);
    QMenu *qfile = mbar->addMenu("文件");
    QAction  *qnew = qfile->addAction("新建");
    */


    /*
    status = new QStatusBar(this);

    //菜单
    menu[0] = new QMenu("File");
    menu[0]->addAction("Edit");
    menu[0]->addAction("View");
    menu[0]->addAction("Tools");

    act[0] = new QAction("New",this);   //添加下级菜单
    act[0]->setShortcut(Qt::CTRL | Qt::Key_A);  //添加快捷键
    act[0]->setStatusTip("This is a new emnu");//添加ToolTip 功能

    act[1] = new QAction("Open",this);
    act[1]->setCheckable(true); //添加校验功能 true激活


    menu[1] = new QMenu("Save");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2] = new QMenu("Print");
    menu[2]->addAction("Page Setup");
    menu[2]->addMenu(menu[1]);


    menubar = new QMenuBar(this);//1.创建菜单栏
    menubar->setGeometry(0,0,width(),40);   //设置大小
    menubar->addMenu(menu[0]);
    menubar->addMenu(menu[2]);

    lb = new QLabel("",this);
    connect(menubar,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));
    */

    /*
    //进度条
    progress[0] = new QProgressBar(this);
    progress[0]->setMinimum(0);     //最小值
    progress[0]->setMaximum(100);   //最大值 setRange()可以同时设置最大最小值。
    progress[0]->setValue(50);//用于最大最小值之间的运行值
    progress[0]->setOrientation(Qt::Horizontal);//显示横向/纵向进度
    progress[0]->setGeometry(10,100,150,50);

    progress[1] = new QProgressBar(this);
    progress[1]->setMinimum(0);
    progress[1]->setMaximum(100);
    progress[1]->setValue(70);
    progress[1]->setOrientation(Qt::Horizontal);
    progress[1]->setInvertedAppearance(true);//设置进度条行进方向。true为反向
    progress[1]->setGeometry(10,200,150,50);

    progress[2] = new QProgressBar(this);
    progress[2]->setValue(50);
    progress[2]->setOrientation(Qt::Vertical);
    progress[2]->setGeometry(10,300,150,50);

    progress[3] = new QProgressBar(this);
    progress[3]->setValue(70);
    progress[3]->setOrientation(Qt::Vertical);
    progress[3]->setInvertedAppearance(true);
    progress[3]->setGeometry(10,400,150,50);
    */

    /*
    //QRadioButton 单选， QCheckBox多选
    QString str1[3] = {"NetBook","Handset","Tablet"};

    int ypos = 30;
    for(int i = 0;i < 3;i++)
    {
        radio1[i] = new QRadioButton(str1[i],this);
        radio1[i]->setGeometry(10,ypos,150,30);

        ypos += 40;
    }

    QString str2[3] = {"In-Vehicle","Smart TV","Media Phone"};

    ypos = 30;
    for(int i = 0;i < 3;i++)
    {
        radio2[i] = new QRadioButton(str2[i],this);
        if(i == 2)
            radio2[i]->setChecked(true);    //默认2被选择
        radio2[i]->setGeometry(180,ypos,150,30);

        ypos += 40;
    }

    QButtonGroup *group1 = new QButtonGroup(this);
    QButtonGroup *group2 = new QButtonGroup(this);
    group1->addButton(radio1[0]);
    group1->addButton(radio1[1]);
    group1->addButton(radio1[2]);
    group2->addButton(radio2[0]);
    group2->addButton(radio2[1]);
    group2->addButton(radio2[2]);
       */


    /*
    //QScrollArea 设置列表框
    QLabel *lb1 = new QLabel(this);
    QImage image(":resources/dj.jpg");
    lb1->setPixmap(QPixmap::fromImage(image));//加载图片

    area = new QScrollArea(this);
    area->setWidget(lb1);//QLabel 包含到QScrollArea
    area->setBackgroundRole(QPalette::Dark);
    area->setGeometry(0,0,image.width(),image.height()-60);
    */

    /*
    //设置滚动条
    int xpos = 10;
    int ypos = 50;

    for(int i = 0;i < 3;i++)
    {
        vscrollbar[i] = new QScrollBar(Qt::Vertical,this);
        vscrollbar[i]->setRange(0,100);
        vscrollbar[i]->setGeometry(xpos,30,20,200);

        lb1[i] = new QLabel(QString("%1").arg(vscrollbar[i]->value()),this);
        lb1[i]->setGeometry(xpos+2,220,30,30);
        xpos += 50;

        hscrollbar[i] = new QScrollBar(Qt::Horizontal,this);
        hscrollbar[i]->setRange(0,100);
        hscrollbar[i]->setGeometry(150,ypos,200,20);
        ypos += 30;
    }

    connect(vscrollbar[0],SIGNAL(valueChanged(int)),this,SLOT(valueChanged1(int)));
    */


    /*
    //QSlider指定最大值最小值
    slider[0] = new QSlider(Qt::Vertical,this);
    slider[0]->setGeometry(30,20,30,80);
    slider[0]->setRange(0,100);
    slider[0]->setValue(50);

    slider[1] = new QSlider(Qt::Horizontal,this);
    slider[1]->setGeometry(130,30,30,80);
    slider[1]->setRange(0,100);
    slider[1]->setValue(50);

    lb = new QLabel(QString("%1").arg(slider[0]->value()),this);
    lb->setGeometry(10,100,30,40);
    connect(slider[0],SIGNAL(valueChanged(int)),this,SLOT(valueChanged1(int)));

    */

    /*
    tab = new QTabWidget(this);
    browser_tab = new QWidget;
    users_tab = new QWidget;


    tab->addTab(browser_tab,QIcon("./resources/brower.png"),"Browser");
    tab->addTab(users_tab,QIcon("./resources/users.png"),"Users");
    tab->adjustSize();

    QString btn_str[3] = {"Button 1","Button 2","Button 3"};
    QPushButton *btn[3];

    int ypos = 30;
    for(int i = 0;i < 3;i++)
    {
        btn[i] = new QPushButton(btn_str[i],browser_tab);
        btn[i]->setGeometry(10,ypos,100,40);
        ypos += 50;
    }

    connect(tab,SIGNAL(currentChanged(int)),this,SLOT(currentTab(int)));
    */

    /*
    QToolBar *toolbar = new QToolBar(this);
    QAction *act[2];

    act[0] = new QAction(QIcon(":resources/brower.png"),"Brower",this);
    act[1] = new QAction(QIcon(":resources/calendar.png"),"calendar",this);

    act[0]->setShortcut(Qt::Key_Control | Qt::Key_E);
    act[0]->setToolTip("This is a ToolTip");

    for(int i = 0;i < 2;i++)
    {
        toolbar->addAction(act[i]);
        toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//在文本内显示图标 Qt::
        Qt::ToolButtonIconOnly;//只显示图标
        Qt::ToolButtonTextOnly;//只显示按钮名称
        Qt::ToolButtonTextUnderIcon;//在文本下方显示图标

    }
    connect(act[0],SIGNAL(triggered()),this,SLOT(trigger1()));
    */
/*
//    setTabText()设置文本，setTabIcon()设置选项卡图标，setTabToolTip()添加选项卡提示框。
    //setTabTextColor()设置选项卡显示文本颜色，setShape() 设置选项卡样式
//    QTabBar::RoundedNorth           0           默认样式
//    QTabBar::RoundedSouth           1           页面下方为圆形
//    QTabBar::RoundedWest            2           页面左侧部分为圆形
//    QTabBar::RoundedEast            3           页面右侧部分为圆形
//    QTabBar::TrianguarNorth         4           三角形
//    QTabBar::TrianguarSouth         5           与Excel表格中使用的样式类似三角形
//    QTabBar::TrianguarWest          6           页面左侧部分为三角形
//    QTabBar::TrianguarEast          7           页面右侧部分为三角形

    tabBar = new  QTabBar(this);
    tabBar->addTab("Browser");  //添加选项卡
    tabBar->addTab("User");
    tabBar->addTab("Application");
    tabBar->adjustSize();
    connect(tabBar,SIGNAL(currentChanged(int)),this,SLOT(currentTab(int)));
    */

    /*
    //itemText()获取QString 返回值，itemIcon()返回QIcon

    box = new QToolBox(this);
    lay = new QHBoxLayout(this);

    btn[0] = new QPushButton("DataBase -1",this);
    btn[1] = new QPushButton("Network -2",this);
    btn[2] = new QPushButton("Graphics -3",this);
    btn[0]->adjustSize();
    btn[1]->adjustSize();
    btn[2]->adjustSize();
    box->addItem(btn[0],"DataBase");
    box->addItem(btn[1],"Network");
    box->addItem(btn[2],"Graphics");
    box->adjustSize();

    lay->addWidget(box);
    setLayout(lay);

    //insertItem() 和 removeItem() 选项卡的添加/删除项目
    //currentIndex() 返回当前项目控件的索引
    connect(box,SIGNAL(currentChanged(int)),this,SLOT(changedTab(int)));
*/

    /*
    //QIcon类指定QToolButton的图标，是否可用。
    //setToolButtonStyle()设置按钮类型
    //setIconSize()设置图标大小
    tool = new QToolBar(this);
    button[0] = new QToolButton;
    button[0]->setIcon(QIcon(":resources/browser.png"));

    button[1] = new QToolButton;
    button[1]->setIcon(QIcon(":resources/calendar.png"));

    button[2] = new QToolButton;
    button[2]->setIcon(QIcon(":resources/chat.png"));

    tool->addWidget(button[0]);
    tool->addWidget(button[1]);
    tool->addSeparator();   //分隔符
    tool->addWidget(button[2]);
*/


    /*
//    QHBoxLayout             水平布局控件
//    QVBoxLayout             垂直布局控件
//    QGridLayout             将控件布置为网格状
//    QBoxLayout              可以水平或垂直布局控件的类，使用选项决定布局方向

       hboxLayout = new QHBoxLayout(this);

       QString btnStr[6] = {
           "NetBook","Tablet","Handset","Genivi","SmartTV","Vechile"
       };

       for(int i = 0;i < 6;i++)
       {
           btn[i] = new QPushButton(btnStr[i],this);
           hboxLayout->addWidget(btn[i]);
       }

       setLayout(hboxLayout);   //默认布局


       vboxlayout = new QVBoxLayout(this);
        QPushButton *vbtn[6];
       QString vbtnStr[6] = {
           "NetBook","Tablet","Handset","Genivi","SmartTV","Vechile"
       };

       for(int i = 0;i < 6;i++)
       {
           vbtn[i] = new QPushButton(vbtnStr[i],this);
           vboxlayout->addWidget(vbtn[i]);
       }

       setLayout(vboxlayout);   //默认布局

       QVBoxLayout* pLayout = new QVBoxLayout();//水平布局

       QPushButton* p1 = new QPushButton("p1",this);
       QPushButton* p2 = new QPushButton("p2",this);
       QPushButton* p3 = new QPushButton("p3",this);
       QPushButton* p4 = new QPushButton("p4",this);

       pLayout->addWidget(p1);
       pLayout->addStretch();
       pLayout->addWidget(p2);
       pLayout->addWidget(p3);
       pLayout->addWidget(p4);

       this->setLayout(pLayout);

    gridLayout = new QGridLayout(this);
    QPushButton *gbtn[6];
    QString btnStr[6] = {
        "NetBook","Tablet","Handset","Genivi","SmartTV","Vechile"
    };

    for(int i = 0;i < 6;i++)
    {
        gbtn[i] = new QPushButton(btnStr[i],this);
    }
    gridLayout->addWidget(gbtn[0],0,0);
    gridLayout->addWidget(gbtn[1],0,1);
    gridLayout->addWidget(gbtn[2],1,0,1,2);
    gridLayout->addWidget(gbtn[3],2,0);
    gridLayout->addWidget(gbtn[4],2,1);


    this->setLayout(gridLayout);   //默认布局

    QHBoxLayout *hboxLayout = new QHBoxLayout();
    QVBoxLayout *vboxLayout = new QVBoxLayout();
    QGridLayout *gridLayout = new QGridLayout();

    QVBoxLayout *defaultLayout = new QVBoxLayout();

    defaultLayout->addLayout(hboxLayout);
    defaultLayout->addLayout(vboxLayout);
    defaultLayout->addLayout(gridLayout);

    setLayout(defaultLayout);*/

    /*
    QColumnView                         基于模型/视图的列视图控件
    QDataWidgetMapper                   连接控件和模型数据的映射类控件
    QListView                           列表形态的视图控件
    QTableView                          基于模型/视图的表格视图控件
    QTreeView                           基于模型/视图的树型视图控件
    QDesktopWidget                      用一个显卡访问多个虚拟的桌面画面的控件
    QUndoView                           将撤销栈的内容显示并输出到列表控件的控件
    QCalendarWidget                     以日历形式显示用户选择的日期的控件
    QMacCocoaViewContainer              打包Cocoa视图类的Moc  OS X 的控件
    QMacNativeWidget                    提供根据Qt构成方式，将Qt控件添加到Cocoa各级结构方法的控件


    model = new QStandardItemModel;

    name = new QStandardItem("Name");
    firstName = new QStandardItem("First Name");
    lastName = new QStandardItem("Last Name");

    name->appendRow(firstName);
    name->appendRow(lastName);
    model->appendRow(name);

    columnView = new QColumnView;
    columnView->setModel(model);

    QStringList items;
    items << tr("Home") << tr("Work") << tr("Other");
    typeModel = new QStringListModel(items,this);

    model = new QStandardItemModel(5,3,this);
    QStringList names;
    names << "Alice" << "Bob" << "Carol" << "Donald" << "Emma";
    QStringList type;
    type << "0" << "1" << "2" << "0" << "2";

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit,0);

    QHBoxLayout *layout = new QHBoxLayout;

//    QWidget *canvas = new QWidget;
    QSlider *slider = new QSlider;

    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);

    setLayout(layout);

    QPixmap pixmap;
    if(!pixmap.load(":/resources/fish.png"))
    {
        qDebug() << "Fatal error ： Unable to load image";
        exit(-1);
    }

    connect(slider,SIGNAL(valueChanged(int)),SLOT(setZoom(int)));

    QDesktopWidget desk;
    px_width = desk.width();
    px_height = desk.height();


    calendar = new QCalendarWidget(this);
    calendar->setGridVisible(true);
    calendar->setMinimumDate(QDate(2019,12,18));
    calendar->setMaximumDate(QDate(2020,1,1));
    calendar->adjustSize();

    QCalendarWidget::SingleLetterDayNames           1           显示星期首字母
    QCalendarWidget::ShortDayNames                  2           显示星期缩写
    QCalendarWidget::LongDayNames                   3           显示星期完整拼写
    QCalendarWidget::NoHorizontalHeader             0           不水平显示标题行
    QCalendarWidget::NoSelection                    0           设置不能选择日期
    QCalendarWidget::SingleSelection                1           设置可以选择日期
      不
*/

    /*
    QInputDialog            用户可以输入值的对话框;
    QColorDialog            可以选择指定颜色的对话框;
    QFileDialog             提供选择文件或目录的GUI 的对话框
    QFontDialog             选择字体的对话框;
    QMessageBox             模式对话框，通过主窗口传送用户所选项目的返回值
    QProgressDialog         显示百分比进度的对话框;

    bool retValue;
    int i = QInputDialog::getInt(this,tr("QInputDialog::getInteger()"),tr("Percengage:"),25,0,100,1,&retValue);//参数：指定父类，窗体的标题栏题目，输入值控件项目的标签，设定值，输入值的范围（两个参数），对话框旋转框的STEP，是否在对话框中点击

    if(retValue)
            qDebug("true,%d",i);
    else
            qDebug("false,%d",i);

    bool ok;
    double d = QInputDialog::getDouble(this,tr("QInputDialog::getDouble()"),tr("Amount:"),48.56,-100,100,2,&ok);
    if(ok)
        edit1->setText(QString("$%1").arg(d));

    QStringList items;
    items << tr("Spring") << tr("Summer") << tr("Fail") << tr("Winter");

    bool ok;
    QString item = QInputDialog::getItem(this,tr("QInputDialog::getItem()"),tr("Season:"),items,0,false,&ok);

    if(ok&&!item.isEmpty())
         edit1->setText(item);

    bool ok;
    QString text = QInputDialog::getText(this,tr("QInputDialog::getText()"),tr("User name:"),QLineEdit::Normal,QDir::home().dirName(),&ok);

    if(ok && !text.isEmpty())
        edit1->setText(text);

    QColor color;
    color = QColorDialog::getColor(Qt::green,this,"Select Color",QColorDialog::DontUseNativeDialog);

    if(color.isValid())
    {
        edit1->setText(color.name());
        edit1->setPalette(QPalette(color));
        edit1->setAutoFillBackground(true);
    }


    bool ok;
    QFont font = QFontDialog::getFont(&ok,QFont("Courier 10 Pitch"),this);

    if(ok)
    {
        edit1->setText(font.key());
        edit1->setFont(font);
    }


    QFileDialog::Options options;
    options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

    options |= QFileDialog::DontUseNativeDialog;
    QString directory = QFileDialog::getExistingDirectory(this,tr("QFileDialog::getExistingDirectory()"),"/home",options);//参数：指定父类，文件对话框的标题栏题目，指定目录默认目录，对利用文件对话框的常量值进行过滤的option值



    QFileDialog::ShowDirsOnly           0 X 00000001        只显示目录
    QFileDialog::DontResolveSymlinks    0 X 00000002        不显示符号链接
    QFileDialog::DontConfirmOverwrite   0 X 00000004        覆写现存文件时，不显示警告信息
    QFileDialog::DontUseNativeDialog    0 X 00000010        不使用系统默认文件对话框
    QFileDialog::ReadOnly               0 X 00000020        使用只读模式文件对话框
    QFileDialog::HideNameFilterDetails  0 X 00000040        使用过滤器隐藏文件


    QFileDialog::Options options;
    options |= QFileDialog::DontUseNativeDialog;

//    QString selectedFilter;
//    QString fileName = QFileDialog::getOpenFileName(this,tr("QFileDialog::getOpenFileName()"),"/",tr("All Files(*);;Text Files(*.txt)"),&selectedFilter,options);


    QString selectedFilter;
    QStringList files = QFileDialog::getOpenFileNames(this,tr("QFileDialog::getOpenFileName()"),"/",tr("All Files(*);;Text Files (*.txt)"),&selectedFilter,options);

    QFileDialog::Options options;
    options |= QFileDialog::DontUseNativeDialog;

    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName(this,tr("QFileDialog::getSaveFileName()"),"test.txt",tr("All Files(*);;Text Files(*.txt)"),&selectedFilter,options);


    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this,tr("QMessageBox::critical()"),"There is no a disk.",QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    //  critical是为了使用警告消息框而提供的模式对话框，参数：指定父类，消息框的标题栏题目，可以输入消息对话框的内容，布局到对话框上的按钮。
    if(reply == QMessageBox::Abort)
        edit1->setText(tr("Abort"));
    else if(reply == QMessageBox::Retry)
        edit1->setText(tr("Retry"));
    else
        edit1->setText(tr("Ignore"));

    QMessageBox::Ok                     0 X 00000400        Ok按钮
    QMessageBox::Open                   0 X 00002000        打卡文件按钮
    QMessageBox::Save                   0 X 00000800        保存按钮
    QMessageBox::Cancel                 0 X 00400000        取消按钮
    QMessageBox::Close                  0 X 00200000        关闭按钮
    QMessageBox::Discard                0 X 00800000        不保存且放弃按钮
    QMessageBox::Apply                  0 X 02000000        请求按钮
    QMessageBox::Reset                  0 X 04000000        重置按钮
    QMessageBox::RestoreDefaults        0 X 08000000        重新报错按钮
    QMessageBox::Help                   0 X 01000000        帮助按钮
    QMessageBox::SaveAll                0 X 00001000        全部报存按钮
    QMessageBox::Yes                    0 X 00004000        YES按钮
    QMessageBox::YesToAll               0 X 00008000        全部执行YES按钮
    QMessageBox::No                     0 X 00010000        NO按钮
    QMessageBox::NoToAll                0 X 00020000        全部指向NO 按钮
    QMessageBox::Abort                  0 X 00040000        停止按钮
    QMessageBox::Retry                  0 X 00080000        重试按钮
    QMessageBox::Ignore                 0 X 00100000        忽略按钮
    QMessageBox::NoButton               0 X 00000000        无效按钮




    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this,tr("QMessageBox::information()"),"I am a Qt Developer.\
                                                  I Love Qt");

    if(reply == QMessageBox::Ok)
        edit1->setText(tr("OK"));
    else
        edit1->setText(tr("Escape"));

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,tr("QMessageBox::question()"),"Do you save this file?",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if(reply == QMessageBox::Yes)
        edit1->setText(tr("Yes"));
    else if(reply == QMessageBox::No)
        edit1->setText(tr("No"));
    else
        edit1->setText(tr("Cancel"));


    QMessageBox msgBox(QMessageBox::Warning,tr("QMessageBox::warning()"),"you save this file?",0,this);
    msgBox.addButton(tr("Save &Again"),QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"),QMessageBox::RejectRole);

    if(msgBox.exec() == QMessageBox::AcceptRole)
        edit1->setText(tr("Save Again"));
    else
        edit1->setText(tr("continue"));
    //第一个参数选择QMessageBox 上显示的图标
    QMessageBox::Nolcon             0           不使用图标
    QMessageBox::Question           4           使用Question图标
    QMessageBox::Information        1           使用Information图标
    QMessageBox::Warning            2           使用Warning图标
    QMessageBox::Critical           3           使用Critical图标*/


    /*
    //创建菜单栏
    QMenu *filemenu;
    QAction *newAct;
    QAction *openAct;

    newAct = new QAction(QIcon("./images/new.png"),tr("&New"),this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct,SIGNAL(triggered()),this,SLOT(newFile()));

    openAct = new QAction(QIcon("./images/open.png"),tr("&Open..."),this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct,SIGNAL(triggered()),this,SLOT(open()));

    filemenu = menuBar()->addMenu(tr("&File"));
    filemenu->addAction(newAct);
    filemenu->addAction(openAct);

    //创建工具栏
    QToolBar *fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);

    //创建锚接控件
    QDockWidget *dock = new QDockWidget(tr("Target"),this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QListWidget *customerList = new QListWidget(dock);
    customerList->addItems(QStringList() << "One" << "Two" << "Three" << "Four" << "Five");
    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //创建中心控件
    QTextEdit *textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    //添加状态栏
    statusBar()->showMessage(tr("Ready"));
    */

    /*
    模型/视图结果各控件及含义

            控件                  说明
            QListView           列表显示数据的控件
            QTableView          实现表格视图的模型/视图
            QTreeView           实现树形视图的模型/视图

    QAbstractItemModel 是所有模型类的基类

            模型                       说明
            QStringListMode            保存QString数据类型的单一数据列表的类
            QStandardItemModel          通过树形视图提供读取的任意数据的类
            QFileSystemMode             提供文件系统中的文件和目录信息的类
            QSqlQueryModel              通过模型类存取数据库信息的类
            QSqlTableModel
            QSqlRelationalTableModel
    */


    /*
    resize(600,300);
    QSplitter *splitter = new QSplitter(this);

    //Model类
    QFileSystemModel *model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());

    //view控件
    QTreeView *tree = new QTreeView(splitter);\
    tree->adjustSize();
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));


    QListView *list = new QListView(splitter);
    list->adjustSize();
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(splitter);
    setLayout(layout);

    //QListView
    QStringList strList;
    strList << "Monday" << "Tuesday" << "Wedneday" <<"Thurday" << "Friday";

    QAbstractItemModel *model1 = new QStringListModel(strList);

    QListView *view = new QListView();
    view->setModel(model1);

    QModelIndex index = model1->index(3,0);
    QString text = model1->data(index,Qt::DisplayRole).toString();

    QLabel *lb1 = new QLabel("");
    lb1->setText(text);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(view);
    lay->addWidget(lb1);

    setLayout(lay);



    //QTableView

    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Subject"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Description"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));

    model1->setVerticalHeaderItem(0,new QStandardItem("Col 1"));
    model1->setVerticalHeaderItem(1,new QStandardItem("Col 2"));
    model1->setVerticalHeaderItem(2,new QStandardItem("Col 3"));

    model1->setData(model->index(0,0),"Monitor");
    */

    /*
    //基本数据类型
    //类型                大小（bit)             说明
    bool                    8                   true/false
    qint8                   8                   signed char
    qint16                  16                  signed short
    qint32                  32                  signed int
    qint64                  64                  long long int
    quint8                  8                   unsigned char
    quint16                 16                  unsigned short
    quint32                 32                  unsigned int
    quint64                 64                  unsigned long long int
    float                   32
    double                  64
    const char*             32


    //数据类
    类                                   说明
    QBitArray                           提供位运算的数组
    QBrush                              定义QPainter绘制图形的填充模式
    QByteArray                          字节数组的类
    QColor
    QCursor                     定义鼠标光标的图象类
    QDate
    QDateTime
    QEasingCurve                控制GUI动画运行模式的数据类
    QFont
    QIcon
    QImage
    QKeySequence                指定快捷键的类
    QMargins                    定义矩形外边距量
    QMatrix                     为改变2D而定义的类
    QMatrix4x4                  为改变3D4X4而定义的类
    QPalette                    包含各控件状态的颜色组的类
    QPen
    QPicture
    QPixmap
    QPoint
    QQuaternion                 出来向量和标量构成的四元数的类
    QRect
    QRegExp                     出理正则表达式的类
    QRegularExpression
    QRegion
    QSize
    QString
    QTime
    QTransform                  出理图象描绘大小、剪切旋转坐标等类
    QUrl
    QVariant
    QVector2D
    QVector3D
    QVector4D

    //容器类
    QHash<key,T>
    QMap<key,T>
    QPair<T1,T2>
    QList<T>
    QLinkedList<T>
    QVector<T>
    QStack<T>
    QQueue<T>
    QSet<T>
    QMap<key,T>
    QMultiMap<Key,T>
    QMultiHash<Key,T>


     //字符串类
    QByteArray
    QByteArrayMatcher
    QChar
    QLatin1CharQLatin1String
    QLocale
    QString
    QStringList
    QStringMatcher
    QStringRef
    QTextBoundayFinder
    QTextStream
     */

    /*
    //返回绝对值函数
    int absoluteValue;
    int myValue = -4;

    absoluteValue = qAbs(myValue);  //4

    //返回最大值和最小值函数
    int minValue = 2;
    int myValue = 10;
    int maxValue = 6;

    int boundedValue = qBound(minValue,myValue,maxValue);  //6

    //处理Critical消息的函数
    void load(const QString &fileName)
    {
        QFile file(firstName);
        if(!file.exists())
            qCritical("File '%s' does not exist！",qPrintable(firstName));
    }


    //输出调试信息函数
    //qDebug("Items in list: %d",myList.size());

    //出来错误信息的函数
    int divide(int a,int b)
    {
        if(b == 0)
            qFatal("divide: cannot divide by zero");
        return a / b;
    }

    //比较浮点值函数
    qFuzzyCompare(0.0,1.0e-200);        //return false
    qFuzzyCompare(1+0.0,1+1.0e-200);        //return true

    //比较浮动型值的函数，相同true，不同false  bool qFuzzyCompare(float p1,float p2)

    //用户自定义函数，输出Qt定义的调试、预警、严重等信息。
    void myMessageOutput(QtMsgType type,const char *msg)
    {
        switch(type){
        case QtDebugMsg:
            fprintf(stderr,"Debug:%s\n",msg);
            break;
        case QtWarningMsg:
            fprintf(stderr,"Warning:%s\n",msg);
            break;
        case QtCriticalMsg:
            fprintf(stderr,"Critical:%s\n",msg);
            break;
        case QtFatalMsg:
            fprintf(stderr,"Fatal:%s\n",msg);
            break;
            abort();
        }
    }

    int main()
    {
        qInstallMessageHandler(myMessageOutput);
        ...
    }

    */

    /*
    //返回两个值中最大值
    int myValue = 6,yourValue = 4;
    int maxValue = qMax(myValue,yourValue); //6

    //返回两个值中最小值
    int minValue = qMin(myValue,yourValue); //4

    //64位整型四舍五入函数
    qreal ValueA = 42949672960.3;
    qreal ValueB = 42949672960.7;
    int roundValueA = qRound(ValueA);       //42949672960
    int roundValueB = qRound(ValueB);       //42949672961

    //整型四舍五入函数
    qreal ValueA = 2.3;
    qreal ValueB = 2.7;
    int roundValueA = qRound(ValueA);       //2
    int roundValueB = qRound(ValueB);       //3
    */

    /*
    QBitArray ba(200);

    ba.resize(3);
    ba[0] = true;
    ba[1] = false;
    ba[2] = true;

    QBitArray x(5);
    x.setBit(3,true);   //x:[0,0,0,1,0]

    QBitArray y(5);
    y.setBit(4,true);   //x:[0,0,0,0,1]

    x |= y; //x:[0,0,0,1,1]

    QBitArray().isNull();
    QBitArray().isEmpty();

    QBitArray bc(8);
    bc.fill(8);//x:[1,1,1,1,1,1,1,1]

    bc.fill(false,2);//ba:[0,0]

    //QBrush 用于QPainter的图形填充模式
    QPainter painter(this);

    painter.setBrush(Qt::cyan);
    painter.setPen(Qt::darkCyan);
    painter.drawRect(0,0,100,100);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::darkGreen);
    painter.drawRect(40,40,100,100);

    QByteArray bba("hello");

    bba.resize(5);
    bba[0] = 0x3c;
    bba[1] = 0xb8;
    bba[2] = 0x64;
    bba[3] = 0x18;
    bba[4] = 0xca;

    for(int i = 0;i < bba.size();i++)
    {
        if(bba.at(i) >= 'a' && bba.at(i) <= 'f')
           qDebug() << "Found character in range [a-f]" << endl;
    }

    QByteArray ba1("ca\0r\0t");
    ba1.size();     //2
    ba1.constData();  //"ca"

    QByteArray ba2("ca\0r\0t",3);
    ba2.size();     //3
    ba2.constData();  //"ca\0"

    QByteArray ba3("ca\0r\0t",4);
    ba3.size();     //4
    ba3.constData();  //"ca\0\r"

    const char cart[] = {'c','a','\0','r','\0','t'};

    QByteArray ba4(QByteArray::fromRawData(cart,6));
    ba4.size();     //6
    ba4.constData();  //"ca\0r\0t"

    QByteArray x1("and");
    x1.prepend("rock"); //x1 = "rock and"
    x1.append("roll");//x1 = "rock and roll"
    x1.replace(5,3,"&");    //x1 = "rock & roll"

    QByteArray baa("We must be <b>bold</b>,very <b>bold</b>");
    int j = 0;
    while((j = baa.indexOf("<b>",j)) != -1) //从头开始查找特定字符，lastIndexOf()从尾部开始查找。
    {
        qDebug() << "Found <b> tag at index position" << j << endl;
        ++j;
    }

    QByteArray().isNull();
    QByteArray().isEmpty();

    QByteArray baaa("STARTTLS\r\n");    //chop函数参数int值，表示该字符串末尾长度
    baaa.chop(2);   //ba == "STARTTLS"


    QByteArray ba5("Istambul");
    ba5.fill('o');//ba5 = "oooooooo"

    ba5.fill('X',2);//ba5 = "XX"

    QByteArray text = QByteArray::fromBase64("UXQgaXMgZ3J1YXQh");
    text.data();//"Qt is great!"

    QByteArray text1 = QByteArray::fromHex("517420697320677265617421");
    text1.data();//"Qt is great!"

    QByteArray text2 = QByteArray::fromPercentEncoding("Qt%20is%20great%33");
    text2.data();//"Qt is great!"

    QByteArray xx1("Pineapple");
    QByteArray y1 = xx1.left(4);//"Pine"

    QByteArray xx11("apple");
    QByteArray y11 = xx11.leftJustified(8,'.');//"apple..."

    QByteArray xxx("Say yes!");
    QByteArray yyy("no");
    xxx.replace(4,3,yyy); //"Say no!

    QByteArray str("FF");
    bool ok;
    int hex = str.toInt(&ok,16);    //hex = 255,ok = true;
    int dec = str.toInt(&ok,10);    //hex = 0,ok = false;


    QByteArray xxxx("Qt by DIGIA");
    QByteArray yyyy = xxxx.toLower();   //"qt by digia"


    painter.setBrush(QColor(255,0,0,127));
    painter.drawRect(0,0,width()/2,height());

    //QCursor将鼠标光标指定为任意形状。

    QDate d1(1995,5,17);
    QDate d2(1995,5,20);

    d1.daysTo(d2);  //3
    d2.daysTo(d1);  //-3

    QDate d3 = QDate::currentDate();

    int day = d3.dayOfWeek();

    QTime time1 = QTime::fromString("131","HHh");

    QDateTime dateTime2 = QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss");

    QPropertyAnimation animation;
    animation.setStartValue(0);
    animation.setEndValue(1000);
    animation.setDuration(1000);
    animation.setEasingCurve(QEasingCurve::InOutQuad);

    QFont serifFont("Times",10,QFont::Bold);
    QFont sansFont("Helvetica [Cronyx]",12);

    QToolButton *button = new QToolButton;
    button->setIcon(QIcon("open.xpm"));

//    QKeySequence 指定快捷键

//    QMarigns 指定矩形边距值
    */



    /*
    QFile data("output.txt");       //QFile继承于QFileDevice
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out << "Result:" << qSetFieldWidth(10) << left << 3.14 << 2.7;
    }

    //直接在文件中记录数据
    QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        //process_line(line);
        qDebug() << line;
    }

    //使用流读取文件内容

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        //process_line(line);
        qDebug() << line;
    }

    //attend()判断文件是否结束

    //将文件数据记录到<<运算符使用
    QFile file1("out.txt");
    if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream out(&file1);
    out << "The magic number is :" << 49 << "\n";

    QFile file2("/proc/modules");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in1(&file2);
    QString line = in1.readLine();
    while(!line.isNull())
    {
        //process_line(line);
        qDebug() << line;
        line = in.readLine();
    }
    */

    /*
    QList<QString> list;
    list<<"ABCF" <<"EFGH"<<"HIJK" <<"LMNO";

    QListIterator<QString> i(list);
    while(i.hasNext())
    {
        qDebug() << i.next();
    }

    QListIterator<QString> i1(list);
    i1.toBack();
    while(i1.hasPrevious())
    {
        qDebug() << i1.previous();
    }

    //QListIterator  不提供插入和删除操作
    //如果删除，使用QMutableListIterator
    QList<int> in;
    in<< 1 <<2<<3 <<4;
    QMutableListIterator<int> i2(in);
    while(i2.hasNext())
    {
        if(i2.next()%2==0)
            i2.remove();
        qDebug() << i2.next();
    }

    QMap<QString,QString>  map;
    map.insert("Pairs","France");
    map.insert("Paris","France");
    map.insert("Moscow","Russia");

    QMutableMapIterator<QString,QString> i4(map);
    while(i4.hasNext())
    {
        if(i4.next().key().endsWith("City"))
            i4.remove();
//        qDebug() << i4.next().key();
    }

    QMap<int,QWidget*> map1;
    QHash<int,QWidget*> hash;

    QMapIterator<int,QWidget*> i5(map1);
    while(i5.hasNext())
    {
        i5.next();
        hash.insert(i5.key(),i5.value());
    }

    QMutableMapIterator<int,QWidget*> i6(map1);
    while(i6.findNext(widget))
    {
        i6.remove();
    }
    */

    QList<QString> list;
    list<<"ABCF" <<"EFGH"<<"HIJK" <<"LMNO";

    QList<QString>::iterator i;
    for(i = list.begin();i != list.end();i++)
    {
       *i = (*i).toLower();
    }

    QList<QString>::const_iterator i1;
    for(i = list.begin();i != list.end();i++)
    {
        qDebug() << *i;
    }

    QMap<int,int> map;
    map.insert(1,3);
    map.insert(2,4);
    map.insert(6,5);

    QMap<int,int>::const_iterator i2;
    for(i2 = map.constBegin();i2 != map.constEnd();++i)
    {
        qDebug() << i2.key() << ":" << i2.value();
    }

    QLinkedList<QString> list1;
    list << "1" << "2";
    QString str;
    foreach (str,list1) {
        qDebug() << str;
    }

    QLinkedListIterator<QString> i3(list1);
    while(i3.hasNext())
    {
        qDebug() << i3.next();
    }

    foreach(const QString &str,list1)
    {
        if(str.isEmpty())
            break;
        qDebug() << str;
    }

    foreach(const int &a,map)
    {
        qDebug() << a << ":" << map.value(a);
    }

    QMultiMap<int,int> mmap;
    mmap.insert(1,3);
    mmap.insert(2,4);
    mmap.insert(6,5);
    foreach(const int& b,mmap.uniqueKeys())
    {
        foreach(int i,map.value(b))
        {
            qDebug() << b << ":" << i;
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

//QCheckBox
void MainWindow::chkChanged()
{
    for(int i = 0;i < 3;i++)
    {
        if(exclusive[i]->checkState())
            qDebug("checkbox %d selected",i+1);
    }
}

//QComboBox
void MainWindow::valueChanged()
{
    int current_index = combo->currentIndex();
    qDebug("Current ComboBox index : %d",current_index);
}


//QDial
void MainWindow::changedData()
{
    qDebug("QDial 1 value: %d",dial[0]->value());
}

//QSpinBox
void MainWindow::valuechange()
{
    qDebug("Change value :%d",spin[0]->value());
}

//QDoubleSpinBox
void MainWindow::double_valuechange()
{
    qDebug("Change double value :%d",doublepin[0]->value());
}

//按钮
void MainWindow::btn_click()
{
    qDebug("Button Click");
}

void MainWindow::btn_pressed()
{
    qDebug("Button Pressed");
}

void MainWindow::btn_released()
{
    qDebug("Button Releasedd");
}

//字体
void MainWindow::changedIndex(int idx)
{
    lb = new QLabel("I love Qt programming",this);
    lb->setGeometry(10,150,200,30);
}

void MainWindow::changedFont(const QFont &f)
{
    lb = new QLabel("I love Qt programming",this);
    lb->setGeometry(10,150,200,30);
}

//文本
void MainWindow::textchanged(QString str)
{

}

//菜单
void MainWindow::trigerMenu(QAction* act)
{
    QString str = QString("Selected Menu : %1").arg(act->text());
    lb->setText(str);
    lb->adjustSize();
}

void MainWindow::on_actionnew_triggered()
{

}


void MainWindow::valueChanged1(int value)
{
    lb1[0]->setText(QString("%1").arg(value));
    //hscrollbar[0]->setValue(vscrollbar[0]->value());//滚动条
    slider[0]->setValue(slider[0]->value());
}

void MainWindow::currentTab(int index)
{
    qDebug("Current Tab : %d",index);
}

void MainWindow::trigger1()
{
    qDebug("Tool Button 1 click:");
}

void MainWindow::open()
{

}

void MainWindow::newFile()
{

}
