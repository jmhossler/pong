cmake_minimum_required(VERSION 3.2)
project(pong VERSION 0.1 LANGUAGES C)

add_executable(pong
    difficulty.c
    logic.c 
    paddles.c
    pong.c
    screen.c
)

target_link_libraries(pong 
    PRIVATE ncurses
    PRIVATE m
)
