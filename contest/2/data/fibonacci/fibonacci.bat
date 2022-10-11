@echo off
if "%1"=="" goto loop
copy fibonacci%1.in fibonacci.in >nul
echo Problem Test
echo Data %1
time<enter
fibonacci.exe
time<enter
copy fibonacci%1.out fibonacci.ans >nul
fc fibonacci.out fibonacci.ans
del fibonacci.in
del fibonacci.out
del fibonacci.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
