# Board 04: Sharp RLCD Driver Board Design Specification

## 1. System Architecture
* **Target Display:** Sharp LS032B7DD02 (3.2" 336x536 Reflective Memory LCD)
* **Controller:** Raspberry Pi RP2040 (QFN-56)
* **Firmware Framework:** Raspberry Pi Pico C/C++ SDK (using PIO state machines)
* **Assembly Target:** 100% Turnkey JLCPCB SMT Assembly (Single-side SMD)

---

## 2. Complete Parts List (JLCPCB LCSC Part Numbers)

### Active Silicon
| Designator | Value / Part | Footprint | LCSC Part # | Role |
| :--- | :--- | :--- | :--- | :--- |
| **U1** | RP2040 | QFN-56 (7x7mm, 0.4mm pitch) | `C2914104` | Dual-core Cortex-M0+ MCU with PIO |
| **U2** | W25Q16JVSSIQ | SOIC-8 (208mil / 3.9x4.9mm) | `C49987` | 16 Mbit (2 MB) QSPI NOR Flash |
| **U3** | XC6206P332MR | SOT-23-3 | `C5446` | High-PSRR 3.3V LDO Voltage Regulator |

### Passive Components
| Designators | Value | Package | LCSC Part # | Purpose |
| :--- | :--- | :--- | :--- | :--- |
| **X1** | 12.000 MHz | SMD-3225-4P | `C112250` | RP2040 System Clock |
| **C14, C15** | 15 pF | 0402 | `C1554` | Crystal Load Capacitors |
| **C1, C2, C3, C4, C5, C6, C7, C8, C9** | 100 nF (0.1 µF) | 0402 | `C1525` | Power rail decoupling (1 per VDD/IOVDD pin) |
| **C10, C11** | 1 µF | 0402 | `C52923` | LDO Input/Output & Core Decoupling |
| **C12, C13** | 10 µF | 0603 | `C19702` | Bulk filtering on 5V and 3.3V rails |
| **R1, R2** | 27 Ω | 0402 | `C25111` | USB D+/D- impedance matching |
| **R3, R4** | 5.1 kΩ | 0402 | `C25905` | USB-C CC1/CC2 pull-downs (forces 5V USB source) |
| **R5** | 1 kΩ | 0402 | `C11702` | Flash /CS BOOTSEL pull-up |
| **R6, R7** | 10 kΩ | 0402 | `C25744` | Reset / Display control pull-ups |

### Connectors & Controls
| Designator | Description | Footprint | LCSC Part # | Connection |
| :--- | :--- | :--- | :--- | :--- |
| **J1** | 10-Pin 0.5mm FPC | `FH34SRJ-10S-0.5SH` | `C324723` | Directly to Sharp LS032B7DD02 display |
| **J2** | 18-Pin 1.0mm FPC | `CON_5051101892_MOL` | `C262334` | From Game Boy button board (LCD signals) |
| **J3** | 16-Pin USB-C Receptacle | `TYPE-C-31-M-12` | `C165948` | UF2 firmware flashing & serial debugging |
| **SW1** | Tactile Switch | `SW_SPST_PTS645` | `C318884` | BOOTSEL Button (drag-and-drop programming) |

---

## 3. Pin Mapping & Netlist Configuration

### Sharp Display Interface (J1: 10-Pin FPC)
* **Pin 1 (SCLK):** Connects to RP2040 `GPIO 18` (`SPI0_SCK`)
* **Pin 2 (SI / MOSI):** Connects to RP2040 `GPIO 19` (`SPI0_TX`)
* **Pin 3 (SCS / Chip Select):** Connects to RP2040 `GPIO 17` (`SPI0_CSn`) - *Active HIGH*
* **Pin 4 (EXTMODE):** Connects to `GND` (enables software VCOM toggle mode)
* **Pin 5 (DISP):** Connects to RP2040 `GPIO 20` (pull-up to 3.3V, controls display on/off)
* **Pin 6 (VDDA):** Connects to `+3.3V`
* **Pin 7 (VDD):** Connects to `+3.3V`
* **Pin 8 (VSSA):** Connects to `GND`
* **Pin 9 (VSS):** Connects to `GND`
* **Pin 10 (VCOM):** Handled via bit 1 in SPI command packet

### Game Boy LCD Capture Bus (J2: 18-Pin FPC)
* **`DATA0`:** Connects to RP2040 `GPIO 0` (PIO Input pin 0)
* **`DATA1`:** Connects to RP2040 `GPIO 1` (PIO Input pin 1)
* **`CL2` (Dot Clock):** Connects to RP2040 `GPIO 2` (PIO Clock / Trigger)
* **`CL1` (Line Latch):** Connects to RP2040 `GPIO 3` (Interrupt / Line sync)
* **`VSYNC` (Frame Sync):** Connects to RP2040 `GPIO 4` (Interrupt / Frame sync)
* **`FR` (LCD Inversion):** Connects to RP2040 `GPIO 5`
* **`+5V` Power In:** Connects to input of 3.3V LDO (U3)
* **`GND`:** Connects to System Ground

---

## 4. "God View" 24-Pin VRAM Snooping Bus (`J4_VRAM_SNOOP`)

To enable passive parallel capture of the entire 256x256 background tilemap directly from the Game Boy's VRAM chip, a dedicated 24-pin 0.5mm FPC connector (`Hirose FH12-24S-0.5SH` or equivalent, LCSC `C262334` / standard FPC) is integrated.

### Pinout Mapping:
| Pin | Signal | Direction | Destination on RP2040 |
| :---: | :---: | :---: | :--- |
| **1-8** | `VRAM_D0` - `VRAM_D7` | Input | `GPIO 6` through `GPIO 13` (8-bit data bus) |
| **9-21** | `VRAM_A0` - `VRAM_A12` | Input | Multiplexed / Bus Address latch lines |
| **22** | `VRAM_/WR` | Input | PIO Write-Strobe Trigger |
| **23** | `+3.3V` / `VCC` | Power | Reference power |
| **24** | `GND` | Ground | Ground reference |
