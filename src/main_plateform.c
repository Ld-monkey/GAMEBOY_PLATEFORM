#include <gb/gb.h>
#include "tileset.h"
#include "tilemap.h"

void main(void)
{ 
  set_bkg_data(128, TILESET_TILE_COUNT + PLAYER_TILESET_TILE_COUNT, TILESET);
  set_bkg_tiles(0, 0, TILEMAP_WIDTH, TILEMAP_HEIGHT, TILEMAP);
  SHOW_BKG;

  INT8 player_x = 8;
  INT8 player_y = 136;
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

  // Display sprites.
  SHOW_SPRITES;
}
