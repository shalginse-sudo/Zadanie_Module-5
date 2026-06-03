#include <vector>
#include <iostream>

template<typename T>
T square(const T& val)
{
    return val * val;
}

template<typename T>
std::vector<T> square(const std::vector<T>& vals)
{
    std::vector<T> ans;
    for (size_t i = 0; i < vals.size(); ++i) {
        ans.push_back(square<T>(vals[i]));
    }

    return ans;
}

void task_5_1()
{
    auto a = square(1);
    auto b = square(std::vector<int>{ -1, 2, 3 });

    std::cout << a << std::endl;
    for (size_t i = 0; i < b.size(); ++i) {
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;
}