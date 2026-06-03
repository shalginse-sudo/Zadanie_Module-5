#include <vector>
#include <algorithm>
#include <iostream>

class Functor
{
public:
    void operator()(int val)
    {
        if (val % 3 == 0) {
            sum_ += val;
            ++count_;
        }
    }

    int get_sum() const
    {
        return sum_;
    }

    int get_count() const
    {
        return count_;
    }

private:
    int sum_ = 0;
    int count_ = 0;
};

void task_5_3()
{
    std::vector<int> vals{ 4, 1, 3, 6, 25, 54 };
    Functor functor;
    std::for_each(vals.begin(), vals.end(), std::ref(functor));
    std::cout << functor.get_sum() << std::endl;
    std::cout << functor.get_count() << std::endl;
}
