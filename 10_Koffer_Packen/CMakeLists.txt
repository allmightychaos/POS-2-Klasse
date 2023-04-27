cmake_minimum_required(VERSION 3.20.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main src/main.cpp src/koffer.cpp src/packstueck.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
