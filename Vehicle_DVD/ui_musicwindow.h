/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

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

class Ui_MusicWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QListWidget *listWidget;
    QCommandLinkButton *addfiles;
    QCommandLinkButton *del;
    QCommandLinkButton *volume;
    QLabel *mp3name;
    QLabel *album;
    QLabel *singer;
    QSlider *vol_change;
    QSlider *lrc_change;
    QLabel *pos;
    QLabel *len;
    QLabel *label;
    QListWidget *lrc;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *prev;
    QSpacerItem *horizontalSpacer;
    QCommandLinkButton *play;
    QSpacerItem *horizontalSpacer_2;
    QCommandLinkButton *next;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName(QStringLiteral("MusicWindow"));
        MusicWindow->resize(800, 480);
        MusicWindow->setMinimumSize(QSize(800, 480));
        MusicWindow->setMaximumSize(QSize(800, 480));
        MusicWindow->setStyleSheet(QLatin1String("QMainWindow{background-image: url(:/main/m1.png);}\n"
"\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MusicWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(0, -1, 60, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/music/music/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(50, 50));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(670, 50, 131, 351));
        listWidget->setStyleSheet(QStringLiteral("background-color:transparent;"));
        addfiles = new QCommandLinkButton(centralwidget);
        addfiles->setObjectName(QStringLiteral("addfiles"));
        addfiles->setGeometry(QRect(690, 430, 41, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/music/music/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addfiles->setIcon(icon1);
        addfiles->setIconSize(QSize(30, 30));
        del = new QCommandLinkButton(centralwidget);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(750, 430, 41, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/music/music/del.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon2);
        del->setIconSize(QSize(30, 30));
        volume = new QCommandLinkButton(centralwidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(470, 430, 50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/music/music/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        volume->setIcon(icon3);
        volume->setIconSize(QSize(30, 30));
        volume->setCheckable(true);
        mp3name = new QLabel(centralwidget);
        mp3name->setObjectName(QStringLiteral("mp3name"));
        mp3name->setGeometry(QRect(20, 60, 241, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        mp3name->setFont(font);
        mp3name->setAlignment(Qt::AlignCenter);
        album = new QLabel(centralwidget);
        album->setObjectName(QStringLiteral("album"));
        album->setGeometry(QRect(10, 120, 251, 41));
        album->setAlignment(Qt::AlignCenter);
        singer = new QLabel(centralwidget);
        singer->setObjectName(QStringLiteral("singer"));
        singer->setGeometry(QRect(10, 170, 251, 31));
        singer->setAlignment(Qt::AlignCenter);
        vol_change = new QSlider(centralwidget);
        vol_change->setObjectName(QStringLiteral("vol_change"));
        vol_change->setGeometry(QRect(510, 450, 160, 22));
        vol_change->setStyleSheet(QLatin1String("QWidget#centralWidget{\n"
"       border-style:solid;\n"
"	   background: transparent;\n"
"	   background-color:#0066CC;\n"
"	   \n"
"}\n"
" \n"
"QSlider#vol_change::groove:horizontal {  \n"
"border: 1px solid #4A708B;  \n"
"background: #575757;\n"
"height: 5px;  \n"
"border-radius: 1px;  \n"
"padding-left:-1px;  \n"
"padding-right:-1px;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::sub-page:horizontal {  \n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,   \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,  \n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);  \n"
"border: 1px solid #4A708B;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::add-page:horizontal {  \n"
"background: #575757;  \n"
"border: 0px solid #777;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::handle:horizontal   \n"
"{  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,   \n"
""
                        "    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::handle:horizontal:hover {  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,   \n"
"    stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::sub-page:horizontal:disabled {  \n"
"background: #00009C;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::add-page:horizontal:disabled {  \n"
"background: #eee;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#vol_change::handle:horizontal:disabled {  \n"
"background: #eee;  \n"
"border: 1px solid #aaa;  \n"
"border-radius: 4px;  \n"
"}  "));
        vol_change->setOrientation(Qt::Horizontal);
        lrc_change = new QSlider(centralwidget);
        lrc_change->setObjectName(QStringLiteral("lrc_change"));
        lrc_change->setGeometry(QRect(280, 410, 371, 22));
        lrc_change->setStyleSheet(QLatin1String("QWidget#centralWidget{\n"
"       border-style:solid;\n"
"	   background: transparent;\n"
"	   background-color:#0066CC;\n"
"	   \n"
"}\n"
" \n"
"QSlider#lrc_change::groove:horizontal {  \n"
"border: 1px solid #4A708B;  \n"
"background: #575757;\n"
"height: 5px;  \n"
"border-radius: 1px;  \n"
"padding-left:-1px;  \n"
"padding-right:-1px;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::sub-page:horizontal {  \n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,   \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,  \n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);  \n"
"border: 1px solid #4A708B;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::add-page:horizontal {  \n"
"background: #575757;  \n"
"border: 0px solid #777;  \n"
"height: 10px;  \n"
"border-radius: 2px;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::handle:horizontal   \n"
"{  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,   \n"
""
                        "    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::handle:horizontal:hover {  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,   \n"
"    stop:0.778409 rgba(255, 255, 255, 255));  \n"
"  \n"
"    width: 11px;  \n"
"    margin-top: -3px;  \n"
"    margin-bottom: -3px;  \n"
"    border-radius: 5px;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::sub-page:horizontal:disabled {  \n"
"background: #00009C;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::add-page:horizontal:disabled {  \n"
"background: #eee;  \n"
"border-color: #999;  \n"
"}  \n"
"  \n"
"QSlider#lrc_change::handle:horizontal:disabled {  \n"
"background: #eee;  \n"
"border: 1px solid #aaa;  \n"
"border-radius: 4px;  \n"
"}  "));
        lrc_change->setOrientation(Qt::Horizontal);
        pos = new QLabel(centralwidget);
        pos->setObjectName(QStringLiteral("pos"));
        pos->setGeometry(QRect(290, 430, 81, 21));
        QFont font1;
        font1.setPointSize(9);
        pos->setFont(font1);
        len = new QLabel(centralwidget);
        len->setObjectName(QStringLiteral("len"));
        len->setGeometry(QRect(550, 430, 101, 21));
        len->setFont(font1);
        len->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 10, 111, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        lrc = new QListWidget(centralwidget);
        lrc->setObjectName(QStringLiteral("lrc"));
        lrc->setGeometry(QRect(280, 10, 371, 391));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lrc->setFont(font3);
        lrc->setStyleSheet(QStringLiteral("background-color:transparent;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 330, 280, 72));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prev = new QCommandLinkButton(widget);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setMaximumSize(QSize(50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/music/music/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prev->setIcon(icon4);
        prev->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(prev);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        play = new QCommandLinkButton(widget);
        play->setObjectName(QStringLiteral("play"));
        play->setMaximumSize(QSize(70, 70));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/music/music/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon5);
        play->setIconSize(QSize(60, 60));
        play->setCheckable(true);

        horizontalLayout->addWidget(play);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        next = new QCommandLinkButton(widget);
        next->setObjectName(QStringLiteral("next"));
        next->setMaximumSize(QSize(50, 50));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/music/music/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon6);
        next->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(next);

        MusicWindow->setCentralWidget(centralwidget);

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        MusicWindow->setWindowTitle(QApplication::translate("MusicWindow", "MainWindow", 0));
        commandLinkButton->setText(QString());
        addfiles->setText(QString());
        del->setText(QString());
        volume->setText(QString());
        mp3name->setText(QApplication::translate("MusicWindow", "\346\255\214\345\220\215", 0));
        album->setText(QApplication::translate("MusicWindow", "\344\270\223\350\276\221", 0));
        singer->setText(QApplication::translate("MusicWindow", "\346\255\214\346\211\213", 0));
        pos->setText(QApplication::translate("MusicWindow", "00:00:00", 0));
        len->setText(QApplication::translate("MusicWindow", "00:00:00", 0));
        label->setText(QApplication::translate("MusicWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", 0));
        prev->setText(QString());
        play->setText(QString());
        next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
