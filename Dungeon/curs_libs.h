/* 
 * File:   curs_libs.h
 * Author: kabor
 *
 * Created on October 26, 2017, 5:50 PM
 */

#ifndef CURS_LIBS_H
#define CURS_LIBS_H

#include <ncurses.h>
#include <stdio.h>
#include "szoba.h"
#include "player.h"

void w_hline( WINDOW *win, int pos);
WINDOW *create_win( int x, int y, int height, int width );
void destroy_win( WINDOW *local );
void w_map_win( WINDOW *win, SZOBA *sz );
void w_desc_win( WINDOW *win, SZOBA *sz);
void w_player_win( WINDOW *win, PLAYER *player);
void w_inv_win(WINDOW *win, PLAYER *p);
void move_p( WINDOW *win, PLAYER *p, DIRECTION dir);

#endif /* CURS_LIBS_H */

