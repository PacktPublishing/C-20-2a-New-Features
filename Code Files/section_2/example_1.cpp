#include "inc.hpp"

using namespace std;

int main()
{
    // 100 -> 0x00000064
    int n = 100;
    int pad = 10;

    printf("%#0*x\n", pad, n);
    cout << "0x" << setfill('0') << setw(pad-2) << hex << n << endl;
    cout << format("{:0=#{}x}\n", n, pad);
}
