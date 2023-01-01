#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
}

MainWindow::~MainWindow()
{
    action_t action;
    action.action_number = ACTION_QUIT;
    action_run(action);

    delete ui;
}

int MainWindow::draw_actions(void)
{
    painter_t painter;
    painter.scene = ui->graphicsView->scene();
    painter.width = painter.scene->width();
    painter.height = painter.scene->height();

    action_t action;
    action.action_number = ACTION_DRAW;
    action.painter = painter;

    int rc = action_run(action);

    return rc;
}

void MainWindow::on_button_file_clicked()
{
    action_t action;
    action.action_number = ACTION_DOWNLOAD;
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    action.file_name = filename.toStdString().c_str();

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_actions();
    //printf("draw %d\n", rc);
    if (rc)
    {
        print_error(rc);
    }
}


void MainWindow::on_button_save_clicked()
{
    action_t action;
    action.action_number = ACTION_UPLOAD;
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    action.file_name = filename.toStdString().c_str();

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
    }
}

void MainWindow::on_button_move_clicked()
{
    move_info_t moving;
    moving.dx = ui->entry_dx->value();
    moving.dy = ui->entry_dy->value();
    moving.dz = ui->entry_dz->value();

    action_t action;
    action.action_number = ACTION_MOVE;
    action.moving = moving;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        print_error(rc);
    }
}

void MainWindow::on_button_scale_clicked()
{
    scale_info_t scale;
    scale.kx = ui->entry_kx->value();
    scale.ky = ui->entry_ky->value();
    scale.kz = ui->entry_kz->value();

    action_t action;
    action.action_number = ACTION_SCALE;
    action.scale = scale;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        print_error(rc);
    }
}

void MainWindow::on_button_rotate_clicked()
{
    rotate_info_t rotate;
    rotate.rx = ui->entry_rx->value();
    rotate.ry = ui->entry_ry->value();
    rotate.rz = ui->entry_rz->value();

    action_t action;
    action.action_number = ACTION_ROTATE;
    action.rotate = rotate;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        print_error(rc);
    }
}

