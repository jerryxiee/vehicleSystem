#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //为窗体分配空间
    weather =  new WeatherWindow(this);
    video = new VideoWindow(this);
    music = new MusicWindow(this);
    mapp = new MapWindow(this);
    ui->label->setStyleSheet("color:rgb(255, 255, 255)");   //设置字体颜色
    //定时器
    mytime = new QTimer(this);
    connect(mytime,SIGNAL(timeout()),this,SLOT(show_time()));
    mytime->start();                        //启动定时器
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_time()//时间显示
{
    QDateTime t = QDateTime::currentDateTime();
    ui->lcdNumber->setDigitCount(25);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->display(t.toString("yyyy-MM-dd hh:mm:ss ddd"));
}

void MainWindow::on_commandLinkButton_clicked()//天气
{
    //显示子窗体
    weather->show();
    //隐藏
    this->hide();
}

void MainWindow::on_commandLinkButton_2_clicked()//视频
{
    video->show();
    this->hide();
}

void MainWindow::on_commandLinkButton_3_clicked()//音乐
{
    music->show();
    this->hide();
}

void MainWindow::on_commandLinkButton_4_clicked()//地图
{
    mapp->show();
    this->hide();
}
