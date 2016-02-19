#include <stdio.h>
#include "test/test.h"
#include "util.h"
#include "display.h"
#include "file.h"
#include "rotations.h"

/*----------------------------------------------------------------------------*/
/* la fonction recherche la position d'une case définie par son identifiant */
int recherche_case(miniCube cube[6][N][N], int x) {
    int i, j, k;
    int pos;

    /* On parcours le cube et quand on a trouver sa place, on l'écris sous la
    * forme 9 * face + 3 * ligne + colonne afin d'obtenir un nombre différent
    * pour chaque case
    */

    for (i = 0; i < 6; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                if (cube[i][j][k]->finalPos == x) {
                   pos = 9 * i + 3 * j + k;
                }
            }
        }
    }

    return pos;
}

/* La fonction va placer la face dont le centre est blanc devant */
void white_center_placement (miniCube cube[6][N][N]) {
    int n = 0, pos;
    pos = recherche_case(cube, 11);

    /* on commence par faire des rotations du cube selon l'axe X */
    while (n < 3 && pos != 13) {
        cube_rotation_side(cube);
        pos = recherche_case(cube, 11);
        n = n + 1;
    }

    /* ensuite on fait des rotations selon l'axe Y */
    n = 0;
    pos = recherche_case(cube, 11);
    while (n < 3 && pos != 13) {
        cube_rotation_upside_down(cube);
        pos = recherche_case(cube, 11);
        n = n + 1;
    }

    /* Et enfin on fait des rotations selon l'axe Z  pour placer la face bleu
    * sur la face de droite
    */
    n = 0;
    pos = recherche_case(cube, 111);
    while (n < 3 && pos != 40) {
        cube_rotation_upside_down(cube);
        cube_rotation_side(cube);
        cube_rotation_upside_down(cube);
        cube_rotation_upside_down(cube);
        cube_rotation_upside_down(cube);
        pos = recherche_case(cube, 111);
        n = n + 1;
    }

    return ;
}

/* La fonction va réaliser la croix blanche */
void white_cross(miniCube cube[6][N][N]) {
    int pos;            // pos contiendra la position de la case recherchée

    /* Cette fonction va placer quatre cases: 001, 010, 012, 021. Pour chaque
    * case, on cherche sa position et on la place en fonction de sa position
    */

    /* positionnement de la case 001 */
    pos = recherche_case(cube, 1);

    if (pos == 37) {
        up_rotation(cube);
    }
    if (pos == 46) {
        up_rotation(cube);
        up_rotation(cube);
    }
    if (pos == 1) {
        up_rotation_reverse(cube);
    }
    if (pos == 21) {
        left_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 30) {
        left_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 23) {
        right_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 32) {
        right_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 12) {
        front_rotation(cube);
    }
    if(pos == 14) {
        front_rotation_reverse(cube);
    }
    if (pos == 16) {
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 3) {
        left_rotation_reverse(cube);
        up_rotation_reverse(cube);
    }
    if (pos == 5) {
        left_rotation(cube);
        up_rotation_reverse(cube);
    }
    if (pos == 39) {
        right_rotation(cube);
        up_rotation(cube);
    }
    if (pos == 41) {
        right_rotation_reverse(cube);
        up_rotation(cube);
    }
    if (pos == 48) {
        right_rotation(cube);
        right_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 50) {
        left_rotation(cube);
        left_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 25) {
        up_rotation_reverse(cube);
        right_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 19) {
        up_rotation(cube);
        right_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 28) {
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 34) {
        down_rotation(cube);
        right_rotation(cube);
        front_rotation_reverse(cube);
    }


    /* positionnement de la case 010*/
    pos = recherche_case(cube, 10);

    if (pos == 37) {
        front_rotation(cube);
        up_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 46) {
        front_rotation(cube);
        up_rotation(cube);
        up_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 1) {
        front_rotation(cube);
        up_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 21) {
        left_rotation_reverse(cube);
    }
    if (pos == 30) {
        left_rotation(cube);
    }
    if (pos == 23) {
        front_rotation(cube);
        front_rotation(cube);
        right_rotation_reverse(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 32) {
        front_rotation(cube);
        front_rotation(cube);
        right_rotation(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if(pos == 14) {
        right_rotation(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
        right_rotation_reverse(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 16) {
        down_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 7) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 43) {
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 52) {
        front_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 3) {
        left_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);

    }
    if (pos == 5) {
        left_rotation_reverse(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 39) {
        right_rotation_reverse(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 41) {
        right_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 48) {
        front_rotation(cube);
        front_rotation(cube);
        right_rotation(cube);
        right_rotation(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 50) {
        left_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 19) {
        up_rotation_reverse(cube);
        left_rotation_reverse(cube);
        up_rotation(cube);
    }
    if (pos == 28) {
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 34) {
        down_rotation_reverse(cube);
        left_rotation(cube);
    }

    /* positionnement de la case 012 */
    pos = recherche_case(cube, 12);

    if (pos == 37) {
        front_rotation_reverse(cube);
        up_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 46) {
        front_rotation_reverse(cube);
        up_rotation(cube);
        up_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 1) {
        front_rotation_reverse(cube);
        up_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 21) {
        front_rotation(cube);
        front_rotation(cube);
        left_rotation_reverse(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 30) {
        front_rotation(cube);
        front_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 23) {
        right_rotation_reverse(cube);

    }
    if (pos == 32) {
        right_rotation(cube);
    }
    if (pos == 16) {
        down_rotation(cube);
        front_rotation(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 7) {
        front_rotation(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 43) {
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 52) {
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
        if (pos == 3) {
        front_rotation(cube);
        front_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse (cube);
    }
    if (pos == 39) {
        right_rotation(cube);
        front_rotation_reverse(cube);
        up_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 41) {
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 48) {
        right_rotation(cube);
        right_rotation(cube);
    }
    if (pos == 50) {
        front_rotation(cube);
        front_rotation(cube);
        left_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 19) {
        front_rotation_reverse(cube);
        up_rotation(cube);
        front_rotation(cube);
        right_rotation_reverse(cube);
    }
    if (pos == 28) {
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 34) {
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        right_rotation(cube);
    }

    /* positionnement de la case 021 */
    pos = recherche_case(cube, 21);

    if (pos == 37) {
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
        up_rotation(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 46) {
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
        up_rotation(cube);
        up_rotation(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 1) {
        front_rotation_reverse(cube);
        front_rotation_reverse(cube);
        up_rotation_reverse(cube);
        front_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 21) {
        front_rotation(cube);
        left_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 30) {
        front_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 23) {
        front_rotation_reverse(cube);
        right_rotation_reverse(cube);
        front_rotation(cube);

    }
    if (pos == 32) {
        front_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
    }
    if (pos == 3) {
        left_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
    }
    if (pos == 41) {
        right_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
    }
    if (pos == 48) {
        right_rotation(cube);
        front_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        right_rotation_reverse(cube);
        right_rotation_reverse(cube);
    }
    if (pos == 50) {
        front_rotation(cube);
        left_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 19) {
        up_rotation(cube);
        front_rotation_reverse(cube);
        right_rotation_reverse(cube);
        front_rotation(cube);
        up_rotation_reverse(cube);
    }
    if (pos == 28) {
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
    }
    if (pos == 34) {
        down_rotation(cube);
        front_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
    }
}

/* Cette fonction va placer les coins blancs pour finir la face blanche */
void white_face(miniCube cube[6][N][N]) {
    int pos;

    /* On cherche la position des angles, donc des cases 000, 002, 020 et 022.
    * On les place ensuite en fonction de leur position
    */

    /* recherche et positionnement de la position de la case 000 */
    pos = recherche_case(cube, 0);

    if (pos == 20) {
        right_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
    }
    if (pos == 26) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 24) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
    }
    if (pos == 0) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation(cube);
        right_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 2) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
    }
    if (pos == 9) {
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
    }
    if (pos == 11) {
        front_rotation(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 36) {
        right_rotation_reverse(cube);
        down_rotation(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
    }
    if (pos == 38) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 45) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 47) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 6) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 8) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 15) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
    }
    if (pos == 17) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 42) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 44) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 51) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 53) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 27) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 29) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
    }
    if (pos == 33) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
    }
    if (pos == 35) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }

    /* recherche et positionnement de la position de la case 002 */
    pos = recherche_case(cube, 2);

    if (pos == 26) {
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 24) {
        left_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 2) {
        left_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 9) {
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 11) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 36) {
        right_rotation_reverse(cube);
        down_rotation(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 38) {
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 45) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 6) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 8) {
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 15) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 17) {
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 42) {
        cube_rotation_side(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 44) {
         cube_rotation_side(cube);
         down_rotation(cube);
         right_rotation_reverse(cube);
         down_rotation_reverse(cube);
         right_rotation(cube);
         cube_rotation_side(cube);
         cube_rotation_side(cube);
         cube_rotation_side(cube);
    }
    if (pos == 51) {
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 53) {
        cube_rotation_side(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 27) {
        left_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 29) {
        front_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 33) {
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 35) {
        down_rotation(cube);
        front_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
        down_rotation(cube);
        cube_rotation_side(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }

    /* recherche et positionnement de la position de la case 020 */
    pos = recherche_case(cube, 20);

    if (pos == 26) {
        front_rotation(cube);
        down_rotation_reverse(cube);
        front_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 2) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 9) {
        front_rotation_reverse(cube);
        down_rotation(cube);
        front_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 11) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 36) {
        right_rotation_reverse(cube);
        down_rotation(cube);
        right_rotation(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 6) {
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 8) {
        down_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 15) {
        down_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 17) {
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 42) {
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 44) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 51) {
        down_rotation(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
    }
    if (pos == 53) {
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 27) {
        left_rotation_reverse(cube);
        down_rotation(cube);
        left_rotation(cube);
        front_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
    }
    if (pos == 29) {
        right_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        right_rotation(cube);
    }
    if (pos == 33) {
        down_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        right_rotation(cube);
    }
    if (pos == 35) {
        down_rotation(cube);
        right_rotation_reverse(cube);
        left_rotation_reverse(cube);
        down_rotation(cube);
        down_rotation(cube);
        left_rotation(cube);
        right_rotation(cube);
    }

    /* recherche et positionnement de la position de la case 022 */
    pos = recherche_case(cube, 22);

    if (pos == 11) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 36) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 6) {
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 8) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 15) {
        down_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 17) {
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 42) {
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 44) {
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 51) {
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 53) {
        down_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
    }
    if (pos == 27) {
        down_rotation_reverse(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 29) {
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 33) {
        down_rotation(cube);
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 35) {
        down_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation_reverse(cube);
        right_rotation(cube);
        front_rotation(cube);
        down_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
    }
    if (pos == 45) {
        up_rotation(cube);
        right_rotation_reverse(cube);
        down_rotation(cube);
        right_rotation(cube);
        down_rotation_reverse(cube);
        down_rotation_reverse(cube);
        front_rotation(cube);
        down_rotation(cube);
        front_rotation_reverse(cube);
        up_rotation_reverse(cube);
    }
}

/* Cette fonction fait partie d'un ensemble de fonction qui vont construire
* la deuxième ligne du cube.
* Cette fonction va placer la case 301
*/
void second_line_1(miniCube cube[6][N][N]) {
    int pos;

/* on cherche la position de la case 301 */
    pos = recherche_case(cube, 301);

    /* Si la case est déjà sur la deuxième ligne, mais mal placé, on réalise
    * soit la fonction second_line_right ou second_line_left selon de quel côté
    * du cube la case se trouve. Ensuite, un fait un appel récusif de la
    * fonction afin de finir de placer la case
    */
    if (pos == 39) {
        second_line_right(cube);
        second_line_1(cube);
    }
    if (pos == 5 || pos == 12) {
        second_line_left(cube);
        second_line_1(cube);
    }
    if (pos == 3 || pos == 50) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_1(cube);
    }
    if (pos == 41 || pos == 48) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_1(cube);
    }

    /* sinon si la case se trouve sur la troisième ligne, on la place sous la
    * case 311, la case du centre de la face rouge et on réalise la fonction
    * second_line_right
    */
    if (pos == 16) {
        second_line_right(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
        second_line_right(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
        second_line_right(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
        second_line_right(cube);
    }

    /* Sinon on place la case qui se trouve sur la même arrête sous la case 311
    */
    if (pos == 28) {
        down_rotation_reverse(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 32) {
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 34) {
        down_rotation(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 30) {
        down_rotation(cube);
        down_rotation(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }

    return ;
}

/* Cette fonction fait partie d'un ensemble de fonction qui vont construire
* la deuxième ligne du cube.
* Cette fonction va placer la case 321
*/
void second_line_2 (miniCube cube[6][N][N]) {
    int pos;

    /* on cherche la position de la case 321 et on la place */
    pos = recherche_case(cube, 321);

    /* Si la case est déjà sur la deuxième ligne, mais mal placé, on réalise
    * soit la fonction second_line_right ou second_line_left selon de quel côté
    * du cube la case se trouve. Ensuite, un fait un appel récusif de la
    * fonction afin de finir de placer la case
    */
    if (pos == 14 || pos == 39) {
        second_line_right(cube);
        second_line_2(cube);
    }
    if (pos == 5) {
        second_line_left(cube);
        second_line_2(cube);
    }
    if (pos == 3 || pos == 50) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_2(cube);
    }
    if (pos == 41 || pos == 48) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_2(cube);
    }

    /* sinon si la case se trouve sur la troisième ligne, on la place sous la
    * case 311, la case du centre de la face rouge et on réalise la fonction
    * second_line_left
    */
    if (pos == 16) {
        second_line_left(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
        second_line_left(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
        second_line_left(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
        second_line_left(cube);
    }

    /* Sinon on place la case qui se trouve sur la même arrête sous la case 311
    */
    if (pos == 28) {
        down_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
    if (pos == 32) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation(cube);
        down_rotation(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
    if (pos == 34) {
        down_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
    if (pos == 30) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
}

/* Cette fonction fait partie d'un ensemble de fonction qui vont construire
* la deuxième ligne du cube.
* Cette fonction va placer la case 221
*/
void second_line_3 (miniCube cube[6][N][N]) {
    int pos;

    /* on cherche la position de la case 221 et on la place */
    pos = recherche_case(cube, 221);

    /* Si la case est déjà sur la deuxième ligne, mais mal placé, on réalise
    * soit la fonction second_line_right ou second_line_left selon de quel côté
    * du cube la case se trouve. Ensuite, un fait un appel récusif de la
    * fonction afin de finir de placer la case
    */
    if (pos == 14 || pos == 39) {
        second_line_right(cube);
        second_line_3(cube);
    }
    if (pos == 5) {
        second_line_left(cube);
        second_line_3(cube);
    }
    if (pos == 3 || pos == 50) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_3(cube);
    }
    if (pos == 41 || pos == 48) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_3(cube);
    }

    /* sinon si la case se trouve sur la troisième ligne, on la place sous la
    * case 211, la case du centre de la face orange et on réalise la fonction
    * second_line_left
    */
    if (pos == 16) {
        second_line_left(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
        second_line_left(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
        second_line_left(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
        second_line_left(cube);
    }

    /* Sinon on place la case qui se trouve sur la même arrête sous la case 211
    */
    if (pos == 28) {
        down_rotation(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
    if (pos == 32) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        down_rotation(cube);
        down_rotation(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
    if (pos == 34) {
        down_rotation_reverse(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        down_rotation(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
    }
    if (pos == 30) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
    }
}

/* Cette fonction fait partie d'un ensemble de fonction qui vont construire
* la deuxième ligne du cube.
* Cette fonction va placer la case 201
*/
void second_line_4(miniCube cube[6][N][N]) {
    int pos;

/* on cherche la position de la case 201 et on la place */
    pos = recherche_case(cube, 201);

    /* Si la case est déjà sur la deuxième ligne, mais mal placé, on réalise
    * soit la fonction second_line_right ou second_line_left selon de quel côté
    * du cube la case se trouve. Ensuite, un fait un appel récusif de la
    * fonction afin de finir de placer la case
    */
    if (pos == 39) {
        second_line_right(cube);
        second_line_4(cube);
    }
    if (pos == 5 || pos == 12) {
        second_line_left(cube);
        second_line_4(cube);
    }
    if (pos == 3 || pos == 50) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_right(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_4(cube);
    }
    if (pos == 41 || pos == 48) {
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        second_line_4(cube);
    }

    /* sinon si la case se trouve sur la troisième ligne, on la place sous la
    * case 211, la case du centre de la face orange et on réalise la fonction
    * second_line_left
    */
    if (pos == 16) {
        second_line_right(cube);
    }
    if (pos == 7) {
        down_rotation_reverse(cube);
        second_line_right(cube);
    }
    if (pos == 43) {
        down_rotation(cube);
        second_line_right(cube);
    }
    if (pos == 52) {
        down_rotation(cube);
        down_rotation(cube);
        second_line_right(cube);
    }

    /* Sinon on place la case qui se trouve sur la même arrête sous la case 211
    */
    if (pos == 28) {
        down_rotation_reverse(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 32) {
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 34) {
        down_rotation(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }
    if (pos == 30) {
        down_rotation(cube);
        down_rotation(cube);
        cube_rotation_side(cube);
        second_line_left(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
        cube_rotation_side(cube);
    }

    return ;
}

/* Cette fonction va construire la seconde ligne du cube à l'aide des fonctions
* second_line_1, second_line_2, second_line_3 et second_line_4
*/
void second_line (miniCube cube[6][N][N]) {
    second_line_1(cube);
    second_line_2(cube);
    cube_rotation_side(cube);
    cube_rotation_side(cube);
    second_line_3(cube);
    second_line_4(cube);
    cube_rotation_side(cube);
    cube_rotation_side(cube);
}

/* Cette fonction va construire la croix jaune */
void yellow_cross (miniCube cube[6][N][N]) {
    int pos1, pos2, pos3, pos4;

/* on récupère la postion des quatre petit cube qui formeront la croix jaune */
    pos1 = recherche_case(cube, 401);
    pos2 = recherche_case(cube, 410);
    pos3 = recherche_case(cube, 412);
    pos4 = recherche_case(cube, 421);

/* Pour réaliser la croix jaune, on sait que soit la croix est déjà faite,
* soit il n'y a aucune case jaune sur la face, soit il y a deux cases jaunes
*/

    /* si la croix est déjà faite on sort de la fonction */
    if (pos1 == 25 || pos1 == 23 || pos1 == 21 || pos1 == 19) {
        if (pos2 == 25 || pos2 == 23 || pos2 == 21 || pos2 == 19) {
            if (pos3 == 25 || pos3 == 23 || pos3 == 21 || pos3 == 19) {
                if (pos4 == 25 || pos4 == 23 || pos4 == 21 || pos4 == 19) {
                    return ;
                }
            }
        }
    }

    /* On regarde si il y a déjà une case jaune sur la face jaune on commence
    * par la case 25
    */
    if (pos1 == 25 || pos2 == 25 || pos3 == 25 || pos4 == 25) {
        /* Si il y a une case jaune qui est sur la position 25, alors il y a une
        * deuxième case jaune
        */

        /* si la case jaune se trouve sur la case 19, on réalise la fonction
        * yellow_cross_line qui va placer les deux autres cases jaunes
        */
        if (pos1 == 19 || pos2 == 19 || pos3 == 19 || pos4 == 19) {
            yellow_cross_line(cube);
        }

        /* si la case jaune se trouve sur la case 21, on réalise la fonction
        * yellow_cross_cross qui va placer les deux autres cases jaunes
        */
        if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
            up_rotation(cube);
            yellow_cross_cross(cube);
        }

        /* si la case jaune se trouve sur la case 23, on réalise la fonction
        * yellow_cross_cross qui va placer les deux autres cases jaunes
        */
        if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
            up_rotation(cube);
            up_rotation(cube);
            yellow_cross_cross(cube);
        }
    }

    /* regarde ensuite si il y a une case jaune à la position 19 */
    else if (pos1 == 19 || pos2 == 19 || pos3 == 19 || pos4 == 19) {
        /* si la case jaune se trouve sur la case 19, alors il y a une
        * deuxième case jaune
        */

        /* si la case jaune se trouve sur la case 21, on réalise la fonction
        * yellow_cross_cross qui va placer les deux autres cases jaunes
        */
        if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
            yellow_cross_cross(cube);
        }

        /* si la case jaune se trouve sur la case 23, on réalise la fonction
        * yellow_cross_cross qui va placer les deux autres cases jaunes
        */
        if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
            up_rotation_reverse(cube);
            yellow_cross_cross(cube);
        }

        /* le cas de la case 25 a déjà été traité plus haut */
    }

    /* regarde ensuite si il y a une case jaune à la position 21 */
    else if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
        /* si la case jaune se trouve sur la case 21, alors il y a une deuxième
        * case jaune qui se trouve sur la case 23 car les autres cas ont déjà
        * été traité
        */
        if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
            up_rotation(cube);
            yellow_cross_line(cube);
        }
    }

    /* Si il n'y a aucune case jaune sur la face jaune, alors on réalise la
    * fonction yellow_cross_cross puis on fait un appel récursif de la fonction
    * afin de placer les deux cases jaunes qui vont manquer
    */
    else {
        yellow_cross_cross(cube);
        yellow_cross(cube);
    }

    return ;
}

/* Cette fonction va orienter la croix jaune, c'est-à-dire qu'elle va faire
* "tourner" la croix jaune pour que les couleurs qui sont sur les arrêtes de la
* croix soient sur la face de leur couleur
*/
void yellow_cross_right_orientation (miniCube cube[6][N][N], int p) {
    int pos1, pos2, pos3, n;

    pos1 = recherche_case(cube, p);

    /* On place la croix de façon à ce que la couleur de l'arrête de la croix
    * soit la couleur de la face de devant
    */
    while (pos1 != 10) {
        up_rotation(cube);
        pos1 = recherche_case(cube, p);
    }

    /* on cherche les position des cases en fonction de la case que l'on a
    * donné en paramètre
    */
    switch(p) {
        case 212:
            pos1 = recherche_case(cube, 510);
            pos2 = recherche_case(cube, 112);
            pos3 = recherche_case(cube, 312);
        break;
        case 112:
            pos1 = recherche_case(cube, 212);
            pos2 = recherche_case(cube, 312);
            pos3 = recherche_case(cube, 510);
        break;
        case 312:
            pos1 = recherche_case(cube, 112);
            pos2 = recherche_case(cube, 510);
            pos3 = recherche_case(cube, 212);
        break;
    }

    n = 0;

    /* on réalise la fonction yellow_cross_orientation tant qu'une des case
    * est mal placé ou tant que l'on ne l'a pas réalisé trois fois car au bout
    * de trois fois, on est revenu à l'état de départ */
    while ((n < 3) && (pos1 != 1 || pos2 != 37 || pos3 != 46)) {
        yellow_cross_orientation(cube);
        switch(p) {
        case 212:
            pos1 = recherche_case(cube, 510);
            pos2 = recherche_case(cube, 112);
            pos3 = recherche_case(cube, 312);
        break;
        case 112:
            pos1 = recherche_case(cube, 212);
            pos2 = recherche_case(cube, 312);
            pos3 = recherche_case(cube, 510);
        break;
        case 312:
            pos1 = recherche_case(cube, 112);
            pos2 = recherche_case(cube, 510);
            pos3 = recherche_case(cube, 212);
        break;
        }
        n = n + 1;
    }

    /* si la croix n'est toujours pas orienté, on a trois cas: */
    if (pos1 != 1 || pos2 != 37 || pos3 != 46) {
        /* si il y a une deuxième case jaune à gauche ou à droite de la case
        * de devant, alors on tourne de cube et on fait un appel récursif de la
        * fonction avec en argument l'identifiant de la nouvel case de devant
        */
        if (pos1 == 1) {
            cube_rotation_side(cube);
            yellow_cross_right_orientation(cube, 112);

        }
        if (pos2 == 37) {
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            yellow_cross_right_orientation(cube, 312);
        }

        /* si il y a une deuxième case jaune sur la face de derrière, on
        * réalise la fonction yellow_cross_orientation et un fait un appel
        * récursif de la fonction avec la même case en paramètre
        */
        if (pos3 == 46) {
            yellow_cross_orientation(cube);
            yellow_cross_right_orientation(cube, 212);
        }
    }

    return ;
}

/* Cette fonction va placer les coins de la face jaune à leur place finale */
void yellow_corners_right_placement (miniCube cube[6][N][N], int p) {
    int pos1, pos2, pos3, pos4, n;

    /* La case rentrée en paramètre est la case qui devra se trouver à la fin
    * sur le mini cube composé des cases 11, 26 et 36
    */
    pos4 = recherche_case(cube, p);

    /* on cherche les position des angles en fonction de la case rentrée en
    * paramètre
    */
    switch(p) {
        case 400:
            pos1 = recherche_case(cube, 402);
            pos2 = recherche_case(cube, 422);
            pos3 = recherche_case(cube, 420);
        break;
        case 420:
            pos1 = recherche_case(cube, 400);
            pos2 = recherche_case(cube, 402);
            pos3 = recherche_case(cube, 422);
        break;
        case 422:
            pos1 = recherche_case(cube, 420);
            pos2 = recherche_case(cube, 400);
            pos3 = recherche_case(cube, 402);
        break;
        case 402:
            pos1 = recherche_case(cube, 422);
            pos2 = recherche_case(cube, 420);
            pos3 = recherche_case(cube, 400);
        break;
        }

    /* si la case rentrée se trouve déjà sur le mini cube qui se trouve en haut
    * à droite de la face de devant alors on va réaliser la fonction
    * yellow_corners_placement jusqu'à ce que la case se retrouve sur le mini
    * cube
    */
    if (pos4 == 11 || pos4 == 26 || pos4 == 36) {
        n = 0;

        while ((n < 3) && (pos1 != 9 && pos1 != 2 && pos1 != 24)) {
            yellow_corners_placement(cube);
            switch(p) {
                case 400:
                    pos1 = recherche_case(cube, 402);
                    pos2 = recherche_case(cube, 422);
                    pos3 = recherche_case(cube, 420);
                break;
                case 420:
                    pos1 = recherche_case(cube, 400);
                    pos2 = recherche_case(cube, 402);
                    pos3 = recherche_case(cube, 422);
                break;
                case 422:
                    pos1 = recherche_case(cube, 420);
                    pos2 = recherche_case(cube, 400);
                    pos3 = recherche_case(cube, 402);
                break;
                case 402:
                    pos1 = recherche_case(cube, 422);
                    pos2 = recherche_case(cube, 420);
                    pos3 = recherche_case(cube, 400);
                break;
            }
            n = n + 1;
        }
    }

    else {
        /* Si la case se trouve sur un des autres angles, on tourne le cube et
        * on fait un appel récursif de la fonction
        */
        if (pos1 == 2 || pos1 == 9 || pos1 == 24) {
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            yellow_corners_right_placement(cube, 402);
        }
        else if (pos2 == 0 || pos2 == 18 || pos2 ==47) {
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            yellow_corners_right_placement(cube, 422);
        }
        else if (pos3 == 20 || pos3 == 38 || pos3 ==45) {
            cube_rotation_side(cube);
            yellow_corners_right_placement(cube, 420);
        }
        else {
            yellow_corners_placement(cube);
            yellow_corners_right_placement(cube, 400);
        }
    }

    return ;
}

/* Cette fontion oriente les angles de la face jaune pour finir le cube */
void yellow_corners_right_orientation (miniCube cube[6][N][N], int p) {
    int pos1, pos2, pos3, pos4, n;

    pos4 = recherche_case(cube, p);
    n = 0;

    /* On cherche la postion des angles jaunes en fonction de l'angle rentré
    * en paramètre
    */
    switch(p) {
        case 400:
            pos1 = recherche_case(cube, 402);
            pos2 = recherche_case(cube, 422);
            pos3 = recherche_case(cube, 420);
        break;
        case 420:
            pos1 = recherche_case(cube, 400);
            pos2 = recherche_case(cube, 402);
            pos3 = recherche_case(cube, 422);
        break;
        case 422:
            pos1 = recherche_case(cube, 420);
            pos2 = recherche_case(cube, 400);
            pos3 = recherche_case(cube, 402);
        break;
        case 402:
            pos1 = recherche_case(cube, 422);
            pos2 = recherche_case(cube, 420);
            pos3 = recherche_case(cube, 400);
        break;
    }

    /* Si aucun angle est placé, on réalise la fonction
    * yellow_corners_orientation puis on fait un appel récursif de la fonction
    */
    if (pos1 != 24 && pos2 != 18 && pos3 != 20 && pos4 != 26) {
        yellow_corners_orientation(cube);
        yellow_corners_right_orientation(cube, p);
    }

    /* Sinon, on tourne le cube jusqu'à ce qu'il y ai un angle bien placé qui se
    * trouve sur la case 24, c'est-à-dire la case en bas à gauche de la face
    * du dessus et on fait un appel récursif de la fonction
    */
    else if (pos1 != 24) {
        while (n < 3 && (pos4 != 24 && pos2 != 24 && pos3 != 24)) {
            cube_rotation_side(cube);
            switch(p) {
                case 400:
                    pos1 = recherche_case(cube, 402);
                    pos2 = recherche_case(cube, 422);
                    pos3 = recherche_case(cube, 420);
                    pos4 = recherche_case(cube, 400);
                break;
                case 420:
                    pos1 = recherche_case(cube, 400);
                    pos2 = recherche_case(cube, 402);
                    pos3 = recherche_case(cube, 422);
                    pos4 = recherche_case(cube, 420);
                break;
                case 422:
                    pos1 = recherche_case(cube, 420);
                    pos2 = recherche_case(cube, 400);
                    pos3 = recherche_case(cube, 402);
                    pos4 = recherche_case(cube, 422);
                break;
                case 402:
                    pos1 = recherche_case(cube, 422);
                    pos2 = recherche_case(cube, 420);
                    pos3 = recherche_case(cube, 400);
                    pos4 = recherche_case(cube, 402);
                break;
            }
            n = n + 1;
        }
        /* En fonction du nombre de rotation du cube effectué, on définit la
        * case que l'on rentrera en paramètre
        */
        switch(n) {
            case 1:
                p = 420;
            break;
            case 2:
                p = 422;
            break;
            case 3:
                p = 402;
            break;
        }
        yellow_corners_right_orientation(cube, p);
    }

    /* Si il y a un angle jaune bien placé qui se trouve sur la case 24, et
    * que l'angle à sa droite n'est pas bien placé, alors on réalise la
    * fonction yellow_corners_orientation et on fait un appel récursif de la
    * fonction
    */
    if (pos1 == 24 && pos4 != 26) {
        yellow_corners_orientation(cube);
        yellow_corners_right_orientation(cube, p);
    }

    /* Si il y a un angle jaune bien placé sur la case 24 et sur la case 26, et
    * que l'angle sur la case 20 n'est pas bien placé, on tourne le cube et on
    * fait un appel récursif de la fonction
    */
    if (pos1 == 24 && pos4 == 26 && pos3 != 20) {
        cube_rotation_side(cube);
        yellow_corners_orientation(cube);
        switch(p) {
            case 400:
                p = 420;
            break;
            case 420:
                p = 422;
            break;
            case 422:
                p = 402;
            break;
            case 402:
                p = 400;
            break;
        }
        yellow_corners_right_orientation(cube, p);
    }

    return;
} 

/* Cette fonction résout le RubiksCube */
void resolution_mecanique (miniCube cube[6][N][N]) {
    int pos;
    pos = recherche_case(cube, 11);

    /* On commence par placer la face blanche sur la face de devant */
    white_center_placement(cube);

    /* On positionne la croix blanche */
    white_cross(cube);

    /* On positionne la face blanche sur la face de dessus et on place ces
    * coins pour la finir
    */
    cube_rotation_upside_down(cube);
    white_face(cube);

    /* On réalise la seconde ligne du cube */
    second_line(cube);

    /* On place la face jaune sur la face du dessus */
    cube_rotation_upside_down(cube);
    cube_rotation_upside_down(cube);

    /* On crée la croix jaune */
    yellow_cross(cube);

    /* On oriente la croix jaune */
    yellow_cross_right_orientation(cube, 212);

    /* On place la face orange sur la face de devant */
    pos = recherche_case(cube, 211);

    while (pos != 13) {
        cube_rotation_side(cube);
        pos = recherche_case(cube, 211);
    }

    /* On place les angles de la face jaune */
    yellow_corners_right_placement(cube, 400);

    /* On place la face orange sur la face de devant */
    pos = recherche_case(cube, 211);

    while (pos != 13) {
        cube_rotation_side(cube);
        pos = recherche_case(cube, 211);
    }

    /* On oriente les angles jaunes pour finir le cube */
    yellow_corners_right_orientation(cube, 400);

    /* On replace la face orange sur la face de devant */
    while (recherche_case(cube, 211) != 13) {
        cube_rotation_side(cube);
    }

    /* On place la face blanche sur la face de devant */
    cube_rotation_upside_down(cube);

    /* On place la face bleu sur la face de devant pour avoir le même schéma
    * que pour la résolution optimisée */
    cubeRotation(cube, "Y");
}
