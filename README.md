# DMG-007

**DMG-007** is a modern hardware integration and re-engineering project for the original Nintendo Game Boy (DMG) form factor. 

The core philosophy of DMG-007 is **zero donor DMG-001 parts**: the console is built entirely from newly fabricated PCBs, modern off-the-shelf components, and automated surface-mount assembly. The **sole donor component** in the entire build is a salvaged **SGB-CPU** from a Japanese Super Famicom / Super Game Boy cartridge.

The designs and documentation are fabrication-agnostic and universally compatible with major PCB fabrication services including **OSH Park**, **PCBWay**, and **JLCPCB**.

---

## 🎯 Design Parameters & Architecture

1. **Zero DMG-001 Consoles Sacrificed:**
   - No original DMG-001 motherboards, power boards, audio boards, or screens are consumed.
   - The primary processor is an **SGB-CPU** (harvested from readily available Japanese Super Game Boy cartridges).
   - VRAM, work RAM, crystal oscillators, and audio amplification all use modern, commercially available replacement silicon and passives.

2. **Automated Surface-Mount (SMT) Assembly:**
   - Boards are designed with standard surface-mount packages (0805/0603 passives, standard IC packages) to allow automated pick-and-place assembly.
   - SGB-CPU (U1) and through-hole mechanical connectors (cartridge slot, headphone jack, battery contacts) are populated post-assembly.
   - Vendor-specific manufacturing instructions (e.g., JLCPCB/JLCONE tooling and LCSC part mappings) are maintained in dedicated vendor documentation.

3. **High-Performance Reflective Display (Sharp RLCD):**
   - Incorporates a modern ultra-fast 1-bit Reflective LCD panel (Sharp Memory LCD / RLCD `LS032B7DD02`, 3.2", 336×536).
   - Preserves the authentic, glare-free, outdoor-readable aesthetic of the original monochrome DMG without backlights or motion smear.
   - Driven by an on-board Raspberry Pi RP2040 utilizing clean-room PIO capture and 2×2 Bayer dithering.

4. **"God View" VRAM Bus Snooping (256×256 Viewport Expansion):**
   - The Sharp driver board includes a dedicated **24-pin 0.5mm FPC expansion port (`J4_VRAM_SNOOP`)**.
   - Snoops the Game Boy VRAM bus (`A0–A12`, `D0–D7`, `/WR`) via an optional parasitic flex cable.
   - Enables hardware capture of the entire internal 256×256 pixel background tilemap in real time, unlocking full-canvas wide-angle rendering beyond the clipped 160×144 PPU viewport.

5. **Clean Power Delivery:**
   - Dedicated high-efficiency synchronous buck-boost regulation (`DMGC-PWR-01`) delivering a rock-solid, isolated 5V rail capable of supporting the RLCD controller and modern audio amplifier across varying battery discharge curves.

---

## 🧩 Integrated Hardware Components & Attribution

This project brings together foundational designs created by talented open-source hardware developers across the retro-modding community:

| Module | Source Design | Original Author | Upstream License | Function in DMG-007 |
| :--- | :--- | :--- | :--- | :--- |
| **Motherboard** | [Super-DMG-01](https://github.com/kamicane/Super-DMG-01) | **kamicane** (Valerio Proietti) | CC BY-SA 4.0 | Main system logic board engineered to host the SGB-CPU, modern RAM, and USB-C power integration. |
| **Audio Board** | [Super DMG JACK](https://github.com/kamicane/Super-DMG-01) | **kamicane** (Valerio Proietti) | CC BY-SA 4.0 | Independent headphone and speaker audio board utilizing a PAM8302 mono Class-D amplifier. |
| **Power Supply** | [DMGC-PWR-01](https://github.com/MouseBiteLabs/Game-Boy-DMG-Color) | **MouseBiteLabs** (Bucket Mouse) | CC BY-SA 4.0 | High-efficiency buck-boost regulator board (TPS630702 based) with undervoltage latching. |
| **Display Subsystem**| Clean-Room Sharp RLCD Driver | DMG-007 Project | CC BY-SA 4.0 | RP2040 controller driving Sharp LS032B7DD02 with PIO capture, 2×2 Bayer dither, and 24-pin VRAM snooping bus. |

For detailed license terms and derivative compliance requirements, see [NOTICE.md](NOTICE.md) and [LICENSE](LICENSE).
