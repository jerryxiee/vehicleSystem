#include "mapwindow.h"
#include "ui_mapwindow.h"

MapWindow::MapWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    jpg = new QNetworkAccessManager(this);
    png = new QNetworkAccessManager(this);

    file1.setFileName("./v2.jpg");  //新建jpg文件
    file2.setFileName("./v3.png");  //新建png文件

    //http://ip-api.com/json 获取本地经纬度
    //23.165673,113.435109;23.170823,113.44438
    //23.165732,113.442672
    //"x":"113.30764968","y":"23.12004910"
    //560*310
    //精准经纬度https://api.map.baidu.com/location/ip?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&coor=bd09ll
    //返回静态图http://api.map.baidu.com/staticimage/v2?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&mcode=666666&center=113.30764968,23.12004910&width=300&height=200&zoom=11
    //返回全景图 http://api.map.baidu.com/panorama/v2?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&width=512&height=256&location=113.4426721,23.165732&fov=180
    //道路状况http://api.map.baidu.com/traffic/v1/bound?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&bounds=23.165428,113.430151;23.170823,113.44438&coord_type_input=gcj02&coord_type_output=gcj02

    //获取本地经纬度
    //发送HTTP 请求获取本地 IP   定位
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.map.baidu.com/location/ip?ak=ELsq1BUYRYAPl0DCr0v0WxUb5qhAjZCT&coor=bd09ll"));

    replyip = manager->get(request);
    connect(replyip, &QIODevice::readyRead, this, &MapWindow::slotReadData);
}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::slotReadData()  //处理获取本地经纬度返回的数据
{
    QString js = replyip->readAll();
    //qDebug()<<js;
    //转换为json数据
    QJsonDocument json = QJsonDocument::fromJson(js.toUtf8());
    //取对象
    QJsonObject obj=json.object();
    //对象里的data
    QJsonValue value1 = obj.take("content");
    QJsonObject obj1=value1.toObject();
    //content里面的point
    QJsonValue value2 = obj1.take("point");
     QJsonObject obj2=value2.toObject();
     //point里的x和y
     x=obj2.take("x").toString();
     y=obj2.take("y").toString();
     //qDebug()<<x<<y;


     ui->lineEdit->setText(x);
     ui->lineEdit_2->setText(y);
}


void MapWindow::on_commandLinkButton_clicked()  //返回上一级窗体
{
    this->parentWidget()->show();
    this->hide();
}

void MapWindow::on_quanjing_clicked()   //全景图请求
{
    x  =  ui->lineEdit->text();
    y  =  ui->lineEdit_2->text();

    QNetworkRequest resquest;

    QString url="http://api.map.baidu.com/panorama/v2?ak=ELsq1BUYRYAPl0DCr0v0WxUb5qhAjZCT&width=560&height=310&location=113.4426721,23.165732&fov=180";
    qDebug()<<"url"<<url;
    resquest.setUrl(QUrl(url));//定制请求

    reply=jpg->get(resquest);//发送请求

    if(file1.exists())//文件存在，删除
            file1.remove();
    file1.open(QIODevice::ReadWrite|QIODevice::Append);

    connect(reply, &QIODevice::readyRead, this, &MapWindow::slotReadyRead);

}

void MapWindow::on_static_2_clicked()   //静态图请求
{
    x  =  ui->lineEdit->text();         //获取键入的经纬度
    y  =  ui->lineEdit_2->text();

    QNetworkRequest resquest1;
    QString url=QString("http://api.map.baidu.com/staticimage/v2?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&mcode=666666&center=%1,%2&width=560&height=310&zoom=11").arg(x).arg(y);

    resquest1.setUrl(QUrl(url));//定制请求

    reply2=png->get(resquest1);//发送请求


    if(file2.exists())//文件存在，删除
            file2.remove();
    file2.open(QIODevice::ReadWrite|QIODevice::Append);

    connect(reply2, &QIODevice::readyRead, this, &MapWindow::slotReadyRead2);
}

void MapWindow::on_state_clicked()      //道路状况请求
{
//    x  =  ui->lineEdit->text();
//    y  =  ui->lineEdit_2->text();
    QNetworkRequest resquest2;

/*    //QString转double丢失精度
//    QString x1=QString::number(x.toDouble()+0.012521);
//    QString y1=QString::number(y.toDouble()+0.002818);

//    QString x2=QString::number(x.toDouble()+0.001708);
//    QString y2=QString::number(y.toDouble()+0.005091);
//    qDebug()<<y1<<","<<x1<<";"<<y2<<","<<x2;*/
    QString url="http://api.map.baidu.com/traffic/v1/bound?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&bounds=23.165428,113.430151;23.170823,113.44438&coord_type_input=gcj02&coord_type_output=gcj02";
    //QString url=QString("http://api.map.baidu.com/traffic/v1/bound?ak=0GZWGtmsOluom1Y1AZRXFNXoX7hTHNyI&bounds=%1,%2;%3,%4&coord_type_input=gcj02&coord_type_output=gcj02").arg(y1).arg(x1).arg(y2).arg(x2);

    resquest2.setUrl(QUrl(url));//定制请求

    reply3=manager->get(resquest2);//发送请求
    connect(reply3, &QIODevice::readyRead, this, &MapWindow::slotReadyRead3);
}

void MapWindow::slotReadyRead()     //全景图数据处理
{
    //保存请求返回的数据，再对data进行操作，不然会读走reply的内容不能使用
    QByteArray data = reply->readAll();
    QString  file_size  = reply->rawHeader("Content-Length");   //获取文件大小
    qDebug() <<"Content-Length"<< file_size;

    file1.write(data);                      //写入文件

    down_size += data.length();
     qDebug() <<"down_size"<< down_size;

    if(down_size == file_size.toInt())      //下载大小等于文件大小
    {
         down_size=0;                       //清空大小
         file1.close();                     //关闭文件
         QPixmap pic=file1.fileName();
        //显示图片
        if(pic.load(file1.fileName()))
        {
            pic=pic.scaled(ui->pic->width(),ui->pic->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
            ui->pic->setPixmap(pic);
        }
    }
}

void MapWindow::slotReadyRead2()        //静态图数据处理
{
    //获取文件大小
    QByteArray data = reply2->readAll();
    QString  file_size  = reply2->rawHeader("Content-Length");
    qDebug() <<"Content-Length"<< file_size;
     //qDebug() <<reply2->readAll();
    file2.write(data);

    down_size += data.length();
     qDebug() <<"down_size"<< down_size;

    if(down_size == file_size.toInt())
    {
         down_size=0;
         file2.close();
         QPixmap pic=file2.fileName();
        //显示图片
        if(pic.load(file2.fileName()))
        {
            pic=pic.scaled(ui->pic->width(),ui->pic->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
            ui->pic->setPixmap(pic);
        }
    }
}

void MapWindow::slotReadyRead3()        //路况数据解析
{
    QString state = reply3->readAll();

    QJsonDocument json = QJsonDocument::fromJson(state.toUtf8());
    //取对象
    QJsonObject obj=json.object();

    //description
    QJsonValue value1 = obj.take("description");
    qDebug()<<value1.toString();
    ui->textBrowser->append(value1.toString());

    QJsonValue value2 = obj.take("road_traffic");
    QJsonArray arr = value2.toArray();
    for(int i=0;i<arr.size();i++)
    {
        QString road_name=arr.at(i).toObject().take("road_name").toString();
        qDebug()<<road_name;
        ui->textBrowser->append("道路:"+road_name);       //显示在控件textBrowser中
    }
}

