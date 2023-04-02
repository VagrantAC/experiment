#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 3e5 + 55;
char str[maxn];
int one[maxn];
typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      if (str[i] == '1') {
        one[i] = 1;
      } else {
        one[i] = 0;
      }
      if (i) {
        one[i] += one[i - 1];
      }
    }

    ll minn = min(one[len - 1], len - one[len - 1]) * 1000000000001ll;
    int zore = 0;
    for (int i = len - 1; i > 0; i--) {
      if (str[i] == '0') {
        zore++;
      }
      ll res = zore + one[i - 1];
      res = res * 1000000000001ll;
      minn = min(res, minn);
    }

    zore = 0;
    for (int i = len - 1; i > 0; i--) {
      // 1 0 1
      if (str[i] == '0') {
        if (i + 1 == len || str[i + 1] == '1') {
          if (str[i - 1] == '1') {
            ll res = (zore + one[i - 1]) * 1000000000001ll - 1;
            minn = min(res, minn);
          }
        }
        zore++;
      }
    }
    printf("%lld\n", minn);
  }
  return 0;
}
