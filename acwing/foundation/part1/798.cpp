#include <iostream>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      b[i][j] = 0;
    }
  }

  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    x1--, y1--;
    x2--, y2--;
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      b[i][j] += b[i][j - 1];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i][j] += b[i - 1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] + b[i][j] << " ";
    }
    cout << endl;
  }
}
