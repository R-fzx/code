@echo off
if "%1"=="" goto loop
copy number%1.in number.in >nul
echo Problem Test
echo Data %1
time<enter
number.exe
time<enter
copy number%1.out number.ans >nul
fc number.out number.ans
del number.in
del number.out
del number.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
