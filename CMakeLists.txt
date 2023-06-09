############################################################
# Basic CMake project setup
############################################################

cmake_minimum_required(VERSION 3.14)
project(PDF-Parsing)

############################################################
# Add compiler flags - note: -std=c++17 REQUIRED
############################################################

add_compile_options(
    -Wall -Wextra -Wpedantic -std=c++20
    -fmessage-length=80 -fno-diagnostics-show-option
    -fstack-protector-all -g -O3
    -Walloca -Wctor-dtor-privacy
    -Werror -Wfatal-errors -Winit-self
    -Wold-style-cast -Wshadow
    -Wunused-const-variable -Wzero-as-null-pointer-constant
)

############################################################
# Create the PDF library & link Poppler
############################################################

add_library(PDF STATIC 
    ${PROJECT_SOURCE_DIR}/src/pdf/PDF.cc
)

target_link_directories(PDF PUBLIC
    /path-to-poppler/version.number/lib
)

target_include_directories(PDF PUBLIC
    /path-to-poppler/version.number/include
    ${PROJECT_SOURCE_DIR}/include/pdf
)

############################################################
# Create the example executable
############################################################

add_executable(example
    ${PROJECT_SOURCE_DIR}/src/pdf/example.cc
)

target_link_libraries(example
    poppler-cpp
    PDF
)
