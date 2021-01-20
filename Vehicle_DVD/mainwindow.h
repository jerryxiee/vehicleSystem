#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//添加窗体头文件
#include "weatherwindow.h"
#include "videowindow.h"
#include "musicwindow.h"
#include "mapwindow.h"

//定时器时间显示
#include <QTimer>
#include <QDateTime>

//ui字体
#include <QFont>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void show_time();   //lcd时间显示

    void on_commandLinkButton_clicked();    //窗体1：天气

    void on_commandLinkButton_2_clicked();  //窗体2：视频播放器

    void on_commandLinkButton_3_clicked();  //窗体3：音乐播放器

    void on_commandLinkButton_4_clicked();  //窗体4：地图ip

private:
    Ui::MainWindow *ui;

    //自定义窗体
    WeatherWindow *weather;
    VideoWindow *video;
    MusicWindow *music;
    MapWindow *mapp;

    //时间定时器
    QTimer  *mytime;

};
#endif // MAINWINDOW_H
