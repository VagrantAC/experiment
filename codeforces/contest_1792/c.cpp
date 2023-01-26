#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int maxn = 2e5 + 55;
int a[maxn];
int b[maxn];
map<int, int> mp;
bool vis[maxn];

bool check(int n, int pos) {
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < pos; i++) {
    vis[mp[b[i]]] = true;
    vis[mp[b[n - i - 1]]] = true;
  }
  int pre = -1;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (a[i] > pre) {
        pre = a[i];
      } else {
        return false;
      }
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
      mp[a[i]] = i;
    }
    sort(b, b + n);

    int l = 0, r = n / 2;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (!check(n, mid)) {
        l = mid + 1;
      } else {
        r = mid;
      }
      // cout << l << " " << r << endl;
    }
    // cout << ">>>>>>> " << r << endl;
    cout << r << endl;
  }
  return 0;
}
