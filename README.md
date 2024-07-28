# CppPathPlanning

![Build Status](https://github.com/BlueNoise/CppPathPlanning/actions/workflows/ci.yml/badge.svg)

CppPathPlanning is a C++ library for robotics path planning, designed to be used on Linux systems, specifically Ubuntu 22.04. This library provides efficient and robust algorithms for path planning in robotic applications.

# Features
Path planning algorithms

# Requirements
- Ubuntu 22.04.4 LTS (Jammy Jellyfish)
- CMake 3.22.1
- GCC 11.4.0
- OpenCV 4.5.4
- GoogleTest 1.11.0-3

# Dependencies installation

```bash
sudo apt update
sudo apt install libgtest-dev libopencv-dev
```

# Build

```bash
mkdir build && cd build
cmake ..
make # use -j4 or whatever the number of cores you have to speed up build process
sudo make install # if you want to install on your system to be able to use find_package in your own CMake project
```

# Usage of CppPathPlanning in your CMake project

```cmake
# CMakeLists.txt
find_package(CppPathPlanning REQUIRED)
add_executable(your_executable src/your_code.cpp)
target_link_libraries(your_executable PRIVATE CppPathPlanning::cpp_path_planning)
```

> **Note:** You don't need to use `target_include_directories` for your target. The include directories are already configured correctly by the CppPathPlanning library.

# License
MIT

# Issues
For any questions or issues with the code, please create an issue.
