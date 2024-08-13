# Test ESP32 flash write on Zephyr v3.7.0

## Build

```
➜ west build -b esp32_devkitc_wrover/esp32/procpu . --sysbuild
➜ west flash
➜ west espressif monitor
```

## Output

It always hangs after block 12

```
--- idf_monitor on /dev/ttyUSB0 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ets Jul 29 2019 12:21:46
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0000,len:10148
load:0x40078000,len:6832
ho 0 tail 12 room 4
load:0x400a0000,len:35788
entry 0x400a2dc8
I (36) boot: MCUboot 2nd stage bootloader
I (36) boot: compile time Aug 13 2024 17:27:29
W (36) boot: Unicore bootloader
I (36) spi_flash: detected chip: generic
I (40) spi_flash: flash io: dio
I (43) boot: chip revision: v3.1
I (46) boot.esp32: SPI Speed      : 40MHz
I (50) boot.esp32: SPI Mode       : DIO
I (53) boot.esp32: SPI Flash Size : 8MB
I (57) boot: Enabling RNG early entropy source...
I (93) spi_flash: flash io: dio
[esp32] [INF] Image index: 0, Swap type: none
[esp32] [INF] Loading image 0 - slot 0 from flash, area id: 1
[esp32] [INF] Application start=40085460h
[esp32] [INF] DRAM segment: paddr=00018b9ch, vaddr=3ffb0000h, size=013a4h (  5028) load
[esp32] [INF] IRAM segment: paddr=00010040h, vaddr=40080000h, size=08b5ch ( 35676) load
[esp32] [INF] DROM segment: paddr=00020000h, vaddr=3f400000h, size=2DDC8h (187848) map
[esp32] [INF] IROM segment: paddr=00050000h, vaddr=400d0000h, size=08EDCh ( 36572) map
I (164) spi_flash: detected chip: gd
I (164) spi_flash: flash io: dio

*** Booting Zephyr OS build v3.7.0 ***
[00:00:00.165,000] <inf> flash_test: Started sample
[00:00:02.165,000] <inf> flash_test: Initialized flash img
[00:00:02.693,000] <inf> flash_test: Wrote block: 0
[00:00:03.195,000] <inf> flash_test: Wrote block: 1
[00:00:03.697,000] <inf> flash_test: Wrote block: 2
[00:00:04.200,000] <inf> flash_test: Wrote block: 3
[00:00:04.726,000] <inf> flash_test: Wrote block: 4
[00:00:05.228,000] <inf> flash_test: Wrote block: 5
[00:00:05.731,000] <inf> flash_test: Wrote block: 6
[00:00:06.233,000] <inf> flash_test: Wrote block: 7
[00:00:06.762,000] <inf> flash_test: Wrote block: 8
[00:00:07.264,000] <inf> flash_test: Wrote block: 9
[00:00:07.766,000] <inf> flash_test: Wrote block: 10
[00:00:08.269,000] <inf> flash_test: Wrote block: 11
[00:00:08.797,000] <inf> flash_test: Wrote block: 12
[00:00:09.300,000] <inf>
```
