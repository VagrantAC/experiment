#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 55;
int a[maxn][13];
int b[13];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    map<ll, bool> mp[13];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      ll ans = 0;
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        b[a[i][j]] = j + 1;
      }
      for (int j = 1; j <= m; j++) {
        ans = ans * 10 + b[j];
        mp[j][ans] = true;
        // cout << ans << " ";
      }
      // cout << endl;
    }

    for (int i = 0; i < n; i++) {
      // for (int j = 0; j < m; j++) {
      // b[a[i][j]] = j + 1;
      // }
      ll ans = 0;
      int res = 0;
      for (int j = 0; j < m; j++) {
        // cout << b[j] << " ";
        ans = ans * 10 + a[i][j];
        if (mp[j + 1][ans]) {
          res = j + 1;
        } else {
          break;
        }
      }
      // cout << endl;
      printf("%d ", res);
      // cout << endl;
    }
    printf("\n");
  }
  return 0;
}
