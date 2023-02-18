#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 55;
int l[maxn], r[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }

    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (l[i] == r[i] && l[i] == m) {
        flag = true;
        break;
      }
      for (int j = 0; j < i; j++) {

        if (r[i] == l[j] && r[i] == m) {
          flag = true;
        }
        if (l[i] == r[j] && l[i] == m) {
          flag = true;
        }
      }
    }

    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
