#include <gb/gb.h>
#include "tileset.h"
#include "tilemap.h"


// Boolean.
#define TRUE 1
#define FALSE 0

void main(void)
{
  // Load tileset and tilemap.
  set_bkg_data(128, TILESET_TILE_COUNT + PLAYER_TILESET_TILE_COUNT, TILESET);
  set_bkg_tiles(0, 0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);

  // Show background.
  SHOW_BKG;

  // Player position.
  INT8 player_x = 8;
  INT8 player_y = 136;

  // Sprite position.
  INT8 player_sprite_left_face_x = player_x;
  INT8 player_sprite_right_face_x = player_sprite_left_face_x + 8;

  //OAM 0 : set sprite left face.
  set_sprite_tile(0, 128 + 6);

  // Place sprite 0.
  move_sprite(0, player_sprite_left_face_x, player_y);

  //OAM 1 : set sprite right face.
  set_sprite_tile(1, 128 + 7);

  // Place sprite 1.
  move_sprite(1, player_sprite_right_face_x, player_y);

  // Show sprites.
  SHOW_SPRITES;

  //to move sprite void scroll_sprite(INT8 sprites, INT8 x, INT8 y);

  INT8 loop_game = 1;

  // loop game
  while(loop_game == TRUE) {
    // waiting for screen refresh.
    wait_vbl_done();

    //keybord on gameboy.
    INT8 keys = joypad();

    if (keys & J_RIGHT) {
      // move at right.
      player_x += 1;
      player_sprite_left_face_x = player_x;
      player_sprite_right_face_x = player_sprite_left_face_x + 8;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    }else if (keys & J_LEFT) {
      // move at left.
      player_x -= 1;
      player_sprite_left_face_x = player_x;
      player_sprite_right_face_x = player_sprite_left_face_x + 8;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    }else if (keys & J_START) {
      // quit game
      loop_game = FALSE;
    }
  }
}
