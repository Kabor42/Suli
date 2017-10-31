#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "szoba.h"

void szoba_kiir(SZOBA *sz) {

    printf("%s\n\n", sz->leiras);

    for (int i = 0; i < sz->sor; i++){
        for (int j = 0; j < sz->osl; j++)
            switch(sz->alaprajz[i][j]){
                case URES:
                    printf(" ");
                    break;
                case FAL:
                    printf("#");
                    break;
                case B_F_SAR:
                    printf("╔");
                    break;
                case B_A_SAR:
                    printf("╚");
                    break;
                case J_F_SAR:
                    printf("╗");
                    break;
                case J_A_SAR:
                    printf("╝");
                    break;
                case H_FAL:
                    printf("║");
                    break;
                case V_FAL:
                    printf("═");
                    break;
            }
        printf("\n");
    }
}

SZOBA *uj_szoba(int sor, int oszlop, char *desc) {
    SZOBA *sz = (SZOBA *) malloc(sizeof(SZOBA));
    if (sz == NULL){
        fprintf(stderr, "[Uj szoba] - Not enough memory for allocation!\n");
        return NULL;
    }

    int s = sor-1;
    int o = oszlop-1;

    sz->sor = sor;
    sz->osl = oszlop;

    if (strlen(desc)+1 > 1000){
        fprintf(stderr,"[Uj szoba][desc] - Too long description!\n");
        return NULL;
    }

    strcpy(sz->leiras, desc);

    SZOBAELEM **elem;
    elem = malloc(sizeof(*elem) * sor);
    for (int i=0;i<sor;i++)
        elem[i] = malloc(sizeof(elem) * oszlop);

    for (int i = 0; i < sor; i++)
        for (int j = 0; j < oszlop; j++) {
            if ( i==0 && j==0)
                elem[i][j] = B_F_SAR;
            else if ( i==0 && j==o)
                elem[i][j] = J_F_SAR;
            else if ( i==s && j==0)
                elem[i][j] = B_A_SAR;
            else if ( i==s && j==o)
                elem[i][j] = J_A_SAR;
            else if ( i==0 || i==s)
                elem[i][j] = V_FAL;
            else if ( j==0 || j==o)
                elem[i][j] = H_FAL;
            else
                elem[i][j] = URES;
        }
    sz->alaprajz = elem;
    return sz;
}

void szoba_ment(SZOBA *sz, char *f_name) {
    FILE *fp;
    fp = fopen(f_name, "w+");
    if (fp == NULL){
        fprintf(stderr,"[szoba_ment] - File %s, could'n be opened!\n", f_name);
        return;
    }

    fprintf( fp, "%s\n", sz->leiras);
    fprintf( fp, "%dx%d\n", sz->sor, sz->osl);
    for (int i=0;i<sz->sor;i++)
        for(int j=0;j<sz->osl;j++)
            fprintf( fp, "%u,", sz->alaprajz[i][j]);
    fprintf( fp, "\n");

    fclose(fp);
}

SZOBA *szoba_olvas(char *f_name){
    FILE *fp = fopen(f_name,"r");
    if (fp == NULL){
        fprintf(stderr,"[szoba_olvas] - File %s doesn't exists!\n", f_name);
        return NULL;
    }

    SZOBA *sz;
    sz = (SZOBA *) malloc(sizeof(SZOBA));
    if (sz == NULL){
        printf("Couldn't allocate more memory!\n");
        return NULL;
    }
    char c[1000];
    int p;
    int s, o;

    fscanf( fp, "%[^\n]", c);
    strcpy(sz->leiras,c);

    fscanf( fp, "%dx%d", &s, &o);
    sz->sor = s;
    sz->osl = o;

    SZOBAELEM **elem;
    elem = malloc(sizeof(*elem) * s);
    for (int i=0;i<s;i++)
        elem[i] = malloc(sizeof(elem) * o);

    for(int i=0;i<s;i++){
        for(int j=0;j<o;j++){
            fscanf( fp, "%d,", &p);
            elem[i][j] = p;
        }
    }

    sz->alaprajz = elem;

    fclose(fp);
    return sz;
}

void sz_free(SZOBA *sz) {
    for(int i=0;i<sz->sor;i++)
        free(sz->alaprajz[i]);
    free(sz->alaprajz);
    free(sz);
    sz = NULL;
}
