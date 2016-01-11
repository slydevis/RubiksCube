#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "test/test.h"
#include "util.h"
#include "display.h"
#include "file.h"


/*----------------------------------------------------------------------------*/

void up_rotation (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessus dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[2][i][j];
        }
    // on stocke la ligne supérieure de la face du devant du cube dans tmp2
        tmp2[j] = cube[1][0][j];
    }

    /* on tourne les lignes en contact avec la face du dessus de chaque face 
    dans le sens des aiguilles d'une montre */ 
    for (j = 0; j < N; j++) {
        cube[1][0][j] = cube[4][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[4][0][j] = cube[5][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[5][0][j] = cube[0][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[0][0][j] = tmp2[j];
    }

    // on tourne la face du dessus
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[2][i][j] = tmp1[N-1-j][i];
        }
    }
}

void up_rotation_reverse (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessus dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[2][i][j];
        }
    }

   // on stocke la ligne supérieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[1][0][j];
    }

    /* on tourne les lignes en contact avec la face du dessus de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][0][j] = cube[0][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[0][0][j] = cube[5][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[5][0][j] = cube[4][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[4][0][j] = tmp2[j];
    }

    // on tourne la face du dessus
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[2][i][j] = tmp1[j][N-1-i];
        }
    }
}

void down_rotation (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessous dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[3][i][j];
        }
    }

    // on stocke la ligne inférieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[1][2][j];
    }

    /* on tourne les lignes en contact avec la face du dessous de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][2][j] = cube[4][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[4][2][j] = cube[5][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[5][2][j] = cube[0][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[0][2][j] = tmp2[j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[3][i][j] = tmp1[j][N-1-i];
        }
    }
}

void down_rotation_reverse (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessous dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[3][i][j];
        }
    }

    // on stocke la ligne inférieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[1][2][j];
    }

    /* on tourne les lignes en contact avec la face du dessous de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][2][j] = cube[0][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[0][2][j] = cube[5][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[5][2][j] = cube[4][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[4][2][j] = tmp2[j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[3][i][j] = tmp1[N-1-j][i];
        }
    }
}

void front_rotation (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[1][i][j];
        }
    }

    /* on stocke la colonne de la face de gauche en contact avec la face de 
    devant dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[0][i][2];
    }

    /* on tourne les lignes en contact avec la face de devant de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[0][j][2] = cube[3][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[3][0][j] = cube[4][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[4][j][0] = cube[2][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[2][2][j] = tmp2[N-1-j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[1][i][j] = tmp1[N-1-j][i];
        }
    }
}

void front_rotation_reverse (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[1][i][j];
        }
    }

    /* on stocke la colonne de la face de gauche en contact avec la face de *
    devant dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[0][i][2];
    }

    /* on tourne les lignes en contact avec la face de devant de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[0][j][2] = cube[2][2][N-1-j];
    }
    for (j = 0; j < N; j++) {
        cube[2][2][j] = cube[4][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[4][j][0] = cube[3][0][N-1-j];
    }
    for (j = 0; j < N; j++) {
        cube[2][2][j] = tmp2[j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[1][i][j] = tmp1[N-1-i][j];
        }
    }
}

void right_rotation (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de droite dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[4][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    droite dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[1][i][2];
    }

    /* on tourne les lignes en contact avec la face de droite de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][j][2] = cube[3][j][2];
    }
    for (j = 0; j < N; j++) {
        cube[3][j][2] = cube[5][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[5][j][0] = cube[2][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[2][j][2] = tmp2[j];
    }

    // on tourne la face de droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[4][i][j] = tmp1[N-1-j][i];
        }
    }
}

void right_rotation_reverse (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de droite dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[4][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    droite dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[1][i][2];
    }

    /* on tourne les lignes en contact avec la face de droite de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][j][2] = cube[2][j][2];
    }
    for (j = 0; j < N; j++) {
        cube[2][j][2] = cube[5][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[5][j][0] = cube[3][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[3][j][2] = tmp2[j];
    }

    // on tourne la face du droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[4][i][j] = tmp1[j][N-1-i];
        }
    }
}

void left_rotation (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de gauche dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[0][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[1][i][0];
    }

    /* on tourne les lignes en contact avec la face de gauche de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][j][0] = cube[3][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[3][j][0] = cube[5][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[5][j][2] = cube[2][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[2][j][0] = tmp2[j];
    }

    // on tourne la face du gauche
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[0][i][j] = tmp1[j][N-1-i];
        }
    }
}

void left_rotation_reverse (int cube[6][N][N]) {
    int tmp1[N][N];           // variable temporaire qui contient une face
    int tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de gauche dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[0][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[1][i][0];
    }

    /* on tourne les lignes en contact avec la face de gauche de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[1][j][0] = cube[2][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[2][j][0] = cube[5][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[5][j][2] = cube[3][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[3][j][0] = tmp2[j];
    }

    // on tourne la face du gauche
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[0][i][j] = tmp1[N-1-j][i];
        }
    }
}

void cube_rotation_side (int cube[6][N][N]) {
    /* on crée deux carré temporaire pour retenir une face de côté, celle du 
    dessus et celle de face */
    int tmp1[N][N];
    int tmp2[N][N];
    int tmp3[N][N];
    int i,j;

    // on stocke la face de devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[1][i][j];
        }
    }

    // on stocke la face du dessus dans tmp2 */
    for (i = 0; i < N; i++) {
        for  (j = 0; j < N; j++) {
            tmp2[i][j] = cube[2][i][j];
        }
    }

    // on stocke la face du dessous dans tmp3 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp3[i][j] = cube[3][i][j];
        }
    }

    // on tourne les faces de côté dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[1][i][j] = cube[4][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[4][i][j] = cube[5][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[5][i][j] = cube[0][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[0][i][j] = tmp1[i][j];
        }
    }

    // on tourne la face du dessus dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[2][i][j] = tmp2[N-1-j][i];
        }
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[3][i][j] = tmp3[j][N-1-i];
        }
    }
}

void cube_rotation_upside_down (int cube[6][N][N]) {
    /* on cr�e deux carr� temporaire pour retenir la face devant, celle de
    gauche et celle de droite */
    int tmp1[N][N];
    int tmp2[N][N];
    int tmp3[N][N];
    int i,j;

    // on stocke la face de devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[1][i][j];
        }
    }

    // on stocke la face de gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        for  (j = 0; j < N; j++) {
            tmp2[i][j] = cube[0][i][j];
        }
    }

    // on stocke la face de droite dans tmp3 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp3[i][j] = cube[4][i][j];
        }
    }

    // on tourne les faces de côté dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[1][i][j] = cube[3][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[3][i][j] = cube[5][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[5][i][j] = cube[2][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[2][i][j] = tmp1[i][j];
        }
    }

    // on tourne la face de gauche dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[0][i][j] = tmp2[j][N-1-i];
        }
    }

    // on tourne la face de droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[4][i][j] = tmp3[N-1-j][i];
        }
    }
}

void second_line_right(int cube[6][N][N]) {
	down_rotation(cube);
	right_rotation_reverse(cube);
	down_rotation_reverse(cube);
	right_rotation(cube);
	down_rotation_reverse(cube);
	front_rotation(cube);
	down_rotation(cube);
	front_rotation_reverse(cube);
}

void second_line_left(int cube[6][N][N]) {
	down_rotation_reverse(cube);
	left_rotation_reverse(cube);
	down_rotation(cube);
	left_rotation(cube);
	down_rotation(cube);
	front_rotation_reverse(cube);
	down_rotation_reverse(cube);
	front_rotation(cube);
}

void yellow_cross_line (int cube[6][N][N]) {
	up_rotation(cube);
	front_rotation(cube);
	right_rotation(cube);
	up_rotation(cube);
	right_rotation_reverse(cube);
	up_rotation_reverse (cube);
	front_rotation_reverse(cube);
}

void yellow_cross_cross  (int cube[6][N][N]) {
	front_rotation(cube);
	up_rotation(cube);
	right_rotation(cube);
	up_rotation_reverse(cube);
	right_rotation_reverse (cube);
	front_rotation_reverse(cube);
}

void yellow_cross_orientation (int cube[6][N][N]) {
	right_rotation(cube);
	up_rotation(cube);
	up_rotation(cube);
	right_rotation_reverse(cube);
	up_rotation_reverse(cube);
	right_rotation(cube);
	up_rotation_reverse(cube);
	right_rotation_reverse(cube);
}

void yellow_corners_placement (int cube[6][N][N]) {
	left_rotation(cube);
	up_rotation(cube);
	right_rotation(cube);
	up_rotation_reverse(cube);
	left_rotation_reverse(cube);
	up_rotation(cube);
	right_rotation_reverse(cube);
	up_rotation_reverse(cube);
}

void yellow_corners_orientation (int cube[6][N][N]) {
	right_rotation(cube);
	up_rotation(cube);
	up_rotation(cube);
	right_rotation_reverse(cube);
	up_rotation_reverse(cube);
	right_rotation(cube);
	up_rotation_reverse(cube);
	right_rotation_reverse(cube);
	left_rotation(cube);
	up_rotation(cube);
	up_rotation(cube);
	left_rotation_reverse(cube);
	up_rotation(cube);
	left_rotation(cube);
	up_rotation(cube);
	left_rotation_reverse(cube);
}
