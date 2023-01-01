#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "painter.h"
#include "errors.h"
#include "shape.h"
#include "action.h"

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
    int draw_action();

    void on_button_move_clicked();

    void on_button_scale_clicked();

    void on_button_rotate_clicked();

    void on_button_file_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
