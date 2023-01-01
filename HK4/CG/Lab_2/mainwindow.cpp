// Нарисовать заштрихованную фигуру затём её перенестить, промасшабировать, певертуть



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

int MainWindow::draw_action(void)
{
    painter_t painter;
    painter.scene = ui->graphicsView->scene();
    painter.width = ui->graphicsView->scene()->width();
    painter.height = ui->graphicsView->scene()->height();

    action_t action;
    action.action_number = ACTION_DRAW;
    action.painter = painter;

    int rc = action_run(action);

//    painter.scene->addLine(painter.width / 2, 0, painter.width / 2, painter.height);
//    painter.scene->addLine(0, painter.height / 2, painter.width, painter.height / 2);

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

    rc = draw_action();
    if (rc)
    {
        print_error(rc);
    }
}

void MainWindow::on_button_move_clicked()
{
    moving_t move;
    move.dx = ui->entry_dx->value();
    move.dy = ui->entry_dy->value();

    action_t action;
    action.action_number = ACTION_MOVE;
    action.moving = move;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_action();
    if (rc)
    {
        print_error(rc);
    }
}

void MainWindow::on_button_scale_clicked()
{
    scaling_t scale;
    scale.kx = ui->entry_kx->value();
    scale.ky = ui->entry_ky->value();
    if (scale.kx <= 0 || scale.ky <= 0)
    {
        QMessageBox::critical(NULL, "Ошибка", "Неверный параметр.");
        return;
    }

    action_t action;
    action.action_number = ACTION_SCALE;
    action.scaling = scale;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_action();
    if (rc)
    {
        print_error(rc);
    }
}


void MainWindow::on_button_rotate_clicked()
{
    rotating_t rotate;
    rotate.alpha = ui->entry_alpha->value();


    action_t action;
    action.action_number = ACTION_ROTATE;
    action.rotating = rotate;

    int rc = action_run(action);
    if (rc != OK)
    {
        print_error(rc);
        return;
    }

    rc = draw_action();
    if (rc)
    {
        print_error(rc);
    }
}




