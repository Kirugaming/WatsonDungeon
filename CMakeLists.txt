cmake_minimum_required(VERSION 3.25)
project(WatsonDungeon)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")



add_executable(WatsonDungeon main.cpp Game.cpp Game.h Player.cpp Player.h Level.cpp Level.h)

# audio support
target_link_libraries(WatsonDungeon Winmm.lib)