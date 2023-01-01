#include "action.h"

int action_run(const action_t &action)
{
    static shape_t shape = shape_init();
    int rc = OK;

    switch (action.action_number)
    {
    case ACTION_DOWNLOAD:
        rc = shape_download(shape, action.file_name);
        break;
    case ACTION_UPLOAD:
        rc = shape_upload(shape, action.file_name);
        break;
    case ACTION_MOVE:
        rc = shape_move(shape, action.moving);
        break;
    case ACTION_SCALE:
        rc = shape_scale(shape, action.scale);
        break;
    case ACTION_ROTATE:
        rc = shape_rotate(shape, action.rotate);
        break;
    case ACTION_DRAW:
        rc = shape_draw(shape, action.painter);
        break;
    case ACTION_QUIT:
        shape_free(shape);
        break;
    default:
        rc = ERR_ACTION;
    }

    return rc;
}
