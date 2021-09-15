# best intro https://www.py4u.net/discuss/83872
cmake_minimum_required(VERSION 3.10.2)

project("nativeapplicationxphase")

add_library(
        native-lib
        SHARED
        native-lib.cpp)

add_library(PanoMaker SHARED IMPORTED)
set_target_properties(PanoMaker PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/PanoMaker/so/${ANDROID_ABI}/PanoMaker.so)
target_include_directories(native-lib PRIVATE
        ${CMAKE_SOURCE_DIR}/PanoMaker/include)

find_library(
        log-lib
        log)

target_link_libraries(
        native-lib
        PanoMaker
        ${log-lib})
