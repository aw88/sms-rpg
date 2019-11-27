#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "SMSlib.h"

#include "../out/bank2.h"

void load_bg_palette(void *palette) __z88dk_fastcall;
void load_sprite_palette(void *palette) __z88dk_fastcall;

void reload_bg_palette_half_brightness(char brightness) __z88dk_fastcall;
void reload_sprite_palette_half_brightness(char brightness) __z88dk_fastcall;

void RL_init_graphics(void);

#endif
