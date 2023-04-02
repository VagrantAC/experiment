#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (k > ans) {
        if (k >= ans + i) {
          ans += i;
          cout << i * 2 << " ";
        } else {
          cout << -1 * (i + k - ans) * (i - k + ans - 1) - 1 << " ";
          ans = k;
        }
      } else {
        cout << -1000 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}