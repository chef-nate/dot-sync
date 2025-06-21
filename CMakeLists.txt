# Set the minimium Cmake version that can be used
cmake_minimum_required(VERSION 4.0)

# Set the minimum cpp standard that can be used
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the project name
project(
  dot-sync
  VERSION 1.0
  DESCRIPTION "C++ Based Dot File Manager"
)

# Create a sources variable and link to all cpp files to compile
set(SOURCES
  src/main.cpp
)

# Add an executable with the above soures
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the include directories to be used (includes are stored in ./include/*)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
