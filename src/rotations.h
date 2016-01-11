#ifndef __ROTATION_H__
#define __ROTATION_H__

#include "define.h"

void up_rotation (int cube[6][N][N]);
void up_rotation_reverse (int cube[6][N][N]);
void down_rotation (int cube[6][N][N]);
void down_rotation_reverse (int cube[6][N][N]);
void front_rotation (int cube[6][N][N]);
void front_rotation_reverse (int cube[6][N][N]);
void right_rotation (int cube[6][N][N]);
void right_rotation_reverse (int cube[6][N][N]);
void left_rotation (int cube[6][N][N]);
void left_rotation_reverse (int cube[6][N][N]);
void cube_rotation_side (int cube[6][N][N]);
void cube_rotation_upside_down (int cube[6][N][N]);
void second_line_right(int cube[6][N][N]);
void second_line_left(int cube[6][N][N]);
void yellow_cross_line (int cube[6][N][N]);
void yellow_cross_cross  (int cube[6][N][N]);
void yellow_cross_orientation (int cube[6][N][N]);
void yellow_corners_placement (int cube[6][N][N]);
void yellow_corners_orientation (int cube[6][N][N]);

#endif /* __ROTATION_H__ */
