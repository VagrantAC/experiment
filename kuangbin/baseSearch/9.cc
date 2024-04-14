#pragma GCC optimize(2)

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pair2;

const int maxn = 15;
string str[maxn];
int dis[maxn][maxn];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline int solve(pair2 &s, pair2 &e, int n, int m, int cnt) {
  queue<pair2> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dis[i][j] = -1;
    }
  }
  que.push(s);
  dis[s.first][s.second] = 0;
  cnt--;

  if (s.first != e.first || s.second != e.second) {
    que.push(e);
    dis[e.first][e.second] = 0;
    cnt -= 1;
  }
  int maxx = 0;
  while (!que.empty()) {
    if (cnt == 0) {
      return maxx;
    }
    pair2 p = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int dx = p.first + step[i][0];
      int dy = p.second + step[i][1];
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && str[dx][dy] == '#' &&
          dis[dx][dy] == -1) {
        dis[dx][dy] = dis[p.first][p.second] + 1;
        maxx = dis[dx][dy];
        cnt--;
        que.push({dx, dy});
      }
    }
  }
  return -1;
}

int main() {
  int t, cas = 1;
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> str[i];
      for (int j = 0; j < m; ++j) {
        cnt += (str[i][j] == '#');
      }
    }
    int res = -1;
    for (int sx = 0; sx < n; ++sx) {
      for (int sy = 0; sy < m; ++sy) {
        if (str[sx][sy] == '#') {
          auto s = make_pair(sx, sy);
          for (int ex = 0; ex < n; ++ex) {
            for (int ey = 0; ey < m; ++ey) {
              if (str[ex][ey] == '#') {
                auto e = make_pair(ex, ey);
                int ans = solve(s, e, n, m, cnt);
                if (ans == -1)
                  continue;
                if (res == -1) {
                  res = ans;
                }
                res = min(res, ans);
              }
            }
          }
        }
      }
    }
    cout << "Case " << cas++ << ": " << res << endl;
  }
  return 0;
}
