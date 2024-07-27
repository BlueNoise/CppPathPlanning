cmake_minimum_required(VERSION 3.22.1)
project(CppPathPlanning VERSION 0.1.0 LANGUAGES CXX)

# Making sure we work with latest C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenCV
find_package(OpenCV REQUIRED)

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
# For later, if needed
# target_link_libraries(cpp_path_planning PUBLIC ${OpenCV_LIBS})

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
