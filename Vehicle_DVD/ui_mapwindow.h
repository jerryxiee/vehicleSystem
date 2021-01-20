/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QLabel *pic;
    QPushButton *quanjing;
    QPushButton *static_2;
    QPushButton *state;
    QTextBrowser *textBrowser;
    QCommandLinkButton *commandLinkButton_2;
    QWidget *widget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->resize(800, 480);
        MapWindow->setMinimumSize(QSize(800, 480));
        MapWindow->setMaximumSize(QSize(800, 480));
        MapWindow->setStyleSheet(QStringLiteral("QMainWindow{background-image: url(:/main/vehicle2.png);}"));
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(0, 0, 61, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(50, 50));
        pic = new QLabel(centralwidget);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(10, 60, 561, 311));
        quanjing = new QPushButton(centralwidget);
        quanjing->setObjectName(QStringLiteral("quanjing"));
        quanjing->setGeometry(QRect(20, 400, 93, 28));
        static_2 = new QPushButton(centralwidget);
        static_2->setObjectName(QStringLiteral("static_2"));
        static_2->setGeometry(QRect(230, 400, 93, 28));
        state = new QPushButton(centralwidget);
        state->setObjectName(QStringLiteral("state"));
        state->setGeometry(QRect(670, 400, 93, 28));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(620, 60, 181, 311));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(740, 0, 61, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon1);
        commandLinkButton_2->setIconSize(QSize(50, 50));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 10, 351, 23));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        MapWindow->setCentralWidget(centralwidget);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", 0));
        commandLinkButton->setText(QString());
        pic->setText(QString());
        quanjing->setText(QApplication::translate("MapWindow", "\345\205\250\346\231\257\345\233\276", 0));
        static_2->setText(QApplication::translate("MapWindow", "\351\235\231\346\200\201\345\233\276", 0));
        state->setText(QApplication::translate("MapWindow", "\351\201\223\350\267\257\347\212\266\345\206\265", 0));
        commandLinkButton_2->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MapWindow", "\347\273\217\345\272\246", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MapWindow", "\347\272\254\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
