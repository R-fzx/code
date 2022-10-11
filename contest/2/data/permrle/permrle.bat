@echo off
if "%1"=="" goto loop
copy permrle%1.in permrle.in >nul
echo Problem Test
echo Data %1
time<enter
permrle.exe
time<enter
copy permrle%1.out permrle.ans >nul
fc permrle.out permrle.ans
del permrle.in
del permrle.out
del permrle.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
