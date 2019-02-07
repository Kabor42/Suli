#include "stuff.h"

int IDcntr = 0;

const int hon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int szhon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void freeLinkedList(Rekord *root) {
    Rekord *tmp = root, *next = NULL;
    while (tmp != NULL) {
        next = tmp->kov;
        free(tmp);
        tmp = next;
    }
}

char *beolvas() {
    int i = 0;
    char *str = (char *) malloc(sizeof(char));
    char c;

    scanf("%c", &c);
    str[i++] = c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        str = realloc(str, ++i * sizeof(char));
        str[i - 1] = c;
    }
    str[i] = '\0';
    return str;
}

bool szokoev(int ev) {
    if (
            (ev % 4 == 0 &&
             ev % 100 != 0) ||
            ev % 400 == 0)
        return true;
    return false;
}


bool mentes(Rekord *root, char *fileName, char del) {
    FILE *fp = fopen(fileName, "w");       /**< Save file */
    if (fp == NULL) {                        /**< Checks for succesfull open */
        fclose(fp);
        fprintf(stderr, "A %s nem lehet megnyitni!", fileName);
        return false;
    }
    /* Writes rekord int format:
     * * ID
     * * esemeny
     * * megjegyzes
     * * helyszin
     * * Datum->ora
     * * Datum->perc
     * * Datum->nap
     * * Datum->ho
     * * Datum->ev
     */
    for (
            Rekord *tmp = root;
            tmp != NULL;
            tmp = tmp->kov
            ) {
        fprintf(fp, "%d%c%s%c%s%c%s%c%d%c%d%c%d%c%d%c%d%c\n",
                tmp->ID, del,
                tmp->esemeny, del,
                tmp->megj, del,
                tmp->hely, del,
                tmp->date->ora, del,
                tmp->date->perc, del,
                tmp->date->nap, del,
                tmp->date->ho, del,
                tmp->date->ev, del
        );
    }

    return true;
}


Rekord *torles(Rekord *root, int ID_rem) {
    Rekord *prev = NULL, *tmp;
    for (tmp = root;          /**< Finds ID in the list */
         tmp != NULL && tmp->ID != ID_rem;
         tmp = tmp->kov
            ) {
        prev = tmp;
    }

    if (prev == NULL) {            /**< If ID is the first */
        Rekord *new = tmp->kov;
        free(tmp);
        root = new;
    } else {                       /**< If ID is elsewhere */
        prev->kov = tmp->kov;
        free(tmp);
    }
    return root;
}

int getTimeVal(Datum d) {
    int retVal = 0;
    const int *arr = (szokoev(d.ev)) ? szhon : hon;
    for (int i = 0; i < d.ho - 1; i++) retVal += arr[i];
    retVal += d.nap;
    retVal *= 1440;
    retVal *= d.ev;
    retVal += 60 * d.ora;
    retVal += d.perc;

    return retVal;
}

int datumOsszehas(
        Datum d1,
        Datum d2
) {
    if (getTimeVal(d1) < getTimeVal(d2)) return -1;
    else if (getTimeVal(d1) > getTimeVal(d2)) return 1;
    else return 0;
}

int newID() {
    return IDcntr++;
}

int getDayOfTheWeek(Datum *d) {
    int day = d->nap;
    int m = d->ho;
    int y = d->ev;
    long long int julian;

    julian = day;
    julian += ((153 * (m - 12 * ((14 - m) / 12) - 3) + 2) / 5);
    julian += (365 * (y + 4800 - ((14 - m) / 12)));
    julian += ((y + 4800 - ((14 - m) / 12)) / 4);
    julian -= ((y + 4800 - ((14 - m) / 12)) / 100);
    julian += ((y + 4800 - ((14 - m) / 12)) / 400);
    julian -= 32045;
    return (int) 1 + julian % 7;
}

Rekord *readFromFile(char *fileName) {
    char buff[2048];
    const char del[2] = ";";
    char *token;
    Rekord *root = NULL;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        fclose(fp);
        fprintf(stderr, "Nem sikerult kinyitni %s!\n", fileName);
        return NULL;
    }
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        if (strlen(buff) < 10)
            break;
        Rekord *new = (Rekord *) malloc(sizeof(Rekord));
        Datum *date = (Datum *) malloc(sizeof(Datum));

        // ID
        token = strtok(buff, del);
        new->ID = (int) atoi(token);
        IDcntr++;

        // Esemeny
        token = strtok(NULL, del);
        new->esemeny = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(new->esemeny, token);
        // Megjegyzes
        token = strtok(NULL, del);
        new->megj = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(new->megj, token);

        // Helyszin
        token = strtok(NULL, del);
        new->hely = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(new->hely, token);

        // Perc
        token = strtok(NULL, del);
        date->perc = (int) atoi(token);
        // Ora
        token = strtok(NULL, del);
        date->ora = (int) atoi(token);
        // Nap
        token = strtok(NULL, del);
        date->nap = (int) atoi(token);
        // Honap
        token = strtok(NULL, del);
        date->ho = (int) atoi(token);
        // Ev
        token = strtok(NULL, del);
        date->ev = (int) atoi(token);

        new->date = date;
        new->kov = NULL;

        if (root == NULL)
            root = new;
        else {
            Rekord *tmp;
            for (tmp = root; tmp->kov != NULL; tmp = tmp->kov);
            tmp->kov = new;
        }
    }
    fclose(fp);
    return root;
}

