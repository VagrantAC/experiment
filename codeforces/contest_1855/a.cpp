#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 55;
int p[MAXN];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      if (p[i] == i + 1) {
        cnt++;
      }
    }
    cout << cnt / 2 << endl;
  }
  return 0;
}
