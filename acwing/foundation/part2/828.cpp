#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> vec;

public:
  Stack();
  void Push(int x);
  void Pop();
  bool Empty();
  int Query();
};

Stack::Stack() { vec.clear(); }

void Stack::Push(int x) { vec.push_back(x); }

void Stack::Pop() { vec.pop_back(); }

bool Stack::Empty() { return vec.size() == 0; }

int Stack::Query() { return vec[vec.size() - 1]; }

int main() {
  int m, x;
  cin >> m;
  Stack sta;
  while (m--) {
    string str;
    cin >> str;
    switch (str[0]) {
    case 'p':
      if (str[1] == 'u') {
        cin >> x;
        sta.Push(x);
      } else {
        sta.Pop();
      }
      break;
    case 'q':
      cout << sta.Query() << endl;
      break;
    default:
      cout << (sta.Empty() ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
