#include <iostream>
#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int>& input)
{
    std::sort(input.begin(), input.end());
    input.erase(std::unique(input.begin(), input.end()), input.end());
}

int main()
{
    std::vector<int> data{ 1, 1, 2, 5, 6, 1, 2, 4 };
    remove_duplicates(data);

    for (auto v : data) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}