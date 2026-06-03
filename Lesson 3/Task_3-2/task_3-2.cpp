#include <stdexcept>
#include <iostream>

class smart_array2
{
public:
    explicit smart_array2(size_t n)
        : array_(new int[n])
        , size_(0)
        , capacity_(n)
    {
    }

    smart_array2(const smart_array2& other)
        : smart_array2(other.capacity_)
    {
        for (size_t i = 0; i < other.size_; ++i) {
            array_[i] = other.array_[i];
            ++size_;
        }
    }

    smart_array2& operator=(const smart_array2& other)
    {
        if (&other == this) {
            return *this;
        }

        int* new_array = new int[other.capacity_];
        for (size_t i = 0; i < other.size_; ++i) {
            new_array[i] = other.array_[i];
        }

        delete[] array_;
        array_ = new_array;
        size_ = other.size_;
        capacity_ = other.capacity_;

        return *this;
    }

    ~smart_array2()
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


void task_3_2()
{
    smart_array2 arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array2 new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    std::cout << arr.get_element(0) << std::endl;
    std::cout << arr.get_element(1) << std::endl;
    try {
        arr.get_element(3);
    }
    catch (const std::out_of_range& e) {
        std::cout << "cannot get 3-th element" << std::endl;
    }
}