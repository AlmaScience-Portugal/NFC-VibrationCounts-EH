Overview
========


Toolchain supported
===================
- IAR embedded Workbench  8.50.1
- Keil MDK  5.30
- GCC ARM Embedded  9.2.1
- MCUXpresso  11.2.0

Hardware requirements
=====================
- Mini/micro USB cable
- LPC8N04 Development Board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the USB port J4 on the target board.
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
If the demo runs successfully,

1.LED martric will show 0, 1, 2 continuous(press key during showing 0/1/2 has no effect, only when the LED martrix die out).

2.After LED martrix die out, please press S2 select power mode, if s2 pressed, LED martrix will show the number of selected power mode(power mode is the one showed previously),
0 - kPmu_Sleep
1 - kPmu_Deep_Sleep
2 - kPmu_Deep_PowerDown

3.After LED die out, mcu will enter selected power mode.
Please press below key to wake up from different power mode,
0 - kPmu_Sleep, press RESET or S2
1 - kPmu_Deep_Sleep, press RESET or S2
2 - kPmu_Deep_PowerDown, press RESET or Connect P4-2 to GND.

4.After wake up, low power mode can be re-enterd with above steps.

Note:
Deep power down mode can be wake up by wakeup key also, after MCU enter deep power down mode, the LPC8N04 overrides the user settings of the PIO0_0 pad before entering Deep power-down. The pad is set to wake-up and the pull-up is enabled, so a external pull down signal can wake CPU up from deep power down, but according to LPC8N04 development board design, while S2 is pressed, wake up pin can be pulled up only. So if you want to wake up CPU from deep power down mode with wake up pin, you can connect wake up pin to GND after deep power down mode is entered.
Customization options
=====================

