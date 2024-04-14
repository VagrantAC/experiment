#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 105;
bool vis[maxn][maxn][maxn * 10];
bool fd[maxn][maxn];
string opers[maxn];
int xs[maxn], vs[maxn], ts[maxn], ys[maxn];
struct Pair3 {
  int x, y, d;
  Pair3(int _x, int _y, int _d) { x = _x, y = _y, d = _d; }
};
const int step[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

queue<Pair3> que;

int solve(int n, int m, int d) {
  que.push(Pair3(0, 0, 0));
  vis[0][0][0] = true;
  while (!que.empty()) {
    Pair3 p = que.front();
    que.pop();
    if (p.x == n && p.y == m) {
      return p.d;
    }
    if (p.d == d)
      break;
    for (int i = 0; i < 5; ++i) {
      int dx = step[i][0] + p.x;
      int dy = step[i][1] + p.y;
      if (dx < 0 || dy < 0 || dx > n || dy > m || vis[dx][dy][p.d + 1]) {
        continue;
      }
      vis[dx][dy][p.d + 1] = true;
      que.push(Pair3(dx, dy, p.d + 1));
    }
  }
  return -1;
}

int main() {
  int n, m, k, d;
  while (cin >> n >> m >> k >> d) {
    while (!que.empty()) {
      que.pop();
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        for (int f = 0; f <= d; ++f) {
          vis[i][j][f] = false;
        }
        fd[i][j] = false;
      }
    }
    string oper;
    int t, v, x, y;
    for (int i = 0; i < k; ++i) {
      cin >> oper >> t >> v >> x >> y;
      fd[x][y] = true;
      opers[i] = oper;
      ts[i] = t;
      vs[i] = v;
      xs[i] = x;
      ys[i] = y;
    }
    for (int p = 0; p < k; ++p) {
      t = ts[p];
      v = vs[p];
      x = xs[p];
      y = ys[p];
      oper = opers[p];
      for (int i = 0; i <= d; ++i) {
        vis[x][y][i] = true;
      }
      for (int i = 0; i <= d; i += t) {
        int dx = x, dy = y;
        int j = i;
        for (int j = 0;; ++j) {
          if (dx < 0 || dy < 0 || dx > n || dy > m ||
              (fd[dx][dy] && !(dx == x && dy == y))) {
            break;
          }
          if (j % v == 0) {
            vis[dx][dy][i + (j / v)] = true;
          }
          switch (oper[0]) {
          case 'N':
            dx -= 1;
            break;
          case 'S':
            dx += 1;
            break;
          case 'W':
            dy -= 1;
            break;
          case 'E':
            dy += 1;
            break;
          }
        }
      }
    }
    int res = solve(n, m, d);
    if (res == -1) {
      cout << "Bad luck!" << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
