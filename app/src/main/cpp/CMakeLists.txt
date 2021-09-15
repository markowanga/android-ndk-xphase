cmake_minimum_required(VERSION 3.10.2)

project("nativeapplicationxphase")

add_library(
        native-lib
        SHARED
        native-lib.cpp)

add_library(
        PanoMaker
        SHARED
        IMPORTED
)
set_target_properties(
        PanoMaker
        PROPERTIES
        IMPORTED_LOCATION ../jniLibs/${ANDROID_ABI}/libPanoMaker.so
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/PanoMaker)

find_library(
        log-lib
        log)

target_link_libraries(
        native-lib
        ${log-lib})
