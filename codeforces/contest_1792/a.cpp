#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, res = 0;
    cin >> n;
    int a1 = 0;
    for (int i = 0; i < n; i ++) {
      cin >> x;
      if (x > 1) {
        res ++;
      } else {
        a1 ++;
      }
    }

    res += (a1 + 1) / 2;
    cout << res << endl;
  }
  return 0;
}
