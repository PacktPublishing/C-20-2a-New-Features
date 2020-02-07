cmake_minimum_required (VERSION 3.11.0)
project (Examples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_TAG 0889856d6160775462e9e0722d121aab0e75e873
)

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
endif()
set(FMT_PATH ${fmt_SOURCE_DIR})

FetchContent_Declare(
    ranges
    GIT_REPOSITORY "https://github.com/ericniebler/range-v3.git"
    GIT_TAG 50ef05324f880569436c424d0c33ba4de36fb6d9
)

FetchContent_GetProperties(ranges)
if(NOT ranges_POPULATED)
    FetchContent_Populate(ranges)
endif()
set(RANGES_PATH ${ranges_SOURCE_DIR})

FetchContent_Declare(
    cppcoro
    GIT_REPOSITORY "https://github.com/lewissbaker/cppcoro.git"
    GIT_TAG 00b34af58e8e74e0ca1739967ce410792e024964
)

FetchContent_GetProperties(cppcoro)
if(NOT cppcoro_POPULATED)
    FetchContent_Populate(cppcoro)
endif()
set(CPPCORO_PATH ${cppcoro_SOURCE_DIR})

add_subdirectory(${FMT_PATH} ${CMAKE_CURRENT_BINARY_DIR}/fmt EXCLUDE_FROM_ALL)
include_directories(${FMT_PATH}/include)
include_directories(${RANGES_PATH}/include)
include_directories(${CPPCORO_PATH}/include)
include_directories(common)
add_subdirectory (section_2)
add_subdirectory (section_3)
add_subdirectory (section_4)
add_subdirectory (section_5)
add_subdirectory (section_6)
add_subdirectory (section_7)
add_subdirectory (section_8)
add_subdirectory (section_9)

