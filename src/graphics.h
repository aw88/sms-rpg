#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "SMSlib.h"

#include "../out/bank2.h"

#define PAL_BG     0x01
#define PAL_SPRITE 0x02

void load_bg_palette(void *palette);
void load_sprite_palette(void *palette);

void reload_bg_palette_half_brightness(char brightness);
void reload_sprite_palette_half_brightness(char brightness);

void RL_init_graphics(void);

#endif
