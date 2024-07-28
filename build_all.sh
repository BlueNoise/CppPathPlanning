#!/bin/bash
# Making sure we are in the correct location first
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"

cmake -S . -B build -DCMAKE_BUILD_TYPE=Coverage
cmake --build build --config Coverage
cd build
ctest -T Test -T Coverage
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
genhtml coverage.info --output-directory coverage-report
