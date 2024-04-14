#pragma GCC optimize(2)
#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> Pair2;
const int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int maxn = 205;
string str[maxn];
int dis[2][maxn][maxn];

inline void getDist(int x, int y, int n, int m, int pos) {
  queue<Pair2> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dis[pos][i][j] = -1;
    }
  }
  dis[pos][x][y] = 0;
  que.push(make_pair(x, y));

  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      int dx = step[i][0] + p.first;
      int dy = step[i][1] + p.second;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && str[dx][dy] != '#' &&
          dis[pos][dx][dy] == -1) {
        dis[pos][dx][dy] = dis[pos][p.first][p.second] + 1;
        que.push(make_pair(dx, dy));
      }
    }
  }
}

int main() {
  int n, m;
  cin.tie(0);
  ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> str[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (str[i][j] == 'Y')
          getDist(i, j, n, m, 0);
        if (str[i][j] == 'M')
          getDist(i, j, n, m, 1);
      }
    }
    int res = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (str[i][j] != '@')
          continue;
        if (dis[0][i][j] == -1 || dis[1][i][j] == -1)
          continue;
        int ans = dis[0][i][j] + dis[1][i][j];
        if (res == -1) {
          res = ans;
        } else {
          res = min(res, ans);
        }
      }
    }
    cout << res * 11 << endl;
  }
}
