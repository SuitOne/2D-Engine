cmake_minimum_required(VERSION 3.10.0)
project(SFML_Test VERSION 0.1.0 LANGUAGES C CXX)

#C Language Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

#Include + Lib
include_directories(
    "C:/Users/U307797/OneDrive - L3Harris - GCCHigh/Documents/Projects/include"
    "${CMAKE_SOURCE_DIR}/include")
link_directories(
    "C:/Users/U307797/OneDrive - L3Harris - GCCHigh/Documents/Projects/lib")

#Include .cpp files in directory
file(GLOB SOURCES 
"${CMAKE_SOURCE_DIR}/*.cpp"
"${CMAKE_SOURCE_DIR}/src/*.cpp")

#Executable
add_executable(SFML_Test ${SOURCES})

#Link libs
target_link_libraries(SFML_Test sfml-graphics sfml-window sfml-system)

#Post
include(CTest)
enable_testing()

#Copy SFML DLLs to build directory
add_custom_command(TARGET SFML_Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "C:/Users/U307797/OneDrive - L3Harris - GCCHigh/Documents/Projects/bin/sfml-system-3.dll"
    "C:/Users/U307797/OneDrive - L3Harris - GCCHigh/Documents/Projects/bin/sfml-window-3.dll"
    "C:/Users/U307797/OneDrive - L3Harris - GCCHigh/Documents/Projects/bin/sfml-graphics-3.dll"
    $<TARGET_FILE_DIR:SFML_Test>)
