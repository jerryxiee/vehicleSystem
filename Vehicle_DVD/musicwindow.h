#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>
#include <QPixmap>
#include <iostream>
#include <QDateTime>
#include <QMouseEvent>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QByteArray>
#include <QtGui/QIcon>
#include <QDebug>
#include <QListWidgetItem>
#include <QSlider>
#include <QTimer>
#include <QScrollBar>
#include <QListWidgetItem>
#include <QListWidget>
#include <QListView>
#include <QFont>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicWindow(QWidget *parent = nullptr);
    ~MusicWindow();
    void music_play(QString music);     //音乐播放
    void lrc_show(QString mp3name);     //歌词显示
private slots:

    void on_commandLinkButton_clicked();        //返回按钮

    void on_volume_toggled(bool checked);       //音量调节按钮

    void on_addfiles_clicked();                 //添加文件

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);        //双击列表项

    void music_data();                          //音乐数据处理

    void on_play_toggled(bool checked);         //音乐暂停播放按钮

    void on_prev_clicked();                     //上一首音乐

    void on_next_clicked();                     //下一首音乐

    void on_del_clicked();                      //删除按钮

    void on_vol_change_sliderMoved(int position);       //音量调节滑动

    void on_lrc_change_sliderMoved(int position);       //进度条滑动

    void onTimeout();   //定时器

    void on_lrc_change_actionTriggered(int action);     //点击进度条实现快进快退

    void on_lrc_change_sliderPressed();                 //进度条按下

    void on_lrc_change_sliderReleased();                 //进度条弹起

private:
    Ui::MusicWindow *ui;
    QStringList musicFile;      //音乐路径列表
    QStringList lrcFile;        //歌词路径列表
    QStringList timeList;       //时间列表
    QStringList lrcList;        //歌词时间列表
    QProcess *process;          //使用进程进行音频操作
    QString mp_path;            //用来存放要使用的mplayer播放器路径
    QIcon icon;                 //图标
    int ntime=0;                //音乐播放当前位置

    QTimer *timer;              //定时器
};

#endif // MUSICWINDOW_H
