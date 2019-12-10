#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "SMSlib.h"

#include "../out/bank2.h"

#define TEXT_ASCII_OFFSET 128

__sfr __at 0xBE VDPDataPort;
__sfr __at 0xBF VDPControlPort;

void write_string_at(char tile_x, char tile_y, char* string);

void load_bg_palette(void *palette) __z88dk_fastcall;
void load_sprite_palette(void *palette) __z88dk_fastcall;

void reload_bg_palette_half_brightness(char brightness) __z88dk_fastcall;
void reload_sprite_palette_half_brightness(char brightness) __z88dk_fastcall;

void RL_init_graphics(void);

void disable_sprites(void);
void enable_sprites(void);

#endif
