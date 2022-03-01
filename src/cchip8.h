#pragma once

#include<cstdint>

class Chip8
{
    private:
    void LoadROM(char const* romFile);


    // Register size, memory size, and other registers given by:
    // http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
    public:
    uint8_t registers[16]{};
    uint8_t memory[4096]{};
    uint16_t stack[16]{};
    uint16_t index{};
    uint16_t opcode;
    uint16_t pc{};

    // Stack pointer
    uint8_t sp{};
    
    // Active whenever the delay timer register (DT) is non-zero
    uint8_t delay_timer{};

    // Active whenever the sound timer register (ST) is non-zero
    uint8_t sound_timer{};

    /*
    1	2	3	C
    4	5	6	D
    7	8	9	E
    A	0	B	F
    */
    uint8_t keypad[16]{};

    /*
    (0,0)-----------(63,0)
    |                  |
    (0,31)----------(63,31)
    */
    uint32_t video[64* 32]{};
};