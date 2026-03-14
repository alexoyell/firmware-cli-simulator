# Firmware CLI Simulator

This project simulates a simple MCU firmware architecture using C.

It demonstrates several common embedded system components:

- UART driver abstraction
- Ring buffer for byte stream handling
- Command-line interface (CLI)
- Modular firmware structure
- Makefile build system
- Unit tests for modules

---
## Features

Current supported commands:

HELP
LED_ON
LED_OFF
TEMP
STATUS
EXIT


---

## Future Improvements

Planned upgrades:

- Byte-stream input model (simulate UART RX)
- Command assembler
- Command queue
- Interrupt-like input simulation
- More CLI commands

---

## Purpose

This project is a learning exercise to simulate firmware architecture patterns commonly used in embedded systems.