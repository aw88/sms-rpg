#include "player.h"
#include "map.h"

#include "SMSlib.h"

_player player;

void init_player(char tile_x, char tile_y) {
  player.tile_x = tile_x;
  player.tile_y = tile_y;
  player.pos_x = 16 * tile_x;
  player.pos_y = 16 * tile_y;
  player.state = STATE_STATIONARY;
  player.sprite_a = SMS_reserveSprite();
  player.sprite_b = SMS_reserveSprite();
  player.just_warped = 1;
}

void update_player(unsigned int input) {
  #define SET_PLAYER_STATE(new_state, timer)                                   \
      player.state = new_state;                                                \
      player.state_timer = timer;                                              \
      player.just_warped = 0;

  #define SET_PLAYER_SPRITE(facing)                                            \
      SMS_updateSpriteImage(player.sprite_a, facing);                          \
      SMS_updateSpriteImage(player.sprite_b, facing + 0x02);

  switch (player.state) {
    case STATE_STATIONARY:
      handle_stationary:
      {
        if (!player.just_warped) {
          _warp_point *warp_point = find_warp_point(player.tile_x, player.tile_y);

          if (warp_point) {
            handle_warp_point(&player, warp_point);
          }
        }

        if (input & PORT_A_KEY_DOWN) {
          SET_PLAYER_SPRITE(0x00);
          if (player_can_move(player.tile_x, player.tile_y + 1)) {
            SET_PLAYER_STATE(STATE_MOVE_DOWN, 16);
            player.tile_y++;
          }
        } else if (input & PORT_A_KEY_UP) {
          SET_PLAYER_SPRITE(0x04);
          if (player_can_move(player.tile_x, player.tile_y - 1)) {
            SET_PLAYER_STATE(STATE_MOVE_UP, 16);
            player.tile_y--;
          }
        } else if (input & PORT_A_KEY_RIGHT) {
          SET_PLAYER_SPRITE(0x08);
          if (player_can_move(player.tile_x + 1, player.tile_y)) {
            SET_PLAYER_STATE(STATE_MOVE_RIGHT, 16);
            player.tile_x++;
          }
        } else if (input & PORT_A_KEY_LEFT) {
          SET_PLAYER_SPRITE(0x0c);
          if (player_can_move(player.tile_x - 1, player.tile_y)) {
            SET_PLAYER_STATE(STATE_MOVE_LEFT, 16);
            player.tile_x--;
          }
        }
      }
      break;

    case STATE_MOVE_UP:
      player.pos_y--;
      break;

    case STATE_MOVE_DOWN:
      player.pos_y++;
      break;

    case STATE_MOVE_LEFT:
      player.pos_x--;
      break;

    case STATE_MOVE_RIGHT:
      player.pos_x++;
      break;
  }

  if (player.state_timer-- == 0) {
    player.state = STATE_STATIONARY;
    goto handle_stationary;
  }

  SMS_updateSpritePosition(player.sprite_a, player.pos_x, player.pos_y);
  SMS_updateSpritePosition(player.sprite_b, player.pos_x + 8, player.pos_y);
}

char player_can_move(char tile_x, char tile_y) {
  return tile_x < 16 && tile_y < 12 && !lookup_tile(tile_x, tile_y);
}
