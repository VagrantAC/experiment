#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long ll;

set<ll> s, s1, s2;

int main() {
  int t;
  cin >> t;
  while (t--) {
    s.clear();
    s1.clear();
    s2.clear();
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i * i <= m1; i++)
      if (m1 % i == 0) {
        s1.insert(i);
        s1.insert(m1 / i);
      }
    for (int i = 1; i * i <= m2; i++)
      if (m2 % i == 0) {
        s2.insert(i);
        s2.insert(m2 / i);
      }

    for (auto i : s1) {
      for (auto j : s2) {
        s.insert(i * j);
      }
    }

    ll x = 0, y = 0;
    for (auto i : s) {
      for (auto j = s.lower_bound((i + n - 1) / n); j != s.end(); j++) {
        if (*j > n)
          break;
        if (i % *j == 0) {
          x++;
          y ^= *j;
          break;
        }
      }
    }
    cout << x << " " << y << endl;
  }

  return 0;
}
