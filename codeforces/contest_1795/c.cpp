#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 55;
ll a[maxn];
ll b[maxn];
ll sum[maxn];
ll ans[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      sum[i] = 0;
      ans[i] = 0;
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
    }

    for (int i = 1; i <= n; i++) {
      int l = i, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (a[i] > (b[mid] - b[i - 1])) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      // cout << l << " " << r << " " << min(b[i] - b[i - 1], a[i] - (b[l - 1] - b[i - 1])) << endl;
      sum[i]++;
      sum[l]--;
      ans[l] += min(b[l] - b[l - 1], a[i] - (b[l - 1] - b[i - 1]));
    }
    // cout << "++++++" << endl;
    for (int i = 1; i <= n; i++) {
      sum[i] += sum[i - 1];
      cout << sum[i] * (b[i] - b[i-1]) + ans[i] << " ";
      // cout << sum[i] << " " << ans[i] << endl;
    }
    cout << endl;
  }
  return 0;
}
