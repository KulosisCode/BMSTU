@echo off
FOR /F "tokens=*" %%* IN (neg_%1_args.txt) DO %%* > out.txt
fc out.txt neg_%1_out.txt
pause