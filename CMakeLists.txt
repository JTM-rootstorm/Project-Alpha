cmake_minimum_required(VERSION 3.15)
project(Project-Alpha)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE
                                            src/main.cpp
        src/core/constants.hpp
        src/core/core.hpp                   src/core/core.cpp
        src/core/perlin_noise.hpp           src/core/perlin_noise.cpp
        src/core/random_number_gen.hpp

        src/gfx/gfx.hpp                     src/gfx/gfx.cpp
        src/gfx/renderable.hpp              src/gfx/renderable.cpp
        src/gfx/tilemap.hpp                 src/gfx/tilemap.cpp

        src/world/terrain/terrain.hpp       src/world/terrain/terrain.cpp
        src/world/terrain/terrain_gen.hpp

        src/world/area.hpp                  src/world/area.cpp
        src/world/location.hpp              src/world/location.cpp
        src/world/tile.hpp                  src/world/tile.cpp)


IF(UNIX)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
ENDIF(UNIX)

IF(WIN32 OR MSVC)
    cmake_policy(SET CMP0074 NEW)
    set(SFML_DIR "${PROJECT_SOURCE_DIR}/win-lib/SFML/lib/cmake/SFML")
    set(TBB_DIR "${PROJECT_SOURCE_DIR}/win-lib/oneTBB/lib/cmake/tbb")
ENDIF(WIN32 OR MSVC)

set(SFML_STATIC_LIBRARIES TRUE)

add_executable(palpha ${SOURCE})

find_package(SFML 2.5 COMPONENTS system graphics window REQUIRED)

if (SFML_FOUND)
    target_link_libraries(palpha sfml-graphics)
endif ()

find_package(TBB)

if(TBB_FOUND)
    target_link_libraries(palpha TBB::tbb)
endif()