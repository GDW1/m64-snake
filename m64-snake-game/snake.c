//
// Created by Guy Wilks on 1/16/22.
//

#include "snake.h"
#include "coordinate.h"
#include <stdlib.h>
#include "main.h"
#include <vram.h>
#include "patterns.h"
#include "draw.h"


#define MAXIMUM_SNAKE_SIZE ((uint8_t)(30*32))

coordinateS8_t snake_queue[MAXIMUM_SNAKE_SIZE];

uint8_t snake_queue_start, snake_queue_end, snake_queue_size;

void snake_queue_init(void){
    snake_queue_start = 0;
    snake_queue_end = 1;
    snake_queue_size = 1;
    snake_get_head()->x = 14;
    snake_get_head()->y = 15;
    draw_snake_head = *snake_get_head();
    draw_snake_dust.y = DRAW_OUT_OF_RANGE;
}

void snake_queue_pop(void){
    draw_snake_dust = *snake_get_tail();
    snake_queue_start += 1;
    if(snake_queue_start == MAXIMUM_SNAKE_SIZE){
        snake_queue_start = 0;
    }
    snake_queue_size -= 1;
}

void snake_queue_push(const coordinateS8_t * const coordinate){
    if (snake_queue_size==MAXIMUM_SNAKE_SIZE) return;
    snake_queue[snake_queue_end] = (*coordinate);
    snake_queue_end += 1;
    if(snake_queue_end == MAXIMUM_SNAKE_SIZE) snake_queue_end = 0;
    snake_queue_size += 1;
    draw_snake_head = *snake_get_head();
}

coordinateS8_t * snake_get_head(void){
    uint8_t head = (snake_queue_end==0)?(MAXIMUM_SNAKE_SIZE-1):(snake_queue_end-1);
    return snake_queue + head;
}

coordinateS8_t * snake_get_tail(void){
    return snake_queue + snake_queue_start;
}

bool snake_has_coordinate(const coordinateS8_t * const coordinate){
    uint8_t i, k;
    k = snake_queue_start;
    for(i = 0; i < snake_queue_size; i++){
        if (snake_queue[k].x == coordinate->x && snake_queue[k].y == coordinate->y)
            return true;
        k++;
        if (k==MAXIMUM_SNAKE_SIZE) k = 0;
    }
    return false;
}

bool snake_can_move_to(const coordinateS8_t * const coordinate){
    if (snake_has_coordinate(coordinate))
        return false;
    if (
        (coordinate->x<0)    || (coordinate->y<0)    ||
        (coordinate->x>=32)  || (coordinate->y>=30)
    )
        return false;
    return true;
}


coordinateS8_t fruit;

void fruit_new(void){
    coordinateS8_t new_coordinate;
    do {
        new_coordinate.x = ((uint8_t)rand())%32;
        new_coordinate.y = ((uint8_t)rand())%30;
    } while (snake_has_coordinate(&new_coordinate));
    fruit = new_coordinate;
    draw_fruit = fruit;
}

bool fruit_location_equals(const coordinateS8_t * const coordinate){
    return (fruit.x == coordinate->x) && (fruit.y == coordinate->y);
}
