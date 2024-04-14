#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> Pair2;
const int maxn = 1e3 + 55;

queue<Pair2> que;
string str[maxn];
int dis[maxn][maxn];
int vis[maxn][maxn];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void initTest(int r, int c) {
  while (!que.empty()) {
    que.pop();
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (str[i][j] == 'F') {
        que.push(make_pair(i, j));
        dis[i][j] = 0;
      } else {
        dis[i][j] = -1;
      }
    }
  }
}

void bfsF(int r, int c) {

  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int dx = step[i][0] + p.first;
      int dy = step[i][1] + p.second;
      if (dx >= 0 && dx < r && dy >= 0 && dy < c && str[dx][dy] != '#' &&
          dis[dx][dy] == -1) {
        dis[dx][dy] = dis[p.first][p.second] + 1;
        que.push(make_pair(dx, dy));
      }
    }
  }
}

int solve(int r, int c) {
  while (!que.empty()) {
    que.pop();
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      vis[i][j] = -1;
      if (str[i][j] == 'J') {
        if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
          return 1;
        }
        vis[i][j] = 0;
        que.push(make_pair(i, j));
      }
    }
  }

  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int dx = step[i][0] + p.first;
      int dy = step[i][1] + p.second;
      if (dx >= 0 && dx < r && dy >= 0 && dy < c && str[dx][dy] != '#' &&
          vis[dx][dy] == -1 &&
          (vis[p.first][p.second] + 1 < dis[dx][dy] || dis[dx][dy] == -1)) {
        vis[dx][dy] = vis[p.first][p.second] + 1;
        if (dx == 0 || dy == 0 || dx == r - 1 || dy == c - 1) {
          return vis[dx][dy] + 1;
        }
        que.push(make_pair(dx, dy));
      }
    }
  }
  return -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
      cin >> str[i];
    }
    initTest(r, c);
    bfsF(r, c);
    int res = solve(r, c);
    if (res == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }

  return 0;
}
