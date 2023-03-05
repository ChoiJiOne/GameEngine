@echo off

SET project=%1
SET visualstudio=%2
SET engine=Engine

echo generate project files...

if not exist %project\\Game\\Crash% (
    echo can't find %project\\Game\\Crash% directory...
    echo generate %project\\Game\\Crash% directory...
    mkdir %project\\Game\\Crash%
)

if exist %project% (
	echo already exist %project%...
)

echo run premake5.exe...
%engine%\\Bin\\premake5.exe %visualstudio%
start %project%\\%project%.sln
PAUSE