#ifndef POINTS_H
#define POINTS_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <stdio.h>
#include <stdlib.h>
#include <errors.h>

struct point_t
{
    double x;
    double y;
    double z;
};

struct points_list_t
{
    int count;
    point_t* array;
};

struct move_info_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_info_t
{
    double kx;
    double ky;
    double kz;
};

struct rotate_info_t
{
    double rx;
    double ry;
    double rz;
};

int points_list_begin(points_list_t &points_list, point_t * const arr, const int count);

int points_list_check(const points_list_t &points_list);

int points_list_free_array(points_list_t &points_list);

int points_list_count_read(points_list_t &points_list, FILE *file);

int points_list_allocate_array(points_list_t &points_list);

int array_read_points(point_t *arr, const int &count, FILE *file);

int points_list_array_read(points_list_t &points_list, FILE *file);

int points_list_input(points_list_t &points_list, FILE *file);

int points_array_output(const point_t *arr, const int &count, FILE *file);

int points_list_output(FILE *file, const points_list_t &points_list);

int points_find_center_x(point_t &center, const point_t *arr, const int &count);

int points_find_center_y(point_t &center, const point_t *arr, const int &count);

int points_find_center_z(point_t &center, const point_t *arr, const int &count);

int points_find_center(point_t &center, const point_t *arr, const int &count);

void point_move(point_t &point, const move_info_t &move);

int points_list_move(points_list_t &points_list, const move_info_t &move);

void point_scale(point_t &point, const scale_info_t &scale, const point_t &scale_center);

int points_list_scale(points_list_t &points_list, const scale_info_t &scale, const point_t &scale_center);

void to_radians(rotate_info_t &rotate);

void point_move_to_center(point_t &point, const point_t &rotate_center);

void point_move_to_origin(point_t &point, const point_t &rotate_center);

void point_rotate(point_t &point, rotate_info_t rotate , const point_t &rotate_center);

int points_list_rotate(points_list_t &points_list, const rotate_info_t &rotate, const point_t &rotate_center);

#endif // POINTS_H
