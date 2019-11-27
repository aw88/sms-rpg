#include "graphics.h"

void *current_bg_palette;
void *current_sprite_palette;

void load_bg_palette(void *palette) {
  current_bg_palette = palette;
  SMS_loadBGPalette(palette);
}

void load_sprite_palette(void *palette) {
  current_sprite_palette = palette;
  SMS_loadSpritePalette(palette);
}

void reload_bg_palette_half_brightness(char brightness) {
  if (brightness) {
    SMS_loadBGPaletteHalfBrightness(current_bg_palette);
  } else {
    SMS_loadBGPalette(current_bg_palette);
  }
}

void reload_sprite_palette_half_brightness(char brightness) {
  if (brightness) {
    SMS_loadSpritePaletteHalfBrightness(current_sprite_palette);
  } else {
    SMS_loadSpritePalette(current_sprite_palette);
  }
}

void RL_init_graphics(void) {
  SMS_mapROMBank(tiles_pal_bank);
  load_bg_palette(tiles_pal);

  SMS_mapROMBank(tiles_bank);
  SMS_loadTiles(tiles, 1, tiles_size);

  // SMS_mapROMBank(tiles_map_bank);
  // RL_draw_map(tiles_map, 0, 0);

  SMS_mapROMBank(sprites_pal_bank);
  load_sprite_palette(sprites_pal);

  SMS_mapROMBank(sprites_bank);
  SMS_loadTiles(sprites, 0x100, sprites_size);
}
