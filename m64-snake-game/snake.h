//
// Created by Guy Wilks on 1/16/22.
//

#ifndef IEEE_SNAKE_H
#define IEEE_SNAKE_H

#include <int.h>
#include "vram_helper.h"

uint8_t init_snake_queue();

uint8_t pop_snake_queue();

uint8_t push_snake_queue(uint8_t x, uint8_t y);

coordinateU8_t current_head_location();

uint8_t check_fruit_collision();

void create_fruit();

uint8 check_snake_collision();

uint8_t check_spot_taken(uint8_t s, uint8_t x, uint8_t y);

#endif //IEEE_SNAKE_H
