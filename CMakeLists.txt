cmake_minimum_required(VERSION 3.15)
project(steam_stub LANGUAGES CXX)

add_library(steam_api64 SHARED steam_api64_stub.cpp)
set_target_properties(steam_api64 PROPERTIES OUTPUT_NAME "steam_api64")
