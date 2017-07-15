cmake_minimum_required(VERSION 2.6.0)

project(kibble C)

file(GLOB autopilot_sources ./*.cpp ./*/*.cpp ./*/*/*.cpp ./*/*/*/*.cpp ./*.c ./*/*.c ./*/*/*.c ./*/*/*/*.c)
SET(autopilot ${autopilot_sources})  

add_executable(kibble ${autopilot})
