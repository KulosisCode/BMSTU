#ifndef ACTION_H
#define ACTION_H

#define ACTION_DOWNLOAD 1
#define ACTION_UPLOAD 2
#define ACTION_MOVE 3
#define ACTION_SCALE 4
#define ACTION_ROTATE 5
#define ACTION_DRAW 6
#define ACTION_QUIT 7

#include "shape.h"

struct action_t
{
    int action_number;
    union
    {
        const char *file_name;
        move_info_t moving;
        scale_info_t scale;
        rotate_info_t rotate;
        painter_t painter;
    };
};

int action_run(const action_t &action);


#endif // ACTION_H
