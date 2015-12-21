#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include "button.h"
#include "room.h"
#include "shujia.h"
#include "books.h"
#include "backg.h"
Button *flo1;
Button *flo2;
Button *flo3;
Button *flo4;
Room *room1;
Shujia *shujia1;
Shujia *shujia2;
Shujia *shujia3;
Shujia *shujia4;
Shujia *shujia5;
Shujia *shujia6;
Shujia *shujia7;
Shujia *shujia8;
Shujia *shujia9;
Shujia *shujia10;
Book *book1;
Book *book2;
Book *book3;
MainWindow::MainWindow(QWidget *parent)    :
    QMainWindow(parent),  ui(new Ui::MainWindow)
{
        ui->setupUi(this);
 //   ConnectDatabase();
    ConnectSerialport();
    scene = new QGraphicsScene(this);
    view = new QGraphicsView;
setFixedSize(740,490);
        Addbutton();

    view->setScene(scene);
    view->setRenderHints(QPainter::Antialiasing
                         | QPainter::TextAntialiasing);
    view->setContextMenuPolicy(Qt::ActionsContextMenu);
      view->setDragMode(QGraphicsView::ScrollHandDrag);

    ui->graphicsView->setViewport(view);
}

MainWindow::~MainWindow()
{
    serial->close();
        delete ui;
        delete serial;
}

bool MainWindow::ConnectDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

     db.setHostName("MEIQUA\\SQLEXPRESS");
     db.setDatabaseName("mydsn32");
     db.setUserName("book");
     db. setPassword ( "123456") ;
     if (!db.open()) {
     QMessageBox::critical(0, QObject::tr("Database Error"),
     db.lastError().text());
     return false;
                     }
//        else
//        {
//            QMessageBox::critical(0, QObject::tr("Database linked!"),
//            "cao");
//        }


     return true;
}

bool MainWindow::ConnectSerialport()
{
    serial = new QSerialPort("COM1");       //串口号，一定要对应好，大写！！！下面这些设置都是针对单片机11.0592的晶振的，但是串口号就要修改，假如不是这种情况，那么波特率之类很可能也要改！！
    serial->open(QIODevice::ReadWrite);      //读写打开
    serial->setBaudRate(QSerialPort::Baud9600);  //波特率
    serial->setDataBits(QSerialPort::Data8); //数据位
    serial->setParity(QSerialPort::NoParity);    //无奇偶校验
    serial->setStopBits(QSerialPort::OneStop);   //无停止位
    serial->setFlowControl(QSerialPort::NoFlowControl);  //无控制
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialRead()));    //连接槽
    return true;
}


void MainWindow::Addbutton()
{
    if(maplevel==1)
        scene->removeItem(buttonParent);
        if(maplevel==2)
            scene->removeItem(roomParent);
            if(maplevel==3)
                scene->removeItem(shujiaParent);
                if(maplevel==4)
                    scene->removeItem(bookParent);
    buttonParent = new QGraphicsRectItem;
    maplevel=1;
    QPixmap bgPix(":/images/bg.bmp");
      scene->setSceneRect(0,0,700,380);
        view->setBackgroundBrush(bgPix);
    flo4=new Button( QPixmap(":/images/F4.bmp"),buttonParent);
        flo4->setPos(150, 0);
       flo3=new Button( QPixmap(":/images/F3.bmp"),buttonParent);
            flo3->setPos(150, 90);
            flo2=new Button( QPixmap(":/images/F2.bmp"),buttonParent);
                flo2->setPos(150, 180);
           flo1=new Button( QPixmap(":/images/F1.bmp"),buttonParent);
                    flo1->setPos(150, 270);
     if(floornub=="F1")
     {
         Bg *floorbg=new Bg(buttonParent,400,100);
         floorbg->setPos(150,270);
     }
    scene->addItem(buttonParent);
    buttonParent->setPos(0, 0);
        connect(flo1,SIGNAL(intofloor()),this,SLOT(Addroom()));
}

void MainWindow::Delbutton()
{
   scene->removeItem(buttonParent);
}

void MainWindow::Addroom()
{
    if(maplevel==1)
        scene->removeItem(buttonParent);
        if(maplevel==2)
            scene->removeItem(roomParent);
            if(maplevel==3)
                scene->removeItem(shujiaParent);
                if(maplevel==4)
                    scene->removeItem(bookParent);
    QPixmap bgPix1(":/images/fenbu.bmp");
        view->setBackgroundBrush(bgPix1);
              scene->setSceneRect(0,0,700,380);
    roomParent = new QGraphicsRectItem;
    maplevel=2;
    room1=new Room( QPixmap(":/images/fenbu.bmp"),roomParent);
    room1->setPos(321, 114);
    if(roomnub=="A100")
    {
        Bg *roombg=new Bg(roomParent,97,121);
        roombg->setPos(321,114);
    }
        scene->addItem(roomParent);
               connect(room1,SIGNAL(intoroom()),this,SLOT(Addshujia()));
   update();

}

void MainWindow::Addshujia()
{
    if(maplevel==1)
        scene->removeItem(buttonParent);
        if(maplevel==2)
            scene->removeItem(roomParent);
            if(maplevel==3)
                scene->removeItem(shujiaParent);
                if(maplevel==4)
                    scene->removeItem(bookParent);
    QPixmap bgPix2(":/images/tushugbg.bmp");
       view->setBackgroundBrush(bgPix2);
             scene->setSceneRect(0,0,1300,624);
      shujiaParent = new QGraphicsRectItem;
      maplevel=3;
      QPointF p1,p2,p3,p4,p5,p6;
      p1=QPointF(213,215);
      p2=QPointF(243,75);
      p3=QPointF(271,77);
      p4=QPointF(311,151);
      p5=QPointF(292,279);
      p6=QPointF(263,281);
       shujia1=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
       p1=QPointF(350,80);
       p2=QPointF(378,80);
       p6=QPointF(330,223);
       p3=QPointF(411,156);
       p5=QPointF(367,285);
       p4=QPointF(392,273);
        shujia2=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
        p1=QPointF(389,270);
        p2=QPointF(565,271);
        p6=QPointF(386,298);
        p3=QPointF(580,326);
        p5=QPointF(420,354);
        p4=QPointF(575,354);
         shujia3=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
         p1=QPointF(378,361);
         p2=QPointF(563,361);
         p3=QPointF(576,409);
         p4=QPointF(572,434);
         p5=QPointF(408,439);
         p6=QPointF(371,389);
          shujia4=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
          p1=QPointF(679,272);
          p2=QPointF(711,274);
          p3=QPointF(715,355);
          p4=QPointF(706,408);
          p5=QPointF(677,408);
          p6=QPointF(675,347);
           shujia5=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
           p1=QPointF(701,119);
           p2=QPointF(789,119);
           p3=QPointF(787,145);
           p4=QPointF(773,214);
           p5=QPointF(696,214);
           p6=QPointF(693,195);
            shujia6=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
            p1=QPointF(998,72);
            p2=QPointF(1077,73);
            p6=QPointF(954,151);
            p3=QPointF(1082,95);
            p4=QPointF(1035,174);
            p5=QPointF(962,174);
             shujia7=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
             p1=QPointF(1037,230);
             p2=QPointF(1066,232);
             p3=QPointF(1083,308);
             p4=QPointF(1030,365);
             p5=QPointF(1002,365);
             p6=QPointF(987,291);
              shujia8=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
              p1=QPointF(1087,229);
              p2=QPointF(1119,228);
              p3=QPointF(1133,306);
              p4=QPointF(1075,364);
              p5=QPointF(1047,366);
              p6=QPointF(1032,281);
               shujia9=new Shujia( QPixmap(":/images/tushug.bmp"),shujiaParent,p1,p2,p3,p4,p5,p6);
               shujia9->setZValue(-1);

       if(shujianub=="4")
       {
           Bg *roombg=new Bg(shujiaParent,105,208);
           roombg->setPos(212,76);
       }                                                        //红色线框标记
           scene->addItem(shujiaParent);
              shujiaParent->setPos(0, 0);
              connect(shujia1,SIGNAL(intoshujia()),this,SLOT(Addbooks()));
      update();

}

void MainWindow::Addbooks()
{
    if(maplevel==1)
        scene->removeItem(buttonParent);
        if(maplevel==2)
            scene->removeItem(roomParent);
            if(maplevel==3)
                scene->removeItem(shujiaParent);
                if(maplevel==4)
                    scene->removeItem(bookParent);
    bookParent=new QGraphicsRectItem;
    maplevel=4;
    QPixmap bgPix2(":/images/bg2.bmp");
          scene->setSceneRect(0,0,700,380);
       view->setBackgroundBrush(bgPix2);
    Bg0 *bbg= new Bg0(QPixmap(":/images/book.bmp"),bookParent);
    bbg->setPos(-10,-30);
    book1=new Book(QPixmap(":/images/whoareyou.bmp"),bookParent,108,23,119,95);
    book1->setPos(19,42);
    book2=new Book(QPixmap(":/images/whoareyou.bmp"),bookParent,397,122,414,200);
    book2->setPos(19,132);
    book3=new Book(QPixmap(":/images/whoareyou.bmp"),bookParent,338,232,355,314);
    book3->setPos(19,222);
    if(booknub=="123")
    {
        Bg *bookbg=new Bg(bookParent,17,82);
        bookbg->setPos(19,222);
    }
    scene->addItem(bookParent);
       bookParent->setPos(220, 50);
}

void MainWindow::Delroom()
{
    scene->removeItem(roomParent);
}

void MainWindow::serialRead()
{
    static QByteArray allData;         //静态变量！！在串口只发送一半的时候用来累加数据
    QByteArray dataTemp;            //每次读到的数据，可能只是部分的，大多数情况下是正确的，大约1/5会出错
    while (!serial->atEnd()) {
        QByteArray dataTemp = serial->readAll();                //因为串口是不稳定的，也许读到的是部分数据而已，但也可能是全部数据
        if( dataTemp.data()[dataTemp.length() - 1] == 0xaa){     //当临时数据最后一位是'~'代表一条数据读完了
            allData += dataTemp;                                //总数据加上临时数据
            allData.resize(allData.size() - 1);                 //删除结尾的~符号

            qCritical() << allData;                             //这时候allData将是你要的数据
            allData.clear();                                    //清除数据!!!!!
                   }
                   else{                                                  //当最后一位数据不是'~'，即未读完
                       allData += dataTemp;                               //每次累加这部分数据,因为可能没发完
                   }
               }
           }

//void MainWindow::on_pushButton_clicked()
//{
//    QString data=ui->lineEdit->text();
//}

void MainWindow::on_pushButton0_clicked()
{
    if (ui->lineEdit->text()=="123")
    {

        ui->pushButton1->setText("Floor:1F");
        ui->pushButton2->setText("Room:A100");
        ui->pushButton3->setText("Area:1");
        ui->pushButton4->setText(" Column:4");
        ui->pushButton5->setText(" Array:3");
        floornub="F1";
        roomnub="A100";
        shujianub="4";
        booknub="123";
        Addshujia();
        if(maplevel==1)
            scene->removeItem(buttonParent);
            if(maplevel==2)
                scene->removeItem(roomParent);
                if(maplevel==3)
                    scene->removeItem(shujiaParent);
                    if(maplevel==4)
                        scene->removeItem(bookParent);
                    if(maplevel==1)
                Addbutton();
                        if(maplevel==2)
                Addroom();
                            if(maplevel==3)
                Addshujia();
                                if(maplevel==4)
                Addbooks();
    }
    else
    {
        ui->pushButton1->setText("Floor:Null");
        ui->pushButton2->setText("Room:Null");
        ui->pushButton3->setText("Area:Null");
        ui->pushButton4->setText(" Column:Null");
        ui->pushButton5->setText(" Array:Null");
        floornub="Null";
        roomnub="Null";
        shujianub="Null";
        booknub="Null";
        if(maplevel==1)
            scene->removeItem(buttonParent);
            if(maplevel==2)
                scene->removeItem(roomParent);
                if(maplevel==3)
                    scene->removeItem(shujiaParent);
                    if(maplevel==4)
                        scene->removeItem(bookParent);
        if(maplevel==1)
    Addbutton();
            if(maplevel==2)
    Addroom();
                if(maplevel==3)
    Addshujia();
                    if(maplevel==4)
    Addbooks();
    }
}

void MainWindow::on_pushButton1_clicked()
{
    Addbutton();
}

void MainWindow::on_pushButton2_clicked()
{
    Addroom();
}

void MainWindow::on_pushButton3_clicked()
{
    Addshujia();
}

void MainWindow::on_pushButton4_clicked()
{
    Addshujia();
}

void MainWindow::on_pushButton5_clicked()
{
    Addbooks();
}
