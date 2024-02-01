#include <algorithm>
#include <iostream>
#include <vector>

void variable_increase() {
  std::vector<int> vec = {1, 2, 3, 4};

  if (const std::vector<int>::iterator itr =
          std::find(vec.begin(), vec.end(), 2);
      itr != vec.end()) {
    *itr = 3;
  }

  if (const std::vector<int>::iterator itr =
          std::find(vec.begin(), vec.end(), 3);
      itr != vec.end()) {
    *itr = 4;
  }

  for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
       ++element) {
    std::cout << *element << std::endl;
  }
}
class Foo {
public:
  int value_a;
  int value_b;
  Foo(int a, int b) : value_a(a), value_b(b) {}
};

void initialization_list1() {
  int arr[3] = {1, 2, 3};
  Foo foo(1, 2);
  std::vector<int> vec = {1, 2, 3, 4, 5};

  std::cout << "arr[0]: " << arr[0] << std::endl;
  std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (std::initializer_list<int>::iterator it = list.begin();
         it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};

void initialization_list2() {
  MagicFoo magicFoo = {1, 2, 3, 4, 5};

  std::cout << "magicFoo: ";
  for (std::vector<int>::iterator it = magicFoo.vec.begin();
       it != magicFoo.vec.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  variable_increase();

  initialization_list1();
  return 0;
}
