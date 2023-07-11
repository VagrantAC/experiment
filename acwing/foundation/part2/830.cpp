#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n, a;
  stack<int> sta;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    while (!sta.empty() && sta.top() >= a) {
      sta.pop();
    }

    if (sta.empty()) {
      cout << -1 << " ";
    } else {
      cout << sta.top() << " ";
    }
    sta.push(a);
  }
  return 0;
}
