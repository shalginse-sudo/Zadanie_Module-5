#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<std::pair<char, size_t>> count_char_occurrence_and_sort(const std::string& input)
{
    std::unordered_map<char, size_t> m;
    for (size_t i = 0; i < input.size(); ++i) {
        size_t& count = m[input[i]];
        ++count;
    }

    std::vector<std::pair<char, size_t>> ans;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        ans.push_back(*it);
    }

    std::sort(ans.begin(), ans.end(), [](const auto& l, const auto& r) { return l.second > r.second; });

    return ans;
}

void task_7_1()
{
    auto res = count_char_occurrence_and_sort("Hello, world!!");
    for (const auto& r : res) {
        std::cout << r.first << " " << r.second << std::endl;
    }
}
