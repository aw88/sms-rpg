#include "SMSlib.h"
#include "rom_header.h"

#include "graphics.h"
#include "player.h"
#include "map.h"

void handle_pause(void);

extern _player player;

void main (void) {
  SMS_init();

  init_map();
  RL_init_graphics();
  SMS_initSprites();

  init_player(4, 8);

  SMS_VDPturnOnFeature(VDPFEATURE_USETALLSPRITES);

  SMS_updateSpritePosition(player.sprite_a, player.pos_x, player.pos_y);
  SMS_updateSpritePosition(player.sprite_b, player.pos_x + 8, player.pos_y);
  SMS_updateSpriteImage(player.sprite_a, 0x00);
  SMS_updateSpriteImage(player.sprite_b, 0x02);

  draw_map();

  SMS_displayOn();

  for (;;) {
    const int input_sms = SMS_getKeysStatus();

    update_player(input_sms);

    SMS_waitForVBlank();
    SMS_copySpritestoSAT();

    if (SMS_queryPauseRequested()) {
      handle_pause();
    }
  }
}

void handle_pause(void) {
  SMS_resetPauseRequest();

  reload_bg_palette_half_brightness(1);
  reload_sprite_palette_half_brightness(1);

  for (;;) {
    if (SMS_queryPauseRequested()) {
      SMS_waitForVBlank();
      reload_bg_palette_half_brightness(0);
      reload_sprite_palette_half_brightness(0);
      SMS_resetPauseRequest(); 
      return;
    }
  }
}