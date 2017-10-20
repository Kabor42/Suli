#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <math.h>

typedef struct PONT {
    double x, y;
} PONT;

double len(PONT a, PONT b) {
    return sqrt(pow(2,a.x-b.x)+pow(2,a.y-b.y));
}

int main() {
    const double eps = 25;
    const int L1 = 200;
    const int L2 = 250;
    const int L3 = 100;

    SDL_Event ev;
    SDL_Surface *screen;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(640, 480, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL program", "SDL program");

    PONT act, A, B1, B2, C1, C2, D1;
    A.x = 320; A.y = 240;
    B1.x = 240; B1.y = 200;
    B2.x = 400; B2.y = 280;
    C1.x = 240; C1.y = 240;
    C2.x = 400; C2.y = 240;
    D1.x = 320; D1.y = 240;

    double l_a = 0;
    double l_b = 0;

    for (int i=0; i<640; i++) {
        for (int j=0; j<480; j++){
            act.x = i; act.y = 480-j;

            l_a = len(act,A);
            if (l_a <= L1+eps && l_a >= L1-eps)
                pixelRGBA(screen, i, j, 255, 0, 0, 255);

            l_a = len(act,B1);
            l_b = len(act,B2);
            if (l_a <= L2+eps && l_a >= L2-eps)
                if (l_b < L2+eps && l_b > L2-eps)
                    pixelRGBA(screen, i, j, 0, 255, 0, 255);

            l_a = len(act,C1);
            l_b = len(act,C2);
            if (fabs(l_a-l_b) <= L3+eps && fabs(l_a-l_b) >= L3-eps)
                pixelRGBA(screen, i, j, 0, 0, 255, 255);

            l_a = len(act,D1);
            l_b = fabs(act.x - 400);
            if (l_a <= l_b+eps && l_a >= l_b-eps)
                pixelRGBA(screen, i, j, 255, 255, 255, 255);

        }
    }
    SDL_Flip(screen);

    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }

    SDL_Quit();

    return 0;
}
