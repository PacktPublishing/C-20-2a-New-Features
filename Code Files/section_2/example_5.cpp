#include "inc.hpp"

using std::cout;
using std::endl;

int main()
{
    cout << format("The number is {} and {}", 20, 6) << endl;
    cout << format("Die Zahl ist {1} und {0}", 20, 6) << endl;
}
