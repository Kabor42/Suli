#include "curse.h"

myWin *createWindow(
        int rows,
        int cols,
        bool border,
        char *title,
        ALIGN pos
) {
    myWin *new = (myWin *) malloc(sizeof(myWin));
    int winX, winY;
    getmaxyx(stdscr, winY, winX);

    new->row = rows;
    new->col = cols;

    switch (pos) {
        case NO:
            new->y = 1;
            new->x = (winX / 2) - (new->col / 2);
            break;
        case NE:
            new->y = 1;
            new->x = (winX - (new->col + 1));
            break;
        case NW:
            new->y = 1;
            new->x = 1;
            break;
        case EA:
            new->y = (winY / 2) - (new->row / 2);
            new->x = winX - (new->col + 1);
            break;
        case WE:
            new->y = (winY / 2) - (new->row / 2);
            new->x = 1;
            break;
        case SE:
            new->y = (winY - (new->row + 1));
            new->x = (winX - (new->col + 1));
            break;
        case SW:
            new->y = (winY - (new->row + 1));
            new->x = 1;
            break;
        case SO:
            new->y = (winY - (new->row + 1));
            new->x = (winX / 2) - (new->col / 2);
            break;
        case CENTER:
            new->y = (winY / 2) - (new->row / 2);
            new->x = (winX / 2) - (new->col / 2);
            break;
        case FULL:
            new->y = 1;
            new->x = 1;
            break;
        default:
            new->y = 1;
            new->x = 1;
            break;
    }
    new->win = newwin(
            new->row,
            new->col,
            new->y,
            new->x
    );
    if(title != NULL) {
      mvwprintw( new->win, 1, 1, "%s", title);
      wmove( new->win, 2, 1);
      whline( new->win, ACS_HLINE, new->col - 2);
    }
    if (border)
        wborder(
                new->win,
                ACS_VLINE,
                ACS_VLINE,
                ACS_HLINE,
                ACS_HLINE,
                ACS_ULCORNER,
                ACS_URCORNER,
                ACS_LLCORNER,
                ACS_LRCORNER
        );

    return new;
}

void deleteWindow(myWin *win) {
    for (int y = 0; y < win->row; y++) {
        for (int x = 0; x < win->col; x++) {
            mvwaddch(win->win, y, x, ' ');
        }
    }
    wrefresh(win->win);
    delwin(win->win);
}

myWin *createCal(Rekord *this) {
    char napok[7][3] = {"H", "K", "SZ", "CS", "P", "SZ", "V"};
    char title[5];
    snprintf(title, 5, "%d", this->date->ev);
    myWin *cal = createWindow(10, 23, true, title, NE);

    int offset = getDayOfTheWeek(this->date);
    for (int i = 0; i < 7; i++)
        mvwprintw(cal->win, 3, 2 + (i * 3), "%-s", napok[i]);

    const int *arr = (szokoev(this->date->ev)) ? szhon : hon;
    for (int i = 1, col = offset, row = 4; i < arr[this->date->ho - 1]; i++, col += 3) {
        if (col >= cal->col - 1) {
            col = 2;
            row++;
        }
        if (i == this->date->nap) {
            wattron(cal->win, A_STANDOUT);
            mvwprintw(cal->win, row, col, "%02d", i);
            wattroff(cal->win, A_STANDOUT);
        } else
            mvwprintw(cal->win, row, col, "%02d", i);
    }
    wrefresh(cal->win);
    return cal;
}

Rekord *newRecord() {
    myWin *new = createWindow(9, 40, true, "Uj esemeny",  SE);
    char buff[1024];

    mvwprintw(new->win, 3, 1, "Esemeny:");
    mvwprintw(new->win, 4, 1, "Helyszin:");
    mvwprintw(new->win, 5, 1, "Megjegyzes:");
    mvwprintw(new->win, 6, 1, "Datum:    .  .  .");
    mvwprintw(new->win, 7, 1, "Idopont:  :  ");

    keypad(stdscr, FALSE);
    keypad(new->win, TRUE);
    curs_set(1);
    echo();
    wrefresh(new->win);

    Rekord *rec = (Rekord *) malloc(sizeof(Rekord));
    Datum *date = (Datum *) malloc(sizeof(Datum));

    rec->ID = newID();

    wmove(new->win, 3, 11);
    wgetstr(new->win, buff);
    rec->esemeny = (char *) malloc(sizeof(char) * (sizeof(buff) + 1));
    strcpy(rec->esemeny, buff);

    wmove(new->win, 4, 11);
    wgetstr(new->win, buff);
    rec->hely = (char *) malloc(sizeof(char) * (sizeof(buff) + 1));
    strcpy(rec->hely, buff);

    wmove(new->win, 5, 13);
    wgetstr(new->win, buff);
    rec->megj = (char *) malloc(sizeof(char) * (sizeof(buff) + 1));
    strcpy(rec->megj, buff);

    mvwscanw(new->win, 6, 7, "%d", date->ev);
    mvwscanw(new->win, 6, 12, "%d", date->ho);
    mvwscanw(new->win, 6, 15, "%d", date->nap);
    mvwscanw(new->win, 7, 11, "%d", date->ora);
    mvwscanw(new->win, 7, 14, "%d", date->perc);

    keypad(new->win, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    rec->date = date;
    rec->kov = NULL;

    deleteWindow(new);

    return rec;
}

char *nGetPasswd() {
    myWin *this = createWindow(5, 20, true, "Jelszo:", CENTER);

    char *pass = (char *) malloc(sizeof(char) * (16));

    mvwprintw(this->win, 3, 1, "$> ");
    wmove(this->win, 3, 4);

    keypad(stdscr, FALSE);
    keypad(this->win, TRUE);
    curs_set(1);
    echo();
    wrefresh(this->win);

    int ch, i = 0;
    while ((ch = wgetch(this->win)) != 10) {
        if (i > 15)
            break;
        mvwaddch(this->win, 3, 4 + i, '*');
        wrefresh(this->win);
        pass[i++] = ch;
    }
    pass[i] = '\0';

    pass = realloc(pass, sizeof(char) * (strlen(pass) + 1));

    keypad(this->win, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    deleteWindow(this);
    return pass;
}

Rekord *addRecord(Rekord *root, Rekord *new) {
    Rekord *prev = NULL, *tmp = root;
    while (tmp != NULL && datumOsszehas(*(tmp->date), *(new->date)) < 0) {
        prev = tmp;
        tmp = tmp->kov;
    }
    if (prev == NULL) {
        new->kov = root;
        root = new;
    } else {
        prev->kov = new;
        new->kov = tmp;
    }
    return root;
}

void nKiir(Rekord *this) {
    myWin *out = createWindow( 10, 54, true, "Esemeny:", NW);

    mvwprintw(out->win, 3, 1, "Esemeny: %s", this->esemeny);
    mvwprintw(out->win, 4, 1, "Helyszin: %s", this->hely);
    mvwprintw(out->win, 5, 1, "Megjegyzes: %s", this->megj);
    mvwprintw(out->win, 6, 1, "Datum: %4d.%2d.%2d", this->date->ev, this->date->ho, this->date->nap);
    mvwprintw(out->win, 7, 10, "%02d:%02d", this->date->ora, this->date->perc);
    wrefresh(out->win);

    int ch;
    keypad(stdscr, FALSE);
    keypad(out->win, TRUE);
    noecho();
    curs_set(1);
    wmove(out->win, out->row - 1, out->col - 1);
    while ((ch = wgetch(out->win)) != 10) {}
    keypad(out->win, FALSE);
    keypad(stdscr, TRUE);
    deleteWindow(out);
}


void run(Rekord *root) {
    myWin *cal;
    Rekord *new = NULL;
    int quit = false;
    while (!quit) {
        menuItem choice = nMenu();

        switch (choice) {
            case UJ:
                new = newRecord();
                root = addRecord(root, new);
                break;
            case MODOSIT:
                break;
            case TORLES:
                break;
            case LISTA:
                cal = createCal(root);
                nKiir(root);
                deleteWindow(cal);
                break;
            case KERES:
                break;
            case MENT:
                break;
            case KILEP:
                quit = true;
                break;
            default:
                break;
        }
    }
}

menuItem nMenu() {
    char list[7][10] = {
            "Uj rekord",
            "Modositas",
            "Torles",
            "Listazas",
            "Kereses",
            "Mentes",
            "Kilep"
    };

    int choice = 0;
    myWin *menu = createWindow(12, 20, false, "HATARIDONAPLO", CENTER);


    for (int i = 0; i < 7; i++) {
        if (choice == i)
            wattron(menu->win, A_STANDOUT);
        else
            wattroff(menu->win, A_STANDOUT);
        mvwprintw(menu->win, 4 + i, 3, "%s", list[i]);
    }

    noecho();
    keypad(menu->win, TRUE);
    curs_set(0);
    wrefresh( menu->win);

    int ch;
    while ((ch = wgetch(menu->win)) != 'q') {
        mvwprintw(menu->win, 4 + choice, 3, "%s", list[choice]);
        switch (ch) {
            case KEY_UP:
                choice--;
                choice = (choice < 0) ? 6 : choice;
                break;
            case KEY_DOWN:
                choice++;
                choice = (choice > 6) ? 0 : choice;
                break;
            case 10:
                return choice;
                break;
            default:
                mvwprintw(menu->win, 0, 0, "%d", ch);
                break;
        }
        wattron(menu->win, A_STANDOUT);
        mvwprintw(menu->win, 4 + choice, 3, "%s", list[choice]);
        wattroff(menu->win, A_STANDOUT);
        wrefresh( menu->win);
    }
    deleteWindow(menu);
    return (menuItem) choice;
}
