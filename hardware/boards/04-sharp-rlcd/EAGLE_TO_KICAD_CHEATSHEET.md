# Autodesk EAGLE to KiCad Migration Cheat Sheet

Coming from EAGLE to KiCad can feel disorienting because EAGLE relies on **modal commands** (click a tool icon first, then click the object), whereas KiCad is **modeless and hover-based** (hover cursor over the component and tap a keyboard shortcut).

---

## 🖱️ 1. Mouse Behavior Differences

| Action | Autodesk EAGLE | KiCad |
| :--- | :--- | :--- |
| **Pan Workspace** | Middle-click drag (or right-click hold) | **Middle-click drag** OR **Right-click drag** |
| **Zoom** | Scroll wheel | **Scroll wheel** (zooms directly toward cursor) |
| **Context Menu** | Right-click (cancels current command) | **Right-click** (opens contextual tool menu) |
| **Select / Drag** | Select tool -> Click part | Hover -> press **`M`** (Move) or **`D`** (Drag with traces) |
| **Cancel / Exit tool**| Click `Stop` button or `Esc` | Press **`Esc`** |

> **Pro-Tip:** In KiCad, you **do not need to click a component first** to move or rotate it. Simply float your mouse pointer over the part and hit the key.

---

## ⌨️ 2. Common Keyboard Shortcuts Comparison

| Operation | EAGLE Equivalent | KiCad Schematic (Eeschema) | KiCad PCB Editor (Pcbnew) |
| :--- | :--- | :--- | :--- |
| **Add Component / Part** | `ADD` command | **`A`** | **`A`** (Footprint) |
| **Add Wire / Route Trace**| `NET` / `ROUTE` | **`W`** (Wire) | **`X`** (Route Track) |
| **Move Component** | `MOVE` | **`M`** (Move free) | **`M`** (Move free) |
| **Drag with Connected Wires/Traces** | N/A (EAGLE snaps nets) | **`G`** (Drag connected) | **`D`** (Drag track segment) |
| **Rotate Part** | Right-click while moving | **`R`** (Rotates 90°) | **`R`** (Rotates 90°) |
| **Flip / Mirror Part** | `MIRROR` tool | **`Y`** (Mirror X) / **`X`** (Mirror Y) | **`F`** (Flip to opposite copper layer) |
| **Add Net Label** | `LABEL` / `NAME` | **`L`** (Add Net Label) | N/A (Netlist driven) |
| **Add Power / Ground** | `ADD` -> supply1/2 | **`P`** | N/A |
| **Add Via** | Spacebar / click via icon | N/A | **`V`** (while routing track) |
| **Switch Active Layer** | Top dropdown menu | N/A | **`Page Up`** (Top) / **`Page Down`** (Bottom) |
| **Delete Item** | `DELETE` tool | **`Delete`** or **`Backspace`** | **`Delete`** or **`Backspace`** |
| **Edit Properties / Value**| Right-click -> Properties | **`E`** | **`E`** |
| **Copy / Duplicate** | `COPY` tool | **`Ctrl + D`** (Duplicate) | **`Ctrl + D`** |
| **Measure Distance** | `INFO` / Grid count | **`Shift + M`** | **`Shift + M`** |
| **Fill / Recalculate Copper Pour** | `RATSNEST` | N/A | **`B`** (Instant copper refour) |
| **Switch Copper Pour Display** | Layer visibility | N/A | Left toolbar icons (Show/Hide Zones) |

---

## 🚀 3. Mental Shifts That Will Save Your Sanity

1. **The "Ratsnest" Button:**
   - In EAGLE, you hit `RATSNEST` to calculate ground polygons and see remaining airwires.
   - In KiCad, just press **`B`** at any time. It instantly repours all copper ground zones and recalculates DRC clearances.

2. **Routing Traces (Push & Shove):**
   - EAGLE's default router is often frustrating with obstacle avoidance.
   - KiCad has a built-in **Interactive Push & Shove Router**: when you hit **`X`** and route a trace, it automatically and dynamically pushes existing traces and vias out of the way without creating DRC violations.

3. **Updating PCB from Schematic:**
   - In EAGLE, schematic and board are locked via "Back-Annotation" (closing one breaks synchronization).
   - In KiCad, they are decoupled: edit your schematic at will, then press **`F8`** (or `Tools` -> `Update PCB from Schematic`). KiCad pushes all new footprints, net changes, and deleted components straight into the PCB editor.

4. **Footprint Assignment:**
   - In EAGLE, the symbol and footprint are tied together in the library (`DEV`).
   - In KiCad, symbols and footprints can be paired flexibly. Press **`Tools` -> `Assign Footprints`** to review or change packages in bulk.
