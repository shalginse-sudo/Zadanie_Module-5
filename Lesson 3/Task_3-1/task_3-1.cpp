#include <stdexcept>
#include <iostream>

class smart_array
{
public:
    explicit smart_array(size_t n)
        : array_(new int[n])
        , size_(0)
        , capacity_(n)
    {
    }

    smart_array(smart_array&) = delete;
    smart_array& operator=(smart_array&) = delete;

    ~smart_array()
    {
        delete[] array_;
    }

    void add_element(int el)
    {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ * 2;
            int* new_array = new int[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_array[i] = array_[i];
            }
            delete[] array_;
            array_ = new_array;
            capacity_ = new_capacity;
        }

        array_[size_++] = el;
    }

    int get_element(size_t idx) const
    {
        if (idx >= size_) {
            throw std::out_of_range("index is too big");
        }

        return array_[idx];
    }

private:
    int* array_;
    size_t size_;
    size_t capacity_;
};

void task_3_1()
{
    smart_array array(3);
    array.add_element(1);
    array.add_element(2);
    array.add_element(3);
    array.add_element(4);
    std::cout << array.get_element(3) << std::endl;
    try {
        array.get_element(100);
    }
    catch (const std::out_of_range& e) {
        std::cout << "cannot get 100-th element" << std::endl;
    }
}