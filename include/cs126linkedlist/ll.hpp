// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head_ = NULL;
  current_ = NULL;
  temp_ = NULL;
  back_ = NULL;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  head_ = NULL;
  current_ = NULL;
  temp_ = NULL;
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

// Move assignment operator->data
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node* n = new Node();
  n->data = value;
  n->next = head_;
  head_ = n;
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
  size_--;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  size_--;
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
void LinkedList<ElementType>::clear() {}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
  size_--;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  size_--;
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs,
                const LinkedList<ElementType>& rhs) {}

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
