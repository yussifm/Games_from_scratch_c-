@echo off
REM Set paths
set SRC_DIR=src
set LIB_DIR=libs
set OUTPUT=gameengine.exe

REM Generate a list of all .cpp files in the src directory
set FILES=
for %%f in (%SRC_DIR%\*.cpp) do (
    set FILES=%FILES% "%%f"
)

REM Compile the project
echo Compiling...
g++ -Wall -std=c++20 -I"%LIB_DIR%" %FILES% -L"C:\msys64\mingw64\lib" -lSDL2main -lSDL2 -o %OUTPUT%

REM Check if the build succeeded
if %ERRORLEVEL% equ 0 (
    echo Build successful!
) else (
    echo Build failed!
)
pause
