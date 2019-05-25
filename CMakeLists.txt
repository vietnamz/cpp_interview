cmake_minimum_required (VERSION 2.6)

project (Interview)

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libs)
add_subdirectory(tests)

