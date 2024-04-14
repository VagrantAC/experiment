#pragma GCC optimize(2)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

unordered_map<int, int> xb;
const int maxn = 10;
struct Matrix {
  int num[3][3];
  int x, y;
  Matrix(string &_st) {
    for (int i = 0; i < _st.length(); ++i) {
      num[i / 3][i % 3] = (_st[i] == 'X') ? 0 : _st[i] - '0';
      if (_st[i] == 'X') {
        x = i / 3;
        y = i % 3;
      }
    }
  }
  bool equal(Matrix &s) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (num[i][j] != s.num[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  int h(Matrix &s) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (num[i][j]) {
          int t = xb[num[i][j]];
          res += abs(i - t / 3) + abs(j - t % 3);
        }
      }
    }
    return res;
  }
};

int step[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
char desc[4] = {'d', 'l', 'r', 'u'};
unordered_map<string, bool> mp;
vector<char> res;
ll mult[9];

bool solve(Matrix &s, Matrix &e, int se) {
  if (s.equal(e)) {
    return true;
  }
  if (se == 0) {
    return false;
  }
  if (s.h(e) > se) {
    return false;
  }
  int x = s.x, y = s.y;
  for (int i = 0; i < 4; ++i) {
    if (res.size()) {
      char ch = res[res.size()-1];
      if (ch == 'd' && i == 3) continue;
      if (ch == 'l' && i == 2) continue;
      if (ch == 'r' && i == 1) continue;
      if (ch == 'u' && i == 0) continue;
    }
    int dx = step[i][0] + x;
    int dy = step[i][1] + y;
    if (dx < 0 || dx > 2 || dy < 0 || dy > 2)
      continue;
    swap(s.num[dx][dy], s.num[x][y]);
    s.x = dx, s.y = dy;
    res.push_back(desc[i]);
    if (solve(s, e, se - 1)) {
      return true;
    }
    res.pop_back();
    swap(s.num[dx][dy], s.num[x][y]);
  }
  return false;
}

inline void init() {
  mult[0] = 1;
  for (int i = 1; i < 9; ++i) {
    mult[i] = mult[i - 1] * 10;
  }
}

int main() {
  init();
  int t, cas = 1;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 9; i++)
      xb[b[i] - '0'] = i;
    for (int i = 0;; ++i) {
      res.clear();
      Matrix s = Matrix(a);
      Matrix t = Matrix(b);
      if (solve(s, t, i)) {
        break;
      }
    }
    cout << "Case " << cas++ << ": " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i];
    }
    cout << endl;
  }
  return 0;
}
#pragma GCC optimize(2)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

unordered_map<int, int> xb;
const int maxn = 10;
struct Matrix {
  int num[3][3];
  int x, y;
  Matrix(string &_st) {
    for (int i = 0; i < _st.length(); ++i) {
      num[i / 3][i % 3] = (_st[i] == 'X') ? 0 : _st[i] - '0';
      if (_st[i] == 'X') {
        x = i / 3;
        y = i % 3;
      }
    }
  }
  bool equal(Matrix &s) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (num[i][j] != s.num[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  int h(Matrix &s) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (num[i][j]) {
          int t = xb[num[i][j]];
          res += abs(i - t / 3) + abs(j - t % 3);
        }
      }
    }
    return res;
  }
};

int step[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
char desc[4] = {'d', 'l', 'r', 'u'};
unordered_map<string, bool> mp;
vector<char> res;
ll mult[9];

bool solve(Matrix &s, Matrix &e, int se) {
  if (s.equal(e)) {
    return true;
  }
  if (se == 0) {
    return false;
  }
  if (s.h(e) > se) {
    return false;
  }
  int x = s.x, y = s.y;
  for (int i = 0; i < 4; ++i) {
    if (res.size()) {
      char ch = res[res.size()-1];
      if (ch == 'd' && i == 3) continue;
      if (ch == 'l' && i == 2) continue;
      if (ch == 'r' && i == 1) continue;
      if (ch == 'u' && i == 0) continue;
    }
    int dx = step[i][0] + x;
    int dy = step[i][1] + y;
    if (dx < 0 || dx > 2 || dy < 0 || dy > 2)
      continue;
    swap(s.num[dx][dy], s.num[x][y]);
    s.x = dx, s.y = dy;
    res.push_back(desc[i]);
    if (solve(s, e, se - 1)) {
      return true;
    }
    res.pop_back();
    swap(s.num[dx][dy], s.num[x][y]);
  }
  return false;
}

inline void init() {
  mult[0] = 1;
  for (int i = 1; i < 9; ++i) {
    mult[i] = mult[i - 1] * 10;
  }
}

int main() {
  init();
  int t, cas = 1;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 9; i++)
      xb[b[i] - '0'] = i;
    for (int i = 0;; ++i) {
      res.clear();
      Matrix s = Matrix(a);
      Matrix t = Matrix(b);
      if (solve(s, t, i)) {
        break;
      }
    }
    cout << "Case " << cas++ << ": " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i];
    }
    cout << endl;
  }
  return 0;
}
