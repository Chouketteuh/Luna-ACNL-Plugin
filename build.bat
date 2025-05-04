@echo off
rmdir /s /q ".vscode"
make clean
make
rundll32 user32.dll,MessageBeep
pause