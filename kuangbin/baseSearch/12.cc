#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> Pair2;
const int maxn = 105;
const int step[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
string str[maxn];
bool vis[maxn][maxn];

void bfs(int x, int y, int n, int m) {
  queue<Pair2> que;
  que.push(make_pair(x, y));
  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();
    for (int i = 0; i < 8; ++i) {
      int dx = step[i][0] + p.first;
      int dy = step[i][1] + p.second;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] &&
          str[dx][dy] == '@') {
        vis[dx][dy] = true;
        que.push(make_pair(dx, dy));
      }
    }
  }
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }

    for (int i = 0; i < n; ++i) {
      cin >> str[i];
      for (int j = 0; j < m; ++j) {
        vis[i][j] = false;
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (str[i][j] == '@' && !vis[i][j]) {
          bfs(i, j, n, m);
          res++;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
