/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_3;
    QListWidget *listWidget;
    QCommandLinkButton *volume;
    QSlider *volchange;
    QCommandLinkButton *del;
    QSlider *horizontalSlider;
    QLabel *vd_len;
    QLabel *vd_po;
    QLabel *vd_list;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *prev;
    QSpacerItem *horizontalSpacer;
    QCommandLinkButton *play;
    QSpacerItem *horizontalSpacer_2;
    QCommandLinkButton *next;

    void setupUi(QMainWindow *VideoWindow)
    {
        if (VideoWindow->objectName().isEmpty())
            VideoWindow->setObjectName(QStringLiteral("VideoWindow"));
        VideoWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWindow->sizePolicy().hasHeightForWidth());
        VideoWindow->setSizePolicy(sizePolicy);
        VideoWindow->setMinimumSize(QSize(800, 480));
        VideoWindow->setMaximumSize(QSize(800, 480));
        VideoWindow->setStyleSheet(QLatin1String("QMainWindow{background-image: url(:/main/vehicle1.png);}\n"
""));
        centralwidget = new QWidget(VideoWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(0, 0, 61, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/video/video/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(40, 40));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(700, 410, 41, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/video/video/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon1);
        commandLinkButton_3->setIconSize(QSize(30, 30));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(680, 30, 121, 371));
        listWidget->setStyleSheet(QStringLiteral("background-color:transparent;"));
        volume = new QCommandLinkButton(centralwidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(640, 410, 41, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/video/video/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        volume->setIcon(icon2);
        volume->setIconSize(QSize(30, 30));
        volume->setCheckable(true);
        volchange = new QSlider(centralwidget);
        volchange->setObjectName(QStringLiteral("volchange"));
        volchange->setGeometry(QRect(650, 230, 22, 181));
        volchange->setStyleSheet(QLatin1String("QSlider#volchange::groove:volchange {  \n"
"border: 1px solid #4A708B;\n"
"background: #C0C0C0;\n"
"width: 5px;\n"
"border-radius: 1px;\n"
"padding-left:-1px;\n"
"padding-right:-1px;\n"
"padding-top:-1px;\n"
"padding-bottom:-1px;  \n"
"}  \n"
"\n"
"QSlider#volchange::sub-page:volchange {  \n"
"background: #575757;  \n"
"border: 1px solid #4A708B;\n"
"border-radius: 2px;\n"
"}  \n"
"  \n"
"QSlider#volchange::add-page:volchange {  \n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,   \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,  \n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);   \n"
"border: 0px solid #777;\n"
"width: 10px;\n"
"border-radius: 2px;\n"
"}  \n"
"  \n"
"QSlider#volchange::handle:volchange   \n"
"{  \n"
" background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #45ADED, \n"
"stop:0.778409 rgba(255, 255, 255, 255));\n"
"\n"
"    height: 11px;\n"
"    margin-left: -3px;\n"
"    margin-right: -3px;\n"
"    b"
                        "order-radius: 5px;\n"
"}  \n"
"\n"
"QSlider#volchange::sub-page:volchange:disabled {  \n"
"background: #00009C;\n"
"border-color: #999;\n"
"}  \n"
"  background-color: rgb(97, 97, 97);\n"
"QSlider#volchange::add-page:volchange:disabled {  \n"
"background: #eee;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#volchange::handle:volchange:disabled {  \n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px; \n"
"}  "));
        volchange->setMinimum(-100);
        volchange->setMaximum(50);
        volchange->setValue(-10);
        volchange->setOrientation(Qt::Vertical);
        del = new QCommandLinkButton(centralwidget);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(750, 410, 50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/video/video/del.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon3);
        del->setIconSize(QSize(30, 30));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 350, 561, 22));
        horizontalSlider->setStyleSheet(QLatin1String("QWidget#centralWidget{\n"
"       border-style:solid;\n"
"	   background: transparent;\n"
"	   background-color:#0066CC;\n"
"	   \n"
"}\n"
" \n"
"QSlider#horizontalSlider::groove:horizontal {  \n"
"border: 1px solid #4A708B;  \n"
"background: #575757;\n"
"height: 5px;  \n"
"border-radius: 1px;  \n"
"padding-left:-1px;  \n"
"padding-right:-1px;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::sub-page:horizontal {  \n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,   \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,  \n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);  \n"
"border: 1px solid #4A708B;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::add-page:horizontal {  \n"
"background: #575757;  \n"
"border: 0px solid #777;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::handle:horizontal   \n"
"{  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0"
                        ".5, fx:0.5, fy:0.5,   \n"
"    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::handle:horizontal:hover {  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,   \n"
"    stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::sub-page:horizontal:disabled {  \n"
"background: #00009C;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::add-page:horizontal:disabled {  \n"
"background: #eee;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#horizontalSlider::handle:horizontal:disabled {  \n"
"background: #eee;  \n"
"border: 1px solid #aaa;  \n"
"border-radius: 4px;  \n"
"}  "));
        horizontalSlider->setOrientation(Qt::Horizontal);
        vd_len = new QLabel(centralwidget);
        vd_len->setObjectName(QStringLiteral("vd_len"));
        vd_len->setGeometry(QRect(180, 370, 91, 21));
        vd_len->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        vd_po = new QLabel(centralwidget);
        vd_po->setObjectName(QStringLiteral("vd_po"));
        vd_po->setGeometry(QRect(81, 370, 91, 21));
        vd_po->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        vd_list = new QLabel(centralwidget);
        vd_list->setObjectName(QStringLiteral("vd_list"));
        vd_list->setGeometry(QRect(690, 0, 121, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        vd_list->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 400, 290, 62));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prev = new QCommandLinkButton(widget);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setMaximumSize(QSize(60, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/video/video/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prev->setIcon(icon4);
        prev->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(prev);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        play = new QCommandLinkButton(widget);
        play->setObjectName(QStringLiteral("play"));
        play->setMaximumSize(QSize(60, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/video/video/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon5);
        play->setIconSize(QSize(50, 50));
        play->setCheckable(true);

        horizontalLayout->addWidget(play);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        next = new QCommandLinkButton(widget);
        next->setObjectName(QStringLiteral("next"));
        next->setMaximumSize(QSize(60, 60));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/video/video/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon6);
        next->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(next);

        VideoWindow->setCentralWidget(centralwidget);

        retranslateUi(VideoWindow);

        QMetaObject::connectSlotsByName(VideoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VideoWindow)
    {
        VideoWindow->setWindowTitle(QApplication::translate("VideoWindow", "MainWindow", 0));
        commandLinkButton->setText(QString());
        commandLinkButton_3->setText(QString());
        volume->setText(QString());
        del->setText(QString());
        vd_len->setText(QApplication::translate("VideoWindow", "00:00:00", 0));
        vd_po->setText(QApplication::translate("VideoWindow", "00:00:00/", 0));
        vd_list->setText(QApplication::translate("VideoWindow", "\350\247\206\351\242\221\345\210\227\350\241\250", 0));
        prev->setText(QString());
        play->setText(QString());
        next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWindow: public Ui_VideoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
