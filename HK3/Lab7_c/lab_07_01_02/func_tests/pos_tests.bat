@echo off
FOR /F "tokens=*" %%* IN (pos_%1_args.txt) DO %%* > out.txt
fc out.txt pos_%1_out.txt
pause