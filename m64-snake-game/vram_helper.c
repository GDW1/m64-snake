//
// Created by Guy Wilks on 1/15/22.
//

#include "vram_helper.h"

uint8_t Clear_TextTable(){
    uint8_t i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 32; j++){
            TXBL[i][j] = 0x00;
        }
    }
    return 1;
}

uint8_t Fill_TextTable(char table[30][32]){
    uint8_t i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 32; j++){
            TXBL[i][j] = table[i][j];
        }
    }
    return 1;
}

uint8_t Fill_TextTable(uint8_t x, uint8_t y, uint8_t value){
    TXBL[x][y] = value;
    return 1;
}

uint8_t Clear_NameTable(){
    uint8_t i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 32; j++){
            NTBL[i][j] = 0x00;
        }
    }
    return 1;
}

uint8_t Fill_NameTable(uint8_t table[30][32]){
    uint8_t i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 32; j++){
            NTBL[i][j] = table[i][j];
        }
    }
    return 1;
}

uint8_t Fill_NameTable(uint8_t x, uint8_t y, uint8_t value){
    NTBL[x][y] = value;
    return 1;
}

uint8_t Clear_PatternMemory(){
    uint8_t i, j;
    for(i = 0; i < PMB.length; i++) {
        for (j = 0; j < PMB[i].length; j++) {
            PMB[i][j] = 0x00;
            PMF[i][j] = 0x00;
        }
        PMB_slots[i] = false;
        PMF_slots[i] = false;
    }
    return 1;
}

uint8_t Clear_PMF(){
    uint8_t i, j;
    for(i = 0; i < PMF.length; i++) {
        for (j = 0; j < PMF[i].length; j++) {
            PMF[i][j] = 0x00;
        }
        PMF_slots[i] = false;
    }
    return 1;
}

uint8_t Push_PMF(pattern_t pattern){
    uint8_t i, j;
    for(i = 0; i < PMF_slots.length; i++) {
        if(!PMF_slots[i]){
            for (j = 0; j < pattern.length; j++) {
                PMF[i][j] = pattern[j];
            }
            PMF_slots[i] = true;
            return i;
        }
    }
    return -1;
}

uint8_t Set_PMF(pattern_t pattern, uint8_t index){
    uint8_t i;
    for(i = 0; i < 16; i++) {
        PMF_slots[index][i] = pattern[i];
    }
    PMF_slots[index] = true;
}
