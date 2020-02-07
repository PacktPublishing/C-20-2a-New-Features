module;
#include <iostream>
export module string_operations;

const char* inner_join(const char* s1,
                       const char* s2,
                       const char* delim)
{
    static std::string retval;
    retval = std::string{s1} + delim + s2;
    return retval.c_str();
}

export namespace so
{
const char* join(const char* s1, const char* s2)
{
    return inner_join(s1, s2, " ");
}
void print(const char* str)
{
    std::cout << str << std::endl;
}
} // namespace so

