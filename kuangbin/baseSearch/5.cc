#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pair2 {
  string key;
  int val;
  Pair2(string _key, int _val) {
    key = _key;
    val = _val;
  }
};

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    queue<Pair2> q;
    q.push(Pair2("1", 1 % n));
    while (!q.empty()) {
      Pair2 p = q.front();
      // cout << p.key << " " << p.val << " " << n << endl;
      q.pop();
      if (p.val == 0) {
        cout << p.key << endl;
        break;
      }

      q.push(Pair2(p.key + "0", (p.val * 10) % n));
      q.push(Pair2(p.key + "1", (p.val * 10 + 1) % n));
    }
  }
  return 0;
}
