# pico-template

## First-time machine setup

1. Admin PowerShell — enable long paths, then **reboot**:
   `Set-ItemProperty HKLM:\SYSTEM\CurrentControlSet\Control\FileSystem LongPathsEnabled 1`
   `git config --global core.longpaths true`
2. Install VS Code + the **Raspberry Pi Pico** extension (published by Raspberry Pi).
   Create one throwaway project with SDK **2.3.0** / toolchain **15_2_Rel1** to
   populate `~/.pico-sdk`. Compile once. Close VS Code.
3. Add `%USERPROFILE%\.pico-sdk\picotool\2.1.1\picotool` to PATH.
4. Install CLion. Toolchain: MinGW, debugger = **Bundled GDB multiarch**.
5. Zadig (`zadig.akeo.ie`) → Options → List All Devices → install **WinUSB** on:
   - **RP2 Boot** (so picotool can flash)
   - **CMSIS-DAP v2 (Interface 0)** (so OpenOCD can see the probe)

   Do **not** touch the composite parent or the CDC interface — that kills the
   probe's UART bridge.

## Per project

Open **`CMakeLists.txt`**, not the folder. Pick a preset from the toolbar.
Builds land in `<projects-parent>/build/<project>-<preset>`.

- `flash` — over USB, needs picotool
- `debug` — over SWD, needs a CMSIS-DAP probe. **Shift+F9**, not Shift+F10.
  (Run mode = flash-only, no GDB server.)

Ignore the auto-generated configs (`pico_template`, `bs2_default`, etc.) — CLion
regenerates one per CMake target on every reload.

Load `svd/RP2040.svd` in the Peripherals tab during a debug session.

## Probe wiring
probe GP2 → target SWCLK      probe GP4 → target GP1  (UART bridge)
probe GP3 → target SWDIO      probe GP5 → target GP0
probe GND → target GND

Both boards need their own USB power. The probe does not power the target.