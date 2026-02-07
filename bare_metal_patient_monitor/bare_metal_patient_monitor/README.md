# 🩺 Pulse Oximeter Patient Monitor - Bare Metal STM32F401RE

A complete bare-metal implementation of a pulse oximeter and patient monitoring system using register-level programming on STM32F401RE microcontroller.

## 📋 Features

- **Real-time Heart Rate Monitoring** - Using MAX30102 pulse oximeter sensor
- **SpO2 Measurement** - Blood oxygen saturation level monitoring
- **Temperature Monitoring** - Body temperature measurement using ADC
- **OLED Display** - Real-time vital signs display on SSD1306 OLED
- **Data Logging** - Store patient data on SD card
- **UART Debugging** - Serial communication for monitoring and debugging
- **Bare Metal Implementation** - No HAL/RTOS, direct register manipulation

## 🔧 Hardware Requirements

### Core Board
- **STM32F401RE** Nucleo board or equivalent
  - Cortex-M4 @ 84MHz
  - 512KB Flash, 96KB SRAM

### Sensors & Peripherals
- **MAX30102** - Pulse oximeter and heart rate sensor (I2C)
- **SSD1306** - 128x64 OLED display (SPI)
- **Temperature Sensor** - LM35/TMP36/Thermistor (ADC)
- **SD Card Module** - For data logging (SPI)
- **UART** - USB-to-Serial adapter (for debugging)

## 📐 Pin Configuration

### I2C1 (MAX30102)
- **PB8** → SCL
- **PB9** → SDA

### SPI1 (SD Card & Display)
- **PA5** → SCK
- **PA6** → MISO
- **PA7** → MOSI
- **PA4** → SD Card CS
- **PB6** → Display CS
- **PB7** → Display DC

### USART2 (Debug)
- **PA2** → TX
- **PA3** → RX

### ADC1 (Temperature)
- **PA0** → Analog Input

### Status LED
- **PC13** → Onboard LED (heartbeat)

## 🏗️ Project Structure

```
bare_metal_patient_monitor/
│
├── inc/                          # Header files
│   ├── stm32f401xx.h            # Register definitions
│   ├── gpio.h                   # GPIO driver
│   ├── i2c.h                    # I2C driver
│   ├── spi.h                    # SPI driver
│   ├── uart.h                   # UART driver
│   ├── delay.h                  # Timing functions
│   ├── max30102.h               # Pulse oximeter driver
│   ├── temperature.h            # Temperature sensor driver
│   ├── ssd1306.h                # OLED display driver
│   └── sdcard.h                 # SD card driver
│
├── src/                          # Source files
│   ├── main.c                   # Main application
│   ├── gpio.c                   # GPIO implementation
│   ├── i2c.c                    # I2C implementation
│   ├── spi.c                    # SPI implementation
│   ├── uart.c                   # UART implementation
│   ├── delay.c                  # Delay implementation
│   ├── max30102.c               # MAX30102 driver
│   ├── temperature.c            # Temperature driver
│   ├── ssd1306.c                # Display driver
│   └── sdcard.c                 # SD card driver
│
├── startup_stm32f401.s          # Startup assembly code
├── STM32F401RETx_FLASH.ld       # Linker script
├── Makefile                      # Build configuration
└── README.md                     # This file
```

## 🔨 Building the Project

### Prerequisites

Install ARM GCC toolchain:
```bash
# Ubuntu/Debian
sudo apt-get install gcc-arm-none-eabi

# macOS
brew install arm-none-eabi-gcc

# Windows
# Download from: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
```

### Build Commands

```bash
# Build the project
make

# Clean build artifacts
make clean

# Flash to board (using st-link)
make flash

# Flash using OpenOCD
make flash-ocd
```

### Build Output
- `build/pulse_oximeter_monitor.elf` - ELF file with debug symbols
- `build/pulse_oximeter_monitor.hex` - Intel HEX format
- `build/pulse_oximeter_monitor.bin` - Binary file for flashing
- `build/pulse_oximeter_monitor.map` - Memory map file

## 🚀 Flashing the Firmware

### Using ST-Link
```bash
st-flash write build/pulse_oximeter_monitor.bin 0x8000000
```

### Using OpenOCD
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
  -c "program build/pulse_oximeter_monitor.elf verify reset exit"
```

### Using STM32CubeProgrammer
1. Open STM32CubeProgrammer
2. Connect to the board
3. Load `build/pulse_oximeter_monitor.hex`
4. Click "Download"

## 📊 Data Format

### UART Output (115200 baud, 8N1)
```
=== VITAL SIGNS ===
Heart Rate: 75 BPM
SpO2: 98 %
Temperature: 36.8 C
==================
```

### SD Card Log Format (CSV)
```
TIME,HR,SPO2,TEMP
TIME:0,HR:75,SPO2:98,TEMP:36.8
TIME:1,HR:76,SPO2:97,TEMP:36.9
```

### OLED Display Layout
```
┌─────────────────────┐
│ HR: 75 BPM         │
│ SPO2: 98 %         │
│ TEMP: 36.8 C       │
│ STATUS: OK         │
└─────────────────────┘
```

## 🔍 Implementation Details

### Register-Level Programming
All peripheral drivers are implemented using direct register manipulation:
- No HAL or LL libraries
- Manual clock configuration
- Direct memory-mapped register access
- Complete control over hardware

### MAX30102 Algorithm
- **Heart Rate**: Peak detection algorithm on IR signal
- **SpO2**: R-value calculation from RED/IR ratio
- **Sampling**: 100 samples/second
- **Buffer**: 100-sample moving window

### Temperature Conversion
Configure for your sensor in `temperature.c`:
- **LM35**: 10mV/°C, 0°C = 0V
- **TMP36**: 10mV/°C, 0°C = 500mV
- **Thermistor**: Steinhart-Hart equation

### Display Driver
- **Resolution**: 128x64 pixels
- **Font**: 5x7 pixel characters
- **Buffer**: Full screen buffer (1KB)
- **Update**: Manual refresh required

## ⚙️ Configuration Options

### Clock Configuration
Modify `system_clock_config()` in `main.c` to change system clock:
```c
// Default: HSI 16MHz
// For 84MHz: Configure PLL
```

### MAX30102 Settings
In `max30102.c`, adjust:
```c
#define MAX30102_SPO2_SR_100    // Sample rate
#define MAX30102_SPO2_PW_411    // LED pulse width
LED1_PA: 0x1F                    // LED current (7mA)
```

### Data Logging Frequency
In `main.c`, modify:
```c
delay_ms(10);  // Sampling period
```

## 🐛 Debugging

### UART Debug Output
Connect USB-to-Serial adapter to PA2 (TX):
```bash
# Linux/macOS
screen /dev/ttyUSB0 115200

# Windows
# Use PuTTY or TeraTerm at 115200 baud
```

### LED Indicators
- **PC13 Heartbeat**: System running (toggles every second)
- **No display**: Check SPI connections
- **No data**: Check I2C connections to MAX30102

### Common Issues

**MAX30102 Not Detected**
- Check I2C pull-up resistors (4.7kΩ)
- Verify power supply (3.3V)
- Check I2C address (0x57)

**Display Not Working**
- Verify SPI connections
- Check DC and CS pins
- Ensure 3.3V or 5V power (check display specs)

**SD Card Not Initializing**
- Use <= 32GB SD card
- Format as FAT32
- Check SPI speed (may need slower)
- Ensure proper power supply

## 📈 Performance Metrics

- **Memory Usage**: ~15KB Flash, ~2KB RAM
- **Sampling Rate**: 100Hz (MAX30102)
- **Update Rate**: Display @ 10Hz, UART @ 1Hz
- **Power Consumption**: ~80mA @ 3.3V (estimate)

## 🔬 Algorithm Details

### Heart Rate Calculation
```
1. Collect IR buffer (100 samples)
2. Apply peak detection (threshold-based)
3. Calculate BPM = (peaks × 60 × sample_rate) / buffer_length
4. Filter outliers
```

### SpO2 Calculation
```
1. Calculate DC component (average)
2. Calculate AC component (peak-to-peak / 2)
3. Calculate R = (AC_red/DC_red) / (AC_ir/DC_ir)
4. SpO2 = -45.060×R² + 30.354×R + 94.845
```

## 📚 Resources

### Datasheets
- [STM32F401RE Reference Manual](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)
- [MAX30102 Datasheet](https://datasheets.maximintegrated.com/en/ds/MAX30102.pdf)
- [SSD1306 Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)

### Tools
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [ARM GCC Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain)
- [OpenOCD](http://openocd.org/)

## 🤝 Contributing

This is a educational/reference implementation. Suggestions for improvements:
- More robust error handling
- Adaptive filtering algorithms
- Bluetooth/WiFi data transmission
- Multi-patient support
- Advanced DSP algorithms

## ⚠️ Disclaimer

**This is an educational project and NOT intended for medical use.**
- Not FDA approved
- Not clinically validated
- For learning purposes only
- Do not use for actual patient monitoring

## 📄 License

This project is provided as-is for educational purposes.
Feel free to use, modify, and distribute with attribution.

## 👨‍💻 Author

Bare Metal Embedded Systems Implementation
Created for learning register-level STM32 programming

---

**Built with ❤️ using pure register-level programming - No HAL, No RTOS, Just Hardware!**
