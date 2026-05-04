#include "../hram.h"
#include "../wram.h"
#include "../cpu.h"

#include "brick.c"
#include "utils.c"

#include <stdint.h>

// equivalent to SWAP A in ASM
static inline uint8_t swap_u8(CPU *cpu) {
    return (cpu->a << 4) | (cpu->a >> 4);
}

static inline uint8_t adc(CPU *cpu) {
    return;
}

void increment_stage_number_display(void) {
    wram.stage_number_display++;
}

// WIP
void add_brick_score_to_player_score(CPU *cpu) {
    cpu->a--;
    cpu->b = cpu->a;
    cpu->e = 6;

    cpu->b = multiply(cpu->b, cpu->e);
    brick_data_table[cpu->b + 3];

    cpu->a = swap_u8(cpu->a);
    cpu->a &= 0x0F;

    hram.player_score_lo += cpu->a;
    hram.player_score_hi += FLAG_C;

    if (FLAG_C == 0) {
        return;
    }

    hram.player_score_hi = 0xFF;
    hram.player_score_lo = 0xFF;
}

/*
void update_score_all(CPU *cpu) {

}


void extra_life_score_handler(void) {

}
*/

uint16_t extra_life_threshold_table[10] = {
    1000, 2000, 3000, 4000, 5000,
    6000, 7000, 8000, 9000, 0xFFFF
};

void set_next_extra_life_score_threshold(void) {
    uint16_t value = extra_life_threshold_table[hram.extra_life_gained_total];

    hram.extra_life_score_threshold_hi = value >> 8;
    hram.extra_life_score_threshold_lo = value & 0xFF;

    hram.extra_life_gained_total++;
}