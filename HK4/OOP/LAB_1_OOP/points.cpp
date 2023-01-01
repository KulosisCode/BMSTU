#include "points.h"

int points_list_begin(points_list_t &points_list, point_t * const arr, const int count)
{
    points_list.array = arr;
    points_list.count = count;
    return OK;
}

int points_list_check(const points_list_t &points_list)
{
    if (!points_list.array || !points_list.count)
    {
        return ERR_NO_POINT;
    }
    return OK;
}

int points_list_free_array(points_list_t &points_list)
{
    if (points_list.array)
        free(points_list.array);
    points_list.count = 0;

    return OK;
}

int points_list_count_read(points_list_t &points_list, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int count = 0;

    if (fscanf(file, "%d", &count) != 1)
    {
        return ERR_INPUT;
    }
    if (count < 2)
    {
        return  ERR_AMOUNT_POINTS;
    }
    points_list.count = count;

    return OK;
}

int points_list_allocate_array(points_list_t &points_list)
{
    point_t *temp_array = (point_t*) malloc (points_list.count * sizeof(point_t));
    if (!temp_array)
    {
        return ERR_MEMORY;
    }

    points_list.array = temp_array;

    return OK;
}

int array_read_points(point_t *arr, const int &count, FILE *file)
{
    if (!arr)
    {
        return ERR_NO_POINT;
    }

    if (!file)
    {
        return ERR_FILE;
    }

    int rc = OK;
    for (int i = 0; ( rc == OK) && (i < count); i++)
    {
        if (fscanf(file, "%lf %lf %lf", &arr[i].x, &arr[i].y, &arr[i].z) != 3)
        {
            return ERR_INPUT;
        }
    }
    return rc;
}

int points_list_array_read(points_list_t &points_list, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = OK;
    rc = array_read_points(points_list.array, points_list.count, file);

    return rc;
}

int points_list_input(points_list_t &points_list, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = points_list_count_read(points_list, file);
    if (rc == OK)
    {
        rc = points_list_allocate_array(points_list);
        if (rc == OK)
        {
            rc = points_list_array_read(points_list, file);
            if (rc != OK)
            {
                points_list_free_array(points_list);
            }
        }
    }

    return rc;
}

int points_array_output(const point_t *arr, const int &count, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    if (!arr)
    {
        return ERR_NO_POINT;
    }

    fprintf(file, "%d\n", count);
    for (int  i = 0; i < count; i++)
    {
        fprintf(file, "%lf %lf %lf\n", arr[i].x, arr[i].y, arr[i].z);
    }

    return OK;
}

int points_list_output(FILE *file, const points_list_t &points_list)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = points_array_output(points_list.array, points_list.count, file);

    return rc;
}

int points_find_center_x(point_t &center, const point_t *arr, const int &count)
{
    if (!arr)
    {
        return ERR_NO_POINT;
    }

    double min = arr[0].x, max = arr[0].x;
    for (int i  = 0; i < count; i++)
    {
        if (arr[i].x < min)
        {
            min = arr[i].x;
        }
        if (arr[i].x > max)
        {
            max = arr[i].x;
        }
    }
    center.x = (max + min) / 2;

    return OK;
}

int points_find_center_y(point_t &center, const point_t *arr, const int &count)
{
    if (!arr)
    {
        return ERR_NO_POINT;
    }

    double min = arr[0].y, max = arr[0]. y;
    for (int i  = 0; i < count; i++)
    {
        if (arr[i].y < min)
        {
            min = arr[i].y;
        }
        if (arr[i].y > max)
        {
            max = arr[i].y;
        }
    }
    center.y = (max + min) / 2;

    return OK;
}

int points_find_center_z(point_t &center, const point_t *arr, const int &count)
{
    if (!arr)
    {
        return ERR_NO_POINT;
    }

    double min = arr[0].z, max = arr[0]. z;
    for (int i  = 0; i < count; i++)
    {
        if (arr[i].z < min)
        {
            min = arr[i].z;
        }
        if (arr[i].z > max)
        {
            max = arr[i].z;
        }
    }
    center.z = (max + min) / 2;

    return OK;
}

int points_find_center(point_t &center, const point_t *arr, const int &count)
{
    if (!arr || count <= 0)
    {
        return ERR_NO_POINT;
    }

    int rc = points_find_center_x(center, arr, count);
    if (rc == OK)
    {
        rc = points_find_center_y(center, arr, count);
        if (rc == OK)
        {
            rc = points_find_center_z(center, arr, count);
        }
    }

    return rc;
}

void point_move(point_t &point, const move_info_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

int points_list_move(points_list_t &points_list, const move_info_t &move)
{
    if (!points_list.array)
    {
        return ERR_NO_POINT;
    }

    for (int i = 0; i < points_list.count ; i++)
    {
        point_move(points_list.array[i], move);
    }

    return OK;
}


void point_scale(point_t &point, const scale_info_t &scale, const point_t &scale_center)
{
    point.x = scale.kx * point.x + scale_center.x * (1 - scale.kx);
    point.y = scale.ky * point.y + scale_center.y * (1 - scale.ky);
    point.z = scale.kz * point.z + scale_center.z * (1 - scale.kz);
}

int points_list_scale(points_list_t &points_list, const scale_info_t &scale, const point_t &scale_center)
{
    if (!points_list.array)
    {
        return ERR_NO_POINT;
    }

    for (int i = 0; i < points_list.count ; i++)
    {
        point_scale(points_list.array[i], scale, scale_center);
    }

    return OK;
}


void to_radians(rotate_info_t &rotate)
{
    rotate.rx *= (M_PI / 180);
    rotate.ry *= (M_PI / 180);
    rotate.rz *= (M_PI / 180);
}

void point_move_to_center(point_t &point, const point_t &rotate_center)
{
    point.x -= rotate_center.x;
    point.y -= rotate_center.y;
    point.z -= rotate_center.z;
}

void point_move_to_origin(point_t &point, const point_t &rotate_center)
{
    point.x += rotate_center.x;
    point.y += rotate_center.y;
    point.z += rotate_center.z;
}

void point_rotate(point_t &point, rotate_info_t rotate , const point_t &rotate_center)
{
    to_radians(rotate);

    point_move_to_center(point, rotate_center);

    double sin_r, cos_r;
    double tmp;

    //rotate around x
    sin_r = sin(rotate.rx);
    cos_r = cos(rotate.rx);
    tmp = point.y;

    point.y = (point.y * cos_r + point.z * sin_r);
    point.z = (-tmp * sin_r + point.z * cos_r);


    //rotate around y
    cos_r = cos(rotate.ry);
    sin_r = sin(rotate.ry);
    tmp = point.x;

    point.x = (point.x * cos_r + point.z * sin_r);
    point.z = (- tmp* sin_r + point.z * cos_r);

    //rotate around z
    cos_r = cos(rotate.rz);
    sin_r = sin(rotate.rz);
    tmp = point.x;

    point.x = (point.x * cos_r + point.y * sin_r);
    point.y = (-tmp * sin_r + point.y * cos_r);

    point_move_to_origin(point, rotate_center);

}

int points_list_rotate(points_list_t &points_list, const rotate_info_t &rotate, const point_t &rotate_center)
{
    if (!points_list.array)
    {
        return ERR_NO_POINT;
    }

    for (int i = 0; i < points_list.count; i++)
    {
        point_rotate(points_list.array[i], rotate, rotate_center);
    }

    return OK;
}
