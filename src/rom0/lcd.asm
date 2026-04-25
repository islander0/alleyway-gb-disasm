SECTION "LCD Switch", ROM0[$0244]

lcd_ppu_enable:
    ldh a, [h_lcdc_mirror] 
    and $7F
    or $80
    ldh [h_lcdc_mirror], a 
    ldh [rLCDC], a 
    ret

lcd_disable_and_wait_vblank:
    ldh a, [h_lcdc_mirror] 
    and $7F
    ldh [h_lcdc_mirror], a 
    jr wait_vblank

SECTION "Palette", ROM0[$08A7]

load_fade_in_data:
    ld hl, $8C2
    jr set_counter

game_win_fade_handler:
    ld hl, $8C6 ; load_fade_out_data

set_counter:
    ld b, $4

.Lab_08b1
    ld a, [hl+] ; =>palette_fade_out_data
    call set_palette_data
    push bc
    push hl
    ld a, $10
    call wait_frames    ; wait 10 frames
    pop hl
    pop bc
    dec b
    jr nz, .Lab_08b1
    ret

SECTION "Set Palette Data", ROM0[$08CA]

set_palette_data:
    ldh [rBGP], a
    ldh [rOBP0], a 
    ldh [rOBP1], a 
    ret

SECTION "LCD Stat Work", ROM0[$0B67]

lcd_stat_work:
    ldh a, [h_brick_scroll_flag]            
    ld c, a
    inc a
    cp $15  ; counter = 20
    jr nc, .lcd_stat_reset

    ldh [h_brick_scroll_flag], a 
    sla a
    sla a
    ld b, $7
    add b

    ldh [rLYC], a
    ld b, $0
    ld hl, $CA00
    add hl, bc
    ld a, [hl]  ; =>[w_scroll_x_table]
    ldh [rSCX], a
    xor a
    cp c
    ret nz

    ld a, [w_lcd_y]               
    ldh [rSCY], a
    ret

.lcd_stat_reset
    xor a
    ldh [h_brick_scroll_flag], a 
    ld b, $7
    add b
    ldh [rLYC], a
    ld a, [w_lcd_y_vblank]        
    ldh [rSCY], a
    xor a
    ldh [rSCX], a
    ret

SECTION "LCD Y", ROM0[$0BAD]

; executes on level load and bricks falling down
; set the LCD viewport's y origin to lcd_y_descent_counter * 4
; there's some code modifying the LCD's position during vblank 
; if the descent counter is <15, but this value is never reached
; during regular gameplay.

update_lcd_y:
    ldh a, [h_lcd_y_descent_counter]        
    sla a
    sla a   ; brick_fall_counter * 4
    add $0  ; useless, maybe old code remnant
    ld [w_lcd_y], a    
    ld b, $70
    ldh a, [h_lcd_y_descent_counter]        
    cp $15
    jr c, .update_lcd_y_vblank   ; normally never happens during normal gameplay
    ld b, $B0

.update_lcd_y_vblank
    ld a, b
    ld [w_lcd_y_vblank], a    ; = $70 always
    ret

lcd_y_handler:
    ldh a, [h_lcd_y_descent_counter]        
    cp $0
    ret z
    dec a
    ldh [h_lcd_y_descent_counter], a
    call load_track_brick_scrolldown    ; play brick scrolldown sfx
    call update_lcd_y
    call load_next_brick_line_obj
    ldh a, [h_lcd_y_descent_counter]        
    cp $0
    ret z
    dec a
    ret z
    ld b, a
    and $1
    ret z
    ld a, b
    ldh [h_play_area_scroll_y], a
    call brick_collision_handler
    ldh a, [h_play_area_scroll_y]           
    add $16
    ldh [h_play_area_scroll_y], a
    jp brick_collision_handler