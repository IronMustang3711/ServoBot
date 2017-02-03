cmake_minimum_required(VERSION 3.6)
set(CMAKE_TOOLCHAIN_FILE  arm-toolchain.cmake)
include(arm-toolchain.cmake)
#-DCMAKE_TOOLCHAIN_FILE=arm-toolchain.cmake
project(ServoBot)
set(TEAM_NUMBER 3711)


set(WPI_DIR "$ENV{HOME}/wpilib")

include_directories(SYSTEM
        "${WPI_DIR}/cpp/current/include"
        "${WPI_DIR}/user/cpp/include")
link_directories(SYSTEM
        "${WPI_DIR}/cpp/current/lib"
        "${WPI_DIR}/user/cpp/lib")








#gcc: -O0 -g3 -Wall -c -fmessage-length=0
#g++: -std=c++1y -I"/Users/jason/wpilib/cpp/current/include" -I"/Users/jason/Documents/workspace/Truffles/src" -O0 -g3 -Wall -c -fmessage-length=0
#linker: -L"/Users/jason/wpilib/cpp/current/lib" -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a,-rpath,/usr/local/frc/rpath-lib


set(CMAKE_INSTALL_RPATH "/opt/GenICam_v2_3/bin/Linux_armv7-a" "/usr/local/frc/rpath-lib")



file(GLOB_RECURSE SOURCE_FILES src/*.cpp)





#add_executable(${PROJECT_NAME} ${SOURCE_FILES})
#target_link_libraries(${PROJECT_NAME} wpi)

add_executable(FRCUserProgram ${SOURCE_FILES})
target_link_libraries(FRCUserProgram wpi)


add_custom_target("antDeploy"
        COMMAND ant -f ${CMAKE_CURRENT_SOURCE_DIR}/build.xml
        DEPENDS FRCUserProgram)