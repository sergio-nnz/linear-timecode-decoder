##################
# Add GoogleTest #
##################

set(INSTALL_GTEST OFF)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

###################
# Unit test files #
###################

set(TEST_FILES
        unittests/unit_tests.cpp
        unittests/timedecoder_tests.cpp
        )

###############################
# Statically linked libraries #
###############################

set(TEST_LINK_LIBRARIES
        gmock
        gtest
        timedecoderlib
        )

#############
# Add tests #
#############

add_executable(timedecoder_tests ${TEST_FILES})
target_include_directories(timedecoder_tests PRIVATE ${INCLUDE_DIRS})
target_link_libraries(timedecoder_tests ${TEST_LINK_LIBRARIES})
set_target_properties(timedecoder_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
