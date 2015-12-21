#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QGraphicsScene>
#include <QSqlDatabase>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit   MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool ConnectDatabase();
    bool ConnectSerialport();
    void Addbutton();
    void Delbutton();
    void Delroom();
    QString floornub;
    QString roomnub;
    QString shujianub;
    QString booknub;
private:
    QSerialPort *serial;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItem *buttonParent;
    QGraphicsItem *roomParent;
    QGraphicsItem *shujiaParent;
    QGraphicsItem *bookParent;
    Ui::MainWindow *ui;
    int maplevel;
  private slots:
      void serialRead();
      void Addroom();
      void Addshujia();
      void Addbooks();
      void on_pushButton0_clicked();
      void on_pushButton1_clicked();
      void on_pushButton2_clicked();
      void on_pushButton3_clicked();
      void on_pushButton4_clicked();
      void on_pushButton5_clicked();
};

#endif // MAINWINDOW_H
