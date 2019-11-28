#include "map.h"

unsigned char map_tiles[MAP_SIZE] = {
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x05, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02,
};

unsigned char map_tiles_2[MAP_SIZE] = {
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02,
};

unsigned char map_tiles_3[MAP_SIZE] = {
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02,
};

_warp_point warp_points[] = {
  { .tile_pos = MAKE_WARP_POS(0x07, 0x00), .target_map = map_tiles_2, .target_pos = MAKE_WARP_POS(0x07, 0x0b) },
  { .tile_pos = MAKE_WARP_POS(0x08, 0x00), .target_map = map_tiles_2, .target_pos = MAKE_WARP_POS(0x08, 0x0b) },
  { .tile_pos = MAKE_WARP_POS(0x1f, 0x02), .target_map = map_tiles_3, .target_pos = MAKE_WARP_POS(0x00, 0x08) },
  { .tile_pos = MAKE_WARP_POS(0x1f, 0x03), .target_map = map_tiles_3, .target_pos = MAKE_WARP_POS(0x00, 0x09) },
};

_warp_point warp_points_2[] = {
  { .tile_pos = MAKE_WARP_POS(0x07, 0x0b), .target_map = map_tiles, .target_pos = MAKE_WARP_POS(0x07, 0x00) },
  { .tile_pos = MAKE_WARP_POS(0x08, 0x0b), .target_map = map_tiles, .target_pos = MAKE_WARP_POS(0x08, 0x00) },
  { .tile_pos = MAKE_WARP_POS(0x1f, 0x08), .target_map = map_tiles_3, .target_pos = MAKE_WARP_POS(0x00, 0x02) },
  { .tile_pos = MAKE_WARP_POS(0x1f, 0x09), .target_map = map_tiles_3, .target_pos = MAKE_WARP_POS(0x00, 0x03) },
};

_warp_point warp_points_3[] = {
  { .tile_pos = MAKE_WARP_POS(0x00, 0x08), .target_map = map_tiles, .target_pos = MAKE_WARP_POS(0x1f, 0x02) },
  { .tile_pos = MAKE_WARP_POS(0x00, 0x09), .target_map = map_tiles, .target_pos = MAKE_WARP_POS(0x1f, 0x03) },
  { .tile_pos = MAKE_WARP_POS(0x00, 0x02), .target_map = map_tiles_2, .target_pos = MAKE_WARP_POS(0x1f, 0x08) },
  { .tile_pos = MAKE_WARP_POS(0x00, 0x03), .target_map = map_tiles_2, .target_pos = MAKE_WARP_POS(0x1f, 0x09) },
};

unsigned int _meta_tiles[][4] = {
  { 0x13, 0x13, 0x13, 0x13 },
  { 0x09, 0x0a, 0x1c, 0x1d },
  { 0x7a, 0x7b, 0x80, 0x81 },
  { 0x5d, 0x5d|TILE_FLIPPED_X, 0x68, 0x68|TILE_FLIPPED_X },
  { 0x7c, 0x7d, 0x82, 0x83 },
  { 0x7e, 0x7f, 0x84, 0x85 },
  { 0x86, 0x87, 0x8a, 0x8b },
  { 0x88, 0x89, 0x8c, 0x8d }
};

char *current_map_tiles = map_tiles;
_warp_point *current_warp_points = warp_points;

void init_map() {
}

void _draw_map_row(char row_number) {
  SMS_setNextTileatXY(0, (row_number << 1));

  for (char x = 0; x < MAP_WIDTH; ++x) {
    const char meta_tile_idx = current_map_tiles[row_number * MAP_WIDTH + x];

    SMS_setTile(_meta_tiles[meta_tile_idx][0]);
    SMS_setTile(_meta_tiles[meta_tile_idx][1]);
  }

  for (char x = 0; x < MAP_WIDTH; ++x) {
    const char meta_tile_idx = current_map_tiles[row_number * MAP_WIDTH + x];

    SMS_setTile(_meta_tiles[meta_tile_idx][2]);
    SMS_setTile(_meta_tiles[meta_tile_idx][3]);
  }
}

void draw_map() {
  // SMS_VRAMmemcpy(0x3800, map_tiles, 2 * 32 * 24);
  for (unsigned char row = 0; row < MAP_HEIGHT; ++row) {
    _draw_map_row(row);
  }
}

_warp_point *find_warp_point(char tile_x, char tile_y) {
  const char count = 4;

  for (unsigned char n = 0; n < count; ++n) {
    if (tile_x == WARP_POINT_X(current_warp_points[n].tile_pos)
        && tile_y == WARP_POINT_Y(current_warp_points[n].tile_pos)) {
      return &current_warp_points[n];
    }
  }

  return 0;
}

char lookup_tile(char tile_x, char tile_y) {
  return current_map_tiles[tile_y * MAP_WIDTH + tile_x];
}

void handle_warp_point(_player *player, _warp_point *warp_point) {
  char tile_x = WARP_POINT_X(warp_point->target_pos);
  char tile_y = WARP_POINT_Y(warp_point->target_pos);

  player->tile_x = tile_x;
  player->pos_x = tile_x * 16;
  player->tile_y = tile_y;
  player->pos_y = tile_y * 16;
  player->just_warped = 1;

  current_map_tiles = warp_point->target_map;
  current_warp_points = (current_map_tiles == map_tiles) ? warp_points
    : (current_map_tiles == map_tiles_2) ? warp_points_2 : warp_points_3;

  SMS_waitForVBlank();
  reload_bg_palette_half_brightness(1);
  reload_sprite_palette_half_brightness(1);
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_displayOff();

  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();

  SMS_updateSpritePosition(player->sprite_a, player->pos_x, player->pos_y);
  SMS_updateSpritePosition(player->sprite_b, player->pos_x + 8, player->pos_y);
  SMS_copySpritestoSAT();

  draw_map();

  SMS_displayOn();

  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();

  reload_bg_palette_half_brightness(0);
  reload_sprite_palette_half_brightness(0);
}
