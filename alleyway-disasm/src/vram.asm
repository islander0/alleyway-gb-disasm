SECTION "VRAM Region", VRAM[$8000]

DEF VRAM_TILE_BLOCK_0_START  EQU $8000
DEF VRAM_TILE_BLOCK_1_START  EQU $8800
DEF VRAM_TILE_BLOCK_2_START  EQU $9000

DEF VRAM_TILE_MAP_0_START    EQU $9800
DEF VRAM_TILE_MAP_1_START    EQU $9C00

v_tile_block_0:
    ds 2048

v_tile_block_1:
    ds 2048

v_tile_block_2:
    ds 2048

v_tile_map_0:
    ds 1024

v_tile_map_1:
    ds 1024