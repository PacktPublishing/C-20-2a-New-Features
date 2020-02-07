#include "inc.hpp"

using std::string;
using std::cout;
using std::endl;

struct Person
{
    int id;
    string name;
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Person: " << p.name << " (" << p.id << ")";
    return os;
}

int main()
{
    Person p = {1, "John"};

    printf("Person: %s (%d)\n", p.name.c_str(), p.id);
    cout << p << std::endl;
    cout << format("{}", p) << std::endl;
}
