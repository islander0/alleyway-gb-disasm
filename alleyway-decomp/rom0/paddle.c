#include "../hram.c"
#include "../wram.c"
#include "../cpu.c"

#include <stdint.h>


void update_paddle_clamp_x(uint8_t paddle_clamp_offset) {
    hram.paddle_x = paddle_clamp_offset; 
    return;
}

void paddle_movement_handler(CPU *cpu) {
    // update serial sample
    if (hram.serial_sample_curr < 0xF1) {
        hram.paddle_collision_width = 0x7F - hram.paddle_collision_width;

        hram.serial_sample_curr -= 0x30;

        if (hram.serial_sample_curr < 0x30) {
            uint8_t paddle_clamp_offset = 0xF;
            update_paddle_clamp_x(paddle_clamp_offset);
        }
    }

    uint8_t paddle_speed = 5;
    if ();

    uint8_t paddle_speed = 1;

    uint8_t paddle_speed = 3;

    // check L + R
    hram.button_pressed_neg = 0x30 ^ (hram.button_pressed_neg & 0x30);

    if (hram.button_pressed_neg == 0) {
        return;
    }

    hram.button_pressed_neg &= 0x20;

    // move paddle right
    if (hram.button_pressed_neg == 0) {
        cpu->a = 0x7F;
        cpu->c = hram.paddle_collision_width;
        cpu->a -= cpu->c;
        cpu->c = cpu->a;

        hram.paddle_x = cpu->a;
        hram.paddle_x += paddle_speed;
        
        if (hram.paddle_x < cpu->c) {
            hram.paddle_x = cpu->a;
            return;
        }

        hram.paddle_x = cpu->c;
        return;
    }
}

void paddle_update(CPU *cpu) {
    paddle_movement_handler(cpu->a);
    update_paddle_oam_buffer();
}


