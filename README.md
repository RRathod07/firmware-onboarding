# onboarding

A hands-on onboarding exercise: get PlatformIO set up, create your own
project from scratch, write and flash real firmware to an Arduino Uno,
and go through our GitHub PR workflow end to end.

**Start here → [TASK.md](TASK.md)**

This repo intentionally does **not** contain a pre-built firmware
project — you'll create your own using PlatformIO's "New Project"
wizard, per the steps in TASK.md. That's the point: knowing how to spin
up a new PlatformIO project is part of what this exercise teaches.

## Quick start

1. Install [VS Code](https://code.visualstudio.com/) and the
   [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode).
2. Fork this repo, then clone your fork locally.
3. Follow [TASK.md](TASK.md) — it walks through creating a new project
   (Board: Arduino Uno, Framework: Arduino) inside
   `submissions/<your-username>/`, wiring up the hardware, adding
   dependencies, and the actual requirements.
4. Build and flash: `pio run -e uno -t upload` (run from inside your
   submission folder)
5. Watch it work: `pio device monitor`
6. Push your branch and open a PR back to this repo.

## Repo layout

```
TASK.md                            The exercise: setup steps, wiring, requirements
submissions/<your-username>/        Where your own PlatformIO project goes
.github/workflows/build.yml         CI: finds whichever submission changed and builds it
.github/PULL_REQUEST_TEMPLATE.md    What your PR needs before it's mergeable
.github/CODEOWNERS                  Auto-requests review on your PR
```

## How CI works here

Since everyone creates their own project in their own
`submissions/<username>/` folder, CI doesn't have a fixed project path
to build. Instead, on every PR it looks at which `submissions/*/`
folder your changes touched, confirms it has a `platformio.ini`, and
runs `pio run -e uno` against just that folder — so your PR is
evaluated independently of anyone else's.
