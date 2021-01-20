#include "weatherwindow.h"
#include "ui_weatherwindow.h"

WeatherWindow::WeatherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    //关联槽函数
    connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinished(QNetworkReply *)));
    manager->get(QNetworkRequest(QUrl("http://t.weather.itboy.net/api/weather/city/101280101")));

    //对qlabel进行赋值
    dw[0]=ui->dateweekday;
    dw[1]=ui->dateweekday_2;
    dw[2]=ui->dateweekday_3;
    dw[3]=ui->dateweekday_4;
    dw[4]=ui->dateweekday_5;
    dw[5]=ui->dateweekday_6;

    tpe1[0]=ui->type1;
    tpe1[1]=ui->type1_2;
    tpe1[2]=ui->type1_3;
    tpe1[3]=ui->type1_4;
    tpe1[4]=ui->type1_5;
    tpe1[5]=ui->type1_6;

    hg[0]=ui->high;
    hg[1]=ui->high_2;
    hg[2]=ui->high_3;
    hg[3]=ui->high_4;
    hg[4]=ui->high_5;
    hg[5]=ui->high_6;

    lw[0]=ui->low;
    lw[1]=ui->low_2;
    lw[2]=ui->low_3;
    lw[3]=ui->low_4;
    lw[4]=ui->low_5;
    lw[5]=ui->low_6;

}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}


void WeatherWindow::on_commandLinkButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void WeatherWindow::replyFinished(QNetworkReply *arg)//对返回的数据进行json解析处理
{
   QString js = arg->readAll();
   QJsonParseError error;
   QJsonDocument json = QJsonDocument::fromJson(js.toUtf8(),&error);
   if(error.error != QJsonParseError::NoError)
   {
       qDebug()<<error.errorString();
   }
   else
       qDebug()<<"init json succeed!";
   //取对象
   QJsonObject obj=json.object();

   //对象里的data
   QJsonValue value1 = obj.take("data");
   QJsonObject obj1=value1.toObject();

   QJsonValue value2 = obj.take("cityInfo");
   QJsonObject obj2=value2.toObject();

   //cityInfo里的city
   QJsonValue value_city = obj2.take("city");
   //qDebug()<<value_city.toString();
   ui->city->setText(value_city.toString());

   //updatetime
   QJsonValue value_upt = obj2.take("updateTime");
   //qDebug()<<value_upt.toString();
    ui->updatetime->setText("更新时间 "+value_upt.toString());

   //centigrade
   QJsonValue value_centg = obj1.take("wendu");
   //qDebug()<<value_centg.toString();
   ui->centigrade->setText(value_centg.toString()+"℃");

   //apilevel
   QJsonValue value_apilevel = obj1.take("quality");
   //qDebug()<<value_apilevel.toString();
   ui->aqilevel->setText("级别 "+value_apilevel.toString());

   //humid
   QJsonValue value_humid = obj1.take("shidu");
   //qDebug()<<value_humid.toString();
   ui->humid->setText("湿度 "+value_humid.toString());

   //data里的forecast
   QJsonValue value = obj1.take("forecast");
   QJsonArray arr = value.toArray();

    QVariantList list = arr.toVariantList();
    QVariantMap map = list[0].toMap();
    ui->weekday->setText(map["week"].toString());
    ui->date_2->setText(map["ymd"].toString());

    ui->aqi->setText("空气质量指数 "+QString::number(map["aqi"].toInt()));
    ui->wind->setText("风速 "+map["fx"].toString() +" "+ map["fl"].toString());
    ui->type->setText(map["type"].toString());
    if(map["type"].toString()=="晴")
        ui->icon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/sunny.png")));
    if(map["type"].toString()=="多云")
        ui->icon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/cloudy.png")));
    if(map["type"].toString()=="阴")
        ui->icon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/yintian.png")));
    if(map["type"].toString()=="小雨")
        ui->icon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/xiaoyu.png")));
    if(map["type"].toString()=="霾")
        ui->icon->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/mai.png")));

    for(int i=0;i<6;i++)
    {
        QVariantMap map = list[i].toMap();
        dw[i]->setText(map["date"].toString()+"("+map["week"].toString()+")");
        hg[i]->setText(map["high"].toString().mid(3).remove("℃")+"°");
        lw[i]->setText(map["low"].toString().mid(3).remove("℃")+"°");
        if(map["type"].toString()=="晴")
        {
           tpe1[i]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/sunny.png")));
        }
        if(map["type"].toString()=="多云")
        {
            tpe1[i]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/cloudy.png")));
        }
        if(map["type"].toString()=="阴")
        {
            tpe1[i]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/yintian.png")));
        }
        if(map["type"].toString()=="小雨")
        {
            tpe1[i]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/xiaoyu.png")));
        }
        if(map["type"].toString()=="霾")
        {
            tpe1[i]->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/weather/mai.png")));
        }
    }
}
/*
for(int i=0; i<5; i++)
    {
        QString day  = arr.at(i).toObject().take("date").toString() + "日(" + arr.at(i).toObject().take("week").toString() + ")";
        QString wea  = arr.at(i).toObject().take("type").toString();
        QString tem1 = arr.at(i).toObject().take("high").toString().mid(3,2) + "℃";
        QString tem2 = arr.at(i).toObject().take("low").toString().mid(3,2) + "℃";

        int n = i+1;
        QString lb1 = QString("day_%1").arg(n);
        QString lb2 = QString("tem1_%1").arg(n);
        QString lb3 = QString("tem2_%1").arg(n);
        QString lb4 = QString("icon_%1").arg(n);

        QList<QLabel *> labelList = ui->centralwidget->findChildren<QLabel *>();
        foreach(auto lbl, labelList)
        {
            if(lbl->objectName() == lb1)
                lbl->setText(day);
            if(lbl->objectName() == lb2)
                lbl->setText(tem1);
            if(lbl->objectName() == lb3)
                lbl->setText(tem2);
            if(lbl->objectName() == lb4)
                set_weather_icon(wea, lbl);
        }
    }
*/
