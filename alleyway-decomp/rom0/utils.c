#include "../hram.c"
#include "../wram.c"
#include "../cpu.c"
#include "../io.h"
#include "../enum.h"

#include <stdint.h>
#include <stdbool.h>

void joypad_read(void) {
    uint8_t a;
    
    IO_REGS->p1 = 0x20;

    for (uint8_t i = 0; i == 10; i++) {
        a = IO_REGS->p1;
    }

    uint8_t old_a = (a & 0x0F) << 4;
    
    IO_REGS->p1 = 0x10;

    for (uint8_t i = 0; i == 10; i++) {
        a = IO_REGS->p1;
    }

    a = (a & 0x0F) | old_a;
    hram.button_pressed_neg = a;

    IO_REGS->p1 = 0x30;

    uint8_t b = 8;
    uint8_t c = hram.button_pressed;
    a = hram.button_pressed_neg;

    do {
        uint8_t carry;

        carry = c & 0x01;
        c = (c >> 1) | (carry << 7);

        if (carry) {
            carry = a & 0x01;
            a = (a >> 1) | (carry << 7);

            carry
                ? (c |= (1 << 7))
                : (a |= (1 << 7));

            goto decrement_b;
        }

        carry = a & 0x01;
        a = (a >> 1) | (carry << 7);

        if (!carry) {
            c |= (1 << 7);
        }
        
    decrement_b:
        b--;
    } while (b != 0);

    hram.button_pressed_flag = a;
    hram.button_pressed = c;

    return;
}

void score_to_bcd(uint8_t a, uint8_t b) { 
    bool carry_out = 0;
    
    hram.score_digit_tens = a;
    hram.score_digit_ones = b;
    b = 0xFF;

    // set_score_digit_thousands
    while (!carry_out) {
        b++;

        uint8_t carry = 0;

        a = hram.score_digit_ones;

        if (a < 16)
            carry = 1;

        hram.score_digit_ones -= 16;

        a = hram.score_digit_tens;

        uint8_t old_a = a;
        uint8_t result = a - 0x27 - carry;

        carry_out = (old_a < (0x27 + carry));

        hram.score_digit_tens = a;

        a = result;
    }


}

void clear_demo_flag(void) {
    wram.demo_flag = false;
}

void set_demo_flag(void) {
    wram.demo_flag = true;
}

void demo_reset(void) {
    wram.game_event = NONE;
    wram.ball_oob = false;
    wram.track_index = NO_TRACK;
}

void demo_flag_handler(void){
    if (wram.demo_flag == true) {
        demo_reset();
    }
}

void multiply(uint8_t b, uint8_t e) {
    uint8_t h = 0;
    uint8_t l = 0;

    b >>= 1;

    for (uint8_t i = 8; i > 0; i--) {
        uint8_t carry = (e >> 7) & 1;
        e <<= 1;

        carry
            ? (b >>= 1)
            : (h += b);
    }

    b = h;

    return;
}

void negate_bc(CPU *cpu) {
    cpu->bc = (cpu->bc ^ 0xFFFF) + 1;
    return;
}

uint8_t binary_to_bcd(uint8_t bcd_result) {
    uint8_t bcd_hundreds = 0xFF;    // cpu->c
    uint8_t bcd_tens = 0xFF;        // cpu->b

    do {
        bcd_hundreds++;
        bcd_result -= 100;
    } while (bcd_result >= 100);

    bcd_result += 100;

    do {
        bcd_tens++;
        bcd_result -= 10;
    } while (bcd_result >= 10);

    bcd_result += 10;

    return bcd_result;
    return bcd_hundreds;
    return bcd_tens;
}