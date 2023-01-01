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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QDoubleSpinBox *entry_dx;
    QDoubleSpinBox *entry_dy;
    QPushButton *button_move;
    QLabel *label_dx;
    QLabel *label_dy;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *entry_kx;
    QDoubleSpinBox *entry_ky;
    QPushButton *button_scale;
    QLabel *label_kx;
    QLabel *label_ky;
    QPushButton *button_file;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *entry_alpha;
    QPushButton *button_rotate;
    QLabel *label_alpha;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1211, 806);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 221));
        QFont font;
        font.setPointSize(14);
        groupBox->setFont(font);
        entry_dx = new QDoubleSpinBox(groupBox);
        entry_dx->setObjectName(QString::fromUtf8("entry_dx"));
        entry_dx->setGeometry(QRect(90, 30, 131, 41));
        entry_dx->setMinimum(-1000.000000000000000);
        entry_dx->setMaximum(1000.000000000000000);
        entry_dy = new QDoubleSpinBox(groupBox);
        entry_dy->setObjectName(QString::fromUtf8("entry_dy"));
        entry_dy->setGeometry(QRect(90, 110, 131, 41));
        entry_dy->setMinimum(-1000.000000000000000);
        entry_dy->setMaximum(1000.000000000000000);
        button_move = new QPushButton(groupBox);
        button_move->setObjectName(QString::fromUtf8("button_move"));
        button_move->setGeometry(QRect(60, 180, 101, 31));
        label_dx = new QLabel(groupBox);
        label_dx->setObjectName(QString::fromUtf8("label_dx"));
        label_dx->setGeometry(QRect(30, 40, 49, 31));
        label_dy = new QLabel(groupBox);
        label_dy->setObjectName(QString::fromUtf8("label_dy"));
        label_dy->setGeometry(QRect(20, 120, 49, 31));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(250, 10, 950, 750));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 240, 231, 221));
        groupBox_2->setFont(font);
        entry_kx = new QDoubleSpinBox(groupBox_2);
        entry_kx->setObjectName(QString::fromUtf8("entry_kx"));
        entry_kx->setGeometry(QRect(100, 30, 121, 41));
        entry_kx->setMaximum(1000.000000000000000);
        entry_kx->setSingleStep(0.500000000000000);
        entry_kx->setValue(1.000000000000000);
        entry_ky = new QDoubleSpinBox(groupBox_2);
        entry_ky->setObjectName(QString::fromUtf8("entry_ky"));
        entry_ky->setGeometry(QRect(100, 110, 121, 41));
        entry_ky->setMaximum(1000.000000000000000);
        entry_ky->setSingleStep(0.500000000000000);
        entry_ky->setValue(1.000000000000000);
        button_scale = new QPushButton(groupBox_2);
        button_scale->setObjectName(QString::fromUtf8("button_scale"));
        button_scale->setGeometry(QRect(60, 180, 101, 31));
        label_kx = new QLabel(groupBox_2);
        label_kx->setObjectName(QString::fromUtf8("label_kx"));
        label_kx->setGeometry(QRect(30, 40, 49, 21));
        label_ky = new QLabel(groupBox_2);
        label_ky->setObjectName(QString::fromUtf8("label_ky"));
        label_ky->setGeometry(QRect(30, 120, 49, 31));
        button_file = new QPushButton(centralwidget);
        button_file->setObjectName(QString::fromUtf8("button_file"));
        button_file->setGeometry(QRect(20, 710, 211, 41));
        button_file->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 470, 231, 221));
        groupBox_3->setFont(font);
        entry_alpha = new QDoubleSpinBox(groupBox_3);
        entry_alpha->setObjectName(QString::fromUtf8("entry_alpha"));
        entry_alpha->setGeometry(QRect(100, 80, 121, 41));
        entry_alpha->setMinimum(-1000.000000000000000);
        entry_alpha->setMaximum(1000.000000000000000);
        button_rotate = new QPushButton(groupBox_3);
        button_rotate->setObjectName(QString::fromUtf8("button_rotate"));
        button_rotate->setGeometry(QRect(60, 180, 101, 41));
        label_alpha = new QLabel(groupBox_3);
        label_alpha->setObjectName(QString::fromUtf8("label_alpha"));
        label_alpha->setGeometry(QRect(30, 95, 61, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1211, 26));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Moving", nullptr));
        button_move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_dx->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_dy->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        button_scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_kx->setText(QCoreApplication::translate("MainWindow", "kx:", nullptr));
        label_ky->setText(QCoreApplication::translate("MainWindow", "ky:", nullptr));
        button_file->setText(QCoreApplication::translate("MainWindow", "Choose File", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Rotating", nullptr));
        button_rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_alpha->setText(QCoreApplication::translate("MainWindow", "Alpha :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
