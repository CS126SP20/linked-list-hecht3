// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Push Back", "[constructor][push_back][size][empty]") {
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

TEST_CASE("LL from vector", "[constructor][size][empty]") {
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
  SECTION("Other element type") {
    REQUIRE(char_vec.size() == 3);
    REQUIRE(!char_vec.empty());
  }
}

// TODO(you): Add more tests below.
