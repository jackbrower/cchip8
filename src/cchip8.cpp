#include<fstream>

#include "./cchip8.h"

// Chip8 fontset, copied from:
// https://github.com/JamesGriffin/CHIP-8-Emulator/blob/master/src/chip8.cpp
unsigned char chip8_fontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, //0
    0x20, 0x60, 0x20, 0x20, 0x70, //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
    0x90, 0x90, 0xF0, 0x10, 0x10, //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
    0xF0, 0x10, 0x20, 0x40, 0x40, //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
    0xF0, 0x90, 0xF0, 0x90, 0x90, //A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
    0xF0, 0x80, 0x80, 0x80, 0xF0, //C
    0xE0, 0x90, 0x90, 0x90, 0xE0, //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
    0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

Chip8::Chip8(){
    // Initialize pointer
    pc = 0x200;
    
    // Load fonts into RAM
    unsigned int FONT_START_ADR = 0x50;
    for (int i = 0; i < 80; i++) {
        memory[FONT_START_ADR + i] = fontset[i];
    }
}

Chip8::LoadROM(char const* romFile) {
    // Open binary and move pointer to end
    std::ifstream file(romFile, std::ios::binary | std::ios::ate);

    if (file.is_open()) {
        // Read file size, allocate buffer
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        // Read file from beginning
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Load buffer into Chip8 RAM
        for (long i = 0; i < size; i++) {
            memory[0x200 + i] = buffer[i];
        }

        // Free buffer after file loaded into RAM
        delete[] buffer;
    }
}