#pragma once

#include "SMSlib.h"

#define STATE_STATIONARY 0x01
#define STATE_MOVE_DOWN  0x02
#define STATE_MOVE_UP    0x03
#define STATE_MOVE_LEFT  0x04
#define STATE_MOVE_RIGHT 0x05

typedef struct {
  char pos_x;
  char pos_y;
  char tile_x;
  char tile_y;
  signed char sprite_a;
  signed char sprite_b;
  char state;
  char state_timer;
  char just_warped;
} _player;

void init_player(char, char);
void update_player(unsigned int);
char player_can_move(char, char);
