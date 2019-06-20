project(interviewLibs)

set(lib_SRCS
        Interview.cpp
        graph.cpp
        )
set(lib_HEADERS
    	Interview.h
        queue.h
        graph.h
        )
add_library(interviewLibs ${Boost_LIBRARIES} ${lib_SRCS} ${lib_HEADERS})
