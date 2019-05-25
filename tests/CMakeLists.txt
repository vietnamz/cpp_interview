enable_testing()

project(InterviewTest)
#add_subdirectory(googletest)
set(googleTest_Dir ${CMAKE_CURRENT_SOURCE_DIR}/googletest)

if (EXISTS ${googleTest_Dir})
    SET(GTestSrc ${googleTest_Dir}/googletest)
    SET(GMockSrc ${googleTest_Dir}/googlemock)
else ()
    message(FATAL_ERROR "No googletest src dir found!")
endif ()

include_directories(${CMAKE_HOME_DIRECTORY} ${CMAKE_HOME_DIRECTORY}/libs)
include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)
include_directories(${CMAKE_HOME_DIRECTORY} ${CMAKE_HOME_DIRECTORY}/test)

set(test_SOURCES
		main.cpp
        Interview_test.cpp)

add_executable(InterviewTest ${test_SOURCES} ${GTestSrc}/src/gtest-all.cc ${GMockSrc}/src/gmock-all.cc)

target_link_libraries(InterviewTest interviewLibs)
