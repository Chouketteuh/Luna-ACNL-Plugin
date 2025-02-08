@echo off
make clean
make
rundll32 user32.dll,MessageBeep
pause