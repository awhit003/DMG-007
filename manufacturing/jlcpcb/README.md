# JLCPCB / JLCONE Manufacturing Guide

This directory contains resources, notes, and configuration specific to manufacturing and assembling DMG-007 boards using **JLCPCB** and the **JLCONE** desktop client (`/Applications/JLCONE.app`).

## Requirements for JLCPCB SMT (PCBA) Assembly

JLCPCB requires three files per board for automated pick-and-place assembly:

1. **Gerber Archive (`gerbers.zip`):** PCB copper, solder mask, silkscreen, edge cuts, and drill files.
2. **BOM (`BOM.csv`):** Maps reference designators to component descriptions, footprints, and **LCSC Part Numbers** (`Cxxxx`).
3. **CPL / Centroid (`CPL.csv`):** Pick-and-place coordinates (`Designator`, `Mid X`, `Mid Y`, `Layer`, `Rotation`).

## Assembly Strategy for DMG-007

* **Maximum Pick-and-Place:** All standard surface-mount passives (resistors, capacitors, inductors, diodes, voltage supervisors, and audio ICs) are mapped to LCSC stock numbers for automated placement.
* **Excluded Parts:**
  * **U1 (SGB-CPU):** Harvested from Japanese Super Game Boy cartridges; hand-soldered after PCBA fabrication.
  * **Through-hole / edge connectors:** Cartridge slot, headphone jack, volume potentiometer, and battery terminals.

## Board Packages

* `super-dmg-cpu/`: Gerbers, BOM, and CPL for the main motherboard.
* `super-dmg-jack/`: Gerbers, BOM, and CPL for the audio amplifier board.
* `dmgc-pwr-01/`: Gerbers, BOM, and CPL for the power regulator board.
* `rlcd-dmg/`: Gerbers, BOM, and CPL for the display controller and debug board.
