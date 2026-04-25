SECTION "Increment Stage Number Display", ROM0[$0744]

; triggers upon losing in a bonus level       

increment_stage_number_display:
    ld a, [w_stage_number_display]
    inc a
    ld [w_stage_number_display], a
    ret

SECTION "Score and Extra Lives", ROM0[$0C32]

; adds brick score to player_score, caps at $FFFF

add_brick_score_to_player_score:
    dec a   ; A = brick type collision - 1
    ld b, a
    ld e, $6
    call multiply   ; bc = A x 6
    ld hl, $1B87
    add hl, bc      ; hl +0, +$6, +$C or +$12
    ld b, $0
    ld c, $3
    add hl, bc
    ld a, [hl]  ; [hl]  ; =>brick_data_table[0][3]): hl +$3, +$9, +$F or +$15
    swap a
    and $F
    ld b, a
    ldh a, [h_player_score_lo]              
    add b
    ldh [h_player_score_lo], a   
    ldh a, [h_player_score_hi]              
    adc $0
    ldh [h_player_score_hi], a   
    ret nc
    xor a   ; cancel score addition: score cap
    dec a
    ldh [h_player_score_hi], a  ; = $FF
    ldh [h_player_score_lo], a  ; = $FF
    ret

; updates the current player score
; if the top score is achieved, the top score will
; update in sync with the player score

update_score_all:
    ld bc, $FFCC
    ld hl, $FFCA
    ldh a, [c]  ; =>h_top_score_lo   
    sub [hl]    ; =>h_player_score_lo
    push af
    inc c
    inc hl      ; =>h_player_score_hi   
    pop af
    ldh a, [c]  ; =>h_top_score_hi   
    sbc [hl]    ; =>h_player_score_hi
    ret nc
; IF SCORE > TOP
    ld a, [hl]  ; =>h_player_score_hi
    ldh [c], a  ; =>h_top_score_hi
    dec c
    dec hl    ; =>h_player_score_lo   
    ld a, [hl]  ; =>h_player_score_lo             
    ldh [c], a  ; =>h_top_score_lo, a 
    ret

extra_life_score_handler:
    ld hl, $FFCA
    ldh a, [h_extra_life_score_threshold_lo]
    sub [hl]    ; [hl]  ; =>h_player_score_lo
    push af
    inc hl      ; [hl] =>h_player_score_hi   
    pop af
    ldh a, [h_extra_life_score_threshold_hi]
    sbc [hl]    ; [hl]  ; =>h_player_score_hi
    ret nc
; IF SCORE >= MULTIPLE OF 1000
    ld a, [w_life_counter]   ; =>[w_life_counter]        
    cp $9
    jr nc, .Lab_0c8c
; IF life < 10
    inc a
    ld [w_life_counter], a      
    call set_event_extra_life

.Lab_0c8c 
    call load_lives_number_vram

set_next_extra_life_score_threshold:
    ldh a, [h_extra_life_gained_total]      
    sla a
    ld c, a
    ld b, $0
    ld hl, $1b5d
    add hl, bc
    ld a, [hl+] ; =>extra_life_threshold_table
    ldh [h_extra_life_score_threshold_hi], a               
    ld a, [hl]  ; =>extra_life_threshold_table[1]
    ldh [h_extra_life_score_threshold_lo], a               
    ldh a, [h_extra_life_gained_total]      
    inc a
    ldh [h_extra_life_gained_total], a                     
    ret

SECTION "Extra Life Threshold Table", ROM0[$1B5D]

; 10 16-bit addresses            
; When extra_life_value increments, the score updates in ... *

extra_life_threshold_table:
    db $03,$E8,$07,$D0,$0B,$B8,$0F,$A0,$13,$88,$17,$70,$1B,$58,$1F,$40,$23,$28,$FF,$FF