# CMakeList.txt : CMake project for ao_engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Header-Directories
include_directories($ENV{vcpkg_root}/x64-windows/include $ENV{python_include_dir})

# Library-Directories
link_directories($ENV{python_library_dir})

# Add source to this project's executable.
#add_executable (ao_engine "ao_engine.cpp" "ao_engine.h")

find_package(pybind11 REQUIRED)
pybind11_add_module(ao_engine "ao_engine.cpp" "ao_engine.h")

# TODO: Add tests and install targets if needed.