@echo off
:loop
t3_gen /wait
t3_ans /wait
t3 /wait
fc t3_ans.out t3.out || pause
goto loop
