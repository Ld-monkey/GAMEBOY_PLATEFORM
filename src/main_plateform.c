#include <gb/gb.h>
#include "tileset.h"
#include "tilemap.h"

// Boolean.
#define TRUE 1
#define FALSE 0
#define NONE 2

// Egde border of screen. WIDHT = 160px, HEIGHT = 144px
#define LIMIT_LEFT_EGDE 6
#define LIMIT_RIGHT_EGDE 154

void main(void)
{
  // Load tileset and tilemap.
  set_bkg_data(128, TILESET_TILE_COUNT + PLAYER_TILESET_TILE_COUNT, TILESET);
  set_bkg_tiles(0, 0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);

  // Show background.
  SHOW_BKG;

  // UINT8 = [0, 255].
  // Player position.
  UINT8 player_x = 8;
  UINT8 player_y = 136;

  // Sprite position.
  UINT8 player_sprite_left_face_x = player_x;
  UINT8 player_sprite_right_face_x = player_sprite_left_face_x + 8;

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

  INT8 loop_game = TRUE;
  INT8 is_jumping = NONE;

  // loop game
  while(loop_game == TRUE) {
    // waiting for screen refresh.
    wait_vbl_done();

    //keybord on gameboy.
    INT8 keys = joypad();

    if (keys & J_RIGHT) {
      // verified right edge of screen.
      if (player_x > LIMIT_RIGHT_EGDE) {
        player_x = LIMIT_RIGHT_EGDE;
      }
      // move at right.
      player_x += 1;
      player_sprite_left_face_x = player_x;
      player_sprite_right_face_x = player_sprite_left_face_x + 8;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    } else if (keys & J_LEFT) {
      //verified left edge of screen.
      if (player_x < LIMIT_LEFT_EGDE) {
        player_x = LIMIT_LEFT_EGDE;
      }

      // move at left.
      player_x -= 1;
      player_sprite_left_face_x = player_x;
      player_sprite_right_face_x = player_sprite_left_face_x + 8;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    } else if (keys & J_START) {
      // quit game
      loop_game = FALSE;
    }
    
    if (keys & J_UP && is_jumping == NONE) {
      // jump the player.
      is_jumping = TRUE;
    }

    // Simple jump not optimised.
    if (is_jumping == TRUE && player_y > 110) {
      player_y -= 1;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    } else if (player_y == 110) {
      is_jumping = FALSE;
    }
    if (is_jumping == FALSE) {
      player_y += 1;
      move_sprite(0, player_sprite_left_face_x, player_y);
      move_sprite(1, player_sprite_right_face_x, player_y);
    }
    if (player_y == 136) {
      player_y = 136;
      is_jumping = NONE;
    }

  }
}
