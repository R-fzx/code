@echo off
echo please input the problem's name
set /p n=
echo please input the start number
set /p i=
echo please input the end number
set /p t=
:lab
if %i% gtr %t% exit
gen.exe>%n%%i%.in
echo finish generating data %i%
set /a i=%i%+1
goto lab