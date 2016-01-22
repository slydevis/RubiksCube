#include <SDL/SDL.h>
#include "display.h"
#include "file.h"
#include "rotations.h"

static int goContinue = 1;
static SDL_Surface* screen = NULL;

Uint32 getSDLColor(int color) {
    switch(color) {
        case COLOR_WHITE:
            return SDL_MapRGB(screen->format, 255, 255, 255);
        case COLOR_BLUE:
            return SDL_MapRGB(screen->format, 38, 18, 222);
        case COLOR_GREEN:
            return SDL_MapRGB(screen->format, 18, 222, 35);
        case COLOR_RED:
            return SDL_MapRGB(screen->format, 222, 18, 18);
        case COLOR_ORANGE:
            return SDL_MapRGB(screen->format, 222, 89, 18);
        case COLOR_YELLOW:
            return SDL_MapRGB(screen->format, 226, 245, 24);
        case COLOR_NONE:
        default:
            return 0;
    }
}

void changeFaceColor(int cube[6][N][N], int side, int i, int j, int color) {
    cube[side][i][j] = color;
}

SDL_Surface* createFace() {
    return SDL_CreateRGBSurface(SDL_HWSURFACE, FACE_SIZE, FACE_SIZE, 32, 0, 0, 0, 0);
}

void freeFace(SDL_Surface* screen) {
    SDL_FreeSurface(screen);
}

void printLeftSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printFrontSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printUpperSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) - (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printBottomSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) + (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printRightSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*2;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printBehindSide(int cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j];
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*3;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

typedef struct
{
    char key[SDLK_LAST];
} Input;

void keyboardEventManager(SDLKey key, int cube[6][N][N], Input* in) {
    switch (key) {
        case SDLK_s:
#ifdef DEBUG
            printf("S key pressed\n");
#endif /* DEBUG */
                saveCube(cube);
            break;
        case SDLK_l:
#ifdef DEBUG
            printf("L key pressed\n");
#endif /* DEBUG */
            if(in->key[SDLK_LCTRL] == 0)
                left_rotation(cube);
            else
                left_rotation_reverse(cube);
        break;
        case SDLK_r:
#ifdef DEBUG
            printf("R key pressed\n");
#endif /* DEBUG */
            if(in->key[SDLK_LCTRL] == 0)
                right_rotation(cube);
            else
                right_rotation_reverse(cube);
        break;
        case SDLK_u:
#ifdef DEBUG
            printf("U key pressed\n");
#endif /* DEBUG */
            if(in->key[SDLK_LCTRL] == 0)
                up_rotation(cube);
            else
                up_rotation_reverse(cube);
        break;
        case SDLK_d:
#ifdef DEBUG
            printf("D key pressed\n");
#endif /* DEBUG */
            if(in->key[SDLK_LCTRL] == 0)
                down_rotation(cube);
            else
                down_rotation_reverse(cube);
        break;
        case SDLK_f:
#ifdef DEBUG
            printf("D key pressed\n");
#endif /* DEBUG */
            if(in->key[SDLK_LCTRL] == 0)
                front_rotation(cube);
            else
                front_rotation_reverse(cube);
        break;
        default:
        break;
    }
}

void UpdateEvents(Input* in, int cube[6][N][N])
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {            case SDL_QUIT:
            goContinue = 0;
        break;
        case SDL_KEYDOWN:
            in->key[event.key.keysym.sym]=1;
            keyboardEventManager(event.key.keysym.sym, cube, in);
            break;
        case SDL_KEYUP:
            in->key[event.key.keysym.sym]=0;
            break;
        default:
            break;
        }
    }
}
void displayCube2D(int cube[6][N][N]) {
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Rubik's Cube", NULL);

    if(screen == NULL) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    Input in;
    // init SDL, chargement, tout ce que vous faites avant la boucle.
    memset(&in,0,sizeof(in));
    while(goContinue) {
//        SDL_WaitEvent(&event);
        UpdateEvents(&in, cube);
        /*        switch(event.type) {
            case SDL_QUIT:
                goContinue = 0;
            break;
            case SDL_KEYDOWN:
                keyboardEventManager(event.key.keysym.sym, cube);
            break;
        }
*/
        SDL_FillRect(screen, NULL, getSDLColor(COLOR_NONE));

        printLeftSide(cube[SIDE_LEFT]);
        printFrontSide(cube[SIDE_FRONT]);
        printUpperSide(cube[SIDE_UPPER]);
        printBottomSide(cube[SIDE_BOTTOM]);
        printRightSide(cube[SIDE_RIGHT]);
        printBehindSide(cube[SIDE_BEHIND]);

        /* Update screen */
        SDL_Flip(screen);
    }

        SDL_Quit();
}
