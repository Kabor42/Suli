#include "curse.h"

#include "debugmalloc.h"

int main() {

    // Initialize nCurses
    initscr();
    raw();
    keypad(stdscr, FALSE);
    noecho();
    cbreak();
    border(
            ACS_VLINE,
            ACS_VLINE,
            ACS_HLINE,
            ACS_HLINE,
            ACS_ULCORNER,
            ACS_URCORNER,
            ACS_LLCORNER,
            ACS_LRCORNER
    );
    refresh();

    char *passwd = nGetPasswd();
    Rekord *root = NULL;

    root = readFromFile("mentes.txt");

    run(root);

    endwin();

    fprintf(stderr, "Password: %s\n", passwd);

    free(passwd);
    freeLinkedList(root);


    return 0;
}
