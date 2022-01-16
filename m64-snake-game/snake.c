//
// Created by Guy Wilks on 1/16/22.
//

#include "snake.h"
#include "coordinate.h"
#include <stdlib.h>
#include "main.h"
#define MAXIMUM_SNAKE_SIZE ((uint8_t)(30*32))

coordinateU8_t snake_stack[MAXIMUM_SNAKE_SIZE];

uint8_t start, end, size;

uint8_t fruit_x, fruit_y;

uint8_t init_snake_queue(){
    start = 0;
    end = 1;
    size = 1;
    snake_stack[start].x = 14;
    snake_stack[start].y = 15;
    return 1;
}

uint8_t pop_snake_queue(){
    start += 1;
    if(start == MAXIMUM_SNAKE_SIZE){
        start = 0;
    }
    size -= 1;
    return 1;
}

uint8_t push_snake_queue(uint8_t x, uint8_t y){
    if(!check_spot_taken(start, x, y)){
        snake_stack[end].x = x;
        snake_stack[end].y = y;
        end += 1;
        if(end == MAXIMUM_SNAKE_SIZE){
            end = 0;
        }
        size += 1;
    }else{
        reset();
    }
    return 1;
}

coordinateU8_t current_head_location(){
    return snake_stack[start];
}

uint8_t check_spot_taken(uint8_t s, uint8_t x, uint8_t y){
    uint8_t i;
    for(i = s; i < start + size; i++){
        if(start > MAXIMUM_SNAKE_SIZE){
            if(snake_stack[i - (size-start)].x == x && snake_stack[i - (size-start)].y == y){
                return 1;
            }
        }else{
            if(snake_stack[i].x == x && snake_stack[i].y == y){
                return 1;
            }
        }
    }
    return 0;
}

void create_fruit(){
    uint8_t rand_x = rand()%32;
    uint8_t rand_y = rand()%30;
    if(check_spot_taken(start, rand_x, rand_y)){
        create_fruit();
    }else{
        fruit_x = rand_x;
        fruit_y = rand_y;
    }
}

uint8_t check_fruit_collision(){
    if(snake_stack[start].x == fruit_x && snake_stack[start].y == fruit_y){
        return 1;
    }
    return 0;
}

uint8_t check_snake_collision() {
    return ((check_spot_taken(start + 1, snake_stack[start].x, snake_stack[start].y)) ||
        snake_stack[start].x > 31 || snake_stack[start].x < 0 || snake_stack[start].y > 29 || snake_stack[start].y < 0 );
}