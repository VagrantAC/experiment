#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll getSum(ll b, ll a) {
  ll res = 0;
  while (a) {
    a /= b;
    res++;
  }
  return res;
}

ll qpow(ll a, ll b, ll mod) {
  ll res = 1;
  a = (a % mod);
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}

ll solveg(ll f, ll l, ll r) {
  ll sum = 0;
  ll n = getSum(f, r);
  ll minn = l;

  cout << " f:" << f << " " << l << " " << r << " " << n << endl;
  for (ll i = getSum(f, l) - 1; i < n; i++) {
    ll maxx = min(qpow(f, i + 1, mod), r + 1);
    sum += (((maxx - minn + mod)) % mod) * i;
    sum %= mod;
    minn = maxx;
  }
  cout << "solveg" << sum << endl;
  return sum;
}

ll solvef(ll ans) {
  ll sum = 0;
  ll n = getSum(2, ans);
  ll minn = 4;
  // std::cout << "n" << n << " " << ans << endl;
  for (ll i = 2; i < n; i++) {
    ll maxx = min(qpow(2, i + 1, mod), ans + 1);
    sum += (solveg(i, minn, maxx - 1));
    sum = (sum % mod + mod) % mod;
    minn = maxx;
  }
  std::cout << sum << endl;
  return sum;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    ll res = (solvef(r) - solvef(l-1) + mod) % mod;
    cout << res << endl;
  }
  return 0;
}
