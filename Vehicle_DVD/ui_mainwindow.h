/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButton;
    QSpacerItem *horizontalSpacer;
    QCommandLinkButton *commandLinkButton_2;
    QSpacerItem *horizontalSpacer_2;
    QCommandLinkButton *commandLinkButton_3;
    QSpacerItem *horizontalSpacer_3;
    QCommandLinkButton *commandLinkButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow#MainWindow{background-image: url(:/main/vehicle2.png);}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(543, 0, 251, 31));
        QFont font;
        font.setPointSize(10);
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QStringLiteral("background-color:transparent;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 50, 580, 220));
        label->setMinimumSize(QSize(580, 220));
        label->setMaximumSize(QSize(580, 220));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font1.setPointSize(40);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 310, 644, 112));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        commandLinkButton = new QCommandLinkButton(layoutWidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setMaximumSize(QSize(120, 110));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/weather.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(100, 100));

        gridLayout->addWidget(commandLinkButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        commandLinkButton_2 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setMaximumSize(QSize(120, 110));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon1);
        commandLinkButton_2->setIconSize(QSize(100, 100));

        gridLayout->addWidget(commandLinkButton_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        commandLinkButton_3 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setMaximumSize(QSize(120, 110));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon2);
        commandLinkButton_3->setIconSize(QSize(100, 100));

        gridLayout->addWidget(commandLinkButton_3, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        commandLinkButton_4 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setMaximumSize(QSize(120, 110));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/main/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon3);
        commandLinkButton_4->setIconSize(QSize(100, 100));

        gridLayout->addWidget(commandLinkButton_4, 0, 6, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\350\275\246\350\275\275\351\237\263\351\242\221\347\263\273\347\273\237", 0));
        commandLinkButton->setText(QString());
        commandLinkButton_2->setText(QString());
        commandLinkButton_3->setText(QString());
        commandLinkButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
