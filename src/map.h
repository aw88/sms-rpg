#ifndef __MAP_H
#define __MAP_H

#include "graphics.h"
#include "player.h"
#include "SMSlib.h"

#define MAP_WIDTH           16
#define MAP_HEIGHT          12
#define MAP_SIZE            (MAP_WIDTH * MAP_HEIGHT)

typedef struct _warp_point {
  char tile_x;
  char tile_y;

  char* target_map;
  char target_x;
  char target_y;
} _warp_point;

void init_map();
void _draw_map_row(char row_number);
void draw_map();
char lookup_tile(char tile_x, char tile_y);
_warp_point *find_warp_point(char tile_x, char tile_y);
void handle_warp_point(_player *player, _warp_point *warp_point);

#endif
