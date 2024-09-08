@echo off

:: Set directories to exclude
set excludeDirs="third-party" "build"

:: Loop through all .h and .cpp files, excluding certain directories
for /r %%G in (*.h *.cpp) do (
    echo %%G | findstr /i /r "\\third-party\\ \\build\\" >nul
    if errorlevel 1 (
        echo Formatting: %%G
        clang-format -i "%%G"
    )
)

echo Formatting completed.
