#include "SMSlib.h"
#include "battle.h"
#include "graphics.h"
#include "map.h"
#include "player.h"
#include "rom_header.h"

#define DO_BATTLE

void handle_pause(void);

extern _player player;

void main(void) {
  SMS_init();

#ifdef DO_BATTLE
  battle_loop();
#else
  init_map();
  RL_init_graphics();
  SMS_initSprites();

  init_player(8, 4);

  SMS_VDPturnOnFeature(VDPFEATURE_USETALLSPRITES);

  SMS_updateSpritePosition(player.sprite_a, player.pos_x, player.pos_y);
  SMS_updateSpritePosition(player.sprite_b, player.pos_x + 8, player.pos_y);
  SMS_updateSpriteImage(player.sprite_a, 0x00);
  SMS_updateSpriteImage(player.sprite_b, 0x02);

  draw_map();
  write_string_at(0, 20, "Hello, Sega Master System!");

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
#endif
}

void enter_pause(void) {
  SMS_resetPauseRequest();
  reload_bg_palette_half_brightness(1);
  disable_sprites();
}

void handle_pause(void) {
  enter_pause();

  for (;;) {
    if (SMS_queryPauseRequested()) {
      SMS_resetPauseRequest();
      break;
    }
  }

  SMS_waitForVBlank();
  enable_sprites();
  reload_bg_palette_half_brightness(0);
}
