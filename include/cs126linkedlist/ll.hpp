// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

const int kEven = 2;

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head_ = NULL;
  current_ = NULL;
  back_ = NULL;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  head_ = NULL;
  current_ = NULL;
  back_ = NULL;
  if (values.size() != 0) {
    for (ElementType value : values) {
      push_back(value);
    }
  }
}


// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {}

// Move assignment operator->datatrue
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node* n = new Node();
  n->data = value;
  n->next = head_;
  head_ = n;
  if (head_->next == NULL) {
    back_ = head_;
  }
  size_++;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node* n = new Node();
  n->data = value;
  n->next = NULL;
  if (head_ != NULL) {
    current_ = head_;
    while (current_->next != NULL) {
      current_ = current_->next;
    }
    current_->next = n;
    back_ = n;
  } else {
    head_ = n;
    back_ = n;
  }
  size_++;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  return head_->data;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  return back_->data;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  Node* temp;
  if (head_ != NULL) {
    size_--;
    if (head_->next != NULL) {
      temp = head_;
      delete head_;
      head_ = temp->next;
    } else {
      head_ = NULL;
    }
  }
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  Node* temp;
  if (size() == 1) {
    pop_front();
  } else if (size() > 0 && head_ != NULL) {
    current_ = head_;
    while (current_->next != back_) {
      current_ = current_->next;
    }
    delete back_;
    current_->next == NULL;
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

}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
  int i = 0;
  if (n == 0 && head_ != NULL) {
    pop_front();
  } else if (head_ != NULL && size() > n) {
    current_ = head_;
    while (current_->next != NULL) {
      if (i == n - 1) {
        current_ = current_->next->next;
        delete current_->next;
        size_--;
      } else {
        current_ = current_->next;
      }
      i++;
    }
  }
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  if (head_ != NULL && size() > 1) {
    current_ = head_;
    while (current_->next != NULL) {
      if (current_->next->next != NULL) {
        current_ = current_->next->next;
        delete current_->next;
      } else {
        current_->next = NULL;
      }
      size_--;
    }
    back_ = current_;
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
  while (temp_this != NULL && is_equal) {
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
