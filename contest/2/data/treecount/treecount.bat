@echo off
if "%1"=="" goto loop
copy treecount%1.in treecount.in >nul
echo Problem Test
echo Data %1
time<enter
treecount.exe
time<enter
copy treecount%1.out treecount.ans >nul
fc treecount.out treecount.ans
del treecount.in
del treecount.out
del treecount.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
