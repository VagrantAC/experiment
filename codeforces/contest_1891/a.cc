#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 25;
int a[maxn];

bool isTwo(int a) {
  while (a % 2 == 0) {
    a /= 2;
  }
  return a == 1 || a == 0;
  }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = 1;
    while (m * 2 <= n) {
      m *= 2;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = true;
    int l = 1, r = 2;
    for (int i = 2; i <= n; i++) {
      if (isTwo(i - 1))
        continue;
      // std::cout << i << " " << i - 1 << std::endl;
      if (a[i] < a[i - 1]) {
        flag = false;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
