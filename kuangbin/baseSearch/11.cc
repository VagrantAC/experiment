#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> Pair2;

const int maxn = 1e3 + 55;
const int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dis[maxn][maxn];
int a[maxn][maxn];
Pair2 nex[maxn][maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      dis[i][j] = -1;
    }
  }

  queue<Pair2> que;
  que.push(make_pair(0, 0));
  dis[0][0] = -1;

  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int dx = p.first + step[i][0];
      int dy = p.second + step[i][1];
      if (dx >= 0 && dx < n && dy >= 0 && dy < n && dis[dx][dy] == -1 &&
          !a[dx][dy]) {
        que.push(make_pair(dx, dy));
        dis[dx][dy] = dis[p.first][p.second] + 1;
        nex[dx][dy] = p;
      }
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << dis[i][j] << "(" << nex[i][j].first << ", " << nex[i][j].second
  //          << ") ";
  //   }
  //   cout << endl;
  // }

  vector<Pair2> vec;
  Pair2 pos = make_pair(n - 1, n - 1);
  while (pos.first != 0 || pos.second != 0) {
    vec.push_back(pos);
    pos = nex[pos.first][pos.second];
    // cout << pos.first << " " << pos.second << endl;
  }
  cout << "0 0" << endl;

  for (int i = vec.size() - 1; i >= 0; --i) {
    cout << vec[i].first << " " << vec[i].second << endl;
  }
  return 0;
}
