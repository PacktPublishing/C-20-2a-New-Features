#include "inc.hpp"

using std::string;
using std::cout;
using std::endl;

struct Person2
{
    int id;
    int ant;
};

int main()
{
    int num = 100;
    string s = "aa";
    Person2 p;
    printf("garbage 1: %f\n", num);
    printf("garbage 2: %s\n", p);
    printf("garbage 3: %s\n");
    //printf("garbage 4: %s\n", s);

    try
    {
        cout << format("{:f", num) << endl;
    }
    catch (const format_error& ex)
    {
        cout << format("!!! Exception: {}\n", ex.what());
    }
}
