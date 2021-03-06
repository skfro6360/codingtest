cmake_minimum_required(VERSION 3.6)
project (codingtest)

set (CMAKE_CXX_STANDARD 11)
set (SOURCE_FILES src/comparison.cpp src/utilities.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Configuration Profile
set (CMAKE_CXX_FLAGS_PROFILE "${CMAKE_CXX_FLAGS} -pg")
set (CMAKE_EXE_LINKER_FLAGS_PROFILE "${CMAKE_EXE_LINKER_FLAGS} -pg")
set (OpenMP_CXX_FLAGS "-fopenmp")

# Enable OpenMP if available
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set (HELIB_SOURCE_DIRECTORY "/home/skfro6360/HElib/src")
 
include_directories(${HELIB_SOURCE_DIRECTORY})
include_directories(include)

add_subdirectory(lib)

add_library(codingtest ${SOURCE_FILES})
target_link_libraries(codingtest HElib NTL GMP -pthread -lm -O2)

add_executable(test_Joohee test/comparisonTest_Joohee.cpp)
target_link_libraries(test_Joohee codingtest -pthread)
