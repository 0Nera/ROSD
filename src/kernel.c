#include <stdint.h>

uint16_t* vga_buffer = (uint16_t*)0xB8000;
#define VGA_COLS 80
#define VGA_ROWS 25
 
int VGA_col = 0;
int VGA_row = 0;
uint8_t VGA_color = 15; // Черный фон, белый текст
 


void clear(){
    for (int col = 0; col < VGA_COLS; col++){
        for (int row = 0; row < VGA_ROWS; row++){
            const int index = (VGA_COLS * row) + col;
            vga_buffer[index] = ((uint16_t)VGA_color << 8) | ' '; 
        }
    }
    VGA_col = 0;
    VGA_row = 0;
}


void puts(const char *str){
    for (int i = 0; str[i] != '\0'; i ++){
        const int index = (VGA_COLS * VGA_row) + VGA_col++;
        vga_buffer[index] = ((uint16_t)VGA_color << 8) | str[i];
    }
}


void kernel_main() {
    clear();

    puts("ROSD 0.1.0");

    for(;;){
        hlt();
    }
}