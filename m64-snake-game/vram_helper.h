//
// Created by Guy Wilks on 1/15/22.
//

#ifndef IEEE_VRAM_HELPER_H
#define IEEE_VRAM_HELPER_H

#include <int.h>
#include <vram.h>

/**
 * Clears the text table. Sets all entries to 0x00
 * @return 1 unless error occurs
 */
uint8_t Clear_TextTable();

/**
 * Fills the text table with all values from the table parameter (acts similarly to a copy constructor)
 * @return 1 unless error occurs
 */
uint8_t Fill_TextTable(char table[30][32]);

/**
 * Fills the text table a specified value at a specified x and y position
 * @return 1 unless error occurs
 */
uint8_t Fill_TextTable(uint8_t x, uint8_t y, uint8_t value);

/**
 * Clears the name table. Sets all entries to 0x00
 * @return 1 unless error occurs
 */
uint8_t Clear_NameTable();

/**
 * Fills the name table with all values from the table parameter (acts similarly to a copy constructor
 * @return 1 unless error occurs
 */
uint8_t Fill_NameTable(uint8_t table[30][32]);

/**
 * Fills the name table with all values from the table parameter (acts similarly to a copy constructor
 * @return 1 unless error occurs
 */
uint8_t Fill_NameTable(uint8_t x, uint8_t y, uint8_t value);

/**
 * Clears both foreground and background pattern memory
 * @return
 */
uint8_t Clear_PatternMemory();

/**
 * Keeps track of which slots in the Pattern memory are open (according to the function calls to this file
 */
bool PMF_slots[32] = {false};
bool PMB_slots[32] = {false};

/**
 * Clears foreground pattern memory
 * @return
 */
uint8_t Clear_PMF();

/**
 * pushes the pattern to foreground pattern memory at earliest available slot
 * @return index of pattern or negative 1 if PMB is filled
 */
uint8_t Push_PMF(pattern_t pattern);

/**
 * replaces the pattern at an an index in foreground pattern memory with parameter pattern
 * @return
 */
uint8_t Set_PMF(pattern_t pattern, uint8_t index);

/**
 * pops the values at an index (does not affect any other
 * @param index
 * @return
 */
uint8_t pop_index_PMF(uint8_t index);

/**
 * returns the number of that haven't been used
 * NOTE: what this returns is monitored by this file such that if the PMF is edited outside this file, it will not keep track
 * @return the PMF_slots array
 */
uint8_t Slots_Open_PMF();

/**
 * Clears background pattern memory
 * @return
 */
uint8_t Clear_PMB();

/**
 * pushes the pattern to background pattern memory at earliest available slot
 * @return index of pattern or negative 1 if PMB is filled
 */
uint8_t Push_PMB(pattern_t pattern);

/**
 * pushes the array pattern to background pattern memory at earliest available slot
 * (will only run if the number of patterns in the input is shorter than or equal to the number of open slots in the PMB)
 * @return index of pattern or negative 1 if PMB is filled
 */
uint8_t Push_PMB(pattern_t *pattern);

/**
 * replaces the pattern at an an index in background pattern memory with parameter pattern
 * @param pattern
 * @param index
 * @return
 */
uint8_t Set_PMB(pattern_t pattern, uint8_t index);

/**
 * returns the number of that haven't been used
 * NOTE: what this returns is monitored by this file such that if the PMB is edited outside this file, it will not keep track
 * @return the PMB_slots array
 */
uint8_t Slots_Open_PMB();

/**
 * Keeps track of which slots in the Pattern memory are open (according to the function calls to this file
 */
bool ObjectMemory_slots[32] = {false};

/**
 * Clears the object memory
 * @return
 */
uint8_t Clear_ObjectMemory();

/**
 * sets the object memory at the index to the object
 * @param index
 * @param obj
 * @return
 */
uint8_t Set_ObjectMemory(uint8_t index, object_t obj);

/**
 * sets the object memory at earliest index
 * @param obj
 * @return the index that it is entered at
 */
uint8_t Set_ObjectMemory(object_t obj);



#endif //IEEE_VRAM_HELPER_H
