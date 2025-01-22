@ECHO off
title Test
set dir1= %cd%
setlocal enabledelayedexpansion

goto test :: delete that line for release 

:Start
cls
echo 1. test loop
echo 2. Quit
set /p choice=I choose (1,2):
if %choice%==1 goto test
if %choice%==2 exit

:test
cls
echo running loop test 
FOR %%X in (dir *.txt) DO (
    echo %%X
)
echo Done
pause