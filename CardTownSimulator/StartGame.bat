@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

SET exec_location=D:\Assortrock\Project_Popor\TeamGit\CardTownSimulator\Windows
SET exec_name=ProjectP.exe

SET res_width=640
SET res_height=480

SET server_ip=127.0.0.1
SET server_port=7777

SET monitor_width=640
SET monitor_height=480

FOR /F "tokens=*" %%g IN ('wmic path Win32_VideoController get CurrentHorizontalResolution ^| findstr /v /r /c:"^$" /c:"^\ *$" ^| findstr /v CurrentHorizontalResolution') do (SET monitor_width=%%g)
FOR /F "tokens=*" %%g IN ('wmic path Win32_VideoController get CurrentVerticalResolution ^| findstr /v /c:"^$" ^| findstr /v /c:"^\ *$" ^| findstr /v CurrentVerticalResolution') do (SET monitor_height=%%g)

echo %monitor_width% X %monitor_height%

set /a max_width_count=(%monitor_width%/%res_width%)-1
set /a max_height_count=(%monitor_height%/%res_height%)-1

SET max_client_count=2

if not [%1] == [] set max_client_count=%1

set runclient_count=0

FOR /L %%i IN (0,1,%max_width_count%) do (
    FOR /L %%j IN (0,1,%max_height_count%) do (
        if %runclient_count%==0 (
            call :multiply %%i %%j -log
        ) else (
            call :multiply %%i %%j
        )
    )
)
goto :eof

:multiply
set /a real_pos_x=%1 * %res_width%
set /a real_pos_y=(%max_height_count% - %2) * %res_height%

if [%3] == [-listen] (
    echo "Starting Listen Server at %real_pos_x% x %real_pos_y%" 
    start %exec_location%\%exec_name% -game -listen -ip=%server_ip% -port=%server_port% -windowed -winx=%real_pos_x% -winy=%real_pos_y% -resx=%res_width% -resy=%res_height% -automove
) else (
    echo "Starting Client at %real_pos_x% x %real_pos_y%"
    start %exec_location%\%exec_name% -game -ip=%server_ip% -port=%server_port% -windowed -winx=%real_pos_x% -winy=%real_pos_y% -resx=%res_width% -resy=%res_height% -automove
)

set /a runclient_count=%runclient_count%+1
IF %runclient_count% == %max_client_count% exit 0
timeout 3 < NUL

ENDLOCAL
