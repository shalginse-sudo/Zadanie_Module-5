#include <vector>
#include <set>
#include <iostream>

std::vector<int> remove_duplitates_and_sort(const std::vector<int>& input)
{
    std::set<int> set;
    for (auto in : input) {
        set.insert(in);
    }

    return { set.rbegin(), set.rend() };
}

void task_7_2()
{
    int count;
    std::cin >> count;
    std::vector<int> input(count);
    for (size_t i = 0; i < count; ++i) {
        std::cin >> input[i];
    }
    std::cout << std::endl;

    auto ans = remove_duplitates_and_sort(input);
    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << std::endl;
    }
}