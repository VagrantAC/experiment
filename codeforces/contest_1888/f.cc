#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

const int maxn = 2e5 + 55;
int a[maxn];
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::map<int, int> pre, nex;

    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (!pre.count(a[i])) {
        pre[a[i]] = i;
      }
    }

    long long ans = 0, res = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (!nex.count(a[i])) {
        res++;
        nex[a[i]] = i;
      }

      if (pre[a[i]] == i) {
        ans += res;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
