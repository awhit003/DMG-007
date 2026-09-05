#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/dma.h"

/*
 * Sharp LS032B7DD02 Memory LCD Driver
 * Resolution: 336 x 536 (Active viewing area scaled 2x: 320 x 288)
 */

#define SHARP_SPI_PORT   spi0
#define PIN_SHARP_CS     17
#define PIN_SHARP_CLK    18
#define PIN_SHARP_MOSI   19
#define PIN_SHARP_DISP   20

#define SHARP_WIDTH      336
#define SHARP_HEIGHT     536

// Command Mode flags
#define SHARP_CMD_UPDATE 0x01
#define SHARP_CMD_VCOM   0x02
#define SHARP_CMD_CLEAR  0x04

static uint8_t vcom_state = 0;

void sharp_mip_init(void) {
    spi_init(SHARP_SPI_PORT, 2000000); // 2 MHz SPI clock
    gpio_set_function(PIN_SHARP_CLK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SHARP_MOSI, GPIO_FUNC_SPI);
    
    gpio_init(PIN_SHARP_CS);
    gpio_set_dir(PIN_SHARP_CS, GPIO_OUT);
    gpio_put(PIN_SHARP_CS, 0);
    
    gpio_init(PIN_SHARP_DISP);
    gpio_set_dir(PIN_SHARP_DISP, GPIO_OUT);
    gpio_put(PIN_SHARP_DISP, 1); // Turn on display
}

void sharp_mip_toggle_vcom(void) {
    vcom_state ^= SHARP_CMD_VCOM;
}

// 2x2 Bayer Dither Matrix for 4 shades of Game Boy grayscale:
// 0 (Black), 1 (Dark Gray), 2 (Light Gray), 3 (White)
static const uint8_t bayer_2x2[4][2] = {
    // Row 0, Row 1 (2 bits wide per row: bit 0, bit 1)
    { 0b00, 0b00 }, // Level 0 (Black): 0 pixels lit
    { 0b10, 0b00 }, // Level 1 (Dark Gray): 1 pixel lit
    { 0b10, 0b01 }, // Level 2 (Light Gray): 2 pixels lit
    { 0b11, 0b11 }  // Level 3 (White): all 4 pixels lit
};

void sharp_render_line(uint16_t gb_y, const uint8_t *gb_line_2bit, uint8_t *out_row0, uint8_t *out_row1) {
    // Expands 160 2-bit pixels to 320 1-bit pixels across two scanlines
    for (int x = 0; x < 160; x++) {
        uint8_t pixel_val = (gb_line_2bit[x / 4] >> ((x % 4) * 2)) & 0x03;
        uint8_t r0 = bayer_2x2[pixel_val][0];
        uint8_t r1 = bayer_2x2[pixel_val][1];
        
        int byte_idx = (x * 2) / 8;
        int bit_shift = (x * 2) % 8;
        
        out_row0[byte_idx] |= (r0 << bit_shift);
        out_row1[byte_idx] |= (r1 << bit_shift);
    }
}
