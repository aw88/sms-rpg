#include "battle.h"

#include "../out/bank2.h"
#include "graphics.h"

const char palette_bg[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
                           0x01, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06};

const short bg_tile_map[] = {
    0x0001, 0x0002, 0x0003, 0x0004, 0x0003, 0x0004, 0x0001, 0x0002,
    0x0005, 0x0006, 0x0007, 0x0008, 0x0007, 0x0008, 0x0005, 0x0006,
    0x0009, 0x000A, 0x000B, 0x000C, 0x000B, 0x000C, 0x0009, 0x000A,
    0x000D, 0x000E, 0x000F, 0x0010, 0x000F, 0x0010, 0x000D, 0x000E,
};

void battle_start() {
  load_bg_palette(palette_bg);
  SMS_loadPSGaidencompressedTiles(battle_bg_forest, 1);

  for (char n = 0; n < 32; n += 8) {
    short t = 0;

    for (char i = 0; i < 4; ++i) {
      SMS_setNextTileatXY(n, i);

      for (char j = 0; j < 8; ++j) {
        SMS_setTile(bg_tile_map[t++]);
      }
    }
  }
}

void battle_loop() {
  battle_start();

  reload_bg_palette_half_brightness(1);
  SMS_displayOn();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  SMS_waitForVBlank();
  reload_bg_palette_half_brightness(0);

  for (;;) {
  }

  battle_end();
}

void battle_end() {}
