#ifndef __MAP_H
#define __MAP_H

#include "SMSlib.h"

#define MAP_WIDTH  16
#define MAP_HEIGHT 12
#define MAP_SIZE   (MAP_WIDTH * MAP_HEIGHT)

void init_map();
void _draw_map_row(char row_number);
void draw_map();
char lookup_tile(char tile_x, char tile_y);

#endif
