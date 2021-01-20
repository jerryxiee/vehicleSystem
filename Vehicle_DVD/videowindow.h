#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>
#include <QPixmap>
#include <QDateTime>
#include <QTime>
#include <QFile>
#include <QProcess>
#include <QByteArray>
#include <QtGui/QIcon>
#include <QDebug>
#include <QListWidgetItem>
#include <QSlider>
#include <QTimer>

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();
    void video_play(QString);      //视频播放

private slots:
    void on_commandLinkButton_clicked();        //返回按钮

    void on_commandLinkButton_3_clicked();      //添加文件按钮

    void video_data();                      //视频数据处理

    void on_volume_toggled(bool checked);   //音量

    void on_play_toggled(bool checked);     //播放暂停

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);    //双击列表项

    void on_next_clicked();                 //下一个视频

    void on_prev_clicked();                 //上一个视频

    void on_del_clicked();                  //删除视频

    void on_volchange_sliderMoved(int position);        //音量条滑动

    void on_horizontalSlider_sliderMoved(int position);     //进度条滑动

    void on_horizontalSlider_actionTriggered(int action);   //点击进度条快进快退

    void on_horizontalSlider_sliderPressed();               //进度条按下

    void on_horizontalSlider_sliderReleased();              //进度条弹起

    void onTimeout();                                       //定时器

private:
    Ui::VideoWindow *ui;
    QStringList fileName;       //视频列表

    QProcess *process;          //使用进程进行视频操作
    QString mp_path;            //用来存放要使用的mplayer播放器路径
    QIcon icon;                 //图标
    int ntime=0;                //进度条的值
    int vd_length=0;            //视频总时长
    QTimer *timer;              //定时器
};

#endif // VIDEOWINDOW_H
