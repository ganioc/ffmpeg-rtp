cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(RTPP LANGUAGES CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ffmpeg REQUIRED IMPORTED_TARGET libavcodec libavformat libavutil)

# 添加头文件包含路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/inc")

#添加根目录的源文件
aux_source_directory(. _SOURCES)
#添加src子目录所有源文件
aux_source_directory(src _SUB_SOURCES)


add_executable(rtpp ${_SOURCES} ${_SUB_SOURCES})

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h )
find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h )
find_library(AVCODEC_LIBRARY avcodec )
find_library(AVFORMAT_LIBRARY avformat )

target_include_directories( rtpp PRIVATE ${AVCODEC_INCLUDE_DIR} 
    ${AVFORMAT_INCLUDE_DIR})
target_link_libraries( rtpp PRIVATE ${AVCODEC_LIBRARY}
    ${AVFORMAT_LIBRARY})

#target_link_directories(rtpp PkgConfig::ffmpeg)


if(CMAKE_SYSTEM STREQUAL "Linux")
    message(STATUS "Configuring on Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on macOS")
else()
    message(STATUS "Unsupported os")
    
endif()





message(STATUS "Start cmake building.")