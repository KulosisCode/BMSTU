//Чыонг Ван Хао   ИУ7И-41Б

//На плоскости дано множество точек. Найти такое треголник в этих точках, укоторый максималная из
//трёх высота имеет минималная значение среды всех треуголников.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);

}

MainWindow::~MainWindow()
{
    delete ui;
}

double line(QPointF a, QPointF b) {
    return sqrt(pow(a.x() - b.x(), 2) + pow(a.y() - b.y(), 2));
}

double max(double a, double b, double c) {
    return a > b ? a > c ? a : c : b > c ? b : c;
}

double min(double a, double b) {
    return a < b ? a : b;
}

// find height of triangle (A point)
double find_Height(QPointF A, QPointF B, QPointF C)
{
    double a = line(A, B); // AB
    double b = line(B, C); // BC
    double c = line(C, A); // AC

    if (a + b <= c + EPS ||
        a + c <= b + EPS ||
        c + b <= a + EPS)
        return 0;

    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    double height = 2 * s / b;

    return height;
}

// Find coord height
QPointF find_Height_coord(QList<QPointF> minTriangle, int indexHeight) {
    QPointF A = minTriangle[indexHeight];
    QPointF B;
    QPointF C;

    if (indexHeight == 0) {
        B = minTriangle[1];
        C = minTriangle[2];
    } else if (indexHeight == 1) {
        B = minTriangle[0];
        C = minTriangle[2];
    } else {
        B = minTriangle[0];
        C = minTriangle[1];
    }

    if (fabs(B.x() - C.x()) <= 10e-6)
        return QPointF(B.x(), A.y());

    if (fabs(B.y() - C.y()) <= 10e-6)
        return QPointF(A.x(), B.y());

    double k = double(B.y() - C.y()) / (B.x() - C.x());
    double b = B.y() - k * B.x();

    double k_new = -1 / k;
    double b_new = A.y() - k_new * A.x();

    double heightX = (b_new - b) / (k - k_new);
    double heightY = k * heightX + b;

    return QPointF(heightX, heightY);
}

int canvas_clear_screen(const scene_type &scene)
{
    scene->clear();

    return OK;
}
//paint
void MainWindow::draw_action(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    QBrush red_brush(Qt::red);
    QBrush blue_brush(Qt::blue);

    QPen blackpen(Qt::black);
    blackpen.setWidth(3);
    QPen greenpen(Qt::green);
    greenpen.setWidth(1);
    QPen redpen(Qt::red);
    redpen.setWidth(2);

    if (points.size() <= 2)
    {
        QMessageBox::critical(this,"ERROR","NOT ENOUGH POINT!");
        return;
    }

    canvas.scene->addLine(canvas.width / 2, 0, canvas.width / 2, canvas.height, blackpen);
    canvas.scene->addLine(0, canvas.height / 2, canvas.width, canvas.height / 2, blackpen);
    blackpen.setWidth(2);

    double maxX = 0;
    double maxY = 0;


    for (int i = 0; i < points.size(); i++)
    {
        if (maxX < fabs(points[i].x())) maxX = fabs(points[i].x());
        if (maxY < fabs(points[i].y())) maxY = fabs(points[i].y());
    }

    double step = 20;
    if (maxX <= 0 && maxY <= 0)
    {
        step = 10;
    }
    else
    {
        if (maxX <= 0) {
            step = double(canvas.height) / ++maxY / 2;
        } else if (maxY <= 0) {
            step = double(canvas.width) / ++maxX / 2;
        } else
        {
            if (double(canvas.width / maxX) <= int(canvas.height / maxY))
            {
                step = double(canvas.height) / ++maxX / 2;
            }
            else
            {
                step = double(canvas.height) / ++maxY / 2;
            }
        }
        if (step <= 1)
        {
            if (int(canvas.width / maxX) <= int(canvas.height / maxY))
            {
                maxX += maxX / 5;
                step = double(canvas.width) / maxX / 2;
            }
            else
            {
                maxY += maxY / 5;
                step = double(canvas.height) / maxY / 2;
            }
        }
    }
    if (step > 3)
    {
        for (double i = canvas.width / 2; i <= canvas.width; i += step)
            canvas.scene->addLine(int(i), 0, int(i), canvas.height);
        for (double i = canvas.width / 2; i >= 0; i -= step)
            canvas.scene->addLine(int(i), 0, int(i), canvas.height);

        for (double i = canvas.height / 2; i <= canvas.height; i += step)
            canvas.scene->addLine(0, int(i), canvas.width, int(i));
        for (double i = canvas.height / 2; i >= 0; i -= step)
            canvas.scene->addLine(0, int(i), canvas.width, int(i));
    }



    // draw points
    for (QPointF point : points)
    {
        canvas.scene->addEllipse(floor(canvas.width / 2 + point.x() * step),
                                 floor(canvas.height / 2 + point.y() * -step), 4, 4,
                                 blackpen, blue_brush);
    }

    double height_Min = INT_MAX;
    QList<QPointF> minTriangle;
    int indexHeight = 0;
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            for (int k = j + 1; k < points.size(); k++)
            {
                QPointF A = points[i];
                QPointF B = points[j];
                QPointF C = points[k];

                double heightA = find_Height(A, B, C);
                double heightB = find_Height(B, A, C);
                double heightC = find_Height(C, A, B);

                double height = max(heightA, heightB, heightC);

                if (height_Min > height)
                {
                    height_Min = height;
                    minTriangle = QList<QPointF>();
                    minTriangle.append(A);
                    minTriangle.append(B);
                    minTriangle.append(C);

                    if (abs(height - heightA) <= 10e-6) indexHeight = 0;
                    if (abs(height - heightB) <= 10e-6) indexHeight = 1;
                    if (abs(height - heightC) <= 10e-6) indexHeight = 2;
                }
            }
        }

    }

    if (abs(height_Min - INT_MAX) > EPS)
    {
        //draw triangle

        canvas.scene->addLine(int(canvas.width  / 2 + minTriangle[0].x() *  step),
                         int(canvas.height / 2 + minTriangle[0].y() * -step),
                         int(canvas.width  / 2 + minTriangle[1].x() *  step),
                          int(canvas.height / 2 + minTriangle[1].y() * -step), greenpen);

        canvas.scene->addLine(int(canvas.width  / 2 + minTriangle[1].x() *  step),
                     int(canvas.height / 2 + minTriangle[1].y() * -step),
                     int(canvas.width  / 2 + minTriangle[2].x() *  step),
                     int(canvas.height / 2 + minTriangle[2].y() * -step), greenpen);

        canvas.scene->addLine(int(canvas.width  / 2 + minTriangle[2].x() *  step),
                     int(canvas.height / 2 + minTriangle[2].y() * -step),
                     int(canvas.width  / 2 + minTriangle[0].x() *  step),
                     int(canvas.height / 2 + minTriangle[0].y() * -step), greenpen);

//        QGraphicsTextItem *item_1 = canvas.scene->addText(QString("(" + QString::number(minTriangle[0].x()) + ";"
//                                + QString::number(minTriangle[0].y()) + ")"));
//        canvas.scene->addText(QString("(" + QString::number(minTriangle[1].x()) + ";"
//                                + QString::number(minTriangle[1].y()) + ")"));
//        canvas.scene->addText(QString("(" + QString::number(minTriangle[2].x()) + ";"
//                                + QString::number(minTriangle[2].y()) + ")"));
    }

    //Рисование высоты - draw height

    QPointF height = find_Height_coord(minTriangle, indexHeight);

    canvas.scene->addLine(int(canvas.width  / 2 + minTriangle[indexHeight].x() *  step),
                        int(canvas.height / 2 + minTriangle[indexHeight].y() * -step),
                        int(canvas.width  / 2 + height.x() *  step),
                        int(canvas.height / 2 + height.y() * -step));

}

//convert string to number
bool MainWindow::get_coord(double &num, const QString text)
{
    QList<QString> number = text.split(" ");
    for (int i = 0; i < number.count(); i++)
    {
        if (number[i] == "")
        {
            number.removeAt(i);
            i--;
        }
    }

    if (number.count() != 1)
    {
        QMessageBox::critical(this, "ERROR", "ENTRY ONLY 1 NUMBER");
        return false;
    }
    bool check = false;

    num = text.toDouble(&check);

    if (!(check))
    {
        QMessageBox::critical(this, "ERROR", "THE NUMBER IS UNCORRECT");
        return false;
    }
    return true;
}

//check point in list ?
bool MainWindow::check_point_no_exist(const double &x, const double &y)
{
    for (int i = 0; i < points.size(); i++)
    {
        if (x == points[i].x() && y == points[i].y())
        {
            return false;
        }
    }
    return true;
}

//click add
void MainWindow::on_Button_add_clicked()
{
    QString text_x = ui->lineEdit_x->text();
    QString text_y = ui->lineEdit_y->text();

    double x, y;
    if (get_coord(x, text_x) && get_coord(y, text_y))
    {
        ui->lineEdit_x->clear();
        ui->lineEdit_y->clear();
        if (check_point_no_exist(x, y))
        {
            points.append(QPointF(x,y));

            QTableWidget *curTable;
            curTable = ui->tableWidget;

            int tableRowCount = curTable->rowCount();
            curTable->insertRow(tableRowCount);
            curTable->setItem(tableRowCount, 0,
                              new QTableWidgetItem(QString::number(x)));
            curTable->setItem(tableRowCount, 1,
                              new QTableWidgetItem(QString::number(y)));
        }

    }

}


void MainWindow::on_Button_del_clicked()
{
    QTableWidgetItem *current = ui->tableWidget->currentItem();

    if (current)
    {
        points.removeAt(current->row());
        ui->tableWidget->removeRow(current->row());
    }
    else
    {
        QMessageBox::about(this, "ERROR", "NEED TO CHOOSE A ROW!");
    }

    repaint();
}


void MainWindow::on_Button_clear_clicked()
{
    points.clear();
    ui->tableWidget->setRowCount(0);

    QGraphicsScene *scene = ui->graphicsView->scene();
    canvas_clear_screen(scene);
    repaint();
}



void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    bool ok;
    double coord = item->text().toDouble(&ok);

    if (!ok)
    {
        if (item->column() == 0)
        {
            item->setText(QString::number(points[item->row()].x()));
        }
        else
        {
            item->setText(QString::number(points[item->row()].y()));
        }

    }
    else
    {
        if (item->column() == 0)
        {
            points[item->row()].setX(coord);
        }
        else
        {
            points[item->row()].setY(coord);
        }

    }
    repaint();
}


void MainWindow::on_Button_solve_clicked()
{
    QGraphicsScene *scene = ui->graphicsView->scene();
    canvas_clear_screen(scene);
    draw_action();
    repaint();
}


