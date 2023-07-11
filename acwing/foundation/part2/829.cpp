#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <class T> class Queue {
private:
  std::vector<T> vec;
  int l;

public:
  Queue();
  void Push(T x);
  void Pop();
  bool Empty();
  int Query();
};
template <class T> Queue<T>::Queue() {
  vec.clear();
  l = 0;
}
template <class T> void Queue<T>::Push(T x) { vec.push_back(x); }
template <class T> void Queue<T>::Pop() { l++; }
template <class T> bool Queue<T>::Empty() { return vec.size() > l; }
template <class T> int Queue<T>::Query() { return vec.at(l); }

int main() {
  int n;
  Queue<int> que;
  std::cin >> n;
  while (n--) {
    std::string str;
    std::cin >> str;
    if (str == "push") {
      int x;
      std::cin >> x;
      que.Push(x);
    } else if (str == "pop") {
      que.Pop();
    } else if (str == "empty") {
      std::cout << (que.Empty() ? "YES" : "NO") << std::endl;
    } else {
      std::cout << que.Query() << std::endl;
    }
  }
  return 0;
}
