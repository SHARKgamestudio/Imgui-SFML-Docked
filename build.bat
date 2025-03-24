:: MSVC Builder - SHARK.studio 2025

@echo off
:: Set the path to your Visual Studio solution
set SOLUTION_PATH="Imgui-SFML-Docked.sln"

:: Build configurations and platforms
set CONFIGURATIONS=Debug Release
set PLATFORMS=x64 x86

:: Loop through configurations and platforms
for %%C in (%CONFIGURATIONS%) do (
    for %%P in (%PLATFORMS%) do (
        echo Building %%C - %%P...
        msbuild %SOLUTION_PATH% /p:Configuration=%%C /p:Platform=%%P
    )
)

echo Build process completed.
pause