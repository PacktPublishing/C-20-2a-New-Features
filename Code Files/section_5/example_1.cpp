#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3};
    std::cout << "2 found at position: " 
	      << std::find(v.begin(), v.end(), 2) - v.begin() << "\n";
}
