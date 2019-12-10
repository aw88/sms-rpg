#include "graphics.h"

void *current_bg_palette;
void *current_sprite_palette;

void load_bg_palette(void *palette) __z88dk_fastcall {
  current_bg_palette = palette;
  SMS_loadBGPalette(palette);
}

void load_sprite_palette(void *palette) __z88dk_fastcall {
  current_sprite_palette = palette;
  SMS_loadSpritePalette(palette);
}

void reload_bg_palette_half_brightness(char brightness) __z88dk_fastcall {
  if (brightness) {
    SMS_loadBGPaletteHalfBrightness(current_bg_palette);
  } else {
    SMS_loadBGPalette(current_bg_palette);
  }
}

void reload_sprite_palette_half_brightness(char brightness) __z88dk_fastcall {
  if (brightness) {
    SMS_loadSpritePaletteHalfBrightness(current_sprite_palette);
  } else {
    SMS_loadSpritePalette(current_sprite_palette);
  }
}

void write_string_at(char tile_x, char tile_y, char* string) {
  SMS_setNextTileatXY(tile_x, tile_y);

  char *c = string;

  while (*c) {
    int next_tile = (*c++) + TEXT_ASCII_OFFSET;
    SMS_setTile(next_tile);
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

  SMS_mapROMBank(font_bank);
  SMS_loadTiles(font, 0x0A0, font_size);
}

// Zero out the SAT
char vram_first_byte = 0xd0;
void disable_sprites(void) {
  __asm
    ld hl, #0x3f00
    call _SMS_crt0_RST08    ; Read from 0x3f00 (SAT)

    in a, (#0xbe)   ; read from buffer into a
    ld hl, #_vram_first_byte
    ld (hl), a

    ld hl, #0x7f00
    call _SMS_crt0_RST08     ; Write to 0x3f00 (SAT)
    ld hl, #0x00d0
    call _SMS_crt0_RST18     ; Write 0xd0 to SAT
  __endasm;
}

// Repopulate the SAT
void enable_sprites(void) {
  __asm
    ld hl, #0x7f00
    call _SMS_crt0_RST08    ; Write to 0x3f00

    ld hl, #_vram_first_byte
    ld a, (hl)

    ld h, #0x00
    ld l, a

    call _SMS_crt0_RST18
  __endasm;
}
