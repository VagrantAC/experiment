#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    char ch = s[0];
    int ans = 0;
    for (int i = 1; i < n + m; i++) {
      char pos;
      if (i < n) {
        pos = s[i];
      } else {
        pos = t[n + m - i - 1];
      }
      if (pos == ch) {
        ans++;
      }
      ch = pos;
    }
    if (ans > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
