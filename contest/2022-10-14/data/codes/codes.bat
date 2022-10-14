@echo off
if "%1"=="" goto loop
copy codes%1.in codes.in >nul
echo Problem Test
echo Data %1
time<enter
codes
time<enter
fc codes.out codes%1.out
del codes.in
del codes.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
