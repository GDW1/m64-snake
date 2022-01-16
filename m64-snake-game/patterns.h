
#ifndef __PATTERNS_H
#define __PATTERNS_H


#include <vram.h>

extern const pattern_t black_pattern;
#define black_pattern_pmba ((uint8_t)0)
extern const pattern_t white_pattern;
#define white_pattern_pmba ((uint8_t)1)
extern const pattern_t fruit_pattern;
#define fruit_pattern_pmba ((uint8_t)2)

void load_background_pattern(const pattern_t pattern, const uint8_t pmba);
void load_foreground_pattern(const pattern_t pattern, const uint8_t pmfa);

void load_patterns(void);

#endif
