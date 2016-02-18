#include <string.h> // strcmp()

#include "util.h"
#include "file.h"

/************************************
 *          Cube rotations
 ************************************/

void up_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessus dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_UPPER][i][j];
        }
    }
    for (j = 0; j < N; j++) {
    // on stocke la ligne supérieure de la face du devant du cube dans tmp2
        tmp2[j] = cube[SIDE_FRONT][0][j];
    }

    /* on tourne les lignes en contact avec la face du dessus de chaque face 
    dans le sens des aiguilles d'une montre */ 
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][0][j] = cube[SIDE_RIGHT][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][0][j] = cube[SIDE_BEHIND][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][0][j] = cube[SIDE_LEFT][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][0][j] = tmp2[j];
    }

    // on tourne la face du dessus
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_UPPER][i][j] = tmp1[N-1-j][i];
        }
    }
}

void up_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessus dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_UPPER][i][j];
        }
    }

   // on stocke la ligne supérieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[SIDE_FRONT][0][j];
    }

    /* on tourne les lignes en contact avec la face du dessus de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][0][j] = cube[SIDE_LEFT][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][0][j] = cube[SIDE_BEHIND][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][0][j] = cube[SIDE_RIGHT][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][0][j] = tmp2[j];
    }

    // on tourne la face du dessus
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_UPPER][i][j] = tmp1[j][N-1-i];
        }
    }
}

void down_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessous dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_BOTTOM][i][j];
        }
    }

    // on stocke la ligne inférieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[SIDE_FRONT][2][j];
    }

    /* on tourne les lignes en contact avec la face du dessous de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][2][j] = cube[SIDE_RIGHT][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][2][j] = cube[SIDE_BEHIND][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][2][j] = cube[SIDE_LEFT][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][2][j] = tmp2[j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BOTTOM][i][j] = tmp1[j][N-1-i];
        }
    }
}

void down_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du dessous dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_BOTTOM][i][j];
        }
    }

    // on stocke la ligne inférieure de la face du devant du cube dans tmp2
    for (j = 0; j < N; j++) {
        tmp2[j] = cube[SIDE_FRONT][2][j];
    }

    /* on tourne les lignes en contact avec la face du dessous de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][2][j] = cube[SIDE_LEFT][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][2][j] = cube[SIDE_BEHIND][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][2][j] = cube[SIDE_RIGHT][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][2][j] = tmp2[j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BOTTOM][i][j] = tmp1[N-1-j][i];
        }
    }
}

void front_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_FRONT][i][j];
        }
    }

    /* on stocke la colonne de la face de gauche en contact avec la face de 
    devant dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_LEFT][i][2];
    }

    /* on tourne les lignes en contact avec la face de devant de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][j][2] = cube[SIDE_BOTTOM][0][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][0][j] = cube[SIDE_RIGHT][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][j][0] = cube[SIDE_UPPER][2][j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][2][j] = tmp2[N-1-j];
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_FRONT][i][j] = tmp1[N-1-j][i];
        }
    }
}

void front_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face du devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_FRONT][i][j];
        }
    }

    /* on stocke la colonne de la face de gauche en contact avec la face de *
    devant dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_LEFT][i][2];
    }

    /* on tourne les lignes en contact avec la face de devant de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_LEFT][j][2] = cube[SIDE_UPPER][2][N-1-j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][2][j] = cube[SIDE_RIGHT][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_RIGHT][j][0] = cube[SIDE_BOTTOM][0][N-1-j];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][0][j] = tmp2[j];
    }

    // on tourne la face de devant
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_FRONT][i][j] = tmp1[j][N-1-i];
        }
    }
}

void right_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de droite dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_RIGHT][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    droite dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][2];
    }

    /* on tourne les lignes en contact avec la face de droite de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][j][2] = cube[SIDE_BOTTOM][j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][j][2] = cube[SIDE_BEHIND][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][j][0] = cube[SIDE_UPPER][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][j][2] = tmp2[j];
    }

    // on tourne la face de droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_RIGHT][i][j] = tmp1[N-1-j][i];
        }
    }
}

void right_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de droite dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_RIGHT][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    droite dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][2];
    }

    /* on tourne les lignes en contact avec la face de droite de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][j][2] = cube[SIDE_UPPER][j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][j][2] = cube[SIDE_BEHIND][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][j][0] = cube[SIDE_BOTTOM][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][j][2] = tmp2[j];
    }

    // on tourne la face du droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_RIGHT][i][j] = tmp1[j][N-1-i];
        }
    }
}

void left_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de gauche dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_LEFT][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][0];
    }

    /* on tourne les lignes en contact avec la face de gauche de chaque face 
    dans le sens inverse des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][j][0] = cube[SIDE_BOTTOM][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][j][0] = cube[SIDE_BEHIND][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][j][2] = cube[SIDE_UPPER][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][j][0] = tmp2[j];
    }

    // on tourne la face du gauche
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_LEFT][i][j] = tmp1[j][N-1-i];
        }
    }
}

void left_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N][N];           // variable temporaire qui contient une face
    miniCube tmp2[N];          // variable temporaire qui contient une ligne
    int i, j;

    //on stocke la face de gauche dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_LEFT][i][j];
        }
    }

    /* on stocke la colonne de la face de devant en contact avec la face de 
    gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][0];
    }

    /* on tourne les lignes en contact avec la face de gauche de chaque face 
    dans le sens des aiguilles d'une montre */
    for (j = 0; j < N; j++) {
        cube[SIDE_FRONT][j][0] = cube[SIDE_UPPER][j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_UPPER][j][0] = cube[SIDE_BEHIND][N-1-j][2];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BEHIND][j][2] = cube[SIDE_BOTTOM][N-1-j][0];
    }
    for (j = 0; j < N; j++) {
        cube[SIDE_BOTTOM][j][0] = tmp2[j];
    }

    // on tourne la face du gauche
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_LEFT][i][j] = tmp1[N-1-j][i];
        }
    }
}

void middle_vectical_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_BOTTOM][i][1];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_FRONT][i][1] = cube[SIDE_UPPER][i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BOTTOM][i][1] = tmp2[i];
    }

    for(i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_BEHIND][i][1];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_BEHIND][i][1] = tmp1[N-i-1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_UPPER][i][1] = tmp2[N-i-1];
    }
}

void middle_vectical_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_UPPER][i][1];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_FRONT][i][1] = cube[SIDE_BOTTOM][i][1];
    }

    for(i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_BEHIND][N-1-i][1];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_BEHIND][i][1] = cube[SIDE_UPPER][N-1-i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_UPPER][i][1] = tmp2[i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BOTTOM][i][1] = tmp1[i];
    }
}
void middle_horizontal_rotation (miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_LEFT][1][i];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_FRONT][1][i] = cube[SIDE_RIGHT][1][i];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_LEFT][1][i] = tmp2[i];
    }

    for(i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_BEHIND][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BEHIND][1][i] = tmp1[i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_RIGHT][1][i] = tmp2[i];
    }
}

void middle_horizontal_rotation_reverse (miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_RIGHT][1][i];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_FRONT][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_FRONT][1][i] = cube[SIDE_LEFT][1][i];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_RIGHT][1][i] = tmp2[i];
    }

    for(i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_BEHIND][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BEHIND][1][i] = tmp1[i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_LEFT][1][i] = tmp2[i];
    }
}

void middle_rotation_side(miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_UPPER][1][i];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_RIGHT][i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_UPPER][1][i] = cube[SIDE_LEFT][N-1-i][1];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_RIGHT][i][1] = tmp1[i];
    }

    for(i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_BOTTOM][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BOTTOM][1][i] = tmp2[N-1-i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_LEFT][i][1] = tmp1[i];
    }
}

void middle_rotation_side_reverse(miniCube cube[6][N][N]) {
    miniCube tmp1[N];
    miniCube tmp2[N];
    int i;

    for (i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_UPPER][1][i];
    }

    for (i = 0; i < N; i++) {
        tmp2[i] = cube[SIDE_LEFT][i][1];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_UPPER][1][i] = cube[SIDE_RIGHT][i][1];
    }

    for(i = 0; i < N; i++) {
        cube[SIDE_LEFT][N-i-1][1] = tmp1[i];
    }

    for(i = 0; i < N; i++) {
        tmp1[i] = cube[SIDE_BOTTOM][1][i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_BOTTOM][1][i] = tmp2[i];
    }

    for (i = 0; i < N; i++) {
        cube[SIDE_RIGHT][N-i-1][1] = tmp1[i];
    }
}

void cube_rotation_side (miniCube cube[6][N][N]) {
    /* on crée deux carré temporaire pour retenir une face de côté, celle du 
    dessus et celle de face */
    miniCube tmp1[N][N];
    miniCube tmp2[N][N];
    miniCube tmp3[N][N];
    int i,j;

    // on stocke la face de devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_FRONT][i][j];
        }
    }

    // on stocke la face du dessus dans tmp2 */
    for (i = 0; i < N; i++) {
        for  (j = 0; j < N; j++) {
            tmp2[i][j] = cube[SIDE_UPPER][i][j];
        }
    }

    // on stocke la face du dessous dans tmp3 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp3[i][j] = cube[SIDE_BOTTOM][i][j];
        }
    }

    // on tourne les faces de côté dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_FRONT][i][j] = cube[SIDE_RIGHT][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_RIGHT][i][j] = cube[SIDE_BEHIND][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BEHIND][i][j] = cube[SIDE_LEFT][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_LEFT][i][j] = tmp1[i][j];
        }
    }

    // on tourne la face du dessus dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_UPPER][i][j] = tmp2[N-1-j][i];
        }
    }

    // on tourne la face du dessous
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BOTTOM][i][j] = tmp3[j][N-1-i];
        }
    }
}

void cube_rotation_upside_down (miniCube cube[6][N][N]) {
    /* on crée deux carré temporaire pour retenir la face devant, celle de
    gauche et celle de droite */
    miniCube tmp1[N][N];
    miniCube tmp2[N][N];
    miniCube tmp3[N][N];
    int i,j;

    // on stocke la face de devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[SIDE_FRONT][i][j];
        }
    }

    // on stocke la face de gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        for  (j = 0; j < N; j++) {
            tmp2[i][j] = cube[SIDE_LEFT][i][j];
        }
    }

    // on stocke la face de droite dans tmp3 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp3[i][j] = cube[SIDE_RIGHT][i][j];
        }
    }

    // on tourne les faces de côté dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_FRONT][i][j] = cube[SIDE_BOTTOM][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BOTTOM][i][j] = cube[SIDE_BEHIND][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_BEHIND][i][j] = cube[SIDE_UPPER][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_UPPER][i][j] = tmp1[i][j];
        }
    }

    // on tourne la face de gauche dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_LEFT][i][j] = tmp2[j][N-1-i];
        }
    }

    // on tourne la face de droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[SIDE_RIGHT][i][j] = tmp3[N-1-j][i];
        }
    }
}

/**
 * \fn void cubeRotation(miniCube cube[6][N][N], const char* rotation)
 * \brief Tranduis la notation Singmaster en une rotation sur le cube
 * \param cube Rubik's cube courant
 * \param rotation Lettre de la rotation Singmaster
 */
void cubeRotation(miniCube cube[6][N][N], const char* rotation) {
    if(strcmp(rotation, "U") == 0)
        up_rotation(cube);
    else if(strcmp(rotation, "U'") == 0)
        up_rotation_reverse(cube);
    else if(strcmp(rotation, "L") == 0)
        left_rotation_reverse(cube);
    else if(strcmp(rotation, "L'") == 0)
        left_rotation(cube);
    else if(strcmp(rotation, "F") == 0)
        front_rotation(cube);
    else if(strcmp(rotation, "F'") == 0)
        front_rotation_reverse(cube);
    else if(strcmp(rotation, "R") == 0)
        right_rotation(cube);
    else if(strcmp(rotation, "R'") == 0)
        right_rotation_reverse(cube);
    else if(strcmp(rotation, "B") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    else if(strcmp(rotation, "B'") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    else if(strcmp(rotation, "D") == 0)
        down_rotation_reverse(cube);
    else if(strcmp(rotation, "D'") == 0)
        down_rotation(cube);
    else if(strcmp(rotation, "M") == 0)
        middle_vectical_rotation(cube);
    else if(strcmp(rotation, "M'") == 0)
        middle_vectical_rotation_reverse(cube);
    else if(strcmp(rotation, "u") == 0) {
        middle_horizontal_rotation(cube);
        up_rotation(cube);
    }
    else if(strcmp(rotation, "u'") == 0) {
        middle_horizontal_rotation_reverse(cube);
        up_rotation_reverse(cube);
    }
    else if(strcmp(rotation, "l") == 0) {
        middle_vectical_rotation(cube);
        left_rotation_reverse(cube);
    }
    else if(strcmp(rotation, "l'") == 0) {
        middle_vectical_rotation_reverse(cube);
        left_rotation(cube);
    }
    else if(strcmp(rotation, "E") == 0)
        middle_horizontal_rotation_reverse(cube);
    else if(strcmp(rotation, "E'") == 0)
        middle_horizontal_rotation(cube);
    else if(strcmp(rotation, "f") == 0) {
        front_rotation(cube);
        middle_rotation_side(cube);
    }
    else if(strcmp(rotation, "f'") == 0) {
        middle_rotation_side_reverse(cube);
        front_rotation_reverse(cube);
    }
    else if(strcmp(rotation, "r") == 0) {
        right_rotation(cube);
        middle_vectical_rotation_reverse(cube);
    }
    else if(strcmp(rotation, "r'") == 0) {
        right_rotation_reverse(cube);
        middle_vectical_rotation(cube);
    }
    else if(strcmp(rotation, "S") == 0)
        middle_rotation_side(cube);
    else if(strcmp(rotation, "S'") == 0)
        middle_rotation_side_reverse(cube);
    else if(strcmp(rotation, "b") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        middle_rotation_side_reverse(cube);
    }
    else if(strcmp(rotation, "b'") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        middle_rotation_side(cube);
    }
    else if(strcmp(rotation, "d") == 0) {
        down_rotation_reverse(cube);
        middle_horizontal_rotation_reverse(cube);
    }
    else if(strcmp(rotation, "d'") == 0) {
        down_rotation(cube);
        middle_horizontal_rotation(cube);
    }
    else if(strcmp(rotation, "X") == 0)
        cube_rotation_upside_down(cube);
    else if(strcmp(rotation, "X'") == 0) {
        cube_rotation_upside_down(cube);
        cube_rotation_upside_down(cube);
        cube_rotation_upside_down(cube);
    }
    else if(strcmp(rotation, "Y") == 0)
        cube_rotation_side(cube);
    else if(strcmp(rotation, "Y'") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    else if(strcmp(rotation, "Z") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        middle_rotation_side(cube);
        front_rotation(cube);
    }
    else if(strcmp(rotation, "Z'") == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        middle_rotation_side_reverse(cube);
        front_rotation_reverse(cube);
    }
    else
        printError("Rotation inconnue");
}

/************************************
 *   Mechanics cube manipulation
 ************************************/

void second_line_right(miniCube cube[6][N][N]) {
    down_rotation(cube);
    right_rotation_reverse(cube);
    down_rotation_reverse(cube);
    right_rotation(cube);
    down_rotation_reverse(cube);
    front_rotation(cube);
    down_rotation(cube);
    front_rotation_reverse(cube);
}

void second_line_left(miniCube cube[6][N][N]) {
    down_rotation_reverse(cube);
    left_rotation_reverse(cube);
    down_rotation(cube);
    left_rotation(cube);
    down_rotation(cube);
    front_rotation_reverse(cube);
    down_rotation_reverse(cube);
    front_rotation(cube);
}

void yellow_cross_line (miniCube cube[6][N][N]) {
    up_rotation(cube);
    front_rotation(cube);
    right_rotation(cube);
    up_rotation(cube);
    right_rotation_reverse(cube);
    up_rotation_reverse (cube);
    front_rotation_reverse(cube);
}

void yellow_cross_cross  (miniCube cube[6][N][N]) {
    front_rotation(cube);
    up_rotation(cube);
    right_rotation(cube);
    up_rotation_reverse(cube);
    right_rotation_reverse (cube);
    front_rotation_reverse(cube);
}

void yellow_cross_orientation (miniCube cube[6][N][N]) {
    right_rotation(cube);
    up_rotation(cube);
    up_rotation(cube);
    right_rotation_reverse(cube);
    up_rotation_reverse(cube);
    right_rotation(cube);
    up_rotation_reverse(cube);
    right_rotation_reverse(cube);
}

void yellow_corners_placement (miniCube cube[6][N][N]) {
    left_rotation(cube);
    up_rotation(cube);
    right_rotation(cube);
    up_rotation_reverse(cube);
    left_rotation_reverse(cube);
    up_rotation(cube);
    right_rotation_reverse(cube);
    up_rotation_reverse(cube);
}

void yellow_corners_orientation (miniCube cube[6][N][N]) {
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
