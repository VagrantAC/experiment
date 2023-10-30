#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 55;

ll a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    sum = (sum + 1) / 2;
    ll res = sum;
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
      tmp += a[i];
      if (tmp > res) {
        res += n - i;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
