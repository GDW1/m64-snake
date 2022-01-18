
#ifndef IEEE_DRAW_H
#define IEEE_DRAW_H

#include "coordinate.h"

#define DRAW_OUT_OF_RANGE ((uint8_t)0xff)

extern bool draw_initialized;

extern coordinateS8_t draw_fruit;
extern coordinateS8_t draw_snake_head;
extern coordinateS8_t draw_snake_dust;

void draw(void);

#endif
