#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QListWidget>
#include <QMessageBox>
#include <QTextItem>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QGraphicsScene>
#include <QPen>
#include <cmath>
#include <math.h>

#include "canvas.h"

#define EPS 1e-6
#define OK 0
#define SCENE_WIDTH 860
#define SCENE_HEIGHT 600

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void draw_action(void);

    void on_Button_add_clicked();

    void on_Button_del_clicked();

    void on_Button_clear_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_Button_solve_clicked();

private:
    bool get_coord(double &num, const QString text);
    bool check_point_no_exist(const double &x, const double &y);

private:
    Ui::MainWindow *ui;

    QList<QPointF> points;
};
#endif // MAINWINDOW_H
