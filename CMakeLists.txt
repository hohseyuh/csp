cmake_minimum_required(VERSION 3.26)
project(csp)

set(CMAKE_CXX_STANDARD 23)

add_executable(CSP
        cspmain.cpp
        ac3.cpp
        graphParser.cpp
        csputils.h
        backtrack.cpp
        heuristics.cpp
        csp.cpp
)
