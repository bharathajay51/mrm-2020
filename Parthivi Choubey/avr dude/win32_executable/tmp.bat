@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA16 -c arduino -P COM7  -U calibration:r:"F:\avr dude\win32_executable\cal_bits.raw":r
avrdudeGUI.exe -done
pause