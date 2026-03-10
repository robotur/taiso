# Hybrid Analog Synthesizer with Oscilloscope Display

A 25-key, 2-octave hybrid analog synthesizer with real-time waveform visualization. Digital oscillator core with an analog filter stage, built into a fully 3D printed enclosure.

---

## Overview

This project combines a digitally generated polyphonic sound engine with an analog OTA filter stage, giving it genuine analog character while remaining tuning-stable and preset-capable. A 2.8" TFT display shows the output waveform in real time, current octave, and active keys.

---

## Features

- 25-key keyboard (2 octaves) with octave shift buttons (+/- to cover full range)
- 8-voice polyphony
- 4 waveforms: sine, sawtooth, square, triangle
- Analog filter stage (LM13700 OTA) with cutoff and resonance control
- Full ADSR envelope per voice
- Real-time oscilloscope display (ILI9341 2.8" TFT)
- Battery powered (2x 18650)
- 3D printed enclosure (Bambu P1S, split in 3 sections)

---

## Controls

| Control | Function |
|---|---|
| Attack | Envelope attack time |
| Decay | Envelope decay time |
| Sustain | Envelope sustain level |
| Release | Envelope release time |
| Cutoff | Analog filter cutoff frequency |
| Resonance | Filter resonance (self-oscillates at max) |
| Volume | Master output volume |
| Waveform | Selects sine / saw / square / tri |
| Oct – / Oct + | Shifts keyboard octave down or up |

---

## System Architecture

```
Keys (MX switches) → 74HC165 Shift Registers → RP2040
                                                    |
                                              Dual Core:
                                   Core 0: Audio synthesis + DAC
                                   Core 1: Key scan + Display
                                                    |
                                             PCM5102A DAC
                                                    |
                                        LM13700 Analog Filter
                                     (Cutoff + Resonance via pots)
                                                    |
                                          Op-amp output stage
                                                    |
                                            3.5mm audio jack
```

---

## Hardware

| Component | Part |
|---|---|
| MCU | Raspberry Pi RP2040 |
| DAC | PCM5102A (I2S) |
| Analog Filter | LM13700 OTA |
| Display | ILI9341 2.8" TFT (SPI) |
| Key Scanning | 2x 74HC165 shift registers |
| Switches | 25x MX Silent Linear |
| Power | 2x 18650 → TP4056 → MT3608 5V boost → 3.3V LDO |
| Knobs | 8x potentiometers |

---

## Enclosure

- Fully 3D printed (FDM, Bambu P1S)
- Split into 3 sections along keybed length to fit 256x256mm bed
- 2-part design: top panel + bottom tray
- Recessed screen bezel for clean flush fit
- Foam strip at key bottom-out point for dampening

---

## Project Status

- [ ] Enclosure design (Fusion 360)
- [ ] PCB schematic (KiCad)
- [ ] Firmware (RP2040 — polyphony, ADSR, display)
- [ ] Full renders
- [ ] Build

---

## Funding

Submitted under the Blueprint Tiers program — targeting Tier 2 ($0–200).
