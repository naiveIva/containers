#ifndef CONTAINERS_ARRAY_H_
#define CONTAINERS_ARRAY_H_

#include <iostream>

namespace s21 {

template <typename T, std::size_t N>
class array {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  array(){};

  array(std::initializer_list<value_type> const &items) {
    if (items.size() > size_)
      throw std::invalid_argument("Initializer list is bigger than array");
    iterator ptr = arr_;
    for (auto i : items) {
      *ptr = i;
      ptr++;
    }
    while (ptr != end()) {
      *ptr = value_type();
      ptr++;
    }
  }

  array(const array &a) = default;

  array(array &&a) = default;

  ~array() = default;

  array &operator=(const array &a) = default;

  array &operator=(array &&a) = default;

  reference at(size_type pos) {
    if (pos >= size_)
      throw std::out_of_range("Index is out of possible range");
    else
      return *(arr_ + pos);
  }

  reference operator[](size_type pos) { return *(arr_ + pos); }

  const_reference front() const { return arr_[0]; }

  const_reference back() const { return arr_[size_ - 1]; }

  iterator data() noexcept { return arr_; }

  iterator begin() noexcept { return arr_; }

  iterator end() noexcept { return arr_ + size_; }

  bool empty() const noexcept { return size_ == 0; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept { return size_; }

  void swap(array &other) noexcept {
    if (arr_ != other.arr_) {
      std::swap(*this, other);
    }
  }

  void fill(const_reference value) {
    if (!size_) return;
    for (iterator ptr = begin(); ptr != end(); ptr++) {
      *ptr = value;
    }
  }

 private:
  value_type arr_[N];
  size_type size_ = N;
};

}  // namespace s21

#endif  // CONTAINERS_ARRAY_H_