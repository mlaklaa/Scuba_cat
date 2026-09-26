# Scuba_cat
Smooth "Scuba Cat" bitmap animation on an SSD1306 0.96" I2C OLED display using ESP32, PlatformIO, and Wokwi simulation.
#  Scuba Cat OLED Animation (ESP32)

A smooth, flicker-free bitmap animation of "Scuba Cat" running on an SSD1306 0.96" OLED display. Developed with **PlatformIO** in VS Code and fully simulated with **Wokwi**.

---

##  Features

- **Smooth Playback:** Non-blocking timing using `millis()` to ensure consistent frame pacing without locking processor cycles.
- **Buffer Optimization:** Fast frame rendering using `memcpy_P` directly into the display buffer, bypassing overhead.
- **Flicker-Free & Glitch Mitigation:** Selective memory clearing (`memset`) to eliminate side-band artifacts and tearing during frame transitions.
- **Ready to Simulate:** Includes `wokwi.toml` and `diagram.json` for one-click testing in VS Code or browser.

---

##  Hardware & Pinout

| SSD1306 OLED (0.96" I2C) | ESP32 DevKit |
| :--- | :--- |
| **GND** | GND |
| **VCC** | 3V3 |
| **SCL** | GPIO 22 |
| **SDA** | GPIO 21 |

---

##  Tech Stack & Libraries

- **Framework:** Arduino / ESP32
- **IDE / Build Tool:** PlatformIO (VS Code)
- **Simulator:** Wokwi
- **Libraries:**
  - `Adafruit SSD1306`
  - `Adafruit GFX Library`
  - `Wire` (configured to Fast Mode @ 400kHz)

---

##  Asset Pipeline

1. **Extraction:** GIF split into individual frames. Initial lead-in artifact frames were removed to ensure an organic loop cycle.
2. **Conversion:** Exported via `image2cpp` using **SSD1306 Vertical Pages** byte orientation.
3. **Data Storage:** Frames stored in flash memory (`PROGMEM`) within `images.h` and accessed sequentially via a pointer array.

---

##  Getting Started

### 1. Prerequisites
Ensure you have the following installed in VS Code:
- [PlatformIO IDE](https://platformio.org/)
- [Wokwi Simulator Extension](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)

---

### 2. Setup & Simulation (Wokwi)
1. Clone the repository and open the folder in VS Code:
   ```bash
   git clone [https://github.com/mlaklaa/Scuba_cat.git](https://github.com/mlaklaa/Scuba_cat.git)
2. Build the project using PlatformIO:Click the Build checkmark icon ($\checkmark$) in the bottom toolbar (or press Ctrl+Alt+B).
3. Launch the simulation:
   Open diagram.json.Press F1, type Wokwi: Start Simulator, and press Enter.

### 3. Flash to Physical Hardware

1. Connect your ESP32 DevKit via micro-USB.Wire the 0.96" SSD1306 OLED as detailed in the pinout table.
2. Click the Upload arrow icon ($\rightarrow$) in the PlatformIO toolbar to flash the firmware.
