#include "painter.h"

int painter_clear_screen(const painter_t &painter)
{
    painter.scene->clear();
    return OK;
}

int painter_draw_edge(const painter_t &painter, const point_t &point_1, const point_t &point_2)
{
    painter.scene->addLine(
        point_1.x + painter.width / 2,
        point_1.y + painter.height / 2,
        point_2.x + painter.width / 2,
        point_2.y + painter.height / 2);

    return OK;
}
