// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Equality operator", "[Vec constructor][pop_back]") {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(9);
  vec.push_back(10);

  SECTION("Ensure equality on identical lists") {
    LinkedList<int> list1(vec);
    LinkedList<int> list2(vec);
    REQUIRE(list1 == list2);
  }

  SECTION("Ensure equality on empty lists") {
    vec.clear();
    LinkedList<int> list1(vec);
    LinkedList<int> list2(vec);
    REQUIRE(list1 == list2);
  }

  SECTION("Ensure inequality on differing lists of same size") {
    vec.push_back(6);
    LinkedList<int> list1(vec);
    vec.pop_back();
    vec.push_back(5);
    LinkedList<int> list2(vec);
    REQUIRE(!(list1 == list2));
  }
}

TEST_CASE("Inequality operator", "[Vec constructor]") {
  std::vector<int> vec;

  SECTION("Ensure inequality on differing lists") {
    vec.push_back(0);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(9);
    vec.push_back(10);
    LinkedList<int> list1(vec);

    vec.clear();
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(9);
    vec.push_back(10);
    LinkedList<int> list2(vec);
    REQUIRE(list1 != list2);
  }

  SECTION("Ensure inequality on empty list and non-empty list") {
    LinkedList<int> list1(vec);
    vec.push_back(1);
    LinkedList<int> list2(vec);
    REQUIRE(list1 != list2);
  }
}

TEST_CASE("Push Back", "[default constructor][push_back][size][empty]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push back one element") {
    list.push_back(1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 1);
  }

  SECTION("Push back two elements") {
    list.push_back(-1);
    list.push_back(10000);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 10000);
  }
}

TEST_CASE("LL from vector", "[Vec constructor][size][empty]") {
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(2);
  vec.push_back(3);
  LinkedList<int> list(vec);

  SECTION("Check size") {
    REQUIRE(list.size() == 3);
    REQUIRE(!list.empty());
  }

  vec.clear();
  LinkedList<int> empty_list(vec);

  SECTION("Empty vector") {
    REQUIRE(empty_list.size() == 0);
    REQUIRE(empty_list.empty());
  }

  std::vector<char> char_vec;
  char_vec.push_back('a');
  char_vec.push_back('b');
  char_vec.push_back('c');
  LinkedList<char> char_list(char_vec);
  SECTION("Other element type") {
    REQUIRE(char_list.size() == 3);
    REQUIRE(!char_list.empty());
  }
}

TEST_CASE("Push front",
          "[Vec constructor][push_front][size][empty][front][back][equality]") {
  std::vector<int> vec;
  vec.push_back(4);
  vec.push_back(1);
  vec.push_back(5);
  LinkedList<int> list(vec);

  SECTION("Check size") {
    REQUIRE(list.size() == 3);
    REQUIRE(!list.empty());
  }

  SECTION("Push front 2 elements") {
    list.push_front(7);
    REQUIRE(list.front() == 7);
    list.push_front(8);
    vec.clear();
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(5);
    LinkedList<int> list_actual(vec);
    REQUIRE(list.front() == 8);
    REQUIRE(list.size() == 5);
    REQUIRE(list == list_actual);
  }

  std::vector<double> empty_vec;
  LinkedList<double> empty_list(empty_vec);
  SECTION("Push front on empty vector") {
    empty_list.push_front(7);
    REQUIRE(empty_list.front() == 7);
    empty_list.push_front(8);
    REQUIRE(empty_list.front() == 8);
    REQUIRE(empty_list.size() == 2);
    REQUIRE(empty_list.back() == 7);
  }
}

TEST_CASE("Pop front",
          "[Vec constructor][size]"
          "[empty][front][back][pop_front]") {
  std::vector<int> vec;
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(0);
  LinkedList<int> list(vec);

  SECTION("Pop front and empty list") {
    list.pop_front();
    REQUIRE(list.front() == 8);
    REQUIRE(list.size() == 2);
    list.pop_front();
    REQUIRE(list.size() == 1);
    list.pop_front();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    // Attempt to pop front on empty list
    list.pop_front();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }
}

TEST_CASE("Remove Nth node", "[Vec constructor][size][empty]") {
  std::vector<int> vec;
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(0);
  LinkedList<int> list(vec);

  SECTION("Remove 0th node") {
    list.RemoveNth(0);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() ==
            8);/////////////////Add more tests here once a method is completed for getting Nth node and fix the current->next->next issue
  }
}

TEST_CASE("Pop back",
          "[Vec constructor][size][empty][front][back][pop_front][pop_back]") {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(7);
  vec.push_back(1);
  LinkedList<int> list(vec);

  SECTION("Pop back and empty list") {
    list.pop_back();
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 7);
    list.pop_back();
    REQUIRE(list.size() == 1);
    list.pop_front();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    // Attempt to pop front on empty list
    list.pop_back();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }
}

TEST_CASE("Remove odd", "[Vec constructor][size][empty][front][back]") {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(9);
  vec.push_back(10);

  SECTION("Remove odd on even length list and check size") {
    LinkedList<int> list(vec);
    REQUIRE(list.size() == 6);
    list.RemoveOdd();
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() == 9);
    REQUIRE(list.front() == 0);
    REQUIRE(!list.empty());
  }

  vec.clear();
  vec.push_back(0);
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(9);

  SECTION("Remove odd on odd length list and check size") {
    LinkedList<int> list(vec);
    REQUIRE(list.size() == 5);
    list.RemoveOdd();
    REQUIRE(list.size() == 3);
    REQUIRE(list.back() == 9);
    REQUIRE(list.front() == 0);
    REQUIRE(!list.empty());
  }
}

// TODO(you): Add more tests below.
