@call "C:\Users\crbonney\AppData\Roaming\MathWorks\MATLAB\R2012b\mexopts.bat"
@echo on
call "%VCINSTALLDIR%\vcvarsall.bat" x86_amd64
set MATLAB=C:\PROGRA~1\Matlab\R2012b
nmake -f Joint_data_collector.mk  GENERATE_REPORT=0 MAT_FILE=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0
