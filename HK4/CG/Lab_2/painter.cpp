#include "painter.h"

int painter_clear_screen(const painter_t &painter)
{
    painter.scene->clear();
    return OK;
}
