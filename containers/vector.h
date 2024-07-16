#ifndef CONTAINERS_VECTOR_H_
#define CONTAINERS_VECTOR_H_

#include <iostream>

namespace s21 {

template <typename T>
class VectorIterator {
  using pointer = T *;
  using reference = T &;

 public:
  VectorIterator() : ptr_(nullptr){};

  VectorIterator(pointer ptr) : ptr_(ptr){};

  pointer getPtr() const { return ptr_; }

  reference operator*() { return *ptr_; }

  VectorIterator &operator++() {
    ptr_++;
    return *this;
  }

  VectorIterator operator++(int) {
    VectorIterator result = *this;
    ptr_++;
    return result;
  }

  VectorIterator &operator--() {
    ptr_--;
    return *this;
  }

  VectorIterator operator--(int) {
    VectorIterator result = *this;
    ptr_--;
    return result;
  }

  bool operator==(const VectorIterator &i) const { return ptr_ == i.ptr_; }

  bool operator!=(const VectorIterator &i) const { return ptr_ != i.ptr_; }

  int operator-(const VectorIterator &i) const { return (ptr_ - i.ptr_); }

 private:
  pointer ptr_;
};

template <typename T>
class VectorConstIterator {
  using pointer = T *;
  using const_reference = const T &;

 public:
  VectorConstIterator() : ptr_(nullptr){};

  VectorConstIterator(pointer ptr) : ptr_(ptr){};

  pointer getPtr() const { return ptr_; }

  const_reference operator*() { return *ptr_; }

  VectorConstIterator &operator++() {
    ptr_++;
    return *this;
  }

  VectorConstIterator operator++(int) {
    VectorConstIterator result = *this;
    ptr_++;
    return result;
  }

  VectorConstIterator &operator--() {
    ptr_--;
    return *this;
  }

  VectorConstIterator operator--(int) {
    VectorConstIterator result = *this;
    ptr_--;
    return result;
  }

  bool operator==(const VectorConstIterator &i) const { return ptr_ == i.ptr_; }

  bool operator!=(const VectorConstIterator &i) const { return ptr_ != i.ptr_; }

  int operator-(const VectorConstIterator &i) const { return (ptr_ - i.ptr_); }

 private:
  pointer ptr_;
};

template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = VectorIterator<T>;
  using const_iterator = VectorConstIterator<T>;
  using size_type = size_t;

  vector() : size_(0), cap_(0), data_(nullptr) {}

  vector(size_type n) : size_(n), cap_(n) {
    data_ = raw_mem_alloc(n);
    for (size_t i = 0; i < size_; i++) {
      new (data_ + i) value_type();
    }
  }

  vector(std::initializer_list<value_type> const &items)
      : size_(items.size()), cap_(size_) {
    data_ = raw_mem_alloc(size_);

    for (size_t i = 0; i < size_; i++) {
      new (data_ + i) value_type();
    }
    std::copy(items.begin(), items.end(), data_);
  }

  vector(const vector &v) : size_(v.size_), cap_(v.cap_) {
    if (cap_)
      data_ = raw_mem_alloc(cap_);
    else
      data_ = nullptr;

    if (size_) {
      for (size_t i = 0; i < size_; i++) {
        new (data_ + i) value_type(v.data_[i]);
      }
    }
  }

  vector(vector &&v) : size_(v.size_), cap_(v.cap_), data_(v.data_) {
    v.size_ = 0;
    v.cap_ = 0;
    v.data_ = nullptr;
  }

  ~vector() {
    if (data_ != nullptr) {
      for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~value_type();
      }
      operator delete(data_);
      data_ = nullptr;
    }
    size_ = 0;
    cap_ = 0;
  }

  vector &operator=(const vector &v) {
    if (data_ == v.data_) {
      return *this;
    }

    if (data_ != nullptr) {
      for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~value_type();
      }
      operator delete(data_);
      data_ = nullptr;
    }
    size_ = v.size_;
    cap_ = v.cap_;

    if (cap_) {
      data_ = raw_mem_alloc(cap_);
    }

    if (size_) {
      for (size_t i = 0; i < size_; i++) {
        new (data_ + i) value_type(v.data_[i]);
      }
    }
    return *this;
  }

  vector &operator=(vector &&v) {
    if (data_ == v.data_) {
      return *this;
    }

    if (data_ != nullptr) {
      for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~value_type();
      }
      operator delete(data_);
    }

    size_ = v.size_;
    cap_ = v.cap_;
    data_ = v.data_;

    v.size_ = 0;
    v.cap_ = 0;
    v.data_ = nullptr;
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_)
      throw std::out_of_range("Index is out of possible range");
    else
      return *(data_ + pos);
  }

  reference operator[](size_type pos) { return *(data_ + pos); }

  const_reference front() { return *data_; }

  const_reference back() { return *(data_ + size_ - 1); }

  T *data() noexcept { return data_; }

  iterator begin() const noexcept { return iterator(data_); }
  iterator end() const noexcept { return iterator(data_ + size_); }

  const_iterator cbegin() const noexcept { return const_iterator(data_); }
  const_iterator cend() const noexcept { return const_iterator(data_ + size_); }

  bool empty() const noexcept { return size_ == 0; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / (sizeof(value_type) * 2);
  }

  void reserve(size_type size) {
    if (size > max_size()) {
      throw std::length_error("Size is greater than the maximum possible size");
    }
    if (size > cap_) {
      change_capacity(size);
    }
  }

  size_type capacity() const noexcept { return cap_; }

  void shrink_to_fit() {
    if (cap_ > size_) {
      change_capacity(size_);
    }
  }

  void clear() noexcept {
    if (data_ != nullptr)
      for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~value_type();
      }
    size_ = 0;
  }

  iterator insert(iterator pos, const_reference value) {
    size_++;
    if (cap_ == 0) {
      cap_++;
      data_ = raw_mem_alloc(cap_);
      new (data_) value_type(value);
      return iterator(data_);

    } else if (cap_ >= size_) {
      for (size_t i = size_ - 1; pos.getPtr() < (data_ + i); i--) {
        if (i == size_ - 1) {
          new (data_ + i) value_type(data_[i - 1]);
        } else {
          data_[i] = data_[i - 1];
        }
      }
      if (pos.getPtr() == data_ + size_ - 1) {
        new (pos.getPtr()) value_type(value);
      } else {
        *(pos.getPtr()) = value;
      }
      return pos;

    } else {
      cap_ *= 2;
      value_type *new_data_ = raw_mem_alloc(cap_);
      iterator result;
      for (size_t i = 0; i < size_; i++) {
        if (data_ + i < pos.getPtr()) {
          new (new_data_ + i) value_type(data_[i]);
        } else if (data_ + i == pos.getPtr()) {
          new (new_data_ + i) value_type(value);
          result = new_data_ + i;
        } else {
          new (new_data_ + i) value_type(data_[i - 1]);
        }
        if (i != size_ - 1) (data_ + i)->~value_type();
      }
      operator delete(data_);
      data_ = new_data_;
      return result;
    }
  }

  void erase(iterator pos) {
    if (data_ != nullptr) {
      size_t pos_numb = pos.getPtr() - begin().getPtr();
      for (; pos_numb < size_ - 1; pos_numb++) {
        data_[pos_numb] = data_[pos_numb + 1];
      }
      (data_ + size_ - 1)->~value_type();
      size_--;
    }
  }

  void push_back(const_reference value) {
    if (!cap_) reserve(1);
    if (cap_ == size_) reserve(size_ * 2);
    new (data_ + size_) value_type(value);
    size_++;
  }

  void pop_back() {
    if (size_ != 0) {
      (data_ + size_ - 1)->~value_type();
      size_--;
    }
  }

  void swap(vector &other) {
    std::swap(size_, other.size_);
    std::swap(cap_, other.cap_);
    std::swap(data_, other.data_);
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }

 private:
  size_type size_;
  size_type cap_;
  value_type *data_;

  T *raw_mem_alloc(size_type n) {
    T *new_data_ = reinterpret_cast<T *>(operator new(sizeof(T) * n));
    return new_data_;
  }

  void change_capacity(size_type n) {
    cap_ = n;
    value_type *new_data_ = raw_mem_alloc(cap_);

    for (size_t i = 0; i < size_; i++) {
      new (new_data_ + i) value_type(data_[i]);
      (data_ + i)->~value_type();
    }

    operator delete(data_);
    data_ = new_data_;
  }
};

}  // namespace s21

#endif  // CONTAINERS_VECTOR_H_
