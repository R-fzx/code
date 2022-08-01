@echo off
set a = 0
:again
set /a a = a + 1
@echo %a%
data.exe
lyx.exe
lyx_bf.exe
fc lyx.out lyx_bf.out
if not errorlevel 1 goto again
pause