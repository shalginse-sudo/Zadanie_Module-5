#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>

template<typename Iter>
void print_container(Iter begin, Iter end)
{
    if (begin == end) {
        return;
    }

    auto curr = begin;
    std::cout << *curr;
    std::advance(curr, 1);

    while (curr != end) {
        std::cout << " " << *curr;
        std::advance(curr, 1);
    }
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set.begin(), test_set.end());
    std::cout << std::endl;

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list.begin(), test_list.end());
    std::cout << std::endl;

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector.begin(), test_vector.end());
    std::cout << std::endl;
    return 0;
}