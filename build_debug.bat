@echo off

echo === Configuring Debug ===
cmake --preset vs2022-debug

if %errorlevel% neq 0 exit /b %errorlevel%

echo === Building Debug ===
cmake --build --preset build-debug

if %errorlevel% neq 0 exit /b %errorlevel%

echo === Done (Debug) ===
pause