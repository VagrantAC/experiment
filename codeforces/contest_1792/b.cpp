#include <iostream>
using namespace std;
  
int main() {
  int t;
  int a[4];
  cin >> t;
  while (t --) {
    for (int i = 0; i < 4; i ++) {
      cin >> a[i];
    }
    if (a[0]) {
      int res = min(a[1], a[2]);
      a[1] -= res;
      a[2] -= res;
      res *= 2;
      res += a[0];
      res += min(a[0]+1, a[1]+a[2]+a[3]);
      cout << res << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
