#include <vector>
#include <iostream>

template<typename T>
class Table
{
public:
    Table(size_t m, size_t n)
        : table_(std::vector<std::vector<T>>(m, std::vector<T>(n)))
        , size_(m* n)
    {
    }

    std::vector<T>& operator[](size_t idx)
    {
        return table_[idx];
    }

    const std::vector<T>& operator[](size_t idx) const
    {
        return table_[idx];
    }

    size_t Size() const
    {
        return size_;
    }

private:
    std::vector<std::vector<T>> table_;
    size_t size_;
};

void task_5_2()
{
    auto test = Table<int>(2, 3);
    test[0][2] = 4;
    std::cout << test[0][2] << std::endl;
    std::cout << test.Size() << std::endl;
}