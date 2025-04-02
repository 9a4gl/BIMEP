cmake_minimum_required(VERSION 3.5)

project(BIMEP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        BIMEPDefinition.cpp BIMEPDefinition.h
        BIMEPCommon.cpp BIMEPCommon.h
        BIMEPCandidate.cpp BIMEPCandidate.h
        BIMEPCandidates.cpp BIMEPCandidates.h
        main.cpp
)

add_executable(BIMEP ${PROJECT_SOURCES})

install(TARGETS BIMEP)
