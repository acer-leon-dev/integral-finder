cmake_minimum_required(VERSION 3.31)
project(integral-finder)

# Determine debug and release modes
set(ISDEBUG TRUE)
set(ISRELEASE FALSE)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ISDEBUG TRUE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(ISRELEASE TRUE)
endif()

# Set c++ standard
set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

# Include YAML parsing library
include(FetchContent)
FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG 0.8.0
)
FetchContent_MakeAvailable(yaml-cpp)

# Set output directory
set(BINDIR "${CMAKE_SOURCE_DIR}/bin")
set(DEBUGDIR "${BINDIR}/debug")
set(RELEASEDIR "${BINDIR}/release")
if(ISDEBUG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DEBUGDIR}")
elseif(ISRELEASE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${RELEASEDIR}")
endif()

# Set compile options
set(COMPILATIONFLAGS "-Wall")
if(ISDEBUG)
    set(COMPILATIONFLAGS COMPILATIONFLAGS "-g")
endif()

# Set source files
set(SOURCESDIR "source")
set(SOURCES 
    "${SOURCESDIR}/main.cpp"
)

add_executable(main ${SOURCES})
target_compile_options(main PUBLIC COMPILATIONFLAGS)
target_link_libraries(main PUBLIC yaml-cpp::yaml-cpp) # The library or executable that require yaml-cpp library
