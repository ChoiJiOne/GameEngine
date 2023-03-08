@echo off

SET project=%1
SET visualstudio=%2
SET engine=Engine

echo generate project files...

if not exist Game\\Crash (
    echo can't find Game\\Crash directory...
    echo generate Game\\Crash directory...
    mkdir Game\\Crash
)

if exist %project% (
	echo already exist %project%...
)

echo run premake5.exe...
%engine%\\Bin\\premake5.exe %visualstudio%
start %project%\\%project%.sln
PAUSE