## Summary

<!-- Briefly describe what you built and any decisions worth flagging. -->

## Checklist

- [ ] My project lives in `submissions/<my-github-username>/` and has
      its own `platformio.ini`
- [ ] `pio run -e uno` builds cleanly from inside my submission folder
      (CI will verify this too)
- [ ] Firmware was actually flashed to a real Uno and tested end-to-end
- [ ] All four Serial commands (`TEMP?`, `HUM?`, `PRESS?`, `LED ON`/`OFF`)
      behave as specified, including the `ERR` response for unknown input
- [ ] OLED display updates with live sensor readings
- [ ] No `delay()` used for the sensor read/display loop

## Proof of hardware

<!--
Attach a short screen recording or a few screenshots/terminal output
showing:
  1. The OLED updating with live readings
  2. `pio device monitor` output for each Serial command
Drag and drop files/video directly into this PR description.
-->

## Anything you got stuck on?

<!-- No wrong answers — this helps us improve the exercise. -->
