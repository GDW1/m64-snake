
// ==================== main.c ==================== //
// Follow this file vram_helper to implement your game //
// ================================================ //

#define SIM 1 // change value depending if running simulation or not

// ================================ //
#pragma code-name ("CODE")
#pragma bss-name ("BSS")

#include "main.h"
#include <int.h>
#include <vram.h>
#include <stop.h>
#include <Q9_6.h>
#include <mapache64_zero_page.h>
#include <controller.h>
#include <screen.h>
#include "snake.h"
#include "patterns.h"
#include "draw.h"

uint8_t current_direction;

// run once on startup
void reset(void) {
    load_patterns();
    snake_queue_init();
    fruit_new();
    current_direction = 0;
    draw_initialized = false;
}

// run 60 times a second
void do_logic(void) {
    coordinateS8_t new_coordniate;

    if(CONTROLLER_1&CONTROLLER_LEFT_MASK){
        if (current_direction!=CONTROLLER_RIGHT_MASK)   current_direction = CONTROLLER_LEFT_MASK;
    }else if(CONTROLLER_1&CONTROLLER_RIGHT_MASK){
        if (current_direction!=CONTROLLER_LEFT_MASK)    current_direction = CONTROLLER_RIGHT_MASK;
    }else if(CONTROLLER_1&CONTROLLER_UP_MASK){
        if (current_direction!=CONTROLLER_DOWN_MASK)    current_direction = CONTROLLER_UP_MASK;
    }else if(CONTROLLER_1&CONTROLLER_DOWN_MASK){
        if (current_direction!=CONTROLLER_UP_MASK)      current_direction = CONTROLLER_DOWN_MASK;
    }

    if(current_direction == CONTROLLER_LEFT_MASK){
        new_coordniate.x = get_snake_head()->x-1;
        new_coordniate.y = get_snake_head()->y;
    }else if(current_direction == CONTROLLER_RIGHT_MASK){
        new_coordniate.x = get_snake_head()->x+1;
        new_coordniate.y = get_snake_head()->y;
    }else if(current_direction == CONTROLLER_UP_MASK){
        new_coordniate.x = get_snake_head()->x;
        new_coordniate.y = get_snake_head()->y-1;
    }else if(current_direction == CONTROLLER_DOWN_MASK){
        new_coordniate.x = get_snake_head()->x;
        new_coordniate.y = get_snake_head()->y+1;
    } else {
        return;
    }

    if (snake_can_move_to(&new_coordniate))
        snake_queue_push(&new_coordniate);
    else
        reset();

    if (fruit_location_equals(&new_coordniate))
        fruit_new();
    else
        snake_queue_pop();

}

// run after do_logic and once gpu is idle
void fill_vram(void) {
    draw();
}
