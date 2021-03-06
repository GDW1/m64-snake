
#include "patterns.h"

void load_background_pattern(const pattern_t pattern, const uint8_t pmba) {
    uint8_t i;
    for (i = 0; i < 16; i++)
        PMB[pmba][i] = pattern[i];
}
void load_foreground_pattern(const pattern_t pattern, const uint8_t pmfa) {
    uint8_t i;
    for (i = 0; i < 16; i++)
        PMF[pmfa][i] = pattern[i];
}

void load_patterns(void) {
    load_background_pattern(black_pattern, black_pattern_pmba);
    load_background_pattern(fruit_pattern, fruit_pattern_pmba);
    load_background_pattern(white_pattern, white_pattern_pmba);
}
