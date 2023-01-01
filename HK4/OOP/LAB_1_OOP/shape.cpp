#include "shape.h"

int shape_init_null(shape_t &shape)
{
    int rc = edges_list_begin(shape.edges, NULL, 0);
    if (rc == OK)
    {
        rc = points_list_begin(shape.points, NULL, 0);
        if (rc == OK)
        {
            shape.center = {0, 0, 0};
        }
    }

    return rc;
}

shape_t &shape_init(void)
{
    static shape_t shape;
    shape_init_null(shape);

    return shape;
}

int shape_free(shape_t &shape)
{
    points_list_free_array(shape.points);
    edges_list_free_array(shape.edges);

    return OK;
}

int shape_find_center(point_t &center, const points_list_t &points_list)
{
    int rc = points_find_center(center, points_list.array, points_list.count);

    return rc;
}

int shape_process_download(shape_t &shape, FILE *file)
{
    int rc = points_list_input(shape.points, file);
    if (rc == OK)
    {
        rc = edges_list_input(shape.edges,file);
        if (rc == OK)
        {
             shape_find_center(shape.center, shape.points);
        }
        else
        {
             points_list_free_array(shape.points);
        }
    }

    return rc;
}

int shape_download(shape_t &shape, const char *file_name)
{
    int rc = OK;
    FILE *file = fopen(file_name, "r");

    if (file  != NULL)
    {
        shape_t tmp_shape = shape_init();
        rc = shape_process_download(tmp_shape, file);
        if (rc == OK)
        {
            shape_free(shape);           // delete old shape
            shape = tmp_shape;
        }
    }
    else
    {
        return ERR_FILE;
    }

    fclose(file);
    return rc;
}

int shape_check_arrays(const points_list_t &points_list, const edges_list_t &edges_list)
{
    int rc = points_list_check(points_list);
    if (rc == OK)
    {
        rc = edges_list_check_array(edges_list);
    }

    return rc;
}

int shape_upload(const shape_t& shape, const char *file_name)
{
    int rc = OK;
    FILE *file = fopen(file_name, "w");

    if (file)
    {
        rc = shape_check_arrays(shape.points, shape.edges);
        if (rc == OK)
        {
            points_list_output(file, shape.points);
            edges_list_output(file, shape.edges);
        }
    }
    else
    {
        return ERR_FILE;
    }

    fclose(file);
    return rc;
}

int shape_draw(const shape_t& shape, const painter_t &painter)
{
    int rc = shape_check_arrays(shape.points, shape.edges);
    if (rc == OK)
    {
        painter_clear_screen(painter);
        edges_list_draw(shape.edges, shape.points, painter);

    }
    return rc;
}


int shape_move(shape_t& shape, const move_info_t& moving)
{
    int rc = shape_check_arrays(shape.points, shape.edges);
    if (rc == OK)
    {
        points_list_move(shape.points, moving);
        point_move(shape.center, moving);

    }

    return rc;
}

int shape_scale(shape_t& shape, const scale_info_t &scale)
{
    int rc = shape_check_arrays(shape.points, shape.edges);
    if (rc == OK)
    {
        points_list_scale(shape.points, scale, shape.center);
    }

    return rc;
}

int shape_rotate(shape_t& shape, const rotate_info_t &rotate)
{
    int rc = shape_check_arrays(shape.points, shape.edges);
    if (rc == OK)
    {
        points_list_rotate(shape.points, rotate, shape.center);
    } 

    return rc;
}
