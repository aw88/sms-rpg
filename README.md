# sms-roguelike

A simple RPG for the Sega Master System written in C and Z80 assembly using the
devkitSMS library.

## Prerequisites

[SDCC](http://sdcc.sourceforge.net/) should be setup with the tools `assets2banks` and
`ihx2sms` available on your `PATH`

## Compiling

Run the `./build.sh` script to compile a runnable ROM.

Intermediate artifacts can be removed by running the `./build.sh clean` command.

## Built with

* [SDCC](http://sdcc.sourceforge.net/) - Small Device C Compiler
* [devkitSMS](https://github.com/sverx/devkitSMS) - C bindings to SMS hardware
* [BMP2Tile](http://www.smspower.org/maxim/Software/BMP2Tile) - Image conversion utility
* [Emulicious](https://emulicious.net/) - Sega Master System with debugging tools

## Acknowledgements

* [SMS Power!](http://www.smspower.org/)
* [Zoria Tileset](https://opengameart.org/content/zoria-tileset)
