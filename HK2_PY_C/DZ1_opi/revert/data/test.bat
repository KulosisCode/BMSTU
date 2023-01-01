@echo off
unit_tests.exe < in_%1.txt > out.txt
fc out.txt out_%1.txt
pause