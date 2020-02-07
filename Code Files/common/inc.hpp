#pragma once

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cxxabi.h>
#include <typeinfo>
#include <math.h>
#include <utility>

using namespace fmt;
using std::cout;
using std::endl;
using namespace std::string_literals;

template<typename T>
struct ShowType;

inline std::string demangle(const std::string& name)
{
    int status;
    auto ptr = abi::__cxa_demangle(name.c_str(), nullptr, nullptr, &status);
    std::string str(ptr);
    free(ptr);
    return str;
}

template<typename T>
inline std::string typeName()
{
    return demangle(typeid(T).name());
}

template<typename T>
inline std::string typeName(T&& obj)
{
    return demangle(typeid(obj).name());
}
