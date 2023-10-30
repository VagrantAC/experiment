#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

const int MAXN = 2e5 + 55;
typedef long long ll;

int main() {
  int n, a;
  cin >> n;

  bitset<200000 + 55> dp;
  dp.reset();
  dp[1] = 1;
  ll res = 0;
  ll sum = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    sum += a;
    // cout << dp.to_string() << endl;
    int index = dp._Find_next(i - 1);
    // cout << index << endl;
    if (index != MAXN) {
      res = max(res, sum - index);
    } else {
      break;
    }
    dp = (dp | ((dp >> i) << (i + a)));
  }
  cout << res << endl;
  return 0;
}
