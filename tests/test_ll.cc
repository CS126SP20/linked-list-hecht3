// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.

TEST_CASE("Destructor", "[Vec constructor][destructor]") {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(9);
  vec.push_back(10);
  auto *list = new LinkedList(vec);
  delete list;
}

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
    REQUIRE(list.front() == 1);
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
    REQUIRE(list.front() == 8);
  }

  SECTION("Remove last node") {
    list.RemoveNth(2);
    REQUIRE(list.size() == 2);
    REQUIRE((list.back() == 8));
  }

  SECTION("Remove second to last node") {
    list.RemoveNth(1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 0);
    REQUIRE(list.front() == 7);
  }

  SECTION("N out of bounds") {
    list.RemoveNth(8);
    REQUIRE_THROWS(std::out_of_range("Node index out of range"));
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

  //FAILS HERE_____________________________________________________________________
  SECTION("Remove odd on even length list and check size") {
    LinkedList<int> list(vec);
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

TEST_CASE("Clear", "[Vec constructor][size][empty][front][back]") {
  std::vector<int> vec;
  vec.push_back(3);
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(9);
  vec.push_back(10);

  SECTION("Clear and check size") {
    LinkedList<int> list(vec);
    REQUIRE(list.size() == 6);
    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }
}

TEST_CASE("Copy constructor",
          "[Copy constructor][size][front][back][equals operator]") {
  std::vector<int> vec;
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(3);
  vec.push_back(8);
  vec.push_back(4);
  vec.push_back(10);

  SECTION("Copy and check size") {
    LinkedList<int> list1(vec);
    LinkedList<int> list2(list1);
    REQUIRE(list2.size() == 6);
    REQUIRE(list1 == list2);
    REQUIRE(list2.back() == 10);
    REQUIRE(list2.front() == 3);
  }
}

TEST_CASE("Copy assignment operator",
          "[Copy assignment operator][size][front][back][equals operator]") {
  std::vector<int> vec;
  vec.push_back(33);
  vec.push_back(27);
  vec.push_back(15);
  vec.push_back(27);
  vec.push_back(91);
  vec.push_back(100);

  SECTION("Copy empty and check size") {
    LinkedList<int> list1(vec);
    LinkedList<int> list2;
    list2 = list1;
    REQUIRE(list2.size() == 6);
    REQUIRE(list1 == list2);
    REQUIRE(list2.back() == 100);
    REQUIRE(list2.front() == 33);
  }

  SECTION("Copy non-empty and check size") {
    LinkedList<int> list1(vec);
    vec.push_back(5);
    LinkedList<int> list2(vec);
    list2 = list1;
    REQUIRE(list2.size() == 6);
    REQUIRE(list1 == list2);
    REQUIRE(list2.back() == 100);
    REQUIRE(list2.front() == 33);
  }

  SECTION("Copy self and check size") {
    LinkedList<int> list1(vec);
    list1 = list1;
    REQUIRE(list1.size() == 6);
    REQUIRE(list1 == list1);
    REQUIRE(list1.back() == 100);
    REQUIRE(list1.front() == 33);
  }
}

TEST_CASE("Move constructor",
          "[move constructor][size][front][back][empty]") {
  std::vector<int> vec;
  vec.push_back(83);
  vec.push_back(87);
  vec.push_back(85);
  vec.push_back(87);
  vec.push_back(81);
  vec.push_back(108);

  SECTION("Copy and check size") {
    LinkedList<int> list1(vec);
    LinkedList<int> list2 = std::move(list1);
    REQUIRE(list2.size() == 6);
    REQUIRE(list1 != list2);
    REQUIRE(list1.empty());
    REQUIRE(list2.back() == 108);
    REQUIRE(list2.front() == 83);
  }
}

TEST_CASE("Test iterator funcs",
          "[vec constructor][begin][end][size][advance iterator]"
          "[iterator get value]") {
  std::vector<int> vec;
  vec.push_back(83);
  vec.push_back(87);
  vec.push_back(85);
  vec.push_back(87);
  vec.push_back(81);
  vec.push_back(108);

  SECTION("Iterate through incrementing size and checking elements") {
    LinkedList<int> list(vec);
    std::vector<int> vec_check;
    int size = 0;
    for (LinkedList<int>::iterator iterator = list.begin();
         iterator != list.end();
         ++iterator) {
      vec_check.push_back(*iterator);
      size++;
    }
    REQUIRE(list.size() == size);
    REQUIRE(vec_check == vec);
  }

  SECTION("Enhanced for loop iteration for const iterators") {
    LinkedList<int> list(vec);
    std::vector<int> vec_check;
    int size = 0;
    for (int element : list) {
      vec_check.push_back(element);
      size++;
    }
    REQUIRE(list.size() == size);
    REQUIRE(vec_check == vec);
  }
}

TEST_CASE("Test insertion operator", "[vec constructor][insertion operator]") {
  std::vector<int> vec;
  vec.push_back(83);
  vec.push_back(87);
  vec.push_back(85);
  vec.push_back(87);
  vec.push_back(81);
  vec.push_back(108);

  SECTION("Print list of ints") {
    LinkedList<int> list(vec);
    std::cout << list;
  }
  std::cout << '\n';

  std::vector<char> char_vec;
  char_vec.push_back('a');
  char_vec.push_back('b');
  char_vec.push_back('c');
  char_vec.push_back('d');
  char_vec.push_back('e');
  std::string correct = "a, b, c, d, e";
  std::stringstream to_check;
  std::ostream& output = to_check;
  LinkedList<char> char_list(char_vec);
  output << char_list;
  SECTION("Check string equality") {
    REQUIRE(correct == to_check.str());
  }
}

// TODO(you): Add more tests below.
