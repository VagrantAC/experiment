#include <iostream>
#include <queue>

using namespace std;
const int maxn = 2e5 + 55;
bool vis[maxn] = {false};
int dis[maxn];

bool check(int pos) {
  if (pos < 0) {
    return false;
  }
  if (pos > 200000) {
    return false;
  }
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> que;

  que.push(n);
  vis[n] = true;
  dis[n] = 0;

  while (!que.empty()) {
    int pos = que.front();
    que.pop();

    if (check(pos - 1) && !vis[pos - 1]) {
      que.push(pos - 1);
      vis[pos - 1] = true;
      dis[pos - 1] = dis[pos] + 1;
    }

    if (check(pos + 1) && !vis[pos + 1]) {
      que.push(pos + 1);
      vis[pos + 1] = true;
      dis[pos + 1] = dis[pos] + 1;
    }

    if (check(pos * 2) && !vis[pos * 2]) {
      que.push(pos * 2);
      vis[pos * 2] = true;
      dis[pos * 2] = dis[pos] + 1;
    }
  }

  cout << dis[k] << endl;

  return 0;
}
