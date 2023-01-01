#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SCENE_WIDTH (1000)
#define SCENE_HEIGHT (800)

#include <QMainWindow>
#include <QFileDialog>
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

    int draw_actions(void);
    void on_button_scale_clicked();

    void on_button_file_clicked();

    void on_button_save_clicked();

    void on_button_move_clicked();

    void on_button_rotate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
