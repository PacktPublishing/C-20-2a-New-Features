add_compile_options(-fmodules-ts)

add_executable(section_5_ex_1 example_1.cpp)
target_link_libraries(section_5_ex_1 PRIVATE fmt::fmt-header-only)

add_executable(section_5_ex_2 string_operations.cpp example_2.cpp)

add_executable(section_5_ex_3
    sysinfo_cpu.cpp
    sysinfo_arch.cpp
    sysinfo.cpp
    example_3.cpp
)

add_executable(section_5_ex_4
    sysinfo2.cpp
    sysinfo2_impl.cpp
    example_3.cpp
)
