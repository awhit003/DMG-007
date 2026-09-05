# DMG-007 Sharp RLCD Driver Firmware

Clean-room open-source firmware for Raspberry Pi RP2040 driving the Sharp Memory LCD (LS032B7DD02) from Nintendo Game Boy DMG LCD signals.

## Architecture

* **PIO 0**: Samples Game Boy LCD `DATA0` and `DATA1` on `CL2` (pixel clock) falling edge.
  * Synchronized by `CL1` (horizontal line latch) and `VSYNC` (frame start).
* **DMA**: Transports line buffers to Core 1 without CPU intervention.
* **Core 1**: Converts 2-bit grayscale pixels (160x144) to 1-bit black & white (320x288) via 2x2 Bayer dithering matrix.
* **Core 0**: Handles USB interface, COM inversion periodic toggle (required for Sharp Memory LCD health), and system status.
* **SPI Controller**: Streams the 320x288 1-bit frame to the Sharp panel over high-speed serial bus at 60 Hz.
