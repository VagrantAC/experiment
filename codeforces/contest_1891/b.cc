#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 55;
ll a[maxn];
ll qpow(ll a, ll b) {
  ll c = 1;
  while (b) {
    if (b & 1)
      c *= a;
    b >>= 1;
    a = a * a;
  }
  return c;
}

vector<ll> c;
int main() {
  int t;
  cin >> t;
  while (t--) {
    c.clear();
    int n, m, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b;
      b = qpow(2, b);
      if (c.size() == 0 || b < c[c.size() - 1]) {
        // cout << b << " | ";
        c.push_back(b);
      }
    }

    // std::cout << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < c.size(); j++) {
        if (a[i] % c[j] == 0) {
          a[i] += (c[j] / 2);
        }
      }
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
