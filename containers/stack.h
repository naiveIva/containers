#ifndef CONTAINERS_STACK_H_
#define CONTAINERS_STACK_H_

#include <iostream>

namespace s21 {

template <typename T>
struct node {
  T value;
  node* next;
};

template <typename T>
class stack {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using Node = node<T>;

 public:
  stack() : head_(nullptr), size_(0) {}

  stack(std::initializer_list<value_type> const& items)
      : head_(nullptr), size_(0) {
    for (auto i : items) push(i);
  }

  stack(const stack& s) : head_(nullptr), size_(0) { copy_stack(s); }

  stack(stack&& s) noexcept : head_(s.head_), size_(s.size_) {
    s.head_ = nullptr;
    s.size_ = 0;
  }

  ~stack() { clear_stack(); }

  stack& operator=(const stack& s) {
    if (s.head_ != head_) {
      clear_stack();
      copy_stack(s);
    }
    return *this;
  }

  stack& operator=(stack&& s) {
    if (&s != this) {
      clear_stack();
      head_ = s.head_;
      size_ = s.size_;
      s.head_ = nullptr;
      s.size_ = 0;
    }
    return *this;
  }

  const_reference top() const { return head_->value; };

  bool empty() const { return (head_ == nullptr); }

  size_type size() const { return size_; }

  void push(const_reference value) {
    Node* tmp = new Node();
    tmp->value = value;
    tmp->next = head_;
    head_ = tmp;
    size_++;
  }

  void pop() {
    if (size_ != 0) {
      Node* tmp = head_;
      head_ = head_->next;
      delete tmp;
      size_--;
    }
  }

  void swap(stack& other) noexcept {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }

 private:
  Node* head_;
  size_type size_;

  void clear_stack() {
    while (size_ != 0) {
      pop();
    }
  }

  void copy_stack(const stack& s) {
    stack<value_type> reversed_stack;
    Node* head_copy = s.head_;

    while (head_copy != nullptr) {
      reversed_stack.push(head_copy->value);
      head_copy = head_copy->next;
    }

    while (reversed_stack.head_ != nullptr) {
      push(reversed_stack.top());
      reversed_stack.pop();
    }
  }
};

}  // namespace s21

#endif  // CONTAINERS_STACK_H_