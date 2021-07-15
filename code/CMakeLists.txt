cmake_minimum_required(VERSION 3.10.2)

project(linear-timecode-decoder)

set(CMAKE_CXX_STANDARD 17)

#######################
# Include directories #
#######################

set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
        )

#################
# Library files #
#################

set(LIB_FILES
        lib/timedecoder.cpp
        )

###############
# Add library #
###############
add_library(timedecoderlib ${LIB_FILES})
target_include_directories(timedecoderlib PRIVATE ${INCLUDE_DIRS})
set_target_properties(timedecoderlib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

###################
# Add application #
###################

set(SOURCE_FILES
        src/main.cpp
        )

add_executable(timedecoder ${SOURCE_FILES})
target_include_directories(timedecoder PRIVATE ${INCLUDE_DIRS})
target_link_libraries(timedecoder timedecoderlib)
set_target_properties(timedecoder PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

############################
# Add other CMakeLists.txt #
############################

add_subdirectory(tests)
