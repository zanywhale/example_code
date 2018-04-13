# Minimum required version
cmake_minimum_required(VERSION 3.5)

# Set source files
SET( SRC_FILES file1.cc file1.hh file2.cc file2.hh )

# Set project name
PROJECT( PROJECT_NAME )

# Set std=c++??
SET( CMAKE_CXX_STRANDARD 11 _

# Compile!
ADD_EXECUTABLE( RESULT ${SRC_FILES} )

# Set pthread
TARGET_LINK_LIBRARIES( RESULT phtread )

