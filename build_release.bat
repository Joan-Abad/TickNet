@echo off

echo === Configuring Release ===
cmake --preset vs2022-release

if %errorlevel% neq 0 exit /b %errorlevel%

echo === Building Release ===
cmake --build --preset build-release

if %errorlevel% neq 0 exit /b %errorlevel%

echo === Done (Release) ===
pause