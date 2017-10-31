#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "szoba.h"
#include "curs_libs.h"
#include "player.h"

void w_hline( WINDOW *win, int pos){
    int x, y;
    char ch;
    getmaxyx( win, y, x);
    for( int i=0;i<x;i++){
        ch = '-';
        if ( i == 0 || i == x-1){
            ch = '+';
        }
        mvwaddch( win, pos, i, ch);
    }
}

WINDOW *create_win( int x, int y, int height, int width ){
    WINDOW *local;
    local = newwin( height, width, y, x );
    /** wborder( local, '|', '|', '-', '-', '+', '+', '+', '+'); */
    wborder(
            local,
            ACS_VLINE,
            ACS_VLINE,
            ACS_HLINE,
            ACS_HLINE,
            ACS_ULCORNER,
            ACS_URCORNER,
            ACS_LLCORNER,
            ACS_LRCORNER
            );
    return local;
}

void destroy_win( WINDOW *local ){
    wborder( local, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local);
    delwin(local);
    refresh();
}

void w_map_win( WINDOW *win, SZOBA *sz ){
  int xMax, yMax, xstart, ystart;
  getmaxyx( win, yMax, xMax);
  xstart = xMax/2 - sz->osl/2;
  ystart = yMax/2 - sz->sor/2;

    for(int i=0;i<sz->sor;i++)
        for(int j=0;j<sz->osl;j++){
            char ch;
            switch(sz->alaprajz[i][j]) {
             case URES:
                    ch = '.';
                    break;
                case FAL:
                    ch = '#';
                    break;
                case B_F_SAR:
                    ch  = '+';
                    break;
                case B_A_SAR:
                    ch = '+';
                    break;
                case J_F_SAR:
                    ch = '+';
                    break;
                case J_A_SAR:
                    ch = '+';
                    break;
                case H_FAL:
                    ch = '|';
                    break;
                case V_FAL:
                    ch = '-';
                    break;
            }
            mvwaddch( win, ystart+i , xstart+j , ch);
        }
    refresh();
    wrefresh( win );
}

void w_desc_win( WINDOW *win, SZOBA *sz ){
    attron(COLOR_PAIR(4));
    mvwaddstr( win, 1, 1, sz->leiras );
    attroff(COLOR_PAIR(4));
    refresh();
    wrefresh( win );
}

void w_player_win( WINDOW *win, PLAYER *player) {
    int x,y;
    getmaxyx( win, y, x);
    attron(COLOR_PAIR(6));mvwprintw( win, 1, 1, "Name: %s", player->name);attroff(COLOR_PAIR(6));
    mvwprintw( win, 2, 1, "Age: %d", player->age);   
    attron(COLOR_PAIR(7));mvwprintw( win, 3, 1, "Sex: %s", print_sex(player->sex));attroff(COLOR_PAIR(7));
    mvwprintw( win, 4, 1, "Equipped:");
    mvwprintw( win, 5, 4, "[MOD]");
    mvwprintw( win, 5, 10, "[CLASS]");
    mvwprintw( win, 5, x-6, "[DMG]");
    mvwprintw( win, 6, 4, "%s ", print_mod(player->inv->weapon->modifier));
        wprintw( win, "%s", player->inv->weapon->name);
        attron(COLOR_PAIR(1));mvwprintw( win, 6, x-5, " %-3g", player->inv->weapon->dmg);attroff(COLOR_PAIR(1));
    mvwprintw( win, 7, 4, "%s ", print_mod(player->inv->armor->modifier));
        wprintw( win, "%s", player->inv->armor->name);
        attron(COLOR_PAIR(3));mvwprintw( win, 7, x-5,  " %-3g", player->inv->armor->def);attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(6));
        mvwprintw( win, 9, 3, "[STR] %2d [DEX] %2d", player->strength, player->dexterity);
        mvwprintw( win, 10, 3, "[AGL] %2d [LCK] %2d", player->agility, player->luck);
    attroff(COLOR_PAIR(6));
        
    attron(COLOR_PAIR(1));
    mvwprintw( win, 12, 5, "%3d", player->health);
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvwprintw( win, 12, 9, "%3d", player->magic);
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvwprintw( win, 12, 13, "%3d", player->stamina);
    attroff(COLOR_PAIR(3));
    
    wrefresh( win );
}

void w_inv_win(WINDOW *win, PLAYER *p){
    int x,y;
    getmaxyx( win, y, x);
    mvwprintw( win, 1, 1, "Inventory:");
    w_hline( win, 2);
    for (int i=0; i<p->inv->items;i++){
        mvwprintw( win, 3+i, 1, "%s", p->inv->bagitems[i]->name);
        mvwprintw( win, 3+i, x-6, "[%3d]", p->inv->bagitems[i]->quantity);
    }
    wrefresh( win );
}

void move_p( WINDOW *win, PLAYER *p, DIRECTION dir){
    bool move = false;
    int x = p->x, y = p->y;
    switch(dir){
        case NORTH:
            if (mvwinch( win, y-1, x) != '-') {
                p->y -= 1;
                move = true;
            }           
            break;
        case SOUTH:
            if (mvwinch( win, y+1, x) != '-'){
                p->y += 1;
                move = true;
            }
            break;
        case EAST:
            if (mvwinch( win, y, x+1) != '|'){
                p->x += 1;
                move = true;
            }
            break;
        case WEST:
            if (mvwinch( win, y, x-1) != '|'){
                p->x -= 1;
                move = true;
            }
            break;
        default:
            break;
    }
    (move)? p->stamina-- : p->stamina++;
}
