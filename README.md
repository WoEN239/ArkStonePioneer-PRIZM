## Description

This is the TETRIX PRIZM part of the program for WoEN: ArkStone Pioneer Puck Collect robot. See [this repository](https://github.com/WoEN239/ArkStonePioneer-REV) for the REV Control Hub part.

## Building the project
Prerequisites: **[CLion](https://www.jetbrains.com/clion/)** with a **[PlatformIO plugin](https://docs.platformio.org/en/latest/integration/ide/clion.html)** and **[AVR GCC Compiler](https://packages.msys2.org/package/mingw-w64-x86_64-avr-gcc)** configured.

* Clone this repo locally

* Open it as CLion project

* Make an **"uno"** build target

<p align="left"><img src="https://github.com/WoEN239/ArkStonePioneer-PRIZM/blob/master/readme-pictures/build-target.png" width="500"></p>

* Select **PlatformIO Re-Init** and **Update All** in Tools menu

* To upload project to controller, make a **PlatformIO Upload** run configuration

<p align="left"><img src="https://github.com/WoEN239/ArkStonePioneer-PRIZM/blob/master/readme-pictures/run-configuration.png" width="500"></p>

* Deploy!
