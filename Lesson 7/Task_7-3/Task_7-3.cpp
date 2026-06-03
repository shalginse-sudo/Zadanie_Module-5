#include <stdexcept>
#include <iostream>

template<typename T>
class Vector
{
    static constexpr size_t init_capacity = 8;

public:
    Vector()
        : buffer_(new T[init_capacity])
        , size_(0)
        , capacity_(init_capacity)
    {
    }

    ~Vector()
    {
        delete[] buffer_;
    }

    Vector(Vector&) = delete;
    Vector& operator=(Vector&) = delete;

    T& at(size_t idx)
    {
        if (idx >= size_) {
            throw std::out_of_range("index is too big");
        }

        return buffer_[idx];
    }

    const T& at(size_t idx) const
    {
        if (idx >= size_) {
            throw std::out_of_range("index is too big");
        }

        return buffer_[idx];
    }

    size_t size() const
    {
        return size_;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    void push_back(const T& val)
    {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ * 2;
            T* new_buffer = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_buffer[i] = buffer_[i];
            }
            delete[] buffer_;
            buffer_ = new_buffer;
            capacity_ = new_capacity;
        }

        buffer_[size_++] = val;
    }


private:
    T* buffer_;
    size_t size_;
    size_t capacity_;
};

void task_7_3()
{
    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    vector.push_back(6);
    vector.push_back(7);
    vector.push_back(8);
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << std::endl;
    std::cout << std::endl;

    vector.push_back(9);
    vector.push_back(10);
    std::cout << "Size: " << vector.size() << std::endl;
    std::cout << "Capacity: " << vector.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "Element at position 9 is " << vector.at(9) << std::endl;
    try {
        vector.at(10);
    }
    catch (const std::exception& e) {
        std::cout << "Cannot get element at position 10: " << e.what() << std::endl;
    }
}
