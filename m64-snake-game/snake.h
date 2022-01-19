//
// Created by Guy Wilks on 1/16/22.
//

#ifndef IEEE_SNAKE_H
#define IEEE_SNAKE_H

#include <int.h>
#include "coordinate.h"


void snake_queue_init(void);

void snake_queue_pop(void);

void snake_queue_push(const coordinateS8_t * const coordinate);

coordinateS8_t * snake_get_tail(void);

coordinateS8_t * snake_get_head(void);

bool snake_has_coordinate(const coordinateS8_t * const coordinate);

bool snake_can_move_to(const coordinateS8_t * const coordinate);


void fruit_new(void);

bool fruit_location_equals(const coordinateS8_t * const coordinate);


#endif //IEEE_SNAKE_H
