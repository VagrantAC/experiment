#include <iostream>
#include <queue>
using namespace std;
const int maxn = 105;
int dis[maxn][maxn];
string str[maxn][maxn];

struct Pair2 {
  int a, b;
  Pair2(int _a, int _b) {
    a = _a;
    b = _b;
  }
};

queue<Pair2> que;
void push(int da, int db, Pair2 &p, string s) {
  if (dis[da][db] == -1) {
    que.push(Pair2(da, db));
    dis[da][db] = dis[p.a][p.b] + 1;
    str[da][db] = str[p.a][p.b] + "\n" + s;
  }
};

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      dis[i][j] = -1;
    }
  }
  while (!que.empty()) {
    que.pop();
  }

  que.push(Pair2(0, 0));
  dis[0][0] = 0;

  while (!que.empty()) {
    Pair2 p = que.front();
    que.pop();
    push(p.a, 0, p, "DROP(2)");
    push(0, p.b, p, "DROP(1)");
    push(p.a, b, p, "FILL(2)");
    push(a, p.b, p, "FILL(1)");

    int da, db;
    if (p.a + p.b >= b) {
      da = p.a + p.b - b;
      db = b;
    } else {
      da = 0;
      db = p.a + p.b;
    }
    push(da, db, p, "POUR(1,2)");

    if (p.a + p.b >= a) {
      db = p.a + p.b - a;
      da = a;
    } else {
      da = p.a + p.b;
      db = 0;
    }
    push(da, db, p, "POUR(2,1)");
  }

  int minn = -1;
  string res = "";
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      if (i == c || j == c) {
        if (dis[i][j] != -1) {
          if (minn == -1 || (minn != -1 && dis[i][j] < minn)) {
            minn = dis[i][j];
            res = str[i][j];
          }
        }
      }
    }
  }
  if (minn == -1) {
    cout << "impossible" << endl;
    return 0;
  }
  cout << minn << res << endl;
  return 0;
}
