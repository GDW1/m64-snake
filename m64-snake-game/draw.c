
#include "draw.h"
#include "patterns.h"
#include <vram.h>

coordinateS8_t draw_fruit;
coordinateS8_t draw_snake_head;
coordinateS8_t draw_snake_dust;

bool draw_initialized;

void draw_initialize(void) {
    uint8_t i, j;
    load_patterns();
    for (i = 0; i < 30; i++)
        for (j = 0; j < 32; j++) {
            TXBL[i][j] = 0x00;
            NTBL[i][j] = 0x00;
        }
    background_palette = (WHITE_C0_MASK | RED_C1_MASK);
    draw_initialized = true;
}

void draw(void) {
    if (!draw_initialized)
        draw_initialize();
    if (draw_snake_dust.y != DRAW_OUT_OF_RANGE)
        NTBL[draw_snake_dust.y][draw_snake_dust.x]  = (black_pattern_pmba);
    if (draw_snake_head.y != DRAW_OUT_OF_RANGE)
        NTBL[draw_snake_head.y][draw_snake_head.x]  = (white_pattern_pmba);
    if (draw_fruit.y != DRAW_OUT_OF_RANGE)
        NTBL[draw_fruit.y][draw_fruit.x]            = (COLOR_SELECT_MASK | fruit_pattern_pmba);
}
