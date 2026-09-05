# DMG-007 Licensing & Attribution

This project, **DMG-007** by Anthony Whittington, integrates and documents multiple open-source hardware designs. To comply with the ShareAlike obligations of the upstream components incorporated into this build, this overall repository is released under the **Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)** license.

* **Project Lead / Integration:** Anthony Whittington
* **Primary License:** CC BY-SA 4.0

---

## Component Provenance & Upstream Attribution

### 1. Super-DMG-01 Motherboard
* **Original Author:** kamicane (Valerio Proietti)
* **Original License:** CC BY-SA 4.0
* **Source:** https://github.com/kamicane/Super-DMG-01
* **Role in DMG-007:** Main system board hosting the salvaged SGB-CPU, modern RAM, and USB-C power delivery.

### 2. Super DMG JACK (Audio Board)
* **Original Author:** kamicane (Valerio Proietti)
* **Original License:** CC BY-SA 4.0
* **Source:** https://github.com/kamicane/Super-DMG-01
* **Role in DMG-007:** Dedicated audio amplifier and headphone jack circuit using the PAM8302 mono amplifier.

### 3. DMGC-PWR-01 Power Board
* **Original Author:** MouseBiteLabs (Bucket Mouse)
* **Original License:** CC BY-SA 4.0
* **Source:** https://github.com/MouseBiteLabs/Game-Boy-DMG-Color
* **Role in DMG-007:** Synchronous buck-boost power regulation (TPS630702 based) delivering clean 5V to the system. Format translated from EAGLE to KiCad for native manufacturing.

---

## Inspiration & Acknowledgments

* **Sharp Microelectronics:** Manufacturer of the LS032B7DD02 3.2" Reflective Memory LCD panel and author of its reference interface specifications.
* **Raspberry Pi Ltd:** Designers of the RP2040 microcontroller and authors of the standard minimal hardware implementation reference designs.
* **Bytendo (`bytendomods`):** Sincere thanks to Bytendo for proving that the Sharp Reflective Memory LCD pairs brilliantly with the Game Boy aesthetic. While this repository contains clean-room hardware layouts built strictly from official manufacturer reference designs and includes no Bytendo files or firmware, their prior work in the modding scene served as the creative spark for this build.
* **Gekkio:** For foundational open-source Game Boy hardware documentation, schematics, and pinout databases.

---

## Liability & Warranty Disclaimer

All original component licenses include liability disclaimers; these designs and notes are provided "AS IS" without warranties of any kind. The integrator assumes no liability for hardware damage, component loss, or personal injury resulting from the fabrication, assembly, or operation of these open-source designs.
