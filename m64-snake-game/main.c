
// ==================== main.c ==================== //
// Follow this file vram_helper to implement your game //
// ================================================ //

#define SIM 1 // change value depending if running simulation or not

// ================================ //
#pragma code-name ("CODE")
#pragma bss-name ("BSS")

#include <int.h>
#include <vram.h>
#include <stop.h>
#include <Q9_6.h>
#include <mapache64_zero_page.h>
#include <controller.h>
#include <screen.h>
#include "snake.h"

// run once on startup
void reset(void) {
    init_snake_queue();
    create_fruit();
}

// run 60 times a second
void do_logic(void) {
    if(CONTROLLER_1&CONTROLLER_LEFT_MASK){
        if(!check_fruit_collision()){ pop_snake_queue();}else{ create_fruit();}
        push_snake_queue(current_head_location().x - 1, current_head_location().y);
    }else if(CONTROLLER_1&CONTROLLER_RIGHT_MASK){
        if(!check_fruit_collision()){ pop_snake_queue();}else{ create_fruit();}
        push_snake_queue(current_head_location().x + 1, current_head_location().y);
    }else if(CONTROLLER_1&CONTROLLER_UP_MASK){
        if(!check_fruit_collision()){ pop_snake_queue();}else{ create_fruit();}
        push_snake_queue(current_head_location().x, current_head_location().y - 1);
    }else if(CONTROLLER_1&CONTROLLER_DOWN_MASK){
        if(!check_fruit_collision()){ pop_snake_queue();}else{ create_fruit();}
        push_snake_queue(current_head_location().x, current_head_location().y + 1);
    }
}

// run after do_logic and once gpu is idle
void fill_vram(void) {

}
