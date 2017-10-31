#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>
#include "szoba.h"
#include "player.h"
#include "curs_libs.h"
#include "inventory.h"

#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif

int main(int argc, char **argv){

#if defined(WIN32) || defined(_WIN32)
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
#endif

    setlocale(LC_ALL,"");

    SZOBA *p_sz;
    PLAYER *player;
    
    p_sz = szoba_olvas( "dungeon.szoba" );
    player = new_player("Kabor", MALE, 18);

    inv_add_item( player->inv, "deer hide", 1.2, 2, 20, 2);
    inv_add_item( player->inv, "wolf pelt", 0.8, 1, 12, 5);
    inv_add_item( player->inv, "virgin's blood", 0.1, 0, 50, 112);
    
    
    initscr();
    cbreak();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_RED, COLOR_WHITE);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

    WINDOW *map = create_win( 0, 0, 14, 25);
    WINDOW *desc = create_win( 0, 14, 8, 80);
    WINDOW *player_info = create_win( 25, 0, 14, 25);
    WINDOW *inventory = create_win( 50, 0, 14, 30);
    WINDOW *interaction = create_win ( 0, 22, 3, 80);
    
    keypad(interaction, TRUE);
    noecho();
    wmove( interaction, 1, 1);

    refresh();
    wrefresh( map );
    wrefresh( desc );
    wrefresh( player_info );
    wrefresh( inventory );
    wrefresh( interaction );

    w_map_win( map, p_sz );
    w_desc_win( desc, p_sz );
    w_player_win( player_info, player);
    w_inv_win( inventory, player);

    refresh();
    
    int ch;
    while(1) {
        ch = wgetch( interaction );
        switch(ch){
            case 'n':
            case KEY_UP:
                move_p( map, player, NORTH);
                break;
            case 's':
            case KEY_DOWN:
                move_p( map, player, SOUTH);
                break;
            case 'e':
            case KEY_RIGHT:
                move_p( map, player, EAST);
                break;
            case 'w':
            case KEY_LEFT:
                move_p( map, player, WEST);
                break;
            default:
                break;
        }
        if (ch == 'q' || ch == 'Q' || ch == 27)
            break;
        w_map_win( map, p_sz );
        mvwaddch( map, player->y, player->x, '@');
        wrefresh( map );
        attron(COLOR_PAIR(4));
        mvwprintw( interaction, 1, 1, "%03d", ch);
        attroff(COLOR_PAIR(4));
        wrefresh( interaction );
        w_player_win( player_info, player);
    }
    

    destroy_win( map );
    destroy_win( desc );
    destroy_win( player_info );
    destroy_win( inventory );
    destroy_win( interaction );
    refresh();

    endwin();
    sz_free(p_sz);
    destroy_player(player);

    return (EXIT_SUCCESS);
}
