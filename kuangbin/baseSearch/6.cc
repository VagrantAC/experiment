#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e5 + 55;

bool vis[maxn] = {false};
std::vector<int> primes;

void initPrimes(int n = 10000) {
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      primes.push_back(i);
    }
    for (int prime : primes) {
      if (i * prime > n)
        break;
      vis[i * prime] = true;
      if (i % prime == 0) {
        break;
      }
    }
  }
}

int getNums(int n, int pos, int val) {
  int ans = 0;
  for (int i = 0, j = 1; n; ++i, n /= 10, j *= 10) {
    if (i != pos) {
      ans += (n % 10) * j;
    } else {
      ans += val * j;
    }
  }
  return ans;
}

int getLen(int n) {
  int res = 0;
  while (n) {
    n /= 10;
    res++;
  }
  return res;
}

vector<int> vecs[maxn];
void init() {
  initPrimes();
  for (auto prime : primes) {
    for (int i = 0; i < getLen(prime); ++i) {
      for (int j = 0; j < 10; ++j) {
        int num = getNums(prime, i, j);
        if (!vis[num]) {
          vecs[prime].push_back(num);
        }
      }
    }
  }
}
int dis[maxn];

int main() {
  int t;
  init();
  cin >> t;
  while (t--) {
    for (int i = 0; i < 10000; ++i) {
      dis[i] = -1;
    }
    int a, b;
    cin >> a >> b;

    std::queue<int> que;
    que.push(a);
    dis[a] = 0;
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      for (int num : vecs[p]) {
        if (dis[num] == -1) {
          // cout << num << " " << p << endl;
          dis[num] = dis[p] + 1;
          que.push(num);
        }
      }
    }

    if (dis[b] == -1) {
      cout << "Impossible" << endl;
    } else {
      cout << dis[b] << endl;
    }
  }
  return 0;
}
