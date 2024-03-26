#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int maxn = 105;
string str[maxn][maxn];
bool vis[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];
int step[6][3] = {{0, 0, 1},  {0, 0, -1}, {0, 1, 0},
                  {0, -1, 0}, {1, 0, 0},  {-1, 0, 0}};

struct Pair3 {
  int x, y, z;
  Pair3(int _x, int _y, int _z) {
    x = _x;
    y = _y;
    z = _z;
  }
};

int main() {
  int l, r, c;
  while (cin >> l >> r >> c) {
    if (l == 0 && r == 0 && c == 0) {
      break;
    }
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
          vis[i][j][k] = false;
          dis[i][j][k] = 0;
        }
      }
    }

    queue<Pair3> que;
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        cin >> str[i][j];
        for (int k = 0; k < c; ++k) {
          if (str[i][j][k] == 'S') {
            que.push(Pair3(i, j, k));
            vis[i][j][k] = true;
          } else if (str[i][j][k] == '#') {
            vis[i][j][k] = true;
          }
        }
      }
    }

    while (!que.empty()) {
      Pair3 p = que.front();
      que.pop();
      for (int i = 0; i < 6; ++i) {
        int x = p.x + step[i][0];
        int y = p.y + step[i][1];
        int z = p.z + step[i][2];
        if (x >= 0 && x < l && y >= 0 && y < r && z >= 0 && z < c &&
            !vis[x][y][z]) {
          dis[x][y][z] = dis[p.x][p.y][p.z] + 1;
          vis[x][y][z] = true;
          que.push(Pair3(x, y, z));
        }
      }
    }
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
          if (str[i][j][k] == 'E') {
            if (vis[i][j][k]) {
              cout << "Escaped in " << dis[i][j][k] << " minute(s)." << endl;
            } else {
              cout << "Trapped!" << endl;
            }
          }
        }
      }
    }
  }
  return 0;
}
