cmake_minimum_required(VERSION 3.18)
project(S102)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE LIB_HEADERS libs/*)
file(GLOB_RECURSE SRC src/*)
add_executable(S102 ${LIB_HEADERS} ${SRC} src/yaml/configReader.cpp libs/game/yaml/configReader.h src/score/score.cpp libs/game/score/score.h src/scenes/getPseudo.cpp libs/game/scenes/getPseudo.h src/scenes/winningScreen.cpp libs/game/scenes/winningScreen.h src/graphic/life.cpp libs/game/graphic/life.h)
target_include_directories(S102 PUBLIC libs)
target_link_directories(S102 PUBLIC .)

target_link_libraries(S102 mingl)
target_link_libraries(S102 GL)
target_link_libraries(S102 GLU)
target_link_libraries(S102 glut)
