#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QDebug>
#include<QFile>
#include<QPixmap>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr);
    ~MapWindow();

private slots:

    void on_commandLinkButton_clicked();

    void on_quanjing_clicked();

    void on_static_2_clicked();

    void on_state_clicked();

    void slotReadyRead();

    void slotReadyRead2();

    void slotReadyRead3();

    void slotReadData();
private:
    Ui::MapWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *jpg;
    QNetworkAccessManager *png;
    QNetworkReply *reply;
    QNetworkReply *reply2;
    QNetworkReply *reply3;
    QNetworkReply *replyip;
    QFile file1;        //全景图文件
    QFile file2;        //静态图文件
    QString x;          //经度
    QString y;          //纬度
    int down_size=0;      //下载大小



};

#endif // MAPWINDOW_H
