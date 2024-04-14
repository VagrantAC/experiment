#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
const int maxn = 18;
int a[maxn][maxn];
int tmp[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];

void cp(int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = tmp[i][j];
      b[i][j] = 0;
    }
  }
}

void change(int x, int y, int m, int n) {
  b[x][y] = 1;
  static int step[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int i = 0; i < 5; ++i) {
    int dx = x + step[i][0];
    int dy = y + step[i][1];
    if (dx >= 0 && dy >= 0 && dx < m && dy < n) {
      a[dx][dy] = !a[dx][dy];
    }
  }
}

int solve(int val, int m, int n) {
  cp(m, n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if ((val >> i) & 1) {
      change(0, i, m, n);
      res++;
    }
  }
  for (int i = 0; i < m - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j]) {
        change(i + 1, j, m, n);
        res++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[m - 1][i]) {
      return -1;
    }
  }

  return res;
}

int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> tmp[i][j];
    }
  }
  int res = -1;
  for (int i = 0; i < (1 << n); ++i) {
    int s = solve(i, m, n);
    if (s == -1) {
      continue;
    }
    if (res == -1) {
      res = s;
      swap(b, c);

    } else if (res > s) {
      res = s;
      swap(b, c);
    }
  }
  // cout << res << endl;
  if (res == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << c[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
