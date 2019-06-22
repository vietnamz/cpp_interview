project(interviewLibs)

set(lib_SRCS
        utilities.cpp
        graph.cpp
        )
set(lib_HEADERS
        utilities.h
        queue.h
        graph.h
        )
add_library(interviewLibs ${Boost_LIBRARIES} ${lib_SRCS} ${lib_HEADERS})
