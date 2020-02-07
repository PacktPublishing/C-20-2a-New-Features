#include "inc.hpp"

using std::cout;
using std::endl;

int main()
{
    int num = 1042;
    std::vector<char> buf;

    format_to(std::back_inserter(buf), "{:#x}", num);
    std::back_inserter(buf) = '\0';

    cout << format("result 0: {} ({})\n", buf.data(), buf.size());


    auto size = formatted_size("{:#x}", num) + 1;
    std::vector<char> buf2(size);
    auto result2 = format_to(buf2.data(), "{:#x}", num);
    *result2 = '\0';
    cout << format("result 1: {} ({})\n", buf2.data(), size);

    char cbuf[10];
    auto result3 = format_to_n(cbuf, sizeof(cbuf), "{:#x}", num);
    *result3.out = '\0';
    cout << format("result 2: {} ({})\n", cbuf, result3.size+1);
}
