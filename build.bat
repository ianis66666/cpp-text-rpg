@echo off
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Player.cpp Skill.cpp Item.cpp Monster.cpp -o dungeon_quest.exe
if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)
echo Build succeeded. Run dungeon_quest.exe to play.
