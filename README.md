# bikeware
This repo contains the firmware that runs on biketrics' SoC of choice (currently the ESP32 on Adafruit's Huzzah32). The Espressif IoT Development Framework (ESP-IDF) is used to build/flash/monitor/test the SoC's firmware.

## Coding Guidelines
All C/C++ code should conform to [Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html). Any exceptions will be documented below.
### Exceptions
```
Currently none...
```

## Installing ESP-IDF
Refer to the following documentation for installation instructions: [docs.espressif.com](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#introduction)

## Building
From within the `biketrics/biketrics` directory, run `idf.py build`

## Cleaning
From within the `biketrics/biketrics` directory, run `idf.py fullclean`

## Flashing the ESP32 SoC
From within the `biketrics/biketrics` directory, run `idf.py -p <port/device> flash`

__NOTE:__ 460800 is the default baud rate, you can specify a buad rate with the `-b` option (e.g. `-b <rate>`)

__Example:__
```
idf.py -p /dev/cu.usbserial-01F4D619 flash
```

## Monitoring Serial Output
Run `idf.py -p <port/device> monitor` to open ESP-IDF's serial monitor.

__Example:__
```
idf.py -p /dev/cu.usbserial-01F4D619 monitor
```

__NOTE:__ Use `Ctrl + ]` to exit the monitor.

## Troubleshooting
- Most of the `idf.py` commands are intended to be run from the project root (not the repo root). Make sure you are running things commands from `biketrics/biketrics`.
- Are you seeing `<shell>: command not found: idf.py`? If so, you probably just forgot to run `get_idf`. Remember, `get_idf` has to be run in each new terminal session.
