# Alleyway (Game Boy) — Decompilation

Annotated decompilation of **Alleyway** (Nintendo, 1989) for the Game Boy.

## Tools
- **Ghidra 11.4.2:** (https://github.com/NationalSecurityAgency/ghidra/
releases/tag/Ghidra_11.4.2_build) with the **GhidraBoy**
(https://github.com/Gekkio/GhidraBoy) extension.

## Files
- This decompilation targets the single known ROM revision (World, CRC32:
5CC01586, SHA-1: 0CF2B8D0428F389F5361F67A0CD1ACE05A1C75CC), which was released
identically across all regions. The ROM is *not* included in this repo for legal
reasons, you will need to provide your own.
- `alleyway_gb.c` — Full decompiled output with renamed functions, 
  variables, and inline comments

## Coverage
197 functions identified and named, including 12 that are either
unreachable, debug or unused.

## Notable Findings

**Unused tilemap blitter (`unused_tilemap_blit`, 0x0302)**  
A general-purpose rectangular tile stamp routine that reads inline 
parameters from the call site. Never called in the final game:
likely a scrapped screen layout system that was replaced by the 
hardcoded `load_*_vram` functions.

**Serial port RNG (`serial_falling_edge_detector_bit7`)**  
The game seeds its RNG using the Game Boy's serial port in 
internal clock mode, exploiting the undefined floating-state 
of SB to generate entropy. Effectively random on real hardware, 
deterministic on emulator.

**Scrapped ball velocity mechanic (`unused_ball_velocity_brick_collision_handler`)**  
Dead code that would have incremented ball speed every 8 bricks 
hit. Replaced by the brick-type-based velocity system used in 
the final game.

**Paddle wall-clip bug (`clamp_paddle_x`)**  
When the player dies with a small paddle while hugging the right wall,
the paddle resets to normal width without re-clamping its position,
causing it to clip inside the wall. Resolves on next movement input.
This bug is fixed in the [Alleyway DX](https://www.romhacking.net/hacks/6510/) ROM hack.

## License
This project contains no Nintendo IP. The `.c` file is a 
decompiler output and represents original research and annotation work.
