/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Button_add;
    QLabel *label_x;
    QLabel *label_y;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QPushButton *Button_del;
    QPushButton *Button_solve;
    QGraphicsView *graphicsView;
    QTableWidget *tableWidget;
    QPushButton *Button_clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1117, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Button_add = new QPushButton(centralwidget);
        Button_add->setObjectName(QString::fromUtf8("Button_add"));
        Button_add->setGeometry(QRect(20, 120, 121, 31));
        label_x = new QLabel(centralwidget);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setGeometry(QRect(20, 10, 45, 21));
        QFont font;
        font.setPointSize(12);
        label_x->setFont(font);
        label_y = new QLabel(centralwidget);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setGeometry(QRect(20, 60, 45, 21));
        label_y->setFont(font);
        lineEdit_x = new QLineEdit(centralwidget);
        lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));
        lineEdit_x->setGeometry(QRect(50, 10, 181, 31));
        lineEdit_y = new QLineEdit(centralwidget);
        lineEdit_y->setObjectName(QString::fromUtf8("lineEdit_y"));
        lineEdit_y->setGeometry(QRect(50, 60, 181, 31));
        Button_del = new QPushButton(centralwidget);
        Button_del->setObjectName(QString::fromUtf8("Button_del"));
        Button_del->setGeometry(QRect(160, 120, 61, 31));
        Button_solve = new QPushButton(centralwidget);
        Button_solve->setObjectName(QString::fromUtf8("Button_solve"));
        Button_solve->setGeometry(QRect(90, 570, 131, 31));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(245, 10, 860, 600));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 170, 201, 391));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        Button_clear = new QPushButton(centralwidget);
        Button_clear->setObjectName(QString::fromUtf8("Button_clear"));
        Button_clear->setGeometry(QRect(20, 570, 51, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1117, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_x->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_y->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        Button_del->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        Button_solve->setText(QCoreApplication::translate("MainWindow", "Solve", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        Button_clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
