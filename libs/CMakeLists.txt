project(interviewLibs)

set(lib_SRCS
        Interview.cpp
        )
set(lib_HEADERS
    	Interview.h
        )

add_library(interviewLibs ${lib_SRCS} ${lib_HEADERS})
