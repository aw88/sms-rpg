#ifndef __MAP_H
#define __MAP_H

#include "graphics.h"
#include "player.h"
#include "SMSlib.h"

#define MAP_WIDTH           16
#define MAP_HEIGHT          12
#define MAP_SIZE            (MAP_WIDTH * MAP_HEIGHT)

#define WARP_POINT_X(pos)   (pos >> 4)
#define WARP_POINT_Y(pos)   (pos & 0x0f)
#define MAKE_WARP_POS(x, y) (((((x) & 0x0f) << 4) | ((y) & 0x0f)) & 0xff)

typedef struct _warp_point {
  char tile_pos;
  char target_pos;

  char* target_map;
} _warp_point;

void init_map();
void _draw_map_row(char row_number);
void draw_map();
char lookup_tile(char tile_x, char tile_y);
_warp_point *find_warp_point(char tile_x, char tile_y);
void handle_warp_point(_player *player, _warp_point *warp_point);

#endif
