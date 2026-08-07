# Onboarding Task: Sensor Logger with Serial Command Interface

Welcome! This exercise is designed to get you comfortable with the tools
you'll use every day here: PlatformIO, a real microcontroller, and our
GitHub workflow (fork → branch → PR → review → merge).

Unlike a lot of tutorials, you're building the PlatformIO project
**from scratch yourself** — this repo only holds instructions, CI, and
the PR checklist. You're done when your PR is approved and merged, and
"approved" requires proof it actually ran on real hardware, not just
that it compiled.

## Hardware

- Arduino Uno (or clone)
- BME280 temperature/humidity/pressure sensor (I2C breakout)
- SSD1306 0.96" OLED display (I2C, 128x64)
- Breadboard + jumper wires

## Step 1 — Create your project

In VS Code, open the PlatformIO sidebar (ant icon) → **PIO Home** →
**New Project**, and fill in:

- **Name:** anything descriptive, e.g. `sensor-logger`
- **Board:** search for and select **"Arduino Uno"**
- **Framework:** Arduino
- **Location:** uncheck "Use default location" and point it at
  `<your fork of this repo>/submissions/<your-github-username>/`

That creates a fresh `platformio.ini`, `src/main.cpp`, and empty
`lib/`, `test/`, `include/` folders — all inside your own submission
folder, so your project doesn't collide with anyone else's.

## Step 2 — Wire it up

Both the BME280 and the SSD1306 are I2C devices, so they share the same
two signal lines and can be wired in parallel:

| Uno pin | BME280 pin | SSD1306 pin |
|---------|-----------|-------------|
| 5V      | VIN/VCC   | VCC         |
| GND     | GND       | GND         |
| A4      | SDA       | SDA         |
| A5      | SCL       | SCL         |

If you're not sure both devices are wired correctly, write (or find) an
I2C scanner sketch first and confirm you see two devices on the bus
(BME280 is usually `0x76` or `0x77`, SSD1306 is usually `0x3C`) before
writing any application code. This is a normal part of the job — expect
to spend time here.

## Step 3 — Add your dependencies

Your fresh project has no libraries yet. Add these to `platformio.ini`
under `lib_deps` (or install via the PlatformIO Libraries sidebar and
let it write them for you):

```ini
lib_deps =
    adafruit/Adafruit BME280 Library@^2.2.4
    adafruit/Adafruit SSD1306@^2.5.9
    adafruit/Adafruit GFX Library@^1.11.9
    adafruit/Adafruit BusIO@^1.15.0
```

## Step 4 — Core requirements (must pass to merge)

1. Read temperature, humidity, and pressure from the BME280 once per
   second **without using `delay()`** (use `millis()` timing).
2. Display the current readings on the OLED, updated each time you read
   the sensor.
3. Implement a simple command parser over Serial (115200 baud). Your
   firmware should respond to these ASCII commands, newline-terminated:
   - `TEMP?` → reply with current temperature, e.g. `TEMP=21.4`
   - `HUM?` → reply with current humidity, e.g. `HUM=48.2`
   - `PRESS?` → reply with current pressure, e.g. `PRESS=1013.2`
   - `LED ON` / `LED OFF` → turn the onboard LED (pin 13) on or off, and
     acknowledge with `OK`
   - Anything else → reply `ERR unknown command`
4. Your PR must include a short screen recording or terminal
   copy/paste from `pio device monitor` showing:
   - the OLED display updating (photo or video is fine here)
   - each Serial command being sent and the correct response

## Stretch goals (optional, don't block merging)

- Pull your command-parsing logic out of `src/main.cpp` into `lib/`,
  written in plain C++ with no Arduino types, and add a `[env:native]`
  section to `platformio.ini` (`platform = native`,
  `test_framework = unity`) so you can unit test it with
  `pio test -e native` — no board required. This is the standard
  pattern we use for keeping firmware logic testable.
- Read the pushbutton on pin 2 via `attachInterrupt()` instead of
  polling, to toggle between Celsius/Fahrenheit display.
- Add a `LOG START` / `LOG STOP` command that streams readings once per
  second until stopped.

## Workflow checklist

- [ ] Fork this repo
- [ ] Create a branch (`yourname/sensor-logger`)
- [ ] Create your PlatformIO project inside `submissions/<your-username>/`
      as described above
- [ ] Write and flash your firmware (`pio run -t upload`, run from
      inside your submission folder)
- [ ] Verify behavior with `pio device monitor`
- [ ] Open a PR back to this repo using the PR template
- [ ] Attach your proof-of-hardware recording/screenshot
- [ ] Address review feedback
- [ ] Get approved and merged 🎉
