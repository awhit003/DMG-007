# DMG-007

**DMG-007** is a modern hardware integration and re-engineering project for the original Nintendo Game Boy (DMG) form factor. 

The core philosophy of DMG-007 is **zero donor DMG-001 parts**: the console is built entirely from newly fabricated PCBs, modern off-the-shelf components, and automated surface-mount assembly. The **sole donor component** in the entire build is a salvaged **SGB-CPU** from a Japanese Super Famicom / Super Game Boy cartridge.

The designs and documentation are kept fabrication-agnostic and universally compatible with major PCB fabrication services including **OSH Park**, **PCBWay**, and **JLCPCB**.

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

3. **High-Performance Reflective Display (RLCD):**
   - Incorporates a modern ultra-fast 1-bit Reflective LCD panel (Sharp Memory LCD / RLCD, similar to Playdate technology).
   - Preserves the authentic, glare-free, outdoor-readable aesthetic of the original monochrome DMG without backlights or motion smear.

4. **Clean Power Delivery:**
   - Dedicated high-efficiency synchronous buck-boost regulation (`DMGC-PWR-01`) delivering a rock-solid, isolated 5V rail capable of supporting the RLCD controller and modern audio amplifier across varying battery discharge curves.

---

## 🧩 Integrated Hardware Components & Attribution

This project brings together foundational designs created by talented open-source hardware developers across the retro-modding community:

| Module | Source Design | Original Author | Upstream License | Function in DMG-007 |
| :--- | :--- | :--- | :--- | :--- |
| **Motherboard** | [Super-DMG-01](https://github.com/kamicane/Super-DMG-01) | **kamicane** (Valerio Proietti) | CC BY-SA 4.0 | Main system logic board engineered to host the SGB-CPU, modern RAM, and USB-C power integration. |
| **Audio Board** | [Super DMG JACK](https://github.com/kamicane/Super-DMG-01) | **kamicane** (Valerio Proietti) | CC BY-SA 4.0 | Independent headphone and speaker audio board utilizing a PAM8302 mono Class-D amplifier. |
| **Power Supply** | [DMGC-PWR-01](https://github.com/MouseBiteLabs/Game-Boy-DMG-Color) | **MouseBiteLabs** (Bucket Mouse) | CC BY-SA 4.0 | High-efficiency buck-boost regulator board (TPS630702 based) with undervoltage latching. |
| **Display Subsystem**| [RLCD-DMG](https://github.com/bytendomods/RLCD-DMG) | **bytendomods** | Apache 2.0 | Sharp RLCD driver integration, mounting brackets, and debug interface. |

For detailed license terms and derivative compliance requirements, see [NOTICE.md](NOTICE.md) and [LICENSE](LICENSE).

---

## 🗂️ Workspace Organization

```text
DMG-007/
├── README.md                          <-- Project overview, design specs, and attribution
├── NOTICE.md                          <-- Upstream licensing and legal attribution
├── LICENSE                            <-- Primary CC BY-SA 4.0 license
├── .gitignore                         <-- Ignores OS, agent, IDE, and KiCad temp files
│
├── hardware/
│   ├── boards/
│   │   ├── 01-super-dmg-cpu/          <-- Main motherboard (KiCad)
│   │   ├── 02-super-dmg-jack/         <-- Audio & headphone PCB (KiCad)
│   │   ├── 03-dmgc-pwr-01/            <-- Power regulator board (EAGLE / KiCad)
│   │   └── 04-rlcd-dmg/               <-- Display driver, bracket, and debug PCB
│   │
│   └── libraries/                     <-- Custom symbols and footprints
│
├── manufacturing/                     <-- Vendor-specific fabrication packages
│   ├── jlcpcb/                        <-- JLCPCB / JLCONE assembly packages & guide
│   ├── pcbway/                        <-- PCBWay project & shared ordering notes
│   └── oshpark/                       <-- OSH Park board links & specs
│
└── bom/                               <-- Master component sourcing lists
```
