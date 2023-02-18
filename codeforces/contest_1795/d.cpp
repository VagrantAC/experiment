#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll fun(int n) {
  ll ans = 1;
  for (ll i = 1; i <= n; i++) {
    ans = (ans * i) % mod;
  }
  // cout << n << " " << ans << endl;
  return ans;
}

ll qpow(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1)
      ans = (ans * x) % mod;
    x = (x * x) % mod;
    y /= 2;
  }
  return ans;
}
int main() {
  int n, a, b, c;
  cin >> n;
  ll ans = (((fun(n / 3) * qpow(fun(n / 6), mod - 2)) % mod) *
            qpow(fun(n / 6), mod - 2)) %
           mod;
  // cout << ans << endl;
  for (int i = 0; i < n / 3; i++) {
    cin >> a >> b >> c;
    int minn = min(a, min(b, c));
    ans = (ans * ((minn == a) + (minn == b) + (minn == c))) % mod;
  }
  cout << ans << endl;
  return 0;
}
