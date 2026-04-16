#define HALT() /* HALT: CPU suspended until next interrupt */

typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    undefined1;
typedef unsigned int    undefined2;
typedef unsigned int    word;
typedef struct switchD_054b switchD_054b, *PswitchD_054b;

struct switchD_054b { // PlaceHolder Class Structure
};

typedef enum cart_type {
    ROM_ONLY=0,
    MBC1=1,
    MBC1_RAM=2,
    MBC1_RAM_BATT=3,
    MBC2=5,
    MBC2_BATT=6,
    RAM=8,
    RAM_BATT=9,
    MMM01=11,
    MMM01_RAM=12,
    MMM01_RAM_BATT=13,
    MBC3_RTC_BATT=15,
    MBC3_RAM_RTC_BATT=16,
    MBC3=17,
    MBC3_RAM=18,
    MBC3_RAM_BATT=19,
    MBC5=25,
    MBC5_RAM=26,
    MBC5_RAM_BATT=27,
    MBC5_RUMBLE=28,
    MBC5_RAM_RUMBLE=29,
    MBC5_RAM_BATT_RUMBLE=30,
    MBC6=32,
    MBC7=34,
    POCKET_CAMERA=252,
    TAMA5=253,
    HUC3=254,
    HUC1=255
} cart_type;

typedef union title_block title_block, *Ptitle_block;

typedef struct title_block_old title_block_old, *Ptitle_block_old;

typedef struct title_block_new title_block_new, *Ptitle_block_new;

typedef enum cgb_flag {
    NONE=0,
    SUPPORT=128,
    ONLY=192
} cgb_flag;

struct title_block_new {
    char title[11];
    char manufacturer_code[4];
    enum cgb_flag cgb_flag;
};

struct title_block_old {
    char title[15];
    enum cgb_flag cgb_flag;
};

union title_block {
    char title_only[16];
    struct title_block_old old_format;
    struct title_block_new new_format;
};

typedef enum ram_size {
    NONE=0,
    2KB=1,
    8KB=2,
    32KB=3,
    128KB=4,
    64KB=5
} ram_size;

typedef enum sgb_flag {
    NONE=0,
    SUPPORT=3
} sgb_flag;

typedef byte logo[48];

typedef struct header header, *Pheader;

typedef enum rom_size {
    32K=0,
    64K=1,
    128K=2,
    256K=3,
    512K=4,
    1MB=5,
    2MB=6,
    4MB=7,
    8MB=8
} rom_size;

typedef enum region {
    JAPAN=0,
    WORLD=1
} region;

struct header {
    union title_block title_block;
    char new_licensee_code[2];
    enum sgb_flag sgb_flag;
    enum cart_type cartridge_type;
    enum rom_size rom_size;
    enum ram_size ram_size;
    enum region region;
    byte old_licensee_code;
    byte mask_rom_version;
    byte header_checksum;
    word global_checksum;
};

undefined BYTE_cffd;
byte BYTE_dfff;
byte scrolling_x_stage_flag;
undefined DAT_feff;
byte button_pressed_neg;
byte[1024] tile_map_1;
byte TMA;
byte TAC;
byte io_interrupt_flags;
byte debug_scroll_x_init;
byte[12] oma_dma_routine_data;
byte game_state;
byte[49] unused_hram;
byte init_hardware_flag_debug;
byte lcdc_mirror;
byte io_lcd;
byte joypad_pressed;
byte io_lcd_status;
byte lcdc_negative;
byte io_scroll_y;
byte ball_phase_through;
byte io_scroll_x;
byte io_lcd_y_coordinate;
byte io_lyc;
byte BGP;
byte OBP0;
byte OBP1;
byte io_serial_transfer_control;
byte vblank_flag;
byte game_tick;
byte serial_phase_counter;
byte io_interrupt_enable;
byte object_dirty_flag;
byte io_serial_transfer_data;
byte serial_sample_curr;
byte serial_prev_sample;
byte serial_falling_edge_latch;
byte BYTE_c901;
byte oam_buffer_pad;
byte unused_blit_width;
byte[1024] tile_map_0;
byte oam_buffer_struct;
byte BYTE_c888;
byte[1424] tile_data_block_2;
byte[2048] vram_tile_block_2;
byte[117] tile_data_block_0;
byte[2048] vram_tile_block_0;
byte[1184] tile_data_block_1;
byte[2048] vram_tile_block_1;
byte button_pressed;
byte io_joypad_input;
byte button_pressed_flag;
byte score_digit_ones;
byte score_digit_tens;
byte score_digit_hundreds;
byte score_digit_thousands;
byte score_digit_tens_of_thousands;
byte frame_accumulator;
byte brick_type_last_hit;
byte BYTE_c806;
byte BYTE_c80a;
byte[4][6] brick_data_table;
byte BYTE_c80e;
byte BYTE_c812;
byte BYTE_c816;
byte BYTE_c81a;
byte BYTE_c81e;
byte BYTE_c89a;
byte BYTE_c89e;
undefined BYTE_3c08;
byte BYTE_c902;
byte BYTE_c903;
byte BYTE_c904;
undefined cartridge_header;
byte BYTE_c905;
byte BYTE_c906;
byte BYTE_c907;
byte BYTE_c908;
byte BYTE_c909;
byte LAB_0000;
undefined BYTE_ARRAY_0003;
byte LAB_0008;
byte rst_00_vector+1;
byte stage_number_display;
byte rst_00_vector+2;
byte LAB_0201+1;
undefined2 LAB_030f;
byte life_counter;
byte active_brick_count_hi;
byte active_brick_count_lo;
byte player_score_lo;
byte player_score_hi;
byte top_score_lo;
byte top_score_hi;
byte paddle_x;
byte paddle_size;
byte ball_x;
byte unused_brick_collision_count;
byte[16] io_wave_pattern_ram;
byte lcd_y_offset_counter;
byte level_demo_cycle_timer;
byte demo_flag;
byte WY;
byte WX;
byte unbreakable_brick_collision_counter;
byte[16][2] game_state_jump_table;
byte mario_jump_x_direction_flag;
byte[24] mario_jump_y_velocity_data;
logo nintendo_logo;
byte mario_jump_frame_index;
byte paddle_collision_width;
byte init_paddle_y;
byte true_stage_number;
byte track_index;
byte extra_life_gained_total;
byte brick_tilemap_offset_hi;
byte brick_tilemap_offset_lo;
byte title_demo_cycle_index;
byte current_anim_x;
byte current_anim_y;
byte bonus_stage_number;
byte BYTE_4075;
float level_scroll_x_max_timer;
byte[20] level_scroll_x_timer;
byte BYTE_c000;
byte lcd_y_descent_counter;
byte total_row_count;
byte object_state_array;
byte play_area_scroll_y;
byte BYTE_c00e;
byte ball_x_tile_play_area;
byte lcd_y;
byte lcd_y_vblank;
byte brick_scroll_flag;
byte[20] scroll_x_table;
byte extra_life_score_threshold_hi;
byte extra_life_score_threshold_lo;
byte[20] extra_life_threshold_table;
byte ball_collision_flag;
byte ball_y;
byte ball_x_velocity_hi;
byte ball_y_velocity_hi;
byte prev_ball_x;
byte ball_y_mirror;
byte prev_ball_y;
byte ball_x_mirror;
byte ball_y_velocity_lo;
byte ball_x_velocity_lo;
byte ball_velocity;
byte ball_y_subpixel;
byte ball_x_subpixel;
byte[16] BYTE_ARRAY_100b;
byte[50] ball_velocity_ptr_table;
byte BYTE_c80c;
byte BYTE_c80d;
byte BYTE_c80f;
byte[16] paddle_0_angle_steepness_data;
byte[12] paddle_1_angle_steepness_data;
byte[10] paddle_hit_max_value_table;
byte paddle_hit_counter;
byte BYTE_c801;
byte BYTE_c802;
byte BYTE_c803;
byte BYTE_c804;
byte BYTE_c805;
byte BYTE_c807;
byte BYTE_c808;
byte BYTE_c809;
byte BYTE_c80b;
byte BYTE_c880;
byte bonus_stage_time;
byte[15] special_bonus_text_tile_data;
byte[15] clear_special_bonus_text_tile_data;
byte[14] try_again!_tile_vram_data;
byte[14] clear_try_again!_tile_vram_data;
byte anim_timer;
byte mario_anim_frame;
byte[3] paddle_open_frame_0_tile_data;
byte[3] paddle_open_close_anim_spr_ptr;
byte BYTE_c884;
byte BYTE_c88c;
byte BYTE_c890;
byte BYTE_c894;
byte BYTE_c898;
byte BYTE_c89c;
byte BYTE_c881;
byte BYTE_c885;
byte BYTE_c889;
byte BYTE_c88d;
byte BYTE_c891;
byte BYTE_c895;
byte BYTE_c899;
byte BYTE_c89d;
byte BYTE_c883;
byte BYTE_c887;
byte BYTE_c88b;
byte BYTE_c88f;
byte BYTE_c893;
byte BYTE_c897;
byte BYTE_c89b;
byte BYTE_c89f;
byte BYTE_c882;
byte BYTE_c886;
byte BYTE_c88a;
byte BYTE_c88e;
byte BYTE_c892;
byte BYTE_c896;
byte BYTE_c814;
byte BYTE_c828;
byte BYTE_c829;
byte BYTE_c82a;
byte BYTE_c82b;
byte BYTE_c82c;
byte BYTE_c82d;
byte BYTE_c82e;
byte BYTE_c82f;
byte BYTE_c830;
byte BYTE_c831;
byte BYTE_c832;
byte BYTE_c833;
byte BYTE_c834;
byte BYTE_c835;
byte BYTE_c836;
byte BYTE_c837;
byte BYTE_c838;
byte BYTE_c839;
byte BYTE_c83a;
byte BYTE_c83b;
byte BYTE_c810;
byte BYTE_c818;
byte BYTE_c81c;
byte BYTE_c811;
byte BYTE_c815;
byte BYTE_c819;
byte BYTE_c81d;
byte BYTE_c813;
byte BYTE_c817;
byte BYTE_c81b;
byte BYTE_c81f;
byte BYTE_c83c;
byte[10] mario_start_spr_ptr_table;
byte NR50;
byte NR51;
byte NR52;
byte game_event;
byte ball_oob;
undefined oam_dma_routine;
byte DAT_ff81;
byte BYTE_dfd0;
byte BYTE_dfd1;
byte BYTE_dffe;
byte sfx_envelope_counter;
byte sfx_envelope;
byte ceiling_collision_sfx_active_flag;
byte current_sfx_active;
byte ch1_freq_hi;
byte io_audio_registers;
byte ch1_pitch;
byte NR11;
byte ch1_freq_lo;
byte NR12;
byte NR13;
byte NR14;
byte ch4_panning_timer;
byte ch4_panning;
byte ch2_pan_active;
byte ch2_note_length;
byte ch2_note_length_max;
byte ch3_note_length;
byte ch3_note_length_max;
byte ch3_pitch_mirror;
byte ch2_pitch_mirror;
byte[44] note_length_table;
byte[2][67] note_freq_lo_table;
byte music_triggered_flag;
byte NR21;
byte NR22;
byte ch1_current_track;
byte NR23;
byte ch3_current_track;
byte NR24;
byte NR30;
byte NR31;
byte NR32;
byte NR33;
byte NR34;
byte ch2_pattern_ptr_lo;
byte ch3_pattern_ptr_lo;
byte ch2_pattern_ptr_hi;
byte ch3_pattern_ptr_hi;
byte ch2_panning_triggered_flag;
byte ch2_pan_direction;
byte ch2_pan_timer_max;
byte ch2_pan_timer;
byte[16] ch3_waveform_data;
byte ch3_waveform_index;
byte music_flag;
byte debug_sfx_clear_flag;

void rst_38_crash(void)
{
    // Crash handler at RST $38 (0x0038). Loops indefinitely on real hardware.
    // Ghidra emits this as self-recursion; the actual instruction is an infinite loop.
    while(1);
}

void cartridge_header(void)
{
  game_init();
  return;
}

// The game initializes: VBlank is set

void game_init(void)
{
  char cVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  
  do {
    bVar2 = io_lcd_y_coordinate;
  } while (bVar2 < 0x91);
  io_lcd = 0;
  _BYTE_cffd = 0x160;
  disable_interrupts_save();
  cVar1 = '\x1f';
  cVar3 = '\0';
  pbVar6 = tile_map_1 + 0x3ff;
  do {
    do {
      pbVar4 = pbVar6 + -1;
      *pbVar6 = 0;
      cVar3 = cVar3 + -1;
      pbVar6 = pbVar4;
    } while (cVar3 != '\0');
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  cVar1 = '?';
  cVar3 = '\0';
  pbVar6 = &BYTE_dfff;
  do {
    do {
      pbVar4 = pbVar6 + -1;
      *pbVar6 = 0;
      cVar3 = cVar3 + -1;
      pbVar6 = pbVar4;
    } while (cVar3 != '\0');
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  cVar3 = '\x7f';
  pbVar6 = unused_hram + 0x30;
  do {
    *pbVar6 = 0;
    cVar3 = cVar3 + -1;
    pbVar6 = pbVar6 + -1;
  } while (cVar3 != '\0');
  cVar3 = -1;
  puVar5 = &DAT_feff;
  do {
    *puVar5 = 0;
    cVar3 = cVar3 + -1;
    puVar5 = puVar5 + -1;
  } while (cVar3 != '\0');
  _BYTE_cffd = 0x193;
  load_tile_data();
  _BYTE_cffd = 0x196;
  fill_tile_map_0();
  _BYTE_cffd = 0x199;
  fill_tile_map_1();
  bVar2 = 0x80;
  cVar3 = '\f';
  pbVar6 = oma_dma_routine_data;
  do {
    *(byte *)(bVar2 | 0xff00) = *pbVar6;
    bVar2 = bVar2 + 1;
    cVar3 = cVar3 + -1;
    pbVar6 = pbVar6 + 1;
  } while (cVar3 != '\0');
  io_interrupt_flags = 1;
  joypad_pressed = 1;
  io_lcd_status = 0x40;
  io_scroll_y = 0;
  io_scroll_x = 0;
  io_lcd = 0;
  BGP = 0xe4;
  OBP0 = 0xe4;
  OBP1 = 0xe4;
  button_pressed_neg = 0xff;
  io_lyc = 0;
  TAC = 0;
  TMA = 0;
  init_hardware_flag_debug = 0x20;
  io_interrupt_flags = 0;
  lcdc_negative = 0;
  debug_scroll_x_init = 0;
  game_state = 0;
  ball_phase_through = 0;
  scrolling_x_stage_flag = 0;
  lcdc_mirror = 0x83;
  io_lcd = 0x83;
  _BYTE_cffd = 0x1ec;
  interrupt_enable();
  main();
  return;
}

// sets up the joypad read, serial_phase_counter, DMA, OAM update, audio update and vblank flag: all
// functions that need to be read while Interrupts are disabled.

void vblank_handler(void)
{
  joypad_read();
  serial_phase_counter = 2;
  io_serial_transfer_control = 0x81;
  oam_dma_routine();
  oam_buffer_update();
  io_lcd = lcdc_mirror;
  io_scroll_x = lcdc_negative;
  io_scroll_y = debug_scroll_x_init;
  audio_update();
  game_tick = game_tick + 1;
  vblank_flag = 1;
  IME(1);
  return;
}

void wait_vblank(void)
{
  do {
    halt();
  } while( true );
}

void interrupt_enable(void)
{
  io_interrupt_enable = joypad_pressed;
  IME(1);
  return;
}

void disable_interrupts_save(void)
{
  joypad_pressed = io_interrupt_enable;
  io_interrupt_enable = 0;
  IME(0);
  return;
}

void check_object_dirty_flag(void)
{
  if (object_dirty_flag == 0) {
    return;
  }
  wait_vblank();
  return;
}

void lcd_ppu_enable(void)
{
  lcdc_mirror = lcdc_mirror & 0x7f | 0x80;
  io_lcd = lcdc_mirror;
  return;
}

void lcd_disable_and_wait_vblank(void)
{
  lcdc_mirror = lcdc_mirror & 0x7f;
  wait_vblank();
  return;
}

// waits 10 VBlanks before returning

void wait_frames(void)
{
  byte bVar1;
  int in_AF;
  
  do {
    wait_vblank();
    bVar1 = (char)((uint)in_AF >> 8) - 1;
    in_AF = (uint)bVar1 << 8;
  } while (bVar1 != 0);
  return;
}

void lcd_stat_handler(void)
{
  byte bVar1;
  
  lcd_stat_work();
  bVar1 = io_interrupt_flags;
  io_interrupt_flags = bVar1 & 0xfd;
  IME(1);
  return;
}

// REAL HARDWARE ONLY
// 2-phase serial sampler using internal clock
// compares consecutive SB reads and latches a filtered 1 -> 0 transition on bit 7 into FF93 (used
// as a rare, hardware-derived init condition)

void serial_falling_edge_detector_bit7(void)
{
  byte bVar1;
  
  bVar1 = serial_prev_sample;
  serial_phase_counter = serial_phase_counter - 1;
  if (serial_phase_counter == 0) {
                    // IF serial_phase_counter = 0
    serial_prev_sample = io_serial_transfer_data;
    serial_falling_edge_latch = serial_prev_sample ^ bVar1 ^ 0xff | serial_prev_sample;
    IME(1);
    return;
  }
                    // IF serial_phase_counter = 1
  serial_sample_curr = io_serial_transfer_data;
  io_serial_transfer_control = 0x81;
  IME(1);
  return;
}

// constantly fill the serial transfer data with 1s
// this, in turn, fills the the register with FF

void serial_init(void)
{
  byte bVar1;
  
  io_serial_transfer_data = 1;
  bVar1 = io_interrupt_enable;
  io_interrupt_enable = bVar1 | 8;
  return;
}

void oam_buffer_update(void)
{
  void *in_HL;
  
  if (object_dirty_flag != 0) {
    is_oam_buffer_empty(in_HL);
    oam_buffer_pad = 0;
    BYTE_c901 = 0;
    object_dirty_flag = 0;
  }
  return;
}

void copy_oam_buffer_to_hl(void)
{
  char *in_DE;
  
  do {
    in_DE = in_DE + 3;
    oam_buffer_handler();
  } while (*in_DE != '\0');
  return;
}

void __thiscall is_oam_buffer_empty(void *this)
{
  char *in_DE;
  
  while (*in_DE != '\0') {
    in_DE = in_DE + 3;
    oam_buffer_handler();
  }
  return;
}

void oam_buffer_handler(void)
{
  byte bVar1;
  byte bVar2;
  undefined2 in_AF;
  byte bVar3;
  undefined1 uVar5;
  undefined1 *in_DE;
  undefined1 *in_HL;
  byte bVar4;
  
  bVar4 = (byte)((uint)in_AF >> 8);
  bVar3 = bVar4 & 0x3f;
  bVar1 = -((char)bVar4 >> 7);
  bVar2 = -((char)(bVar4 << 1 | bVar1) >> 7);
  bVar4 = ((char)bVar4 >> 7) * -2 | bVar2;
  if (bVar1 == 0 && bVar2 == 0) {
    do {
      *in_HL = *in_DE;
      in_DE = in_DE + 1;
      bVar3 = bVar3 - 1;
      in_HL = in_HL + 1;
    } while (bVar3 != 0);
    return;
  }
  if (bVar4 == 1) {
    uVar5 = *in_DE;
    do {
      *in_HL = uVar5;
      bVar3 = bVar3 - 1;
      in_HL = in_HL + 1;
    } while (bVar3 != 0);
    return;
  }
  if (bVar4 == 2) {
    do {
      *in_HL = *in_DE;
      in_DE = in_DE + 1;
      in_HL = in_HL + 0x20;
      bVar3 = bVar3 - 1;
    } while (bVar3 != 0);
    return;
  }
  do {
    *in_HL = *in_DE;
    in_HL = in_HL + 0x20;
    bVar3 = bVar3 - 1;
  } while (bVar3 != 0);
  return;
}

// general-purpose rectangular tile stamp routine.
// walks a descriptor table and writes rectangular regions of tiles into VRAM, supporting both
// unique-tile copies and single-tile fills.
// most likely a scrapped screen layout loader to replace the many load_*_vram functions in the
// game.

void unused_tilemap_blit(void)
{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 *unaff_retaddr;
  char *pcStack_6;
  char *pcVar5;
  
  pcVar4 = (char *)*unaff_retaddr;
  while( true ) {
    if (*pcVar4 == -1) break;
    pcVar3 = (char *)CONCAT11(*pcVar4,pcVar4[1]);
    bVar1 = pcVar4[2] & 0x1f;
    unused_blit_width = pcVar4[3];
    pcVar5 = pcVar4 + 4;
    bVar2 = unused_blit_width;
    pcStack_6 = pcVar3;
    if ((pcVar4[2] & 0x80U) == 0) {
      do {
        do {
          *pcVar3 = pcVar4[4];
          pcVar3 = pcVar3 + 1;
          bVar2 = bVar2 - 1;
        } while (bVar2 != 0);
        pcVar3 = pcStack_6 + 0x20;
        bVar1 = bVar1 - 1;
        bVar2 = unused_blit_width;
        pcStack_6 = pcVar3;
      } while (bVar1 != 0);
      pcVar4 = pcVar4 + 5;
    }
    else {
      do {
        do {
          pcVar4 = pcVar5 + 1;
          *pcVar3 = *pcVar5;
          pcVar3 = pcVar3 + 1;
          bVar2 = bVar2 - 1;
          pcVar5 = pcVar4;
        } while (bVar2 != 0);
        pcVar3 = pcStack_6 + 0x20;
        bVar1 = bVar1 - 1;
        bVar2 = unused_blit_width;
        pcStack_6 = pcVar3;
      } while (bVar1 != 0);
    }
  }
  return;
}

// Fill tile_map_0 with 0xFF tiles

void fill_tile_map_0(void)
{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0x400;
  pbVar2 = tile_map_0;
  do {
    *pbVar2 = 0xff;
    iVar1 = iVar1 + -1;
    pbVar2 = pbVar2 + 1;
  } while (iVar1 != 0);
  return;
}

// Fill tile_map_1 with 0xFF tiles

void fill_tile_map_1(void)
{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0x400;
  pbVar2 = tile_map_1;
  do {
    *pbVar2 = 0xff;
    iVar1 = iVar1 + -1;
    pbVar2 = pbVar2 + 1;
  } while (iVar1 != 0);
  return;
}

// clear most OAMs' buffer on screen during gameplay

void clear_main_oam_buffer(void)
{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = -0x60;
  pbVar2 = &oam_buffer_struct;
  do {
    *pbVar2 = 0;
    cVar1 = cVar1 + -1;
    pbVar2 = pbVar2 + 1;
  } while (cVar1 != '\0');
  return;
}

// Clears the OAM buffer of the explosion

void clear_anim_oam_buffer(void)
{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = '\x18';
  pbVar2 = &BYTE_c888;
  do {
    *pbVar2 = 0;
    cVar1 = cVar1 + -1;
    pbVar2 = pbVar2 + 1;
  } while (cVar1 != '\0');
  return;
}

// Loads all the visual assets of ROM Bank 01 into the 3 VRAM tile blocks

void load_tile_data(void)
{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = vram_tile_block_2;
  iVar1 = 0x800;
  pbVar3 = tile_data_block_2;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (iVar1 != 0);
  pbVar2 = vram_tile_block_1;
  iVar1 = 0x800;
  pbVar3 = tile_data_block_1;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (iVar1 != 0);
  pbVar2 = vram_tile_block_0;
  iVar1 = 0x800;
  pbVar3 = tile_data_block_0;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (iVar1 != 0);
  return;
}

void joypad_read(void)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  
  io_joypad_input = 0x20;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  bVar2 = io_joypad_input;
  io_joypad_input = 0x10;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  bVar3 = io_joypad_input;
  button_pressed_flag = bVar3 & 0xf | bVar2 << 4;
  button_pressed_neg = button_pressed_flag;
  io_joypad_input = 0x30;
  cVar4 = '\b';
  do {
    bVar1 = (bool)(button_pressed & 1);
    button_pressed = button_pressed >> 1;
    bVar2 = bVar1 << 7 | button_pressed;
    if (bVar1) {
      bVar1 = (bool)(button_pressed_flag & 1);
      button_pressed_flag = bVar1 << 7 | button_pressed_flag >> 1;
      if (!bVar1) {
        button_pressed_flag = button_pressed_flag | 0x80;
        button_pressed = bVar2;
      }
    }
    else {
      bVar1 = (bool)(button_pressed_flag & 1);
      button_pressed_flag = bVar1 << 7 | button_pressed_flag >> 1;
      button_pressed = bVar2;
      if (!bVar1) {
        button_pressed = bVar2 | 0x80;
      }
    }
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return;
}

void nop_handler(void)
{
  return;
}

void debug_update_vblank(void)
{
  byte bVar1;
  
  bVar1 = io_interrupt_enable;
  io_interrupt_enable = bVar1 & 0xfe;
  return;
}

void debug_enable_vblank(void)
{
  byte bVar1;
  
  bVar1 = io_interrupt_enable;
  io_interrupt_enable = bVar1 | 1;
  return;
}

// BC = B x E

void multiply(void)
{
  char cVar1;
  
  cVar1 = '\b';
  do {
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// general use math that never gets used in the game

void unused_load_absolute_value(void)
{
  char in_A;
  char in_B;
  
  if ((in_A - in_B & 0x80U) == 0) {
    return;
  }
  return;
}

// converts A to decimal digits: C=hundreds, B=tens, A=units

void binary_to_bcd(void)
{
  bool bVar1;
  byte in_A;
  byte bVar2;
  
  do {
    bVar2 = in_A;
    in_A = bVar2 + 0x9c;
  } while (99 < bVar2);
  do {
    bVar1 = 9 < bVar2;
    bVar2 = bVar2 - 10;
  } while (bVar1);
  return;
}

// $FF96-$FF9A

void score_to_bcd(void)
{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte in_A;
  byte in_B;
  
  score_digit_tens_of_thousands = 0xff;
  bVar3 = in_B;
  score_digit_tens = in_A;
  do {
    score_digit_ones = bVar3;
    score_digit_tens_of_thousands = score_digit_tens_of_thousands + 1;
    bVar1 = (score_digit_tens - 0x27) - (score_digit_ones < 0x10);
    bVar2 = (byte)((score_digit_ones < 0x10) + 0x27U) <= score_digit_tens;
    bVar3 = score_digit_ones - 0x10;
    score_digit_tens = bVar1;
  } while (bVar2);
  score_digit_thousands = 0xff;
  bVar3 = score_digit_ones;
  score_digit_tens = bVar1 + 0x27 + (0xef < (byte)(score_digit_ones - 0x10));
  do {
    score_digit_ones = bVar3;
    score_digit_thousands = score_digit_thousands + 1;
    bVar1 = (score_digit_tens - 3) - (score_digit_ones < 0xe8);
    bVar2 = (byte)((score_digit_ones < 0xe8) + 3U) <= score_digit_tens;
    bVar3 = score_digit_ones + 0x18;
    score_digit_tens = bVar1;
  } while (bVar2);
  score_digit_hundreds = 0xff;
  bVar3 = score_digit_ones;
  score_digit_tens = bVar1 + 3 + (0x17 < (byte)(score_digit_ones + 0x18));
  do {
    score_digit_ones = bVar3;
    score_digit_hundreds = score_digit_hundreds + 1;
    bVar2 = (score_digit_ones < 100) <= score_digit_tens;
    bVar3 = score_digit_ones + 0x9c;
    score_digit_tens = score_digit_tens - (score_digit_ones < 100);
  } while (bVar2);
  score_digit_tens = 0xff;
  bVar3 = score_digit_ones;
  do {
    score_digit_ones = bVar3;
    score_digit_tens = score_digit_tens + 1;
    bVar3 = score_digit_ones - 10;
  } while (9 < score_digit_ones);
  return;
}

// Advances a hidden frame accumulator (likely debug leftover).
// Adds 0x41 per frame via 5 iterations of +0x0D.

void debug_update_frame_accumulator(void)
{
  char cVar1;
  
  cVar1 = '\x05';
  do {
    frame_accumulator = frame_accumulator + 0xd;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// Audio and Serial registers are initialized. The main loop is contained here.

void main(void)
{
  audio_init();
  serial_init();
  game_state = 0;
  ball_phase_through = 0;
  scrolling_x_stage_flag = 0;
  do {
    game_state_dispatcher();
    debug_update_frame_accumulator();
    wait_vblank();
  } while( true );
}

// The dispatcher uses JP HL (0x054B) to index a 16-entry little-endian jump table.
// Ghidra cannot resolve the indirect jump statically, producing spurious case branches
// below case 0x1E. Those cases are decompiler artifacts and should be ignored.
// This is also why the switchD_054b struct at the top of the file is unresolved.
// Reads game_state value, uses it for the jump table and JP to corresponding handler.

void game_state_dispatcher(void)
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  byte in_F;
  uint uVar5;
  state_dispatcher sVar6;
  byte bVar7;
  char cVar8;
  byte bVar10;
  char cVar11;
  byte *pbVar9;
  int iVar12;
  byte *in_DE;
  undefined1 uVar13;
  byte *pbVar14;
  byte *this;
  undefined1 uVar16;
  char *pcVar15;
  int *piVar17;
  undefined2 unaff_retaddr;
  
  bVar7 = (byte)((uint)unaff_retaddr >> 8);
  if (((button_pressed_neg & 8) == 0) && ((button_pressed_flag & 4) == 0)) {
    game_state = 1;
    rst_00_vector = 0xc3;
    bRam0001 = 0x50;
    bRam0002 = 1;
    BYTE_ARRAY_0003[0] = 0xff;
    BYTE_ARRAY_0003[1] = 0xff;
    BYTE_ARRAY_0003[2] = 0xff;
    rst_08_vector = 0xff;
    nintendo_logo[0x18] = 0xdc;
    bRam0202 = 0xa1;
    uRam030f = 0x4428;
    _BYTE_3c08 = (undefined1 *)0x100;
    return;
  }
  bVar1 = game_state << 1;
  bVar2 = bVar1 == 0;
  bVar4 = 0xfab3 < bVar1;
  bVar10 = game_state_jump_table[0][bVar1];
  uVar5 = CONCAT11(bVar10,in_F & 0xf | bVar4 << 4);
  pbVar9 = (byte *)CONCAT11(bVar10,bVar1);
  this = *(byte **)(game_state_jump_table[0] + bVar1);
  switch(bVar1) {
  case 0:
    top_score_lo = 200;
    top_score_hi = 0;
    game_state = 1;
    rst_00_vector = 0xc3;
    bRam0001 = 0x50;
    bRam0002 = 1;
    BYTE_ARRAY_0003[0] = 0xff;
    BYTE_ARRAY_0003[1] = 0xff;
    BYTE_ARRAY_0003[2] = 0xff;
    rst_08_vector = 0xff;
    nintendo_logo[0x18] = 0xdc;
    bRam0202 = 0xa1;
    uRam030f = 0x4428;
    _BYTE_3c08 = (undefined1 *)0x100;
    return;
  case 2:
    title_demo_cycle_index = 4;
    game_state = 2;
    rst_00_vector = 0xc3;
    bRam0001 = 0x50;
    bRam0002 = 1;
    BYTE_ARRAY_0003[0] = 0xff;
    BYTE_ARRAY_0003[1] = 0xff;
    BYTE_ARRAY_0003[2] = 0xff;
    rst_08_vector = 0xff;
    nintendo_logo[0x18] = 0xdc;
    bRam0202 = 0xa1;
    uRam030f = 0x4428;
    _BYTE_3c08 = (undefined1 *)0x100;
    return;
  case 4:
    lcd_disable_and_wait_vblank();
    disable_interrupts_save();
    joypad_pressed = joypad_pressed & 0xfd;
    fill_tile_map_0();
    clear_main_oam_buffer();
    is_oam_buffer_empty(this);
    load_title_screen_score_buffer_oam();
    BGP = 0xe4;
    lcdc_mirror = lcdc_mirror & 0xdf;
    interrupt_enable();
    lcd_ppu_enable();
    title_demo_cycle_index = title_demo_cycle_index + 1;
    if (title_demo_cycle_index == 5) {
      title_demo_cycle_index = 0;
    }
    if (title_demo_cycle_index == 0) {
      clear_demo_flag();
      load_track_title();
    }
    else {
      set_demo_flag();
    }
    level_demo_cycle_timer = 3;
    do {
      wait_vblank();
      if (game_tick == 0) {
        level_demo_cycle_timer = level_demo_cycle_timer - 1;
        if (level_demo_cycle_timer == 0) {
          game_state = 3;
          return;
        }
      }
    } while (((button_pressed_flag & 8) != 0) && ((serial_falling_edge_latch & 0x80) != 0));
    true_stage_number = 0;
    stage_number_display = 0;
    bonus_stage_number = 0;
    extra_life_gained_total = 0;
    player_score_lo = 0;
    player_score_hi = 0;
    life_counter = 4;
    set_next_extra_life_score_threshold();
    clear_demo_flag();
    level_load_handler();
    game_state = 4;
    return;
  case 6:
    set_demo_flag();
    level_load_handler();
    do {
      uVar13 = SUB21(pbVar9,0);
      bVar7 = (byte)(uVar5 >> 8);
      debug_update_frame_accumulator();
      true_stage_number = bVar7 & 0x1f;
      pbVar9 = (byte *)(CONCAT11(bVar7,uVar13) & 0x1fff);
      multiply();
      sVar6 = *(state_dispatcher *)(pbVar9 + 0x1be1);
      uVar5 = (uint)(byte)sVar6 << 8;
    } while (((byte)sVar6 & 0x80) != 0);
    stage_number_display = 0xff;
    player_score_lo = 0;
    player_score_hi = 0;
    life_counter = 0;
    state_dispatcher::init_load_stage((state_dispatcher *)(pbVar9 + 0x1be1));
    level_demo_cycle_timer = 10;
    shift_paddle_left();
    init_ball();
    paddle_x = ball_x - 0xb;
    update_paddle_oam_buffer();
    wait_frames();
    do {
      scroll_x_handler();
      ball_update();
      update_paddle_oam_buffer();
      paddle_x = ball_x - 0xb;
      clamp_paddle_x();
      debug_update_frame_accumulator();
      wait_vblank();
      if (((button_pressed_flag & 8) == 0) || ((serial_falling_edge_latch & 0x80) == 0)) {
        game_state = 1;
        return;
      }
    } while ((game_tick != 0) ||
            (level_demo_cycle_timer = level_demo_cycle_timer - 1, level_demo_cycle_timer != 0));
    wait_frames();
    game_state = 2;
    return;
  case 8:
  case 0xf2:
    clear_bonus_time_text_vram();
    uVar13 = SUB21(pbVar9,0);
    clear_special_bonus_text_vram();
    ball_phase_through = 0;
    scrolling_x_stage_flag = 0;
    paddle_size = 0;
    paddle_collision_width = 0x18;
    iVar12 = CONCAT11(true_stage_number,uVar13);
    multiply();
    bVar7 = *(byte *)(iVar12 + 0x1be1);
    if ((bVar7 & 0x80) == 0) {
      increment_stage_number_display();
    }
    else {
      bonus_ball_set();
    }
    if ((bVar7 & 0x40) != 0) {
      init_scrolling_stage_data();
    }
    paddle_x = 0x28;
    init_paddle_y = 0x90;
    load_level_brick_data();
    count_level_bricks();
    init_scroll_x_table();
    load_wall_oam_buffer();
    update_score_oam_buffer();
    load_lives_number_vram();
    debug_ball_velocity();
    if (stage_number_display == 1) {
      mario_start_handler();
    }
    if (ball_phase_through == 0) {
      load_stage_number_oam_buffer();
    }
    else {
      load_bonus_text_oam_buffer();
    }
    update_score_oam_buffer();
    debug_ball_velocity();
    load_lives_number_vram();
    load_stage_number_display_vram();
    wait_frames();
    animate_bricks_scroll_in();
    clear_main_oam_buffer();
    update_score_oam_buffer();
    debug_ball_velocity();
    load_wall_oam_buffer();
    if (ball_phase_through != 0) {
      bonus_start_handler();
    }
    lcd_y_offset_counter = 0;
    game_state = 5;
    return;
  case 10:
    scroll_x_handler();
    paddle_update();
    if (((button_pressed_flag & 1) != 0) && ((serial_falling_edge_latch & 0x80) != 0)) {
      return;
    }
    unused_brick_collision_count = 0;
    unbreakable_brick_collision_counter = 0;
    update_brick_scrolldown_threshold();
    ball_spawn_handler();
    debug_ball_velocity();
    load_lives_number_vram();
    set_event_ball_launched();
    if (ball_phase_through != 0) {
      load_track_bonus_stage();
    }
    game_state = 6;
    return;
  case 0xc:
    if (ball_phase_through != 0) {
      decrement_bonus_stage_time();
    }
    scroll_x_handler();
    ball_update();
    paddle_update();
    if ((button_pressed_flag & 8) != 0) {
      if ((serial_falling_edge_latch & 0x80) != 0) {
        return;
      }
      serial_falling_edge_latch = 0xff;
    }
    if (ball_phase_through == 0) {
      load_pause_text_oam_buffer();
      load_track_pause();
      game_state = 0xc;
      return;
    }
    return;
  case 0xe:
    stop_music_wrapper();
    explosion_oam_handler();
    wait_frames();
    if (ball_phase_through == 0) {
      game_state = 0xb;
      if (life_counter != 0) {
        life_counter = life_counter - 1;
        load_lives_number_vram();
        paddle_size = 0;
        paddle_collision_width = 0x18;
        lcd_y_offset_counter = 2;
        game_state = 5;
        return;
      }
      return;
    }
  case 0x10:
    if (ball_phase_through == 0) {
      load_track_5_and_wait();
    }
    else {
      state_dispatcher::init_bonus_state();
    }
    game_win_handler();
    game_state = 4;
    if (true_stage_number == 0) {
      game_state = 9;
    }
    return;
  case 0x12:
    game_win_fade_handler();
    joypad_pressed = joypad_pressed & 0xfd;
    level_load_handler();
    joypad_pressed = joypad_pressed & 0xfd;
    io_interrupt_enable = joypad_pressed;
    load_wall_oam_buffer();
    update_score_oam_buffer();
    load_lives_number_vram();
    debug_ball_velocity();
    load_stage_number_display_vram();
    load_track_nice_play_();
    load_fade_in_data();
    wait_frames();
    wait_frames();
    wait_frames();
    wait_frames();
    mario_wink_oam_handler();
    wait_frames();
    wait_frames();
    load_try_again__vram();
    wait_frames();
    clear_try_again__vram();
    game_win_fade_handler();
    joypad_pressed = joypad_pressed | 2;
    io_interrupt_enable = joypad_pressed;
    clear_objects_wram0();
    bricks_slide_in_from_top();
    load_fade_in_data();
    game_state = 4;
    return;
  case 0x14:
    stop_music_wrapper();
    if (active_brick_count_lo != 0 || active_brick_count_hi != 0) {
      load_track_bonus_stage_lose();
      wait_frames();
      return;
    }
    load_track_bonus_stage_win();
    wait_frames();
    wait_frames();
    load_special_bonus_text_vram();
    update_bonus_stage_properties();
    iVar12 = CONCAT11(this[1],this[2]);
    load_special_bonus_points_oam_buffer();
    wait_frames();
    do {
      if ((char)((uint)iVar12 >> 8) == '\0') {
        if ((byte)iVar12 == 0) {
          return;
        }
        if ((byte)iVar12 < 10) {
          do {
            iVar12 = iVar12 + -1;
            load_special_bonus_points_oam_buffer();
            iVar3 = CONCAT11(player_score_hi,player_score_lo) + 1;
            player_score_hi = (byte)((uint)iVar3 >> 8);
            player_score_lo = (byte)iVar3;
            update_score_all();
            extra_life_score_handler();
            update_score_oam_buffer();
            set_event_bonus_countdown();
            wait_vblank();
          } while (iVar12 != 0);
          return;
        }
      }
      iVar12 = iVar12 + -10;
      load_special_bonus_points_oam_buffer();
      iVar3 = CONCAT11(player_score_hi,player_score_lo) + 10;
      player_score_hi = (byte)((uint)iVar3 >> 8);
      player_score_lo = (byte)iVar3;
      update_score_all();
      extra_life_score_handler();
      update_score_oam_buffer();
      set_event_bonus_countdown();
      wait_vblank();
    } while( true );
  case 0x16:
    mario_game_over_handler();
    wait_frames();
    lcd_disable_and_wait_vblank();
    disable_interrupts_save();
    fill_tile_map_0();
    clear_main_oam_buffer();
    lcdc_mirror = lcdc_mirror & 0xdf;
    joypad_pressed = joypad_pressed & 0xfd;
    load_track_game_over();
    load_game_over_text_oam_buffer();
    interrupt_enable();
    lcd_ppu_enable();
    wait_frames();
    game_state = 1;
    return;
  case 0x18:
    if ((button_pressed_flag & 8) != 0) {
      if ((serial_falling_edge_latch & 0x80) != 0) {
        rst_00_vector = 0xc3;
        bRam0001 = 0x50;
        bRam0002 = 1;
        BYTE_ARRAY_0003[0] = 0xff;
        BYTE_ARRAY_0003[1] = 0xff;
        BYTE_ARRAY_0003[2] = 0xff;
        rst_08_vector = 0xff;
        nintendo_logo[0x18] = 0xdc;
        bRam0202 = 0xa1;
        uRam030f = 0x4428;
        _BYTE_3c08 = (undefined1 *)0x100;
        return;
      }
      serial_falling_edge_latch = 0xff;
    }
    clear_main_oam_buffer();
    update_score_oam_buffer();
    debug_ball_velocity();
    load_wall_oam_buffer();
    break;
  case 0x1a:
  case 0x1c:
  case 0x1e:
    rst_00_vector = 0xc3;
    bRam0001 = 0x50;
    bRam0002 = 1;
    BYTE_ARRAY_0003[0] = 0xff;
    BYTE_ARRAY_0003[1] = 0xff;
    BYTE_ARRAY_0003[2] = 0xff;
    rst_08_vector = 0xff;
    nintendo_logo[0x18] = 0xdc;
    bRam0202 = 0xa1;
    uRam030f = 0x4428;
    _BYTE_3c08 = (undefined1 *)0x100;
    return;
  }
  // NOTE: All cases below this point are decompiler artifacts.
  // The actual dispatch is JP HL at 0x054B, which Ghidra cannot statically resolve.
  // Ghidra misreads the 16-entry jump table bytes and subsequent code as additional
  // case branches. Only cases 0x00–0x1E above correspond to real game states.
}

// set top score to 200
// top score isn't saved

void state_dispatcher::init_boot_init(void)
{
  top_score_lo = 200;
  top_score_hi = 0;
  game_state = 1;
  return;
}

void state_dispatcher::init_game_init(void)
{
  title_demo_cycle_index = 4;
  game_state = 2;
  return;
}

void __thiscall state_dispatcher::init_title_screen(state_dispatcher *this)
{
  lcd_disable_and_wait_vblank();
  disable_interrupts_save();
  joypad_pressed = joypad_pressed & 0xfd;
  fill_tile_map_0();
  clear_main_oam_buffer();
  is_oam_buffer_empty(this);
  load_title_screen_score_buffer_oam();
  BGP = 0xe4;
  lcdc_mirror = lcdc_mirror & 0xdf;
  interrupt_enable();
  lcd_ppu_enable();
  title_demo_cycle_index = title_demo_cycle_index + 1;
  if (title_demo_cycle_index == 5) {
    title_demo_cycle_index = 0;
  }
  if (title_demo_cycle_index == 0) {
    clear_demo_flag();
    load_track_title();
  }
  else {
    set_demo_flag();
  }
  level_demo_cycle_timer = 3;
  do {
    wait_vblank();
    if (game_tick == 0) {
      level_demo_cycle_timer = level_demo_cycle_timer - 1;
      if (level_demo_cycle_timer == 0) {
        game_state = 3;
        return;
      }
    }
  } while (((button_pressed_flag & 8) != 0) && ((serial_falling_edge_latch & 0x80) != 0));
  true_stage_number = 0;
  stage_number_display = 0;
  bonus_stage_number = 0;
  extra_life_gained_total = 0;
  player_score_lo = 0;
  player_score_hi = 0;
  life_counter = 4;
  set_next_extra_life_score_threshold();
  clear_demo_flag();
  level_load_handler();
  game_state = 4;
  return;
}

void state_dispatcher::init_load_demo(void)
{
  state_dispatcher in_A;
  undefined1 uVar1;
  uint in_BC;
  
  set_demo_flag();
  level_load_handler();
  do {
    uVar1 = (undefined1)in_BC;
    debug_update_frame_accumulator();
    true_stage_number = (byte)in_A & 0x1f;
    in_BC = CONCAT11(in_A,uVar1) & 0x1fff;
    multiply();
    in_A = *(state_dispatcher *)(in_BC + 0x1be1);
  } while (((byte)in_A & 0x80) != 0);
  stage_number_display = 0xff;
  player_score_lo = 0;
  player_score_hi = 0;
  life_counter = 0;
  init_load_stage((state_dispatcher *)(in_BC + 0x1be1));
  level_demo_cycle_timer = 10;
  shift_paddle_left();
  init_ball();
  paddle_x = ball_x - 0xb;
  update_paddle_oam_buffer();
  wait_frames();
  do {
    scroll_x_handler();
    ball_update();
    update_paddle_oam_buffer();
    paddle_x = ball_x - 0xb;
    clamp_paddle_x();
    debug_update_frame_accumulator();
    wait_vblank();
    if (((button_pressed_flag & 8) == 0) || ((serial_falling_edge_latch & 0x80) == 0)) {
      game_state = 1;
      return;
    }
  } while ((game_tick != 0) ||
          (level_demo_cycle_timer = level_demo_cycle_timer - 1, level_demo_cycle_timer != 0));
  wait_frames();
  game_state = 2;
  return;
}

void __thiscall state_dispatcher::init_load_stage(state_dispatcher *this)
{
  byte bVar1;
  undefined1 in_C;
  int iVar2;
  
  clear_bonus_time_text_vram();
  clear_special_bonus_text_vram();
  ball_phase_through = 0;
  scrolling_x_stage_flag = 0;
  paddle_size = 0;
  paddle_collision_width = 0x18;
  iVar2 = CONCAT11(true_stage_number,in_C);
  multiply();
  bVar1 = *(byte *)(iVar2 + 0x1be1);
  if ((bVar1 & 0x80) == 0) {
    increment_stage_number_display();
  }
  else {
    bonus_ball_set();
  }
  if ((bVar1 & 0x40) != 0) {
    init_scrolling_stage_data();
  }
  paddle_x = 0x28;
  init_paddle_y = 0x90;
  load_level_brick_data();
  count_level_bricks();
  init_scroll_x_table();
  load_wall_oam_buffer();
  update_score_oam_buffer();
  load_lives_number_vram();
  debug_ball_velocity();
  if (stage_number_display == 1) {
    mario_start_handler();
  }
  if (ball_phase_through == 0) {
    load_stage_number_oam_buffer();
  }
  else {
    load_bonus_text_oam_buffer();
  }
  update_score_oam_buffer();
  debug_ball_velocity();
  load_lives_number_vram();
  load_stage_number_display_vram();
  wait_frames();
  animate_bricks_scroll_in();
  clear_main_oam_buffer();
  update_score_oam_buffer();
  debug_ball_velocity();
  load_wall_oam_buffer();
  if (ball_phase_through != 0) {
    bonus_start_handler();
  }
  lcd_y_offset_counter = 0;
  game_state = 5;
  return;
}

// ball phases through and increase the bonus level number

void bonus_ball_set(void)
{
  ball_phase_through = 1;
  bonus_stage_number = bonus_stage_number + 1;
  return;
}

// triggers upon losing in a bonus level
// 

void increment_stage_number_display(void)
{
  stage_number_display = stage_number_display + 1;
  return;
}

// set if the stage number displayed's value's bit 6 is set to 1

void init_scrolling_stage_data(void)
{
  byte bVar1;
  char cVar2;
  undefined2 in_AF;
  float *pfVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pfVar3 = &level_scroll_x_max_timer;
  pbVar4 = level_scroll_x_timer;
  cVar2 = '\x14';
  pbVar5 = *(byte **)(&BYTE_4075 + (byte)(((byte)((uint)in_AF >> 8) & 0x3f) << 1));
  do {
    bVar1 = *pbVar5;
    *(byte *)pfVar3 = bVar1;
    *pbVar4 = bVar1 & 0x7f;
    pfVar3 = (float *)((int)pfVar3 + 1);
    pbVar4 = pbVar4 + 1;
    cVar2 = cVar2 + -1;
    pbVar5 = pbVar5 + 1;
  } while (cVar2 != '\0');
  scrolling_x_stage_flag = 1;
  return;
}

void state_dispatcher::init_standby_play(void)
{
  scroll_x_handler();
  paddle_update();
  if (((button_pressed_flag & 1) != 0) && ((serial_falling_edge_latch & 0x80) != 0)) {
    return;
  }
  unused_brick_collision_count = 0;
  unbreakable_brick_collision_counter = 0;
  update_brick_scrolldown_threshold();
  ball_spawn_handler();
  debug_ball_velocity();
  load_lives_number_vram();
  set_event_ball_launched();
  if (ball_phase_through != 0) {
    load_track_bonus_stage();
  }
  game_state = 6;
  return;
}

void init_ball(void)
{
  unused_brick_collision_count = 0;
  unbreakable_brick_collision_counter = 0;
  update_brick_scrolldown_threshold();
  ball_spawn_handler();
  debug_ball_velocity();
  load_lives_number_vram();
  set_event_ball_launched();
  if (ball_phase_through != 0) {
    load_track_bonus_stage();
  }
  game_state = 6;
  return;
}

void state_dispatcher::init_normal_play(void)
{
  if (ball_phase_through != 0) {
    decrement_bonus_stage_time();
  }
  scroll_x_handler();
  ball_update();
  paddle_update();
  if ((button_pressed_flag & 8) != 0) {
    if ((serial_falling_edge_latch & 0x80) != 0) {
      return;
    }
    serial_falling_edge_latch = 0xff;
  }
  if (ball_phase_through != 0) {
    return;
  }
  load_pause_text_oam_buffer();
  load_track_pause();
  game_state = 0xc;
  return;
}

void state_dispatcher::init_lose_life(void)
{
  stop_music_wrapper();
  explosion_oam_handler();
  wait_frames();
  if (ball_phase_through != 0) {
    if (ball_phase_through == 0) {
      load_track_5_and_wait();
    }
    else {
      init_bonus_state();
    }
    game_win_handler();
    game_state = 4;
    if (true_stage_number == 0) {
      game_state = 9;
    }
    return;
  }
  game_state = 0xb;
  if (life_counter != 0) {
    life_counter = life_counter - 1;
    load_lives_number_vram();
    paddle_size = 0;
    paddle_collision_width = 0x18;
    lcd_y_offset_counter = 2;
    game_state = 5;
    return;
  }
  return;
}

void state_dispatcher::init_stage_clear(void)
{
  if (ball_phase_through == 0) {
    load_track_5_and_wait();
  }
  else {
    init_bonus_state();
  }
  game_win_handler();
  game_state = 4;
  if (true_stage_number == 0) {
    game_state = 9;
  }
  return;
}

void load_track_5_and_wait(void)
{
  load_track_stage_complete();
  wait_frames();
  return;
}

// checks if the player has reached the last level
// if so, load the win animation/screen and set the player back to level 0

void game_win_handler(void)
{
  true_stage_number = true_stage_number + 1;
  if (0x1f < true_stage_number) {
    true_stage_number = 0;
  }
  return;
}

void state_dispatcher::init_win(void)
{
  game_win_fade_handler();
  joypad_pressed = joypad_pressed & 0xfd;
  level_load_handler();
  joypad_pressed = joypad_pressed & 0xfd;
  io_interrupt_enable = joypad_pressed;
  load_wall_oam_buffer();
  update_score_oam_buffer();
  load_lives_number_vram();
  debug_ball_velocity();
  load_stage_number_display_vram();
  load_track_nice_play_();
  load_fade_in_data();
  wait_frames();
  wait_frames();
  wait_frames();
  wait_frames();
  mario_wink_oam_handler();
  wait_frames();
  wait_frames();
  load_try_again__vram();
  wait_frames();
  clear_try_again__vram();
  game_win_fade_handler();
  joypad_pressed = joypad_pressed | 2;
  io_interrupt_enable = joypad_pressed;
  clear_objects_wram0();
  bricks_slide_in_from_top();
  load_fade_in_data();
  game_state = 4;
  return;
}

// when the players wins the game, the screens fades out and in to show the "win" screen.
// shifts bitwise data for the color indices in BGP, OBP0 and OBP1 at the same time.

void load_fade_in_data(void)
{
  char cVar1;
  
  cVar1 = '\x04';
  do {
    set_palette_data();
    wait_frames();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

void game_win_fade_handler(void)
{
  char cVar1;
  
  cVar1 = '\x04';
  do {
    set_palette_data();
    wait_frames();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

void set_palette_data(void)
{
  byte in_A;
  
  BGP = in_A;
  OBP0 = in_A;
  OBP1 = in_A;
  return;
}

void state_dispatcher::init_game_over(void)
{
  mario_game_over_handler();
  wait_frames();
  lcd_disable_and_wait_vblank();
  disable_interrupts_save();
  fill_tile_map_0();
  clear_main_oam_buffer();
  lcdc_mirror = lcdc_mirror & 0xdf;
  joypad_pressed = joypad_pressed & 0xfd;
  load_track_game_over();
  load_game_over_text_oam_buffer();
  interrupt_enable();
  lcd_ppu_enable();
  wait_frames();
  game_state = 1;
  return;
}

void state_dispatcher::init_pause(void)
{
  if ((button_pressed_flag & 8) != 0) {
    if ((serial_falling_edge_latch & 0x80) != 0) {
      return;
    }
    serial_falling_edge_latch = 0xff;
  }
  clear_main_oam_buffer();
  update_score_oam_buffer();
  debug_ball_velocity();
  load_wall_oam_buffer();
  load_track_pause();
  game_state = 6;
  return;
}

// Loads the level's brick layout from a ROM pointer table into WRAM (BYTE_c000 = brick types,
// object_state_array = hit states). It also calculates BYTE_ffa8 (total row count) and
// lcd_y_descent_counter (rows that are off-screen above).

void load_level_brick_data(void)
{
  byte bVar1;
  undefined1 in_A;
  byte bVar2;
  undefined1 in_C;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  iVar4 = CONCAT11(in_A,in_C);
  multiply();
  pbVar5 = *(byte **)(iVar4 + 0x1be2);
  clear_objects_wram0();
  bricks_slide_in_from_top();
  pbVar6 = &BYTE_c000;
  bVar2 = 0;
  do {
    bVar1 = bVar2;
    cVar3 = '\x0e';
    do {
      bVar2 = *pbVar5;
      *pbVar6 = bVar2;
      if (bVar2 != 0) {
        iVar4 = CONCAT11(bVar2 - 1,cVar3);
        multiply();
        pbVar6[0x400] = brick_data_table[0][iVar4 + 3] & 0xf;
      }
      pbVar6 = pbVar6 + 1;
      pbVar5 = pbVar5 + 1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
    bVar2 = bVar1 + 1;
  } while (*pbVar5 != 0xff);
  total_row_count = bVar2;
  lcd_y_descent_counter = bVar1 - 0x13;
  if (bVar2 < 0x14) {
    lcd_y_descent_counter = 0;
  }
  return;
}

// clears the WRAM memory where the bricks' type and state are stored

void clear_objects_wram0(void)
{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = &object_state_array;
  iVar1 = 0x348;
  pbVar3 = &BYTE_c000;
  do {
    *pbVar3 = 0;
    *pbVar2 = 0;
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (iVar1 != 0);
  return;
}

// Runs brick_collision_handler + wait_vblank 10 times, decrementing $FFAD by 2 each time, then
// handles the remainder via lcd_y_descent_counter. This is the timed scroll-in animation that
// slides the brick field down into view when a level starts.

void animate_bricks_scroll_in(void)
{
  char cVar1;
  
  play_area_scroll_y = total_row_count - 2;
  cVar1 = '\n';
  do {
    brick_collision_handler();
    wait_vblank();
    play_area_scroll_y = play_area_scroll_y - 2;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  if (lcd_y_descent_counter == 0) {
    return;
  }
  play_area_scroll_y = lcd_y_descent_counter - 1;
  brick_collision_handler();
  return;
}

void bricks_slide_in_from_top(void)
{
  play_area_scroll_y = 0x3a;
  while( true ) {
    brick_collision_handler();
    wait_vblank();
    if (play_area_scroll_y == 0) break;
    play_area_scroll_y = play_area_scroll_y - 2;
  }
  return;
}

void count_level_bricks(void)
{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = &BYTE_c000;
  iVar2 = 0;
  iVar1 = 0x348;
  do {
    if ((*pbVar3 != 0) && (pbVar3[0x400] != 0)) {
      iVar2 = iVar2 + 1;
    }
    pbVar3 = pbVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  active_brick_count_hi = (byte)((uint)iVar2 >> 8);
  active_brick_count_lo = (byte)iVar2;
  return;
}

// Sets up the OAM buffer entries for a single specific brick
// It writes two OAM entries side by side (the brick's top and bottom halves) using $C901 to $C909

void setup_single_brick_oam_entry(void)
{
  byte bVar1;
  int iVar2;
  byte bVar3;
  undefined1 in_C;
  int iVar4;
  
  check_object_dirty_flag();
  iVar4 = CONCAT11(play_area_scroll_y >> 1,in_C);
  multiply();
  brick_tilemap_offset_hi = (byte)((uint)ball_x_tile_play_area + iVar4 >> 8);
  brick_tilemap_offset_lo = (byte)((uint)ball_x_tile_play_area + iVar4);
  iVar4 = CONCAT11(play_area_scroll_y >> 1,(char)iVar4);
  multiply();
  brick_type_last_hit = 0xff;
  bVar3 = *(byte *)((uint)ball_x_tile_play_area + iVar4 + -0x4000);
  bVar1 = bVar3 != 0;
  if ((bool)bVar1) {
    brick_type_last_hit = bVar3;
  }
  if ((&BYTE_c00e)[(uint)ball_x_tile_play_area + iVar4] != 0) {
    bVar1 = bVar1 | 2;
    brick_type_last_hit = (&BYTE_c00e)[(uint)ball_x_tile_play_area + iVar4];
  }
  if (bVar1 != 0) {
    iVar4 = CONCAT11(brick_type_last_hit - 1,0xe);
    multiply();
    brick_type_last_hit = brick_data_table[0][(uint)(byte)(bVar1 - 1) + iVar4];
  }
  iVar4 = CONCAT11(brick_tilemap_offset_hi,brick_tilemap_offset_lo) + -0x67df;
  iVar2 = CONCAT11(brick_tilemap_offset_hi,brick_tilemap_offset_lo) + -0x67d1;
  BYTE_c901 = (byte)((uint)iVar2 >> 8);
  BYTE_c902 = (byte)iVar2;
  BYTE_c903 = 1;
  BYTE_c904 = brick_type_last_hit;
  BYTE_c905 = (byte)((uint)iVar4 >> 8);
  BYTE_c906 = (byte)iVar4;
  BYTE_c907 = 1;
  BYTE_c908 = brick_type_last_hit;
  BYTE_c909 = 0;
  object_dirty_flag = 1;
  return;
}

void brick_collision_handler(void)
{
  byte bVar1;
  char cVar2;
  undefined1 in_C;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  check_object_dirty_flag();
  iVar3 = CONCAT11(play_area_scroll_y >> 1,in_C);
  multiply();
  BYTE_c901 = (byte)((uint)(iVar3 + -0x67df) >> 8);
  BYTE_c902 = (byte)(iVar3 + -0x67df);
  BYTE_c903 = 0x1c;
  iVar3 = CONCAT11(play_area_scroll_y >> 1,BYTE_c902);
  multiply();
  pbVar6 = (byte *)(iVar3 + -0x4000);
  pbVar4 = &BYTE_c904;
  cVar2 = '\x0e';
  do {
    brick_type_last_hit = 0xff;
    bVar1 = *pbVar6 != 0;
    if ((bool)bVar1) {
      brick_type_last_hit = *pbVar6;
    }
    if (pbVar6[0xe] != 0) {
      bVar1 = bVar1 | 2;
      brick_type_last_hit = pbVar6[0xe];
    }
    if (bVar1 != 0) {
      iVar3 = CONCAT11(brick_type_last_hit - 1,0xe);
      multiply();
      brick_type_last_hit = brick_data_table[0][(uint)(byte)(bVar1 - 1) + iVar3];
    }
    bVar1 = brick_type_last_hit;
    *pbVar4 = brick_type_last_hit;
    pbVar5 = pbVar4 + 0xf;
    pbVar4[0xe] = bVar1;
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  *pbVar5 = 0;
  object_dirty_flag = 1;
  return;
}

// executed each frame during gameplay, even when the level doesn't scroll

void scroll_x_handler(void)
{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  float *pfVar4;
  
  if (scrolling_x_stage_flag != 0) {
    pfVar4 = &level_scroll_x_max_timer;
    pbVar3 = level_scroll_x_timer;
    bVar1 = 0;
    do {
      bVar2 = *pbVar3 - 1;
      if ((bVar2 == 0) && (bVar2 = *(byte *)pfVar4, bVar2 != 0)) {
        if ((bVar2 & 0x80) == 0) {
          scroll_x_advance();
        }
        else {
          scroll_x_recede();
        }
        bVar2 = *(byte *)pfVar4 & 0x7f;
      }
      *pbVar3 = bVar2;
      pfVar4 = (float *)((int)pfVar4 + 1);
      pbVar3 = pbVar3 + 1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x14);
    return;
  }
  return;
}

// Increments the current row's scroll X value, wrapping at 0x6F back to 0.

void scroll_x_advance(void)
{
  byte bVar1;
  byte *in_HL;
  
  bVar1 = *in_HL + 1;
  if (0x6f < bVar1) {
    bVar1 = 0;
  }
  *in_HL = bVar1;
  return;
}

// Mirror of above: decrements, wrapping 0xFF -> 0x6F
// This is a safeguard put in place in case the scroll x value goes above 6F.

void scroll_x_recede(void)
{
  char cVar1;
  char *in_HL;
  
  cVar1 = *in_HL + -1;
  if (cVar1 == -1) {
    cVar1 = 'o';
  }
  *in_HL = cVar1;
  return;
}

void lcd_stat_work(void)
{
  byte bVar1;
  
  bVar1 = brick_scroll_flag;
  brick_scroll_flag = brick_scroll_flag + 1;
  if (0x14 < brick_scroll_flag) {
    brick_scroll_flag = 0;
    io_lyc = 7;
    io_scroll_y = lcd_y_vblank;
    io_scroll_x = 0;
    return;
  }
  io_lyc = brick_scroll_flag * '\x04' + 7;
  io_scroll_x = scroll_x_table[bVar1];
  if (bVar1 != 0) {
    return;
  }
  io_scroll_y = lcd_y;
  return;
}

// on level load, sets up the origin of the 20 4px scrollables rows all at x = 0

void init_scroll_x_table(void)
{
  char cVar1;
  byte *pbVar2;
  
  lcdc_negative = 0;
  cVar1 = '\x14';
  pbVar2 = scroll_x_table;
  do {
    *pbVar2 = 0;
    cVar1 = cVar1 + -1;
    pbVar2 = pbVar2 + 1;
  } while (cVar1 != '\0');
  debug_scroll_x_init = 0;
  lcd_y = lcd_y_descent_counter * '\x04';
  lcd_y_vblank = 0x70;
  if (0x14 < lcd_y_descent_counter) {
    lcd_y_vblank = 0xb0;
  }
  return;
}

// executes on level load and bricks falling down
// set the LCD viewport's y origin to lcd_y_descent_counter * 4
// there's some code modifying the LCD's position during vblank if the descent counter is <15, but
// this value is never reached during regular gameplay

void update_lcd_y(void)
{
  lcd_y = lcd_y_descent_counter * '\x04';
  lcd_y_vblank = 0x70;
                    // UNUSED
  if (0x14 < lcd_y_descent_counter) {
    lcd_y_vblank = 0xb0;
  }
  return;
}

void lcd_y_handler(void)
{
  byte bVar1;
  
  if (lcd_y_descent_counter == 0) {
    return;
  }
  lcd_y_descent_counter = lcd_y_descent_counter - 1;
  load_track_brick_scrolldown();
  update_lcd_y();
  load_next_brick_line_obj();
  if (lcd_y_descent_counter == 0) {
    return;
  }
  bVar1 = lcd_y_descent_counter - 1;
  if (bVar1 == 0) {
    return;
  }
  if ((bVar1 & 1) == 0) {
    return;
  }
  play_area_scroll_y = bVar1;
  brick_collision_handler();
  play_area_scroll_y = play_area_scroll_y + 0x16;
  brick_collision_handler();
  return;
}

// executes when bricks "fall down"
// updates brick count based on obj state values from $C000 and $C400
// checks the whole line of bricks and updates obj data accordingly
// clears the level if there are no bricks left

void load_next_brick_line_obj(void)
{
  char cVar1;
  undefined1 in_C;
  int iVar2;
  char *pcVar3;
  
  iVar2 = CONCAT11(lcd_y_descent_counter + 0x14,in_C);
  multiply();
  pcVar3 = (char *)(iVar2 + -0x4000);
  cVar1 = '\x0e';
  do {
    if ((*pcVar3 != '\0') && (*pcVar3 = '\0', pcVar3[0x400] != '\0')) {
      iVar2 = CONCAT11(active_brick_count_hi,active_brick_count_lo) + -1;
      active_brick_count_hi = (byte)((uint)iVar2 >> 8);
      active_brick_count_lo = (byte)iVar2;
      if (active_brick_count_lo == 0 && active_brick_count_hi == 0) {
        game_state = 8;
      }
    }
    pcVar3 = pcVar3 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// adds brick score to player_score, caps at $FFFF

void add_brick_score_to_player_score(void)
{
  bool bVar1;
  byte bVar2;
  char in_A;
  undefined1 in_C;
  int iVar3;
  
  iVar3 = CONCAT11(in_A + -1,in_C);
  multiply();
  bVar2 = brick_data_table[0][iVar3 + 3] >> 4;
  bVar1 = CARRY1(player_score_lo,bVar2);
  player_score_lo = player_score_lo + bVar2;
  player_score_hi = player_score_hi + bVar1;
  return;
}

// updates the current player score
// if the top score is achieved, the top score will update in sync with the player score

void update_score_all(void)
{
  if ((byte)(player_score_hi + (top_score_lo < player_score_lo)) <= top_score_hi) {
    return;
  }
                    // IF SCORE > TOP
  top_score_hi = player_score_hi;
  top_score_lo = player_score_lo;
  return;
}

void extra_life_score_handler(void)
{
  if ((byte)(player_score_hi + (extra_life_score_threshold_lo < player_score_lo)) <=
      extra_life_score_threshold_hi) {
    return;
  }
                    // IF SCORE >= MULTIPLE OF 1000
  if (life_counter < 9) {
                    // IF LIFE < 10
    life_counter = life_counter + 1;
    set_event_extra_life();
  }
  load_lives_number_vram();
  extra_life_score_threshold_hi = extra_life_threshold_table[(byte)(extra_life_gained_total << 1)];
  extra_life_score_threshold_lo =
       extra_life_threshold_table[(byte)(extra_life_gained_total << 1) + 1];
  extra_life_gained_total = extra_life_gained_total + 1;
  return;
}

void set_next_extra_life_score_threshold(void)
{
  extra_life_score_threshold_hi = extra_life_threshold_table[(byte)(extra_life_gained_total << 1)];
  extra_life_score_threshold_lo =
       extra_life_threshold_table[(byte)(extra_life_gained_total << 1) + 1];
  extra_life_gained_total = extra_life_gained_total + 1;
  return;
}

// Thin wrapper called each frame during gameplay

void ball_update(void)
{
  update_ball_position();
  ball_physics_and_collision_handler();
  update_ball_oam_buffer();
  return;
}

// Ball physics dispatcher. Handles paddle collision (including side-hit ->
// reverse_ball_x_velocity), ceiling bounce + paddle shrink, wall bounce, out-of-bounds ->
// game_state = 7 (ball lost), and dispatches to the brick collision sub-system via
// check_brick_collision_both_axes.

void ball_physics_and_collision_handler(void)
{
  if (((((ball_y_velocity_hi & 0x80) == 0) && (0x8c < ball_y)) && ((byte)(ball_y + 0x73) < 8)) &&
     ((byte)(ball_x - (paddle_x - 3)) < (byte)(paddle_collision_width + 5))) {
    if ((byte)(ball_y + 0x73) < 7) {
      paddle_collision_handler();
    }
    else {
      reverse_ball_x_velocity();
    }
  }
  if (ball_y < 0x18) {
    set_event_wall();
    if ((ball_phase_through == 0) && (paddle_size == 0)) {
      paddle_size = 1;
      paddle_collision_width = 0x10;
      paddle_x = paddle_x + 4;
      set_event_ceiling();
    }
    reverse_ball_y_velocity();
  }
  else if (0x9f < ball_y) {
    game_state = 7;
    return;
  }
  if ((ball_x < 0x10) || (0x7b < ball_x)) {
    reverse_ball_x_velocity();
    set_event_wall();
  }
  if (ball_y < 0x88) {
    ball_collision_flag = 0;
    check_brick_collision_both_axes();
    if (ball_collision_flag != 0) {
      if ((ball_x_velocity_hi & 0x80) == 0) {
        check_brick_collision_x_leading_right();
      }
      else {
        check_brick_collision_x_leading_left();
      }
      if ((ball_y_velocity_hi & 0x80) == 0) {
        check_brick_collision_y_leading_down();
      }
      else {
        check_brick_collision_y_leading_up();
      }
      return;
    }
    return;
  }
  return;
}

// Unconditionally probes both X and Y axes by dispatching to the appropriate directional collision
// checks based on current velocity signs. Called before a confirmed collision.

void check_brick_collision_both_axes(void)
{
  if ((ball_x_velocity_hi & 0x80) == 0) {
    check_brick_collision_x_leading_right();
  }
  else {
    check_brick_collision_x_leading_left();
  }
  if ((ball_y_velocity_hi & 0x80) == 0) {
    check_brick_collision_y_leading_down();
  }
  else {
    check_brick_collision_y_leading_up();
  }
  return;
}

// On hit: aligns to tile boundary, negates Y velocity.

void check_brick_collision_y_leading_down(void)
{
  byte bVar1;
  
  prev_ball_y = ball_y + 3;
  prev_ball_x = ball_x_mirror;
  bVar1 = ball_x_mirror;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    if ((ball_y_velocity_hi & 0x80) == 0) {
      align_ball_y_down();
    }
    else {
      align_ball_y_up();
    }
    negate_bc();
    ball_y_mirror = ball_y;
    return;
  }
  prev_ball_y = ball_y;
  prev_ball_x = ball_x_mirror;
  bVar1 = ball_x_mirror;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    return;
  }
  return;
}

// mirror of $0D50

void check_brick_collision_y_leading_up(void)
{
  byte bVar1;
  
  prev_ball_y = ball_y;
  prev_ball_x = ball_x_mirror;
  bVar1 = ball_x_mirror;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    if ((ball_y_velocity_hi & 0x80) == 0) {
      align_ball_y_down();
    }
    else {
      align_ball_y_up();
    }
    negate_bc();
    ball_y_mirror = ball_y;
    return;
  }
  prev_ball_y = ball_y + 3;
  prev_ball_x = ball_x_mirror;
  bVar1 = ball_x_mirror;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    return;
  }
  return;
}

// On hit: aligns to tile boundary, negates X velocity.

void check_brick_collision_x_leading_right(void)
{
  byte bVar1;
  
  prev_ball_y = ball_y_mirror;
  bVar1 = ball_x + 3;
  prev_ball_x = bVar1;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    if ((ball_x_velocity_hi & 0x80) == 0) {
      align_ball_x_left();
    }
    else {
      align_ball_x_right();
    }
    negate_bc();
    ball_x_mirror = ball_x;
    return;
  }
  prev_ball_y = ball_y_mirror;
  prev_ball_x = ball_x;
  bVar1 = ball_x;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    align_ball_x_update();
    return;
  }
  return;
}

// Mirror of $0D96

void check_brick_collision_x_leading_left(void)
{
  byte bVar1;
  
  prev_ball_y = ball_y_mirror;
  prev_ball_x = ball_x;
  bVar1 = ball_x;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    if ((ball_x_velocity_hi & 0x80) == 0) {
      align_ball_x_left();
    }
    else {
      align_ball_x_right();
    }
    negate_bc();
    ball_x_mirror = ball_x;
    return;
  }
  prev_ball_y = ball_y_mirror;
  bVar1 = ball_x + 3;
  prev_ball_x = bVar1;
  get_brick_at_pixel_pos();
  if (bVar1 != 0) {
    align_ball_x_update();
    return;
  }
  return;
}

void get_brick_at_pixel_pos(void)
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = CONCAT11(active_brick_count_hi,active_brick_count_lo);
  if (!CARRY1(prev_ball_y - 0x18,lcd_y)) {
    play_area_scroll_y = (byte)((prev_ball_y - 0x18) + lcd_y) >> 2;
    iVar3 = CONCAT11(active_brick_count_hi,active_brick_count_lo);
    if (play_area_scroll_y < 0x3c) {
      bVar2 = (prev_ball_x - 0x10) +
              scroll_x_table[(byte)(play_area_scroll_y - lcd_y_descent_counter)];
      if (0x6f < bVar2) {
        bVar2 = bVar2 + 0x90;
      }
      ball_x_tile_play_area = bVar2 >> 3;
      iVar3 = CONCAT11(play_area_scroll_y,play_area_scroll_y - lcd_y_descent_counter);
      multiply();
      uVar4 = (uint)ball_x_tile_play_area;
      pbVar1 = (byte *)(uVar4 + iVar3 + -0x4000);
      bVar2 = *pbVar1;
      if (bVar2 == 0) {
        return;
      }
      brick_type_last_hit = bVar2;
      brick_type_velocity_handler();
      bVar2 = (&object_state_array)[uVar4 + iVar3];
      if (bVar2 == 0) {
        update_unbreakable_brick_collision_counter();
        brick_type_handler();
        iVar3 = CONCAT11(active_brick_count_hi,active_brick_count_lo);
      }
      else {
        if ((ball_phase_through == 0) &&
           (bVar2 = bVar2 - 1, (&object_state_array)[uVar4 + iVar3] = bVar2, bVar2 != 0)) {
          return;
        }
        *pbVar1 = 0;
        add_brick_score_to_player_score();
        update_score_all();
        extra_life_score_handler();
        update_score_oam_buffer();
        brick_type_handler();
        setup_single_brick_oam_entry();
        iVar3 = CONCAT11(active_brick_count_hi,active_brick_count_lo) + -1;
        if (iVar3 == 0) {
                    // IF NO REMAINING BRICKS:
          game_state = 8;
        }
        if (ball_phase_through != 0) goto return;
      }
      active_brick_count_hi = (byte)((uint)iVar3 >> 8);
      active_brick_count_lo = (byte)iVar3;
      ball_collision_flag = ball_collision_flag + 1;
      return;
    }
  }
return:
  active_brick_count_hi = (byte)((uint)iVar3 >> 8);
  active_brick_count_lo = (byte)iVar3;
  return;
}

void reverse_ball_y_velocity(void)
{
  if ((ball_y_velocity_hi & 0x80) == 0) {
    align_ball_y_down();
  }
  else {
    align_ball_y_up();
  }
  negate_bc();
  ball_y_mirror = ball_y;
  return;
}

void reverse_ball_x_velocity(void)
{
  if ((ball_x_velocity_hi & 0x80) == 0) {
    align_ball_x_left();
  }
  else {
    align_ball_x_right();
  }
  negate_bc();
  ball_x_mirror = ball_x;
  return;
}

void align_ball_x_update(void)
{
  if ((ball_x_velocity_hi & 0x80) == 0) {
    align_ball_x_right();
  }
  else {
    align_ball_x_left();
  }
  return;
}

// snap to lower 4-pixel boundary (ball moving down)

void align_ball_y_down(void)
{
  if ((ball_y & 3) == 0) {
    return;
  }
                    // IF BALL_Y IS NOT A MULTIPLE OF 4:
  ball_y = ((ball_y & 0xfc) - (ball_y & 3)) + 1;
  return;
}

// snap to lower 4-pixel boundary (ball moving up)

void align_ball_y_up(void)
{
  if ((ball_y & 3) == 0) {
    return;
  }
                    // IF BALL_Y IS NOT A MULTIPLE OF 4:
  ball_y = ((ball_y & 0xfc) - (ball_y & 3)) + 7;
  return;
}

void align_ball_x_left(void)
{
  char cVar1;
  
  cVar1 = '\x04';
  if ((ball_x & 4) == 0) {
    cVar1 = -4;
  }
  ball_x = (ball_x & 0xf8) + cVar1;
  if (ball_x < 0x10) {
    ball_x = 0x10;
  }
  return;
}

void align_ball_x_right(void)
{
  ball_x = (ball_x & 0xf8) + 8;
  if (0x7b < ball_x) {
    ball_x = 0x7c;
  }
  return;
}

// on ball collision with any brick, checks the velocity data associated with it through the fifth
// data entry in the brick's data at $1B87.
// if it's a white or unbreakable brick -> no update
// if it's light/dark grey -> check if the brick would increase the velocity of the ball or not. If
// yes, update it. If not, RET.

void brick_type_velocity_handler(void)
{
  byte bVar1;
  undefined1 in_C;
  int iVar2;
  
  iVar2 = CONCAT11(brick_type_last_hit - 1,in_C);
  multiply();
  bVar1 = brick_data_table[0][iVar2 + 4];
  if (bVar1 == 0) {
    return;
  }
  if (bVar1 <= ball_velocity) {
    return;
  }
  ball_velocity = bVar1;
  update_ball_velocity_on_brick_collision();
  return;
}

// when the ball hits an unbreakable brick, increase the value of the counter
// if the ball hits an unbreakable brick for the 10th time, reset the value

void update_unbreakable_brick_collision_counter(void)
{
  byte bVar1;
  
  bVar1 = unbreakable_brick_collision_counter + 1;
  if (9 < bVar1) {
    update_ball_velocity_on_brick_collision();
    bVar1 = 0;
  }
  unbreakable_brick_collision_counter = bVar1;
  return;
}

// most likely a scrapped game mechanic that incremented the ball's velocity each time the player
// hit 8 bricks

void unused_ball_velocity_brick_collision_handler(void)
{
  byte bVar1;
  
  bVar1 = unused_brick_collision_count + 1;
  if (7 < bVar1) {
    increment_ball_velocity();
    update_ball_velocity_on_brick_collision();
    bVar1 = 0;
  }
  unused_brick_collision_count = bVar1;
  return;
}

void increment_ball_velocity(void)
{
  ball_velocity = ball_velocity + 1;
  if (0x19 < ball_velocity) {
    ball_velocity = 3;
  }
  debug_ball_velocity();
  return;
}

void update_ball_position(void)
{
  int iVar1;
  
  ball_y_mirror = ball_y;
  iVar1 = CONCAT11(ball_y,ball_y_subpixel) + CONCAT11(ball_y_velocity_hi,ball_y_velocity_lo);
  ball_y_subpixel = (byte)iVar1;
  ball_y = (byte)((uint)iVar1 >> 8);
  ball_x_mirror = ball_x;
  iVar1 = CONCAT11(ball_x,ball_x_subpixel) + CONCAT11(ball_x_velocity_hi,ball_x_velocity_lo);
  ball_x_subpixel = (byte)iVar1;
  ball_x = (byte)((uint)iVar1 >> 8);
  return;
}

void negate_bc(void)
{
  return;
}

void update_ball_velocity_on_brick_collision(void)
{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  byte *pbVar8;
  
  uVar6 = (uint)(byte)((ball_velocity - 1) * '\x02');
  bVar3 = ball_velocity_ptr_table[uVar6 + 1];
  iVar2 = *(int *)(ball_velocity_ptr_table + uVar6);
  debug_update_frame_accumulator();
  pbVar1 = (byte *)((uint)(byte)(BYTE_ARRAY_100b[bVar3 & 0xff07] << 2) + iVar2);
  bVar3 = *pbVar1;
  pbVar8 = pbVar1 + 2;
  bVar4 = pbVar1[1];
  if ((ball_y_velocity_hi & 0x80) != 0) {
    negate_bc();
  }
  bVar7 = *pbVar8;
  bVar5 = pbVar8[1];
  ball_y_velocity_hi = bVar3;
  ball_y_velocity_lo = bVar4;
  if ((ball_x_velocity_hi & 0x80) != 0) {
    negate_bc();
  }
  ball_x_velocity_hi = bVar7;
  ball_x_velocity_lo = bVar5;
  return;
}

// calculates where the ball should spawn relative to the paddle's collision center and its x
// velocity

void ball_spawn_handler(void)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  ball_y_subpixel = 0;
  ball_x_subpixel = 0;
  ball_velocity = 3;
  if (ball_phase_through == 0) {
    if (active_brick_count_hi != 0) goto read_paddle_center_x;
    if (0x27 < active_brick_count_lo) goto read_paddle_center_x;
  }
  ball_velocity = 7;
read_paddle_center_x:
  bVar2 = 0x18;
  if (0x47 < (byte)(paddle_x + (paddle_collision_width >> 1))) {
                    // IF PADDLE RIGHT OF CENTER PLAY AREA:
    bVar2 = 0xe8;
  }
  ball_x = paddle_x + bVar2 + (paddle_collision_width >> 1);
  ball_y = 0x74;
  ball_y_mirror = 0x74;
  ball_y_velocity_hi = 0;
  ball_y_velocity_lo = 0xb5;
  bVar3 = 0;
  bVar1 = 0xb5;
  ball_x_mirror = ball_x;
  if (bVar2 < 0x80) {
    negate_bc();
  }
  ball_x_velocity_hi = bVar3;
  ball_x_velocity_lo = bVar1;
  return;
}

// fetches the ball's xy coordinates and updates the oam data accordingly
// only affects the oam, not the collision data

void update_ball_oam_buffer(void)
{
  BYTE_c80c = ball_y;
  BYTE_c80d = ball_x;
  BYTE_c80e = 5;
  BYTE_c80f = 0;
  return;
}

// syncs the collision and sprites of the paddle

void paddle_update(void)
{
  paddle_movement_handler();
  update_paddle_oam_buffer();
  return;
}

// manages the movement and collision of the paddle, taking into account its size and collision
// against the walls
// B is the speed modifier of the paddle:
// - slow (+1): B only  
// - normal (+3): N/A
// - fast (+5): A (even if A+B)
// (there's also code that executes based on serial_sample_curr, but in emulators, it's always set
// to 0xFF, so it never executes)

void paddle_movement_handler(void)
{
  byte bVar1;
  char cVar2;
  
  if (serial_sample_curr < 0xf1) {
                    // NOT EMULATED
    paddle_x = serial_sample_curr - 0x30;
    if ((serial_sample_curr < 0x30) || (paddle_x < 0xf)) {
      paddle_x = 0xf;
    }
    else if ((byte)(0x7f - paddle_collision_width) <= paddle_x) {
      paddle_x = 0x7f - paddle_collision_width;
    }
    return;
  }
  cVar2 = '\x05';
  if (((bool)(button_pressed_neg & 1)) && (cVar2 = '\x01', (bool)(button_pressed_neg >> 1 & 1))) {
    cVar2 = '\x03';
  }
  if (((button_pressed_neg ^ 0xff) & 0x30) == 0) {
    return;
  }
  if (((button_pressed_neg ^ 0xff) & 0x20) == 0) {
    bVar1 = paddle_x + cVar2;
    if ((byte)(0x7f - paddle_collision_width) <= (byte)(paddle_x + cVar2)) {
      bVar1 = 0x7f - paddle_collision_width;
    }
  }
  else {
    bVar1 = paddle_x - cVar2;
    if ((byte)(paddle_x - cVar2) < 0xf) {
      bVar1 = 0xf;
    }
  }
  paddle_x = bVar1;
  return;
}

// Bounds clamp: ensures paddle stays within [0xF, 0x7F - paddle_collision_width]. Called as a
// utility from paddle movement code.

void clamp_paddle_x(void)
{
  byte in_A;
  byte in_B;
  
  if (in_A < 0xf) {
                    // IF PADDLE_X < 0xF
    in_A = 0xf;
  }
  else {
                    // IF PADDLE_X >= 0xF
    if (in_B <= in_A) {
      in_A = in_B;
    }
  }
  paddle_x = in_A;
  return;
}

// shifts paddle 4px left when player dies or demo starts
// also set the paddle size to 0

void shift_paddle_left(void)
{
  paddle_size = 0;
  paddle_collision_width = 0x18;
  paddle_x = paddle_x - 4;
  clamp_paddle_x();
  return;
}

void paddle_collision_handler(void)
{
  byte bVar1;
  uint in_AF;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  pbVar6 = paddle_0_angle_steepness_data;
  if (paddle_size != 0) {
    pbVar6 = paddle_1_angle_steepness_data;
  }
  pbVar6 = (byte *)((uint)(byte)(pbVar6[in_AF >> 8] << 2) +
                   *(int *)(ball_velocity_ptr_table + (byte)((ball_velocity - 1) * '\x02')));
  bVar4 = *pbVar6;
  pbVar7 = pbVar6 + 2;
  bVar2 = pbVar6[1];
  negate_bc();
  bVar5 = *pbVar7;
  bVar3 = pbVar7[1];
  bVar1 = 8;
  if (paddle_size != 0) {
    bVar1 = 6;
  }
  ball_y_velocity_hi = bVar4;
  ball_y_velocity_lo = bVar2;
  if ((byte)(in_AF >> 8) < bVar1) {
    negate_bc();
  }
  ball_x_velocity_hi = bVar5;
  ball_x_velocity_lo = bVar3;
  update_paddle_hit_counter();
  set_event_paddle_collision();
  return;
}

void update_paddle_hit_counter(void)
{
  uint uVar1;
  
  paddle_hit_counter = paddle_hit_counter - 1;
  if (paddle_hit_counter == 0) {
    lcd_y_handler();
    if (lcd_y_offset_counter < 10) {
      uVar1 = (uint)lcd_y_offset_counter;
      lcd_y_offset_counter = lcd_y_offset_counter + 1;
      paddle_hit_counter = paddle_hit_max_value_table[uVar1];
    }
    else {
      paddle_hit_counter = 1;
    }
  }
  return;
}

// change the value of the amount of paddle hits necessary to decrease the "brick scrolldown"
// mechanic
// uses the data table at $1B7D with the current number of times the ball has hit the table as the
// offset
// after 10 scrolldowns, each paddle hit lowers the bricks

void update_brick_scrolldown_threshold(void)
{
  uint uVar1;
  
  if (lcd_y_offset_counter < 10) {
    uVar1 = (uint)lcd_y_offset_counter;
    lcd_y_offset_counter = lcd_y_offset_counter + 1;
    paddle_hit_counter = paddle_hit_max_value_table[uVar1];
  }
  else {
    paddle_hit_counter = 1;
  }
  return;
}

// Paddle OAM: $C800-$C80B

void update_paddle_oam_buffer(void)
{
  if (paddle_size == 0) {
                    // IF PADDLE SIZE NORMAL
    oam_buffer_struct = init_paddle_y;
    BYTE_c801 = paddle_x + 1;
    BYTE_c802 = 0;
    BYTE_c803 = 0;
    BYTE_c804 = init_paddle_y;
    BYTE_c805 = paddle_x + 9;
    BYTE_c806 = 1;
    BYTE_c807 = 0;
    BYTE_c808 = init_paddle_y;
    BYTE_c809 = paddle_x + 0x11;
    BYTE_c80a = 0;
    BYTE_c80b = 0x20;
    return;
  }
                    // IF PADDLE SIZE SMALL
  oam_buffer_struct = init_paddle_y;
  BYTE_c801 = paddle_x + 1;
  BYTE_c802 = 0;
  BYTE_c803 = 0;
  BYTE_c804 = init_paddle_y;
  BYTE_c805 = paddle_x + 9;
  BYTE_c806 = 0;
  BYTE_c807 = 0x20;
  BYTE_c808 = init_paddle_y;
  BYTE_c809 = paddle_x + 5;
  BYTE_c80a = 1;
  BYTE_c80b = 0;
  return;
}

void decrement_bonus_stage_time(void)
{
  byte bVar1;
  char in_B;
  byte *pbVar2;
  
  if ((game_tick & 0x1f) != 0) {
    return;
  }
  bVar1 = bonus_stage_time - 1;
  bonus_stage_time = bVar1;
  if (bVar1 == 0) {
    set_lose_state();
  }
  if (bVar1 == 0x14) {
    load_track_bonus_stage_fast();
  }
  pbVar2 = &BYTE_c880;
  bVar1 = bonus_stage_time;
  binary_to_bcd();
  *pbVar2 = 0x80;
  pbVar2[1] = 0x90;
  pbVar2[2] = in_B + 0x80;
  pbVar2[3] = 0;
  pbVar2[4] = 0x80;
  pbVar2[5] = 0x98;
  pbVar2[6] = bVar1 + 0x80;
  pbVar2[7] = 0;
  return;
}

// Loads maximum bonus time into the OAM buffer
// bonus stage 1 = 0x5F
// bonus stage 2 = 0x5A
// bonus stage 3 = 0x55
// bonus stage 4+ = 0x50

void load_bonus_stage_time_oam_buffer(void)
{
  byte bVar1;
  char in_B;
  byte *pbVar2;
  
  pbVar2 = &BYTE_c880;
  bVar1 = bonus_stage_time;
  binary_to_bcd();
  *pbVar2 = 0x80;
  pbVar2[1] = 0x90;
  pbVar2[2] = in_B + 0x80;
  pbVar2[3] = 0;
  pbVar2[4] = 0x80;
  pbVar2[5] = 0x98;
  pbVar2[6] = bVar1 + 0x80;
  pbVar2[7] = 0;
  return;
}

void set_lose_state(void)
{
  game_state = 7;
  return;
}

// loads the time and points of the bonus level + loads the music that plays when bonus stages begin

void bonus_start_handler(void)
{
  byte *in_HL;
  
  update_bonus_stage_properties();
  bonus_stage_time = *in_HL;
  load_bonus_time_text_vram();
  load_bonus_stage_time_oam_buffer();
  load_track_bonus_stage_start();
  wait_frames();
  return;
}

// tracks the value of the current bonus stage and uses that value to point to a table that contains
// the data of the maximum bonus stage time at $1B71
// caps at bonus stage 4

void update_bonus_stage_properties(void)
{
  multiply();
  return;
}

// checks whether the player lost the bonus stage or not

void state_dispatcher::init_bonus_state(void)
{
  int iVar1;
  int iVar2;
  int in_HL;
  
  stop_music_wrapper();
  if (active_brick_count_lo != 0 || active_brick_count_hi != 0) {
    load_track_bonus_stage_lose();
    wait_frames();
    return;
  }
  load_track_bonus_stage_win();
  wait_frames();
  wait_frames();
  load_special_bonus_text_vram();
  update_bonus_stage_properties();
  iVar2 = CONCAT11(*(undefined1 *)(in_HL + 1),*(undefined1 *)(in_HL + 2));
  load_special_bonus_points_oam_buffer();
  wait_frames();
  do {
    if ((char)((uint)iVar2 >> 8) == '\0') {
      if ((byte)iVar2 == 0) {
        return;
      }
      if ((byte)iVar2 < 10) {
        do {
          iVar2 = iVar2 + -1;
          load_special_bonus_points_oam_buffer();
          iVar1 = CONCAT11(player_score_hi,player_score_lo) + 1;
          player_score_hi = (byte)((uint)iVar1 >> 8);
          player_score_lo = (byte)iVar1;
          update_score_all();
          extra_life_score_handler();
          update_score_oam_buffer();
          set_event_bonus_countdown();
          wait_vblank();
        } while (iVar2 != 0);
        return;
      }
    }
    iVar2 = iVar2 + -10;
    load_special_bonus_points_oam_buffer();
    iVar1 = CONCAT11(player_score_hi,player_score_lo) + 10;
    player_score_hi = (byte)((uint)iVar1 >> 8);
    player_score_lo = (byte)iVar1;
    update_score_all();
    extra_life_score_handler();
    update_score_oam_buffer();
    set_event_bonus_countdown();
    wait_vblank();
  } while( true );
}

// loads the "SPECIAL BONUS" and "PTS." text when a bonus stage is won
// the two tile sets are offset, 2 addresses are used

void load_special_bonus_text_vram(void)
{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  check_object_dirty_flag();
  pbVar2 = &BYTE_c901;
  cVar1 = '\x17';
  pbVar3 = special_bonus_text_tile_data;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (cVar1 != '\0');
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// clears the "SPECIAL BONUS" and "PTS." text when a bonus stage is won
// the two tile sets are offset, 2 addresses are used

void clear_special_bonus_text_vram(void)
{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  check_object_dirty_flag();
  pbVar2 = &BYTE_c901;
  cVar1 = '\x17';
  pbVar3 = clear_special_bonus_text_tile_data;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (cVar1 != '\0');
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// Loads "TRY AGAIN!" under the big Mario during the Win sequence

void load_try_again_vram(void)
{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  check_object_dirty_flag();
  pbVar2 = &BYTE_c901;
  cVar1 = '\x0e';
  pbVar3 = try_again__tile_vram_data;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (cVar1 != '\0');
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// Removes TRY AGAIN! text with FF tiles

void clear_try_again__vram(void)
{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  check_object_dirty_flag();
  pbVar2 = &BYTE_c901;
  cVar1 = '\x0e';
  pbVar3 = clear_try_again__tile_vram_data;
  do {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
    pbVar3 = pbVar3 + 1;
  } while (cVar1 != '\0');
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// initializes the paddle and music
// manages mario's walking and jumping animation

void mario_start_handler(void)
{
  update_paddle_oam_buffer();
  load_track_start();
  current_anim_x = paddle_x + 0x50;
  current_anim_y = init_paddle_y - 0x10;
  anim_timer = 3;
  do {
    update_mario_walking_frame();
    copy_current_anim_xy();
    current_anim_x = current_anim_x - 1;
  } while (current_anim_x != 0x44);
  mario_anim_frame = 3;
  copy_current_anim_xy();
  set_event_mario_jump();
  paddle_open_anim_handler();
  mario_anim_frame = 4;
  mario_jump_frame_index = 0;
  mario_jump_x_direction_flag = 0;
  do {
    copy_current_anim_xy();
    mario_jump_velocity_handler();
  } while (mario_jump_frame_index < 0x18);
  do {
    copy_current_anim_xy();
    current_anim_y = current_anim_y + 4;
  } while (current_anim_y < 0x88);
  clear_anim_oam_buffer();
  wait_frames();
  paddle_close_anim_handler();
  update_paddle_oam_buffer();
  return;
}

void mario_game_over_handler(void)
{
  shift_paddle_left();
  update_paddle_oam_buffer();
  set_event_death_no_lives();
  paddle_open_anim_handler();
  current_anim_y = 0x88;
  current_anim_x = paddle_x + 4;
  mario_anim_frame = 5;
  mario_jump_x_direction_flag = current_anim_x < 0x4c;
  if ((bool)mario_jump_x_direction_flag) {
    mario_anim_frame = 6;
  }
  mario_jump_frame_index = 0;
  do {
    copy_current_anim_xy();
    mario_jump_velocity_handler();
  } while (mario_jump_frame_index < 0x18);
  do {
    copy_current_anim_xy();
    current_anim_y = current_anim_y + 4;
  } while (current_anim_y < 0xa0);
  clear_anim_oam_buffer();
  wait_frames();
  return;
}

// increase mario's walking frame when the animation timer hits 0
// caps at 3

void update_mario_walking_frame(void)
{
  anim_timer = anim_timer - 1;
  if (anim_timer != 0) {
    return;
  }
  mario_anim_frame = mario_anim_frame + 1;
  if (2 < mario_anim_frame) {
    mario_anim_frame = 0;
  }
  anim_timer = 5;
  return;
}

// Copy mario's XY to BC

void copy_current_anim_xy(void)
{
  copy_tiles4_oam_buffer();
  wait_vblank();
  return;
}

void mario_jump_velocity_handler(void)
{
  byte bVar1;
  
  bVar1 = mario_jump_frame_index;
  mario_jump_frame_index = mario_jump_frame_index + 1;
  current_anim_y = current_anim_y + mario_jump_y_velocity_data[bVar1];
  current_anim_x = current_anim_x + mario_jump_x_direction_flag * '\x02' + -1;
  return;
}

void paddle_open_anim_handler(void)
{
  byte bVar1;
  
  update_paddle_oam_buffer();
  bVar1 = 0;
  do {
    paddle_open_close_oam_handler();
    wait_frames();
    bVar1 = bVar1 + 1;
  } while (bVar1 < 3);
  return;
}

void paddle_close_anim_handler(void)
{
  char cVar1;
  
  cVar1 = '\x02';
  do {
    paddle_open_close_oam_handler();
    wait_frames();
    cVar1 = cVar1 + -1;
  } while (cVar1 != -1);
  return;
}

void paddle_open_close_oam_handler(void)
{
  byte in_A;
  int iVar1;
  
  iVar1 = CONCAT11(paddle_open_close_anim_spr_ptr[in_A],in_A);
  multiply();
  BYTE_c802 = paddle_open_frame_0_tile_data[iVar1];
  BYTE_c806 = paddle_open_frame_0_tile_data[iVar1 + 1];
  BYTE_c80a = paddle_open_frame_0_tile_data[iVar1 + 2];
  return;
}

void explosion_oam_handler(void)
{
  set_ball_oob();
  current_anim_x = ball_x - 8;
  current_anim_y = 0x90;
  anim_timer = 0;
  do {
    copy_tiles4_oam_buffer();
    wait_vblank();
    anim_timer = anim_timer + 1;
  } while (anim_timer < 0x24);
  clear_anim_oam_buffer();
  return;
}

void mario_wink_oam_handler(void)
{
  anim_timer = 0;
  do {
    copy_tiles4_oam_buffer();
    wait_vblank();
    anim_timer = anim_timer + 1;
  } while (anim_timer < 0x1d);
  clear_anim_oam_buffer();
  return;
}

void level_load_handler(void)
{
  void *in_HL;
  
  lcd_disable_and_wait_vblank();
  disable_interrupts_save();
  fill_tile_map_0();
  fill_tile_map_1();
  clear_main_oam_buffer();
  stop_music_wrapper();
  WX = 0x7f;
  WY = 0;
  lcdc_mirror = lcdc_mirror | 0x60;
  io_lyc = 8;
  io_lcd_status = 0x44;
  joypad_pressed = joypad_pressed | 10;
  set_palette_data();
  is_oam_buffer_empty(in_HL);
  if (((game_state != 3) && (stage_number_display != 0)) && (true_stage_number == 0)) {
    is_oam_buffer_empty(in_HL);
    set_palette_data();
  }
  load_wall_oam_buffer();
  interrupt_enable();
  lcd_ppu_enable();
  return;
}

// loads OAM buffer data from $C990 to $C89F

void load_stage_number_oam_buffer(void)
{
  byte bVar1;
  char in_B;
  
  BYTE_c880 = 0x70;
  BYTE_c884 = 0x70;
  BYTE_c888 = 0x70;
  BYTE_c88c = 0x70;
  BYTE_c890 = 0x70;
  BYTE_c894 = 0x70;
  BYTE_c898 = 0x70;
  BYTE_c89c = 0x70;
  BYTE_c881 = 0x30;
  BYTE_c885 = 0x38;
  BYTE_c889 = 0x40;
  BYTE_c88d = 0x48;
  BYTE_c891 = 0x50;
  BYTE_c895 = 0x58;
  BYTE_c899 = 0x60;
  BYTE_c89d = 0x68;
  BYTE_c883 = 0;
  BYTE_c887 = 0;
  BYTE_c88b = 0;
  BYTE_c88f = 0;
  BYTE_c893 = 0;
  BYTE_c897 = 0;
  BYTE_c89b = 0;
  BYTE_c89f = 0;
  BYTE_c882 = 0x9c;
  BYTE_c886 = 0x9d;
  BYTE_c88a = 0x8a;
  BYTE_c88e = 0x90;
  BYTE_c892 = 0x8e;
  BYTE_c896 = 0x3e;
  bVar1 = stage_number_display;
  binary_to_bcd();
  BYTE_c89a = in_B + 0x80;
  BYTE_c89e = bVar1 + 0x80;
  return;
}

// loads OAM buffer data from $C880 to $C893

void load_bonus_text_oam_buffer(void)
{
  BYTE_c880 = 0x70;
  BYTE_c884 = 0x70;
  BYTE_c888 = 0x70;
  BYTE_c88c = 0x70;
  BYTE_c890 = 0x70;
  BYTE_c881 = 0x38;
  BYTE_c885 = 0x40;
  BYTE_c889 = 0x48;
  BYTE_c88d = 0x50;
  BYTE_c891 = 0x58;
  BYTE_c897 = 0;
  BYTE_c89b = 0;
  BYTE_c89f = 0;
  BYTE_c893 = 0;
  BYTE_c882 = 0x8b;
  BYTE_c886 = 0x98;
  BYTE_c88a = 0x97;
  BYTE_c88e = 0x9e;
  BYTE_c892 = 0x9c;
  return;
}

// loads OAM buffer data from $C880 to $C893

void load_pause_text_oam_buffer(void)
{
  BYTE_c880 = 0x70;
  BYTE_c884 = 0x70;
  BYTE_c888 = 0x70;
  BYTE_c88c = 0x70;
  BYTE_c890 = 0x70;
  BYTE_c881 = 0x38;
  BYTE_c885 = 0x40;
  BYTE_c889 = 0x48;
  BYTE_c88d = 0x50;
  BYTE_c891 = 0x58;
  BYTE_c897 = 0;
  BYTE_c89b = 0;
  BYTE_c89f = 0;
  BYTE_c893 = 0;
  BYTE_c882 = 0x99;
  BYTE_c886 = 0x8a;
  BYTE_c88a = 0x9e;
  BYTE_c88e = 0x9c;
  BYTE_c892 = 0x8e;
  return;
}

// loads the stage number (not counting bonus levels) to VRAM

void load_stage_number_display_vram(void)
{
  byte bVar1;
  char in_B;
  byte *pbVar2;
  
  check_object_dirty_flag();
                    // $9D62
  BYTE_c901 = 0x9d;
  BYTE_c902 = 0x62;
                    // 2 TILES
  pbVar2 = &BYTE_c904;
  BYTE_c903 = 2;
  bVar1 = stage_number_display;
  binary_to_bcd();
                    // STAGE NUMBER TEXT
  *pbVar2 = in_B + 0x80;
  pbVar2[1] = bVar1 + 0x80;
  pbVar2[2] = 0;
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// loads the number of lives that the player currently has to VRAM

void load_lives_number_vram(void)
{
  check_object_dirty_flag();
                    // $9E04
  BYTE_c901 = 0x9e;
  BYTE_c902 = 4;
                    // 1 TILE
  BYTE_c903 = 1;
                    // LIFE NUMBER
  BYTE_c904 = life_counter + 0x80;
  BYTE_c905 = 0;
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// loads the "TIME" text that appears during bonus stages

void load_bonus_time_text_vram(void)
{
  check_object_dirty_flag();
                    // $9DA1
  BYTE_c901 = 0x9d;
  BYTE_c902 = 0xa1;
                    // 4 TILES
  BYTE_c903 = 4;
                    // "TIME"
  BYTE_c904 = 0x9d;
  BYTE_c905 = 0x92;
  BYTE_c906 = 0x96;
  BYTE_c907 = 0x8e;
  BYTE_c908 = 0;
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// on every level load, clears the "TIME" tiles of the bonus stages

void clear_bonus_time_text_vram(void)
{
  check_object_dirty_flag();
                    // $9D1A
  BYTE_c901 = 0x9d;
  BYTE_c902 = 0xa1;
                    // 4 TILES
  BYTE_c903 = 4;
                    // TRANSPARENT
  BYTE_c904 = 0xff;
  BYTE_c905 = 0xff;
  BYTE_c906 = 0xff;
  BYTE_c907 = 0xff;
  BYTE_c908 = 0;
  object_dirty_flag = 1;
  wait_vblank();
  return;
}

// updates score on level load, bonus win and game win

void update_score_oam_buffer(void)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = &BYTE_c814;
  score_to_bcd();
  *pbVar2 = 0x40;
  pbVar2[1] = 0x88;
  bVar1 = 0xff;
  if (((score_digit_tens_of_thousands != 0) && (bVar1 = 0xbf, score_digit_tens_of_thousands != 1))
     && (bVar1 = 0xbc, score_digit_tens_of_thousands != 2)) {
    bVar1 = 0xc9;
  }
  pbVar2[2] = bVar1;
  pbVar2[3] = 0;
  pbVar2[4] = 0x38;
  pbVar2[5] = 0x88;
  pbVar2[6] = score_digit_thousands + 0x80;
  pbVar2[7] = 0;
  pbVar2[8] = 0x38;
  pbVar2[9] = 0x90;
  pbVar2[10] = score_digit_hundreds + 0x80;
  pbVar2[0xb] = 0;
  pbVar2[0xc] = 0x38;
  pbVar2[0xd] = 0x98;
  pbVar2[0xe] = score_digit_tens + 0x80;
  pbVar2[0xf] = 0;
  pbVar2[0x10] = 0x38;
  pbVar2[0x11] = 0xa0;
  pbVar2[0x12] = score_digit_ones + 0x80;
  pbVar3 = pbVar2 + 0x14;
  pbVar2[0x13] = 0;
  score_to_bcd();
  *pbVar3 = 0x28;
  pbVar3[1] = 0x88;
  bVar1 = 0xff;
  if (((score_digit_tens_of_thousands != 0) && (bVar1 = 0xbf, score_digit_tens_of_thousands != 1))
     && (bVar1 = 0xbc, score_digit_tens_of_thousands != 2)) {
    bVar1 = 0xc9;
  }
  pbVar3[2] = bVar1;
  pbVar3[3] = 0;
  pbVar3[4] = 0x20;
  pbVar3[5] = 0x88;
  pbVar3[6] = score_digit_thousands + 0x80;
  pbVar3[7] = 0;
  pbVar3[8] = 0x20;
  pbVar3[9] = 0x90;
  pbVar3[10] = score_digit_hundreds + 0x80;
  pbVar3[0xb] = 0;
  pbVar3[0xc] = 0x20;
  pbVar3[0xd] = 0x98;
  pbVar3[0xe] = score_digit_tens + 0x80;
  pbVar3[0xf] = 0;
  pbVar3[0x10] = 0x20;
  pbVar3[0x11] = 0xa0;
  pbVar3[0x12] = score_digit_ones + 0x80;
  pbVar3[0x13] = 0;
  return;
}

// called during title screen initialization

void load_title_screen_score_buffer_oam(void)
{
  score_to_bcd();
  BYTE_c828 = 0x70;
  BYTE_c829 = 0x70;
  BYTE_c82a = 0xff;
  if (((score_digit_tens_of_thousands != 0) &&
      (BYTE_c82a = 0xbf, score_digit_tens_of_thousands != 1)) &&
     (BYTE_c82a = 0xbc, score_digit_tens_of_thousands != 2)) {
    BYTE_c82a = 0xc9;
  }
  BYTE_c82b = 0;
  BYTE_c82c = 0x68;
  BYTE_c82d = 0x70;
  BYTE_c82e = score_digit_thousands + 0x80;
  BYTE_c82f = 0;
  BYTE_c830 = 0x68;
  BYTE_c831 = 0x78;
  BYTE_c832 = score_digit_hundreds + 0x80;
  BYTE_c833 = 0;
  BYTE_c834 = 0x68;
  BYTE_c835 = 0x80;
  BYTE_c836 = score_digit_tens + 0x80;
  BYTE_c837 = 0;
  BYTE_c838 = 0x68;
  BYTE_c839 = 0x88;
  BYTE_c83a = score_digit_ones + 0x80;
  BYTE_c83b = 0;
  return;
}

// triggers upon bonus level win
// only loads the number, not the "SPECIAL BONUS PTS." text

void load_special_bonus_points_oam_buffer(void)
{
  byte *pbVar1;
  
  pbVar1 = &BYTE_c888;
  score_to_bcd();
  *pbVar1 = 0x78;
  pbVar1[1] = 0x30;
  pbVar1[2] = score_digit_thousands + 0x80;
  pbVar1[3] = 0;
  pbVar1[4] = 0x78;
  pbVar1[5] = 0x38;
  pbVar1[6] = score_digit_hundreds + 0x80;
  pbVar1[7] = 0;
  pbVar1[8] = 0x78;
  pbVar1[9] = 0x40;
  pbVar1[10] = score_digit_tens + 0x80;
  pbVar1[0xb] = 0;
  pbVar1[0xc] = 0x78;
  pbVar1[0xd] = 0x48;
  pbVar1[0xe] = score_digit_ones + 0x80;
  pbVar1[0xf] = 0;
  return;
}

void load_game_over_text_oam_buffer(void)
{
  oam_buffer_struct = 0x50;
  BYTE_c804 = 0x50;
  BYTE_c808 = 0x50;
  BYTE_c80c = 0x50;
  BYTE_c810 = 0x50;
  BYTE_c814 = 0x50;
  BYTE_c818 = 0x50;
  BYTE_c81c = 0x50;
  BYTE_c801 = 0x38;
  BYTE_c805 = 0x40;
  BYTE_c809 = 0x48;
  BYTE_c80d = 0x50;
  BYTE_c811 = 0x60;
  BYTE_c815 = 0x68;
  BYTE_c819 = 0x70;
  BYTE_c81d = 0x78;
  BYTE_c803 = 0;
  BYTE_c807 = 0;
  BYTE_c80b = 0;
  BYTE_c80f = 0;
  BYTE_c813 = 0;
  BYTE_c817 = 0;
  BYTE_c81b = 0;
  BYTE_c81f = 0;
  BYTE_c802 = 0x90;
  BYTE_c806 = 0x8a;
  BYTE_c80a = 0x96;
  BYTE_c80e = 0x8e;
  BYTE_c812 = 0x98;
  BYTE_c816 = 0x9f;
  BYTE_c81a = 0x8e;
  BYTE_c81e = 0x9b;
  return;
}

void load_wall_oam_buffer(void)
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = &BYTE_c83c;
  bVar1 = 0x18;
  cVar2 = '\x11';
  do {
    *pbVar3 = bVar1;
    pbVar3[1] = 8;
    pbVar4 = pbVar3 + 3;
    pbVar3[2] = 0xb4;
    pbVar3 = pbVar3 + 4;
    *pbVar4 = 0;
    bVar1 = bVar1 + 8;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return;
}

// loads the current value of the ball's velocity at the upper right corner of the screen

void debug_ball_velocity(void)
{
  return;
}

void copy_tiles4_oam_buffer(void)
{
  char cVar1;
  undefined2 in_AF;
  char in_C;
  char in_B;
  uint uVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  uVar2 = (uint)(byte)((char)((uint)in_AF >> 8) << 1);
  pcVar3 = (char *)CONCAT11(mario_start_spr_ptr_table[uVar2],mario_start_spr_ptr_table[uVar2 + 1]);
  pbVar4 = &BYTE_c888;
  cVar1 = '\x04';
  do {
    *pbVar4 = *pcVar3 + in_C;
    pbVar4[1] = pcVar3[1] + in_B;
    pbVar5 = pbVar4 + 3;
    pbVar4[2] = pcVar3[2];
    pbVar4 = pbVar4 + 4;
    *pbVar5 = pcVar3[3];
    pcVar3 = pcVar3 + 4;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// Audio systems on

void audio_init(void)
{
  NR52 = 0x80;
  NR50 = 0x77;
  NR51 = 0xff;
  return;
}

void clear_demo_flag(void)
{
  demo_flag = 0;
  return;
}

void set_demo_flag(void)
{
  demo_flag = 1;
  return;
}

void brick_type_handler(void)
{
  byte bVar1;
  undefined1 in_C;
  int iVar2;
  
  iVar2 = CONCAT11(brick_type_last_hit - 1,in_C);
  multiply();
  bVar1 = brick_data_table[0][iVar2 + 5];
  if (bVar1 == 0) {
    game_event = 3;
  }
  else if (bVar1 == 1) {
    game_event = 2;
  }
  else {
    if (bVar1 != 2) {
      set_event_dark_grey_brick();
      return;
    }
    game_event = 5;
  }
  return;
}

void set_event_extra_life(void)
{
  game_event = 1;
  return;
}

void set_event_white_brick(void)
{
  game_event = 2;
  return;
}

void set_event_unbreakable_brick(void)
{
  game_event = 3;
  return;
}

void set_event_paddle_collision(void)
{
  game_event = 4;
  return;
}

void set_event_light_grey_brick(void)
{
  game_event = 5;
  return;
}

void set_event_dark_grey_brick(void)
{
  game_event = 6;
  return;
}

void set_event_ball_launched(void)
{
  game_event = 7;
  return;
}

void set_event_bonus_countdown(void)
{
  game_event = 8;
  return;
}

void set_event_mario_jump(void)
{
  game_event = 9;
  return;
}

void set_event_death_no_lives(void)
{
  game_event = 10;
  return;
}

void set_event_ceiling(void)
{
  game_event = 0xb;
  return;
}

// game_event = 0C: ball collides with wall

void set_event_wall(void)
{
  game_event = 0xc;
  return;
}

// Investigate: happens immediately when the ball is lost in a bonus level

void set_ball_oob(void)
{
  ball_oob = 1;
  return;
}

void load_track_title(void)
{
  track_index = 1;
  return;
}

void load_track_start(void)
{
  track_index = 2;
  return;
}

void load_track_game_over(void)
{
  track_index = 3;
  return;
}

void load_track_pause(void)
{
  track_index = 4;
  return;
}

void load_track_stage_complete(void)
{
  track_index = 5;
  return;
}

void load_track_bonus_stage(void)
{
  track_index = 6;
  return;
}

void load_track_bonus_stage_fast(void)
{
  track_index = 7;
  return;
}

void load_track_bonus_stage_start(void)
{
  track_index = 8;
  return;
}

void load_track_bonus_stage_lose(void)
{
  track_index = 9;
  return;
}

void load_track_bonus_stage_win(void)
{
  track_index = 10;
  return;
}

void load_track_brick_scrolldown(void)
{
  track_index = 0xb;
  return;
}

void load_track_nice_play_(void)
{
  track_index = 0xc;
  return;
}

void audio_update(void)
{
  demo_flag_handler();
  sfx_handler();
  ch4_explosion_handler();
  music_track_handler();
  ch2_pan_handler();
  game_event = 0;
  ball_oob = 0;
  track_index = 0;
  return;
}

void unused_set_game_event(void)
{
  if ((oam_dma_routine & 1) != 0) {
    game_event = 1;
    return;
  }
  if ((oam_dma_routine & 2) != 0) {
    game_event = 2;
    return;
  }
  if ((oam_dma_routine & 8) != 0) {
    game_event = 3;
    return;
  }
  if ((oam_dma_routine & 4) != 0) {
    game_event = 4;
    return;
  }
  if ((oam_dma_routine & 0x10) != 0) {
    game_event = 5;
    return;
  }
  if ((oam_dma_routine & 0x20) != 0) {
    game_event = 6;
    return;
  }
  if ((oam_dma_routine & 0x40) != 0) {
    game_event = 7;
    return;
  }
  if ((oam_dma_routine & 0x80) == 0) {
    return;
  }
  game_event = 8;
  return;
}

void unused_game_event_track_handler(void)
{
  if ((oam_dma_routine & 1) != 0) {
    game_event = 1;
    track_index = 1;
    return;
  }
  if ((oam_dma_routine & 2) != 0) {
    game_event = 2;
    track_index = 2;
    return;
  }
  if ((oam_dma_routine & 8) != 0) {
    game_event = 3;
    track_index = 3;
    return;
  }
  if ((oam_dma_routine & 4) != 0) {
    game_event = 4;
    track_index = 4;
    return;
  }
  if ((oam_dma_routine & 0x10) != 0) {
    game_event = 5;
    track_index = 5;
    return;
  }
  if ((oam_dma_routine & 0x20) != 0) {
    game_event = 6;
    track_index = 6;
    return;
  }
  if ((oam_dma_routine & 0x40) != 0) {
    game_event = 7;
    track_index = 7;
    return;
  }
  if ((oam_dma_routine & 0x80) == 0) {
    return;
  }
  game_event = 8;
  track_index = 8;
  return;
}

// ball_oob in this function most likely used to be either the game_track or game_event at some
// point in development before getting switched

void unused_event_handler(void)
{
  if ((oam_dma_routine & 1) != 0) {
    ball_oob = 1;
    return;
  }
  if ((oam_dma_routine & 2) != 0) {
    ball_oob = 2;
    return;
  }
  if ((oam_dma_routine & 8) != 0) {
    ball_oob = 3;
    return;
  }
  if ((oam_dma_routine & 4) != 0) {
    ball_oob = 4;
    return;
  }
  if ((oam_dma_routine & 0x10) != 0) {
    ball_oob = 5;
    return;
  }
  if ((oam_dma_routine & 0x20) != 0) {
    ball_oob = 6;
    return;
  }
  if ((oam_dma_routine & 0x40) != 0) {
    ball_oob = 7;
    return;
  }
  if ((oam_dma_routine & 0x80) == 0) {
    return;
  }
  ball_oob = 8;
  return;
}

void unused_track_handler(void)
{
  if ((oam_dma_routine & 1) != 0) {
    track_index = 1;
    return;
  }
  if ((oam_dma_routine & 2) != 0) {
    track_index = 2;
    return;
  }
  if ((oam_dma_routine & 8) != 0) {
    track_index = 3;
    return;
  }
  if ((oam_dma_routine & 4) != 0) {
    track_index = 4;
    return;
  }
  if ((oam_dma_routine & 0x10) != 0) {
    track_index = 5;
    return;
  }
  if ((oam_dma_routine & 0x20) != 0) {
    track_index = 6;
    return;
  }
  if ((oam_dma_routine & 0x40) != 0) {
    track_index = 7;
    return;
  }
  if ((oam_dma_routine & 0x80) == 0) {
    return;
  }
  track_index = 8;
  return;
}

void unused_joypad_update(void)
{
  byte bVar1;
  byte bVar2;
  code cVar3;
  
  io_joypad_input = 0x10;
  bVar1 = io_joypad_input;
  io_joypad_input = 0x20;
  bVar2 = io_joypad_input;
  cVar3 = (code)(~bVar2 << 4 | ~bVar1 & 0xf);
  bRamff81 = ((byte)oam_dma_routine ^ (byte)cVar3) & (byte)cVar3;
  oam_dma_routine = cVar3;
  io_joypad_input = 0x30;
  return;
}

// resets game_event, ball_oob and track_index flags if the game is in demo mode

void demo_flag_handler(void)
{
  if (demo_flag != 1) {
    return;
  }
  game_event = 0;
  ball_oob = 0;
  track_index = 0;
  return;
}

void sfx_handler(void)
{
  byte bVar1;
  
  if (current_sfx_active == 1) {
                    // IF EXTRA LIFE SFX PLAYING:
    if (sfx_envelope_counter != 6) {
LAB_6f9c:
      sfx_envelope_counter = sfx_envelope_counter + 1;
      return;
    }
    sfx_envelope_counter = 0;
    sfx_envelope = sfx_envelope - 1;
    if (sfx_envelope == 6) {
      ch1_initializer();
      return;
    }
    if (sfx_envelope == 5) {
      ch1_initializer();
      return;
    }
    if (sfx_envelope == 4) {
      ch1_initializer();
      return;
    }
    if (sfx_envelope == 3) {
      ch1_initializer();
      return;
    }
    if (sfx_envelope == 2) {
      ch1_initializer();
      ceiling_collision_sfx_active_flag = 0;
      return;
    }
  }
  else {
    if (game_event == 4) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 4;
        sfx_envelope = 4;
        ch1_initializer();
      }
      return;
    }
    if (game_event == 2) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 2;
        sfx_envelope = 5;
        ch1_initializer();
      }
      return;
    }
    if (game_event == 3) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 3;
        sfx_envelope = 5;
        ch1_initializer();
      }
      return;
    }
    if (game_event == 1) {
      current_sfx_active = 1;
      sfx_envelope = 7;
      ch1_initializer();
      return;
    }
    if (game_event == 5) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 5;
        sfx_envelope = 5;
        ch1_initializer();
      }
      return;
    }
    if (game_event == 6) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 6;
        sfx_envelope = 5;
        ch1_initializer();
      }
      return;
    }
    if (game_event == 7) {
      current_sfx_active = 7;
      sfx_envelope = 4;
      ch1_initializer();
      return;
    }
    if (game_event == 8) {
      current_sfx_active = 8;
      sfx_envelope = 5;
      ch1_initializer();
      return;
    }
    if (game_event == 9) {
      current_sfx_active = 9;
      ch1_pitch = 99;
      ch1_freq_lo = 10;
      ch1_freq_hi = 0x87;
      sfx_envelope_counter = 0xff;
      return;
    }
    if (game_event == 10) {
      current_sfx_active = 10;
      ch1_pitch = 0xb;
      ch1_freq_lo = 0xac;
      ch1_freq_hi = 0x86;
      BYTE_dffe = 0x87;
      sfx_envelope_counter = 0xff;
      return;
    }
    if (game_event == 0xb) {
      current_sfx_active = 0xb;
      ch1_freq_lo = 0xa5;
      BYTE_dffe = 0x87;
      ceiling_collision_sfx_active_flag = 1;
      return;
    }
    if (game_event == 0xc) {
      if (ceiling_collision_sfx_active_flag != 1) {
        current_sfx_active = 0xc;
        ch1_pitch = 0xff;
        ch1_freq_lo = 10;
        ch1_freq_hi = 0x85;
        sfx_envelope_counter = 0xff;
      }
      return;
    }
                    // IF ANY OTHER SFX ACTIVE
    if (current_sfx_active == 2) {
      if (sfx_envelope_counter != 4) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 3) {
      if (sfx_envelope_counter != 2) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 4) {
      if (sfx_envelope_counter != 4) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 5) {
      if (sfx_envelope_counter != 4) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 6) {
      if (sfx_envelope_counter != 4) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 7) {
      if (sfx_envelope_counter != 4) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 8) {
      if (sfx_envelope_counter != 1) goto LAB_6f9c;
      sfx_envelope_counter = 0;
      sfx_envelope = sfx_envelope - 1;
      if (sfx_envelope == 4) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 3) {
        ch1_initializer();
        return;
      }
      if (sfx_envelope == 2) {
        ch1_initializer();
        return;
      }
    }
    else if (current_sfx_active == 9) {
      BYTE_dfd0 = 5;
      BYTE_dfd1 = 4;
      io_audio_registers = 0;
      NR11 = 0xbf;
      NR12 = 0x40;
      if (sfx_envelope_counter != 0) {
        do {
          bVar1 = ch1_pitch + 1;
          if (bVar1 == 99) {
            sfx_envelope_counter = 0;
            return;
          }
          ch1_pitch = bVar1;
          BYTE_dfd0 = BYTE_dfd0 - 1;
        } while (BYTE_dfd0 != 0);
        NR13 = bVar1;
        NR14 = ch1_freq_hi;
        return;
      }
      while (bVar1 = ch1_freq_lo - 1, bVar1 != 0x10) {
        ch1_freq_lo = bVar1;
        BYTE_dfd1 = BYTE_dfd1 - 1;
        if (BYTE_dfd1 == 0) {
          NR13 = bVar1;
          NR14 = ch1_freq_hi;
          return;
        }
      }
      NR12 = 0;
    }
    else {
      if (current_sfx_active == 10) {
        BYTE_dfd0 = 9;
        BYTE_dfd1 = 4;
        io_audio_registers = 0;
        NR11 = 0xbf;
        NR12 = 0x90;
        if (sfx_envelope_counter == 0) {
          do {
            bVar1 = ch1_freq_lo - 1;
            if (bVar1 == 0x1e) {
              current_sfx_active = 0;
              NR12 = 0;
              return;
            }
            ch1_freq_lo = bVar1;
            BYTE_dfd1 = BYTE_dfd1 - 1;
          } while (BYTE_dfd1 != 0);
          NR13 = bVar1;
          NR14 = BYTE_dffe;
          return;
        }
        do {
          bVar1 = ch1_pitch + 1;
          if (bVar1 == 0x89) {
            sfx_envelope_counter = 0;
            return;
          }
          ch1_pitch = bVar1;
          BYTE_dfd0 = BYTE_dfd0 - 1;
        } while (BYTE_dfd0 != 0);
        NR13 = bVar1;
        NR14 = ch1_freq_hi;
        return;
      }
      if (current_sfx_active == 0xb) {
        BYTE_dfd1 = 8;
        io_audio_registers = 0;
        NR11 = 0xbf;
        NR12 = 0x90;
        while (bVar1 = ch1_freq_lo - 1, bVar1 != 6) {
          ch1_freq_lo = bVar1;
          BYTE_dfd1 = BYTE_dfd1 - 1;
          if (BYTE_dfd1 == 0) {
            NR13 = bVar1;
            NR14 = BYTE_dffe;
            return;
          }
        }
        NR12 = 0;
        ceiling_collision_sfx_active_flag = 0;
      }
      else {
        if (current_sfx_active != 0xc) {
          return;
        }
        BYTE_dfd0 = 0x28;
        BYTE_dfd1 = 0x28;
        io_audio_registers = 0;
        NR11 = 0xbf;
        NR12 = 0x40;
        if (sfx_envelope_counter != 0) {
          do {
            bVar1 = ch1_pitch - 1;
            if (bVar1 == 0x10) {
              sfx_envelope_counter = 0;
              return;
            }
            ch1_pitch = bVar1;
            BYTE_dfd0 = BYTE_dfd0 - 1;
          } while (BYTE_dfd0 != 0);
          NR13 = bVar1;
          NR14 = ch1_freq_hi;
          return;
        }
        while (bVar1 = ch1_freq_lo + 1, bVar1 != 99) {
          ch1_freq_lo = bVar1;
          BYTE_dfd1 = BYTE_dfd1 - 1;
          if (BYTE_dfd1 == 0) {
            NR13 = bVar1;
            NR14 = ch1_freq_hi;
            return;
          }
        }
        NR12 = 0;
      }
    }
  }
  current_sfx_active = 0;
  NR12 = 0;
  sfx_envelope_counter = 0;
  sfx_envelope = 0;
  return;
}

// Copies 5 bytes of data from (HL) to (C) incrementally

void ch1_initializer(void)
{
  byte in_C;
  undefined1 *in_HL;
  
  *(undefined1 *)(in_C | 0xff00) = *in_HL;
  *(undefined1 *)((byte)(in_C + 1) | 0xff00) = in_HL[1];
  *(undefined1 *)((byte)(in_C + 2) | 0xff00) = in_HL[2];
  *(undefined1 *)((byte)(in_C + 3) | 0xff00) = in_HL[3];
  *(undefined1 *)((byte)(in_C + 4) | 0xff00) = in_HL[4];
  return;
}

// Handles whether to trigger the explosion SFX or not and loads the CH4 data for it

void ch4_explosion_handler(void)
{
  if (ball_oob != 1) {
    init_ch4_explosion_sfx_pan();
    return;
  }
  ch4_panning_timer = 0x49;
  ch4_panning = 0xf;
  ch2_pan_active = 0;
  ch4_initializer();
  return;
}

// Triggers the explosion soundWrites 4 bytes that inits CH4

void ch4_initializer(void)
{
  byte in_C;
  undefined1 *in_HL;
  
  *(undefined1 *)(in_C | 0xff00) = *in_HL;
  *(undefined1 *)((byte)(in_C + 1) | 0xff00) = in_HL[1];
  *(undefined1 *)((byte)(in_C + 2) | 0xff00) = in_HL[2];
  *(undefined1 *)((byte)(in_C + 3) | 0xff00) = in_HL[3];
  return;
}

// Inits the auto-pan for the explosion sfx

void init_ch4_explosion_sfx_pan(void)
{
  bool bVar1;
  
  if (ch4_panning_timer != 0) {
    ch4_panning_timer = ch4_panning_timer - 1;
    if (ch4_panning_timer != 0) {
      bVar1 = (bool)(ch4_panning >> 7);
      ch4_panning = ch4_panning << 1 | bVar1;
      if (bVar1) {
        NR51 = 0xf;
        return;
      }
      NR51 = 0xf0;
      return;
    }
    NR51 = 0xff;
  }
  ch4_panning_timer = 0;
  return;
}

void music_track_handler(void)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (track_index == 1) {
    ch1_current_track = 1;
    ch3_current_track = 1;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pan_active = 1;
    ch2_panning_triggered_flag = 1;
    ch2_pan_direction = 1;
    ch2_pan_timer = 0x60;
    ch2_pan_timer_max = 0x60;
    ch2_pattern_ptr_hi = 0x75;
    ch2_pattern_ptr_lo = 0xe3;
    ch3_pattern_ptr_hi = 0x76;
    ch3_pattern_ptr_lo = 0x52;
    music_playback_handler();
    return;
  }
  if (track_index == 2) {
    NR51 = 0xff;
    ch2_pan_active = 0;
    ch1_current_track = 2;
    ch3_current_track = 2;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x76;
    ch2_pattern_ptr_lo = 0xc3;
    ch3_pattern_ptr_hi = 0x76;
    ch3_pattern_ptr_lo = 0xd9;
    music_playback_handler();
    return;
  }
  if (track_index == 3) {
    ch1_current_track = 3;
    ch3_current_track = 3;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pan_active = 1;
    ch2_panning_triggered_flag = 1;
    ch2_pan_direction = 1;
    ch2_pan_timer = 0x60;
    ch2_pan_timer_max = 0x60;
    ch2_pattern_ptr_hi = 0x76;
    ch2_pattern_ptr_lo = 0xf0;
    ch3_pattern_ptr_hi = 0x77;
    ch3_pattern_ptr_lo = 0x12;
    music_playback_handler();
    return;
  }
  if (track_index == 4) {
    ch2_pan_active = 0;
    ch1_current_track = 4;
    ch3_current_track = 4;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x77;
    ch2_pattern_ptr_lo = 0x33;
    ch3_pattern_ptr_hi = 0x77;
    ch3_pattern_ptr_lo = 0x38;
    music_playback_handler();
    return;
  }
  if (track_index == 5) {
    NR51 = 0xff;
    ch2_pan_active = 0;
    ch1_current_track = 5;
    ch3_current_track = 5;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x77;
    ch2_pattern_ptr_lo = 0x3b;
    ch3_pattern_ptr_hi = 0x77;
    ch3_pattern_ptr_lo = 0x50;
    music_playback_handler();
    return;
  }
  if (track_index == 6) {
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pan_active = 1;
    ch2_panning_triggered_flag = 1;
    ch2_pan_direction = 1;
    ch2_pan_timer = 0x28;
    ch2_pan_timer_max = 0x28;
    ch2_pattern_ptr_hi = 0x77;
    ch2_pattern_ptr_lo = 0x65;
    ch3_pattern_ptr_hi = 0x77;
    ch3_pattern_ptr_lo = 0x9b;
    music_playback_handler();
    return;
  }
  if (track_index == 7) {
    ch1_current_track = 7;
    ch3_current_track = 7;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pan_active = 1;
    ch2_panning_triggered_flag = 1;
    ch2_pan_direction = 1;
    ch2_pan_timer = 0x20;
    ch2_pan_timer_max = 0x20;
    ch2_pattern_ptr_hi = 0x77;
    ch2_pattern_ptr_lo = 0xd7;
    ch3_pattern_ptr_hi = 0x78;
    ch3_pattern_ptr_lo = 0xd;
    music_playback_handler();
    return;
  }
  if (track_index == 8) {
    ch2_pan_active = 0;
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x78;
    ch2_pattern_ptr_lo = 0x49;
    ch3_pattern_ptr_hi = 0x78;
    ch3_pattern_ptr_lo = 0x5c;
    music_playback_handler();
    return;
  }
  if (track_index == 9) {
    ch2_pan_active = 0;
    NR51 = 0xff;
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x78;
    ch2_pattern_ptr_lo = 0x75;
    ch3_pattern_ptr_hi = 0x78;
    ch3_pattern_ptr_lo = 0x87;
    music_playback_handler();
    return;
  }
  if (track_index == 10) {
    ch2_pan_active = 0;
    NR51 = 0xff;
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x78;
    ch2_pattern_ptr_lo = 0x9c;
    ch3_pattern_ptr_hi = 0x78;
    ch3_pattern_ptr_lo = 0xd6;
    music_playback_handler();
    return;
  }
  if (track_index == 0xb) {
    ch2_pan_active = 0;
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x79;
    ch2_pattern_ptr_lo = 0xf;
    ch3_pattern_ptr_hi = 0x79;
    ch3_pattern_ptr_lo = 0x19;
    music_playback_handler();
    return;
  }
  if (track_index == 0xc) {
    ch2_pan_active = 0;
    ch1_current_track = 6;
    ch3_current_track = 6;
    ch2_note_length = 1;
    ch3_note_length = 1;
    music_triggered_flag = 1;
    ch2_pattern_ptr_hi = 0x79;
    ch2_pattern_ptr_lo = 0x1f;
    ch3_pattern_ptr_hi = 0x79;
    ch3_pattern_ptr_lo = 0x88;
    music_playback_handler();
    return;
  }
  if (ch1_current_track == 0) {
    if (ch3_current_track == 0) {
      return;
    }
  }
  else {
    ch2_note_length = ch2_note_length - 1;
    if (ch2_note_length == 0) {
      pbVar3 = (byte *)CONCAT11(ch2_pattern_ptr_hi,ch2_pattern_ptr_lo);
      while( true ) {
        pbVar2 = pbVar3 + 1;
        bVar1 = *pbVar3;
        if ((bVar1 & 0x80) == 0) break;
        ch2_note_length = note_length_table[bVar1 & 0xff7f];
        pbVar3 = pbVar2;
        ch2_note_length_max = ch2_note_length;
      }
      if (bVar1 == 0) {
        ch1_current_track = 0;
        ch2_pan_active = 0;
        NR12 = 0;
        return;
      }
      if (bVar1 == 0x7f) goto pattern_loop_command;
      if (bVar1 == 1) {
        mute_ch2();
      }
      else {
        NR21 = 0xbf;
        NR22 = 0xf2;
        NR23 = note_freq_lo_table[1][bVar1];
        NR24 = note_freq_lo_table[0][bVar1];
        ch2_pitch_mirror = bVar1;
      }
      ch2_pattern_ptr_hi = (byte)((uint)pbVar2 >> 8);
      ch2_pattern_ptr_lo = (byte)pbVar2;
      if (ch2_note_length == 0) {
        ch2_note_length = ch2_note_length_max;
      }
    }
  }
  ch3_note_length = ch3_note_length - 1;
  if (ch3_note_length == 0) {
    pbVar3 = (byte *)CONCAT11(ch3_pattern_ptr_hi,ch3_pattern_ptr_lo);
    while( true ) {
      pbVar2 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if ((bVar1 & 0x80) == 0) break;
      ch3_note_length = note_length_table[bVar1 & 0xff7f];
      pbVar3 = pbVar2;
      ch3_note_length_max = ch3_note_length;
    }
    if (bVar1 == 0) {
      ch3_current_track = 0;
      ch2_pan_active = 0;
      NR32 = 0;
      return;
    }
    if (bVar1 == 0x7f) {
pattern_loop_command:
      track_index = ch1_current_track;
      music_track_handler();
      return;
    }
    if (bVar1 == 1) {
      mute_ch3();
    }
    else {
      NR30 = 0;
      NR30 = 0x80;
      NR31 = 0xff;
      ch3_pitch_mirror = bVar1;
      load_ch3_waveform();
      NR32 = 0x20;
      NR33 = note_freq_lo_table[1][ch3_pitch_mirror];
      NR34 = note_freq_lo_table[0][ch3_pitch_mirror];
    }
    ch3_pattern_ptr_hi = (byte)((uint)pbVar2 >> 8);
    ch3_pattern_ptr_lo = (byte)pbVar2;
    if (ch3_note_length == 0) {
      ch3_note_length = ch3_note_length_max;
    }
  }
  return;
}

void music_playback_handler(void)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  ch2_note_length = ch2_note_length - 1;
  if (ch2_note_length == 0) {
    pbVar3 = (byte *)CONCAT11(ch2_pattern_ptr_hi,ch2_pattern_ptr_lo);
    while( true ) {
      pbVar2 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if ((bVar1 & 0x80) == 0) break;
      ch2_note_length = note_length_table[bVar1 & 0xff7f];
      pbVar3 = pbVar2;
      ch2_note_length_max = ch2_note_length;
    }
    if (bVar1 == 0) {
      ch1_current_track = 0;
      ch2_pan_active = 0;
      NR12 = 0;
      return;
    }
    if (bVar1 == 0x7f) goto pattern_loop_command;
    if (bVar1 == 1) {
      mute_ch2();
    }
    else {
      NR21 = 0xbf;
      NR22 = 0xf2;
      NR23 = note_freq_lo_table[1][bVar1];
      NR24 = note_freq_lo_table[0][bVar1];
      ch2_pitch_mirror = bVar1;
    }
    ch2_pattern_ptr_hi = (byte)((uint)pbVar2 >> 8);
    ch2_pattern_ptr_lo = (byte)pbVar2;
    if (ch2_note_length == 0) {
      ch2_note_length = ch2_note_length_max;
    }
  }
  ch3_note_length = ch3_note_length - 1;
  if (ch3_note_length == 0) {
    pbVar3 = (byte *)CONCAT11(ch3_pattern_ptr_hi,ch3_pattern_ptr_lo);
    while( true ) {
      pbVar2 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if ((bVar1 & 0x80) == 0) break;
      ch3_note_length = note_length_table[bVar1 & 0xff7f];
      pbVar3 = pbVar2;
      ch3_note_length_max = ch3_note_length;
    }
    if (bVar1 == 0) {
      ch3_current_track = 0;
      ch2_pan_active = 0;
      NR32 = 0;
      return;
    }
    if (bVar1 == 0x7f) {
pattern_loop_command:
      track_index = ch1_current_track;
      music_track_handler();
      return;
    }
    if (bVar1 == 1) {
      mute_ch3();
    }
    else {
      NR30 = 0;
      NR30 = 0x80;
      NR31 = 0xff;
      ch3_pitch_mirror = bVar1;
      load_ch3_waveform();
      NR32 = 0x20;
      NR33 = note_freq_lo_table[1][ch3_pitch_mirror];
      NR34 = note_freq_lo_table[0][ch3_pitch_mirror];
    }
    ch3_pattern_ptr_hi = (byte)((uint)pbVar2 >> 8);
    ch3_pattern_ptr_lo = (byte)pbVar2;
    if (ch3_note_length == 0) {
      ch3_note_length = ch3_note_length_max;
    }
  }
  return;
}

// loads ch3_waveform_data in intervals of 0x10

void load_ch3_waveform(void)
{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = 0x30;
  pbVar2 = ch3_waveform_data;
  do {
    *(byte *)(bVar1 | 0xff00) = *pbVar2;
    bVar1 = bVar1 + 1;
    ch3_waveform_index = ch3_waveform_index + 1;
    pbVar2 = pbVar2 + 1;
  } while (ch3_waveform_index != 0x10);
  ch3_waveform_index = 0;
  return;
}

void ch2_set_note_length(void)
{
  byte bVar1;
  byte in_A;
  byte *pbVar2;
  byte *pbVar3;
  byte *in_HL;
  
  do {
    ch2_note_length = note_length_table[in_A & 0xff7f];
    ch2_note_length_max = ch2_note_length;
    pbVar2 = in_HL + 1;
    in_A = *in_HL;
    in_HL = pbVar2;
  } while ((in_A & 0x80) != 0);
  if (in_A == 0) {
    ch1_current_track = 0;
    ch2_pan_active = 0;
    NR12 = 0;
    return;
  }
  if (in_A != 0x7f) {
    if (in_A == 1) {
      mute_ch2();
    }
    else {
      NR21 = 0xbf;
      NR22 = 0xf2;
      NR23 = note_freq_lo_table[1][in_A];
      NR24 = note_freq_lo_table[0][in_A];
      ch2_pitch_mirror = in_A;
    }
    ch2_pattern_ptr_hi = (byte)((uint)pbVar2 >> 8);
    ch2_pattern_ptr_lo = (byte)pbVar2;
    if (ch2_note_length == 0) {
      ch2_note_length = ch2_note_length_max;
    }
    ch3_note_length = ch3_note_length - 1;
    if (ch3_note_length == 0) {
      pbVar2 = (byte *)CONCAT11(ch3_pattern_ptr_hi,ch3_pattern_ptr_lo);
      while( true ) {
        pbVar3 = pbVar2 + 1;
        bVar1 = *pbVar2;
        if ((bVar1 & 0x80) == 0) break;
        ch3_note_length = note_length_table[bVar1 & 0xff7f];
        pbVar2 = pbVar3;
        ch3_note_length_max = ch3_note_length;
      }
      if (bVar1 == 0) {
        ch3_current_track = 0;
        ch2_pan_active = 0;
        NR32 = 0;
        return;
      }
      if (bVar1 == 0x7f) goto pattern_loop_command;
      if (bVar1 == 1) {
        mute_ch3();
      }
      else {
        NR30 = 0;
        NR30 = 0x80;
        NR31 = 0xff;
        ch3_pitch_mirror = bVar1;
        load_ch3_waveform();
        NR32 = 0x20;
        NR33 = note_freq_lo_table[1][ch3_pitch_mirror];
        NR34 = note_freq_lo_table[0][ch3_pitch_mirror];
      }
      ch3_pattern_ptr_hi = (byte)((uint)pbVar3 >> 8);
      ch3_pattern_ptr_lo = (byte)pbVar3;
      if (ch3_note_length == 0) {
        ch3_note_length = ch3_note_length_max;
      }
    }
    return;
  }
pattern_loop_command:
  track_index = ch1_current_track;
  music_track_handler();
  return;
}

// $7F handler: reads current ch1 track as byte as track number, restarts music_handler

void pattern_loop_command(void)
{
  track_index = ch1_current_track;
  music_track_handler();
  return;
}

// Auto-panner for CH2

void ch2_pan_handler(void)
{
  if (ch2_pan_active != 1) {
    ch2_pan_active = 0;
    return;
  }
  if (ch2_pan_direction == 1) {
    ch2_pan_timer = ch2_pan_timer - 1;
    if (ch2_pan_timer != 0) {
      NR51 = 0x75;
      return;
    }
    ch2_pan_direction = 0;
    ch2_pan_timer = ch2_pan_timer_max;
    return;
  }
  ch2_pan_timer = ch2_pan_timer - 1;
  if (ch2_pan_timer != 0) {
    NR51 = 0x57;
    return;
  }
  ch2_pan_direction = 1;
  ch2_pan_timer = ch2_pan_timer_max;
  return;
}

// clears the current_track values and sets the music_flag to 0
// Turns CH1,2 and 3's amplitudes to 0 as well

void stop_music(void)
{
  music_flag = 0;
  ch1_current_track = 0;
  ch3_current_track = 0;
  NR12 = 0;
  NR22 = 0;
  NR32 = 0;
  return;
}

// Turns off CH2's volume and envelope

void mute_ch2(void)
{
  NR22 = 0;
  return;
}

// turns off CH3's DAC

void mute_ch3(void)
{
  NR30 = 0;
  return;
}

void debug_reset_sfx_clear_flag(void)
{
  debug_sfx_clear_flag = 1;
  return;
}

void debug_set_sfx_clear_flag(void)
{
  debug_sfx_clear_flag = 0;
  return;
}

void audio_update(void)
{
  demo_flag_handler();
  sfx_handler();
  ch4_explosion_handler();
  music_track_handler();
  ch2_pan_handler();
  game_event = 0;
  ball_oob = 0;
  track_index = 0;
  return;
}

// CALL instruction as a means to switch banks

void stop_music_wrapper(void)
{
  stop_music();
  return;
}