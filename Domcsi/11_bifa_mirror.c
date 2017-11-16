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

int bifa_elemszam(BiFa *root){
    if (root == NULL)
        return 0;
    return( 1 + bifa_elemszam(root->bal) + bifa_elemszam(root->jobb));
}

int bifa_oszeg(BiFa *root){
    if ( root == NULL)
        return 0;
    return ( root->ertek + bifa_oszeg(root->bal) + bifa_oszeg(root->jobb));
}

void mirror(BiFa *node){
    if ( node == NULL)
        return;
    BiFa *tmp;

    mirror(node->bal);
    mirror(node->jobb);
    tmp = node->bal;
    node->bal = node->jobb;
    node->jobb = tmp;
}

BiFa *keres(BiFa *node, int ertek){
    if ( node == NULL )
        return NULL;

    if ( node->ertek == ertek){
        return node;
    } else if (node->ertek < ertek){
        return keres(node->bal, ertek);
    } else {
        return keres(node->jobb, ertek);
    }
}


int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    BiFa *keresett = NULL;
    int i;
    for (i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */
    bifa_kiir(gyoker);
    printf("\n");
    printf("A fa elemeinek szama: %d\n"
            "A fa elemeinek osszege %d\n",
            bifa_elemszam( gyoker),
            bifa_oszeg( gyoker)
          );
    bifa_kiir( gyoker);
    printf("\n");
    mirror( gyoker);
    keresett = keres( gyoker, 56);
    if ( keresett != NULL)
        printf("A keresett szam [[%d]] benne van a faban\n", 56);
    else
        printf("A keresett szam [[%d]] nincs a faban \n", 56);
    bifa_torol(gyoker);

    return 0;
}
