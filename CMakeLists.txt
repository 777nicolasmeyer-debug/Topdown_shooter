
cmake_minimum_required(VERSION 3.10)

project(Topdown_shooter)

add_subdirectory(
    "C:/Users/777ni/OneDrive/Documents/Projects/Libraries/raylib/raylib" # Your path to raylib
    raylib_build
)

add_executable(
    Topdown_shooter
    Topdown_shooter.cpp

    Player.cpp
    Player.h

    Bullet.cpp
    Bullet.h

    Enemy.cpp
    Enemy.h 

    Topdown_shooter.h

    Spawn_logic.cpp 
    Spawn_logic.h 

    Collisions.cpp
    Collisions.h
)

target_link_libraries(Topdown_shooter PRIVATE raylib)


set_property(TARGET Topdown_shooter PROPERTY CXX_STANDARD 20)
