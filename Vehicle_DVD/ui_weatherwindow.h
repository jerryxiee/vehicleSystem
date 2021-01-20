/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QLabel *city;
    QLabel *icon;
    QLabel *centigrade;
    QLabel *type;
    QLabel *updatetime;
    QLabel *aqi;
    QLabel *aqilevel;
    QLabel *wind;
    QLabel *humid;
    QLabel *dateweekday;
    QLabel *type1;
    QLabel *high;
    QLabel *low;
    QFrame *line;
    QLabel *weekday;
    QLabel *date_2;
    QLabel *high_2;
    QLabel *type1_2;
    QLabel *low_2;
    QLabel *dateweekday_2;
    QLabel *high_3;
    QLabel *type1_3;
    QLabel *low_3;
    QLabel *dateweekday_3;
    QLabel *high_4;
    QLabel *type1_4;
    QLabel *low_4;
    QLabel *dateweekday_4;
    QLabel *high_5;
    QLabel *type1_5;
    QLabel *low_5;
    QLabel *dateweekday_5;
    QLabel *high_6;
    QLabel *type1_6;
    QLabel *low_6;
    QLabel *dateweekday_6;

    void setupUi(QMainWindow *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName(QStringLiteral("WeatherWindow"));
        WeatherWindow->resize(800, 480);
        WeatherWindow->setMinimumSize(QSize(800, 480));
        WeatherWindow->setMaximumSize(QSize(800, 480));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        WeatherWindow->setFont(font);
        WeatherWindow->setStyleSheet(QStringLiteral("QMainWindow{background-image: url(:/new/prefix1/weather/wea1.png);}"));
        centralwidget = new QWidget(WeatherWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(0, 0, 61, 71));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon1);
        commandLinkButton->setIconSize(QSize(50, 50));
        city = new QLabel(centralwidget);
        city->setObjectName(QStringLiteral("city"));
        city->setGeometry(QRect(280, 10, 200, 50));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        city->setFont(font1);
        city->setAlignment(Qt::AlignCenter);
        icon = new QLabel(centralwidget);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(270, 70, 80, 80));
        icon->setScaledContents(true);
        centigrade = new QLabel(centralwidget);
        centigrade->setObjectName(QStringLiteral("centigrade"));
        centigrade->setGeometry(QRect(340, 70, 141, 80));
        QFont font2;
        font2.setPointSize(35);
        font2.setBold(true);
        font2.setWeight(75);
        centigrade->setFont(font2);
        centigrade->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        type = new QLabel(centralwidget);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(350, 140, 50, 50));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        type->setFont(font3);
        type->setAlignment(Qt::AlignCenter);
        updatetime = new QLabel(centralwidget);
        updatetime->setObjectName(QStringLiteral("updatetime"));
        updatetime->setGeometry(QRect(280, 190, 191, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        updatetime->setFont(font4);
        updatetime->setAlignment(Qt::AlignCenter);
        aqi = new QLabel(centralwidget);
        aqi->setObjectName(QStringLiteral("aqi"));
        aqi->setGeometry(QRect(200, 220, 140, 20));
        aqi->setFont(font);
        aqilevel = new QLabel(centralwidget);
        aqilevel->setObjectName(QStringLiteral("aqilevel"));
        aqilevel->setGeometry(QRect(350, 220, 131, 20));
        aqilevel->setFont(font);
        wind = new QLabel(centralwidget);
        wind->setObjectName(QStringLiteral("wind"));
        wind->setGeometry(QRect(460, 220, 141, 20));
        wind->setFont(font);
        humid = new QLabel(centralwidget);
        humid->setObjectName(QStringLiteral("humid"));
        humid->setGeometry(QRect(330, 250, 101, 16));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setWeight(50);
        humid->setFont(font5);
        humid->setAlignment(Qt::AlignCenter);
        dateweekday = new QLabel(centralwidget);
        dateweekday->setObjectName(QStringLiteral("dateweekday"));
        dateweekday->setGeometry(QRect(-10, 320, 141, 21));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        dateweekday->setFont(font6);
        dateweekday->setAlignment(Qt::AlignCenter);
        type1 = new QLabel(centralwidget);
        type1->setObjectName(QStringLiteral("type1"));
        type1->setGeometry(QRect(20, 350, 51, 51));
        type1->setScaledContents(true);
        high = new QLabel(centralwidget);
        high->setObjectName(QStringLiteral("high"));
        high->setGeometry(QRect(10, 390, 61, 51));
        QFont font7;
        font7.setPointSize(17);
        font7.setBold(true);
        font7.setWeight(75);
        high->setFont(font7);
        low = new QLabel(centralwidget);
        low->setObjectName(QStringLiteral("low"));
        low->setGeometry(QRect(70, 400, 51, 41));
        low->setFont(font4);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-3, 270, 801, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        weekday = new QLabel(centralwidget);
        weekday->setObjectName(QStringLiteral("weekday"));
        weekday->setGeometry(QRect(600, 40, 200, 50));
        QFont font8;
        font8.setPointSize(13);
        font8.setBold(true);
        font8.setWeight(75);
        weekday->setFont(font8);
        weekday->setAlignment(Qt::AlignCenter);
        date_2 = new QLabel(centralwidget);
        date_2->setObjectName(QStringLiteral("date_2"));
        date_2->setGeometry(QRect(590, 0, 231, 50));
        date_2->setFont(font8);
        date_2->setAlignment(Qt::AlignCenter);
        high_2 = new QLabel(centralwidget);
        high_2->setObjectName(QStringLiteral("high_2"));
        high_2->setGeometry(QRect(140, 390, 61, 51));
        high_2->setFont(font7);
        type1_2 = new QLabel(centralwidget);
        type1_2->setObjectName(QStringLiteral("type1_2"));
        type1_2->setGeometry(QRect(150, 350, 51, 51));
        type1_2->setScaledContents(true);
        low_2 = new QLabel(centralwidget);
        low_2->setObjectName(QStringLiteral("low_2"));
        low_2->setGeometry(QRect(200, 400, 51, 41));
        low_2->setFont(font4);
        dateweekday_2 = new QLabel(centralwidget);
        dateweekday_2->setObjectName(QStringLiteral("dateweekday_2"));
        dateweekday_2->setGeometry(QRect(120, 320, 141, 21));
        dateweekday_2->setFont(font6);
        dateweekday_2->setAlignment(Qt::AlignCenter);
        high_3 = new QLabel(centralwidget);
        high_3->setObjectName(QStringLiteral("high_3"));
        high_3->setGeometry(QRect(270, 390, 61, 51));
        high_3->setFont(font7);
        type1_3 = new QLabel(centralwidget);
        type1_3->setObjectName(QStringLiteral("type1_3"));
        type1_3->setGeometry(QRect(280, 350, 51, 51));
        type1_3->setScaledContents(true);
        low_3 = new QLabel(centralwidget);
        low_3->setObjectName(QStringLiteral("low_3"));
        low_3->setGeometry(QRect(330, 400, 51, 41));
        low_3->setFont(font4);
        dateweekday_3 = new QLabel(centralwidget);
        dateweekday_3->setObjectName(QStringLiteral("dateweekday_3"));
        dateweekday_3->setGeometry(QRect(250, 320, 141, 21));
        dateweekday_3->setFont(font6);
        dateweekday_3->setAlignment(Qt::AlignCenter);
        high_4 = new QLabel(centralwidget);
        high_4->setObjectName(QStringLiteral("high_4"));
        high_4->setGeometry(QRect(410, 390, 61, 51));
        high_4->setFont(font7);
        type1_4 = new QLabel(centralwidget);
        type1_4->setObjectName(QStringLiteral("type1_4"));
        type1_4->setGeometry(QRect(420, 350, 51, 51));
        type1_4->setScaledContents(true);
        low_4 = new QLabel(centralwidget);
        low_4->setObjectName(QStringLiteral("low_4"));
        low_4->setGeometry(QRect(470, 400, 51, 41));
        low_4->setFont(font4);
        dateweekday_4 = new QLabel(centralwidget);
        dateweekday_4->setObjectName(QStringLiteral("dateweekday_4"));
        dateweekday_4->setGeometry(QRect(380, 320, 141, 21));
        dateweekday_4->setFont(font6);
        dateweekday_4->setAlignment(Qt::AlignCenter);
        high_5 = new QLabel(centralwidget);
        high_5->setObjectName(QStringLiteral("high_5"));
        high_5->setGeometry(QRect(540, 390, 61, 51));
        high_5->setFont(font7);
        type1_5 = new QLabel(centralwidget);
        type1_5->setObjectName(QStringLiteral("type1_5"));
        type1_5->setGeometry(QRect(550, 350, 51, 51));
        type1_5->setScaledContents(true);
        low_5 = new QLabel(centralwidget);
        low_5->setObjectName(QStringLiteral("low_5"));
        low_5->setGeometry(QRect(600, 400, 51, 41));
        low_5->setFont(font4);
        dateweekday_5 = new QLabel(centralwidget);
        dateweekday_5->setObjectName(QStringLiteral("dateweekday_5"));
        dateweekday_5->setGeometry(QRect(510, 320, 141, 21));
        dateweekday_5->setFont(font6);
        dateweekday_5->setAlignment(Qt::AlignCenter);
        high_6 = new QLabel(centralwidget);
        high_6->setObjectName(QStringLiteral("high_6"));
        high_6->setGeometry(QRect(660, 390, 61, 51));
        high_6->setFont(font7);
        type1_6 = new QLabel(centralwidget);
        type1_6->setObjectName(QStringLiteral("type1_6"));
        type1_6->setGeometry(QRect(670, 350, 51, 51));
        type1_6->setScaledContents(true);
        low_6 = new QLabel(centralwidget);
        low_6->setObjectName(QStringLiteral("low_6"));
        low_6->setGeometry(QRect(720, 400, 51, 41));
        low_6->setFont(font4);
        dateweekday_6 = new QLabel(centralwidget);
        dateweekday_6->setObjectName(QStringLiteral("dateweekday_6"));
        dateweekday_6->setGeometry(QRect(640, 320, 141, 21));
        dateweekday_6->setFont(font6);
        dateweekday_6->setAlignment(Qt::AlignCenter);
        WeatherWindow->setCentralWidget(centralwidget);

        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QApplication::translate("WeatherWindow", "MainWindow", 0));
        commandLinkButton->setText(QString());
        city->setText(QApplication::translate("WeatherWindow", "\345\271\277\345\267\236\345\270\202", 0));
        icon->setText(QString());
        centigrade->setText(QApplication::translate("WeatherWindow", "T", 0));
        type->setText(QApplication::translate("WeatherWindow", "type", 0));
        updatetime->setText(QApplication::translate("WeatherWindow", "updatetime", 0));
        aqi->setText(QApplication::translate("WeatherWindow", "aqi", 0));
        aqilevel->setText(QApplication::translate("WeatherWindow", "aqilevel", 0));
        wind->setText(QApplication::translate("WeatherWindow", "wind", 0));
        humid->setText(QApplication::translate("WeatherWindow", "humid", 0));
        dateweekday->setText(QApplication::translate("WeatherWindow", "date/week", 0));
        type1->setText(QApplication::translate("WeatherWindow", "type1", 0));
        high->setText(QApplication::translate("WeatherWindow", "high", 0));
        low->setText(QApplication::translate("WeatherWindow", "low", 0));
        weekday->setText(QApplication::translate("WeatherWindow", "weekday", 0));
        date_2->setText(QApplication::translate("WeatherWindow", "date", 0));
        high_2->setText(QApplication::translate("WeatherWindow", "high", 0));
        type1_2->setText(QApplication::translate("WeatherWindow", "type1", 0));
        low_2->setText(QApplication::translate("WeatherWindow", "low", 0));
        dateweekday_2->setText(QApplication::translate("WeatherWindow", "date/week", 0));
        high_3->setText(QApplication::translate("WeatherWindow", "high", 0));
        type1_3->setText(QApplication::translate("WeatherWindow", "type1", 0));
        low_3->setText(QApplication::translate("WeatherWindow", "low", 0));
        dateweekday_3->setText(QApplication::translate("WeatherWindow", "date/week", 0));
        high_4->setText(QApplication::translate("WeatherWindow", "high", 0));
        type1_4->setText(QApplication::translate("WeatherWindow", "type1", 0));
        low_4->setText(QApplication::translate("WeatherWindow", "low", 0));
        dateweekday_4->setText(QApplication::translate("WeatherWindow", "date/week", 0));
        high_5->setText(QApplication::translate("WeatherWindow", "high", 0));
        type1_5->setText(QApplication::translate("WeatherWindow", "type1", 0));
        low_5->setText(QApplication::translate("WeatherWindow", "low", 0));
        dateweekday_5->setText(QApplication::translate("WeatherWindow", "date/week", 0));
        high_6->setText(QApplication::translate("WeatherWindow", "high", 0));
        type1_6->setText(QApplication::translate("WeatherWindow", "type1", 0));
        low_6->setText(QApplication::translate("WeatherWindow", "low", 0));
        dateweekday_6->setText(QApplication::translate("WeatherWindow", "date/week", 0));
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
