set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

add_executable(section_8_ex_1 example_1.cpp)
add_executable(section_8_ex_2 example_2.cpp)
add_executable(section_8_ex_4
    example_4.cpp
    ${cppcoro_SOURCE_DIR}/lib/lightweight_manual_reset_event.cpp
)
