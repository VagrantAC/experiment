#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> Pair2;

const int maxn = 105;
int dis[maxn][maxn];

queue<Pair2> que;

void push(int n, int m, Pair2 &p) {
  if (dis[n][m] != -1) {
    return;
  }
  que.push(make_pair(n, m));
  dis[n][m] = dis[p.first][p.second] + 1;
}

int main() {
  int s, n, m;
  while (cin >> s >> n >> m) {
    if (s == 0 && n == 0 && m == 0) {
      break;
    }

    while (!que.empty()) {
      que.pop();
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        dis[i][j] = -1;
      }
    }
    que.push(make_pair(0, 0));
    dis[0][0] = 0;

    int dn, dm;
    while (!que.empty()) {
      Pair2 p = que.front();
      que.pop();

      // s --> n
      push(p.first + min(n - p.first, s - p.first - p.second), p.second, p);

      // s --> m
      push(p.first, p.second + min(m - p.second, s - p.first - p.second), p);

      // n --> m
      dm = min(p.first, m - p.second);
      push(p.first - dm, p.second + dm, p);

      // m --> n
      dm = min(n - p.first, p.second);
      push(p.first + dm, p.second - dm, p);
      // n --> s
      push(0, p.second, p);
      // m --> s
      push(p.first, 0, p);
    }
    int res = -1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (dis[i][j] == -1 || s & 1)
          continue;
        if (i != s / 2 && i)
          continue;
        if (j != s / 2 && j)
          continue;
        if (i == 0 && j == 0)
          continue;
        // cout << i << " " << j << endl;
        if (res == -1) {
          res = dis[i][j];
        } else {
          res = min(res, dis[i][j]);
        }
      }
    }
    if (res == -1) {
      cout << "NO" << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
