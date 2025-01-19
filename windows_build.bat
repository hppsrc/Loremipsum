@ECHO OFF

@REM Compile resources:

windres .\src\res\res.rc -O coff -o app.res

@REM Compile source code:

clang .\src\main.c app.res

echo Done!

pause