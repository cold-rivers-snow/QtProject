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
