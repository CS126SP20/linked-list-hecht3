// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>
#include <stdexcept>

// TODO(you): Implement these methods.

namespace cs126linkedlist {
  
const int kEven = 2;

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head_ = nullptr;
  current_ = nullptr;
  back_ = nullptr;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  head_ = nullptr;
  current_ = nullptr;
  back_ = nullptr;
  if (values.size() != 0) {
    for (ElementType value : values) {
      push_back(value);
    }
  }
}


// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
  Node* n = source.head_;
  while(n != nullptr) {
    push_back(n->data);
    n = n->next;
  }
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
  Node* n = source.head_;
  while(n != nullptr) {
    push_back(n->data);
    n = n->next;
  }
  source.clear();
}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
  Node* ptr = head_;
  while(ptr) {
    Node* temp = ptr->next;
    delete ptr;
    ptr = temp;
  }
  head_ = nullptr;
  back_ = nullptr;
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
  clear();
  Node* n = source.head_;
  while(n != nullptr) {
    push_back(n);
    n = n->next;
  }
}

// Move assignment operator->datatrue
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node* n = new Node(value, head_);
  head_ = n;
  if (head_->next == nullptr) {
    back_ = head_;
  }
  size_++;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node* n = new Node(value, nullptr);
  if (head_ != nullptr && back_ != nullptr) {
    back_->next = n;
    back_ = n;
  } else {
    head_ = n;
    back_ = n;
  }
  size_++;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  if (head_) {
    return head_->data;
  } else {
    throw std::out_of_range("List is empty");
  }
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  if (head_) {
    return back_->data;
  } else {
    throw std::out_of_range("List is empty");
  }
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  Node* temp;
  if (head_ != nullptr) {
    size_--;
    if (head_->next != nullptr) {
      temp = head_;
      delete head_;
      head_ = temp->next;
    } else {
      head_ = nullptr;
    }
  }
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  if (size() == 1) {
    pop_front();
  } else if (size() > 0 && head_ != nullptr) {
    current_ = head_;
    while (current_->next != back_) {
      current_ = current_->next;
    }
    current_->next == nullptr;
    back_ = current_;
    size_--;
  }
}

template <typename ElementType>
int LinkedList<ElementType>::size() const {
  return size_;
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
  return size_ == 0;
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {
  Node* temp;
  current_ = head_;
  while (current_ != nullptr) {
    temp = current_;
    delete current_;
    current_ = temp->next;
  }
  head_ = nullptr;
  back_ = nullptr;
  size_ = 0;
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
  int i = 0;
  if (n == 0 && head_ != nullptr) {
    pop_front();
  } else if (n == size() - 1) {
    pop_back();
  } else if (head_ != nullptr && size() > n) {
    current_ = head_;
    while (current_->next != nullptr) {
      if (i == n - 1 && current_->next->next) {
        current_ = current_->next->next;
        delete current_->next;
        size_--;
      } else {
        current_ = current_->next;
      }
      i++;
    }
  } else if (size() <= n) {
    throw std::out_of_range("Node index out of range");
  }
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  if (head_ != nullptr && size_ > 1) {
    Node* ptr = head_->next;

  }
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {
  if (rhs.size() == 0 && size() == 0) {
    return true;
  }
  bool is_equal = (rhs.size() == size());
  Node* temp_this;
  Node* temp_rhs;
  temp_this = head_;
  temp_rhs = rhs.head_;
  while (temp_this != nullptr && is_equal) {
    if (temp_this->data != temp_rhs->data) {
      is_equal = false;
    } else {
      temp_this = temp_this->next;
      temp_rhs = temp_rhs->next;
    }
  }
  return is_equal;
}

template <typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs,
                const LinkedList<ElementType>& rhs) {
  return !(lhs == rhs);
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const LinkedList<ElementType>::iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const LinkedList<ElementType>::const_iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {}


}  // namespace cs126linkedlist
