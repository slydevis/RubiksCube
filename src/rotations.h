#ifndef __ROTATION_H__
#define __ROTATION_H__

#include "define.h"

/************************************
 *          Cube rotations
 ************************************/

void up_rotation (miniCube cube[6][N][N]);
void up_rotation_reverse (miniCube cube[6][N][N]);
void down_rotation (miniCube cube[6][N][N]);
void down_rotation_reverse (miniCube cube[6][N][N]);
void front_rotation (miniCube cube[6][N][N]);
void front_rotation_reverse (miniCube cube[6][N][N]);
void right_rotation (miniCube cube[6][N][N]);
void right_rotation_reverse (miniCube cube[6][N][N]);
void left_rotation (miniCube cube[6][N][N]);
void left_rotation_reverse (miniCube cube[6][N][N]);
void middle_vectical_rotation (miniCube cube[6][N][N]);
void middle_vectical_rotation_reverse (miniCube cube[6][N][N]);
void middle_horizontal_rotation (miniCube cube[6][N][N]);
void middle_horizontal_rotation_reverse (miniCube cube[6][N][N]);
void middle_rotation_side(miniCube cube[6][N][N]);
void middle_rotation_side_reverse(miniCube cube[6][N][N]);
void cube_rotation_side (miniCube cube[6][N][N]);
void cube_rotation_upside_down (miniCube cube[6][N][N]);
void cubeRotation(miniCube cube[6][N][N], const char* rotation);

/************************************
 *   Mechanics cube manipulation
 ************************************/

void second_line_right(miniCube cube[6][N][N]);
void second_line_left(miniCube cube[6][N][N]);
void yellow_cross_line (miniCube cube[6][N][N]);
void yellow_cross_cross  (miniCube cube[6][N][N]);
void yellow_cross_orientation (miniCube cube[6][N][N]);
void yellow_corners_placement (miniCube cube[6][N][N]);
void yellow_corners_orientation (miniCube cube[6][N][N]);

#endif /* __ROTATION_H__ */
