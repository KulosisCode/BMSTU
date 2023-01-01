@echo off
cls

for %%i in (01 02 03 04 05 ) do call neg_tests.bat %%i

for %%i in (01 02 03 04 ) do call pos_tests.bat %%i

