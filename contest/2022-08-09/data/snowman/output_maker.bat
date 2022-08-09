@echo off
echo please input the problem's name
set /p n=
echo please input the number of data
set /p t=
set /a i=1
:lab
if %i% gtr %t% exit
%n%.exe<%n%%i%.in>%n%%i%.out
echo finish calculating data %i%
set /a i=%i%+1
goto lab