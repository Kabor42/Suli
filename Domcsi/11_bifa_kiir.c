#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void bifa_kiir( BiFa *root){
    if( root == NULL)
        return;

    bifa_kiir( root->bal);
    printf("%d ", root->ertek);
    bifa_kiir( root->jobb);
}

void bifa_torol( BiFa *root){
    if(root==NULL)
        return;
    if(root->bal!=NULL)
        bifa_torol(root->bal);
    if(root->jobb!=NULL)
        bifa_torol(root->jobb);
    free(root);
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    int i;
    for (i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */
    bifa_kiir(gyoker);
    printf("\n");
    bifa_torol(gyoker);

    return 0;
}
