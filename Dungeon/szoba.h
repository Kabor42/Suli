/* 
 * File:   szoba.h
 * Author: kabor
 *
 * Created on October 26, 2017, 5:52 PM
 */

#ifndef SZOBA_H
#define SZOBA_H

#include <stdio.h>
#include <stdlib.h>

typedef enum SZOBAELEM {
    URES = 0,
    FAL,
    B_F_SAR,
    B_A_SAR,
    J_F_SAR,
    J_A_SAR,
    H_FAL,
    V_FAL
} SZOBAELEM;

typedef struct SZOBA{

    int sor;
    int osl;
    char leiras[1000];
    SZOBAELEM **alaprajz;

} SZOBA;

void szoba_kiir( SZOBA *sz);
SZOBA *uj_szoba(int sor, int oszlop, char *desc);
void szoba_ment(SZOBA *sz, char *file);
SZOBA *szoba_olvas(char *f_name);
void sz_free(SZOBA *sz);

#endif /* SZOBA_H */

