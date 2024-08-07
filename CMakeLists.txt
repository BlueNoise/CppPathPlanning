cmake_minimum_required(VERSION 3.22.1)
project(CppPathPlanning VERSION 0.1.0 LANGUAGES CXX)

# Making sure we work with latest C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenCV
find_package(OpenCV REQUIRED)

# Google Test
find_package(GTest REQUIRED)

# Add coverage flags
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message(STATUS "Building with code coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0 --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Note to test OpenCV works as intended
add_executable(test_opencv_node
                 src/test_opencv_node.cpp
)
target_include_directories(test_opencv_node PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(test_opencv_node ${OpenCV_LIBS})

add_library(cpp_path_planning
              src/cpp_path_planning/astar.cpp
)
target_include_directories(cpp_path_planning
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Include Doxygen documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else()
    message("Doxygen needs to be installed to generate the documentation.")
endif()

### Testing
include(CTest)
enable_testing()

add_executable(cpp_path_planning_tests
                 tests/test_main.cpp
                 tests/test_astar.cpp
                 tests/test_basic_function.cpp
)

target_link_libraries(cpp_path_planning_tests
  GTest::gtest_main
  cpp_path_planning
)

include(GoogleTest)
gtest_discover_tests(cpp_path_planning_tests)

### End of testing

# Specify the install rules - for executables
install(TARGETS test_opencv_node
    EXPORT CppPathPlanningTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# Specify the install rules - for libraries
install(TARGETS cpp_path_planning
    EXPORT CppPathPlanningTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Install header files
install(DIRECTORY include/cpp_path_planning
        DESTINATION include
)

# Helper files to help find this package with find_package
include(CMakePackageConfigHelpers)

# Create the package configuration file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/package-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CppPathPlanningConfig.cmake
    INSTALL_DESTINATION lib/cmake/CppPathPlanning
)

# Create the version configuration file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/CppPathPlanningConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Install the package configuration and version files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/CppPathPlanningConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/CppPathPlanningConfigVersion.cmake
    DESTINATION lib/cmake/CppPathPlanning
)

install(EXPORT CppPathPlanningTargets
    FILE CppPathPlanningTargets.cmake
    NAMESPACE CppPathPlanning::
    DESTINATION lib/cmake/CppPathPlanning
)
