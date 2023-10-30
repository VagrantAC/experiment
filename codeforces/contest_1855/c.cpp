#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
struct Node {
  int a, b;
  Node(int _a, int _b) {
    a = _a;
    b = _b;
  }
};
const int maxn = 25;
int a[maxn];
int b[maxn];

vector<Node> sub(int n) {
  int maxx = a[0];
  int minn = a[0];
  int pos = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
    maxx = max(maxx, b[i]);
    minn = min(minn, b[i]);
    if (minn == b[i]) {
      pos = i;
    }
  }

  vector<Node> res;

  while (maxx > -minn) {
    minn += minn;
    b[pos] = minn;
    res.push_back(Node(pos + 1, pos + 1));
  }

  for (int i = 0; i < n; i++) {
    if (b[i] > 0) {
      res.push_back(Node(i + 1, pos + 1));
      b[i] += minn;
    }
  }

  for (int i = n - 1; i > 0; i--) {
    if (b[i] < b[i - 1]) {
      res.push_back(Node(i, i + 1));
      b[i - 1] += b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return res;
}

vector<Node> add(int n) {
  int maxx = a[0];
  int minn = a[0];
  int pos = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
    maxx = max(maxx, b[i]);
    if (maxx == b[i]) {
      pos = i;
    }
    minn = min(minn, b[i]);
  }

  vector<Node> res;

  while (maxx < -minn) {
    maxx += maxx;
    b[pos] = maxx;
    res.push_back(Node(pos + 1, pos + 1));
  }

  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      res.push_back(Node(i + 1, pos + 1));
      b[i] += maxx;
    }
  }

  for (int i = 1; i < n; i++) {
    if (b[i] < b[i - 1]) {
      res.push_back(Node(i + 1, i));
      b[i] += b[i - 1];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return res;
}
void print(vector<Node> &res) {
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].a << " " << res[i].b << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int maxx = -20, minn = 20;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxx = max(maxx, a[i]);
      minn = min(minn, a[i]);
    }

    if (maxx >= 0 && minn >= 0) {
      cout << n - 1 << endl;
      for (int i = 1; i < n; i++) {
        cout << i + 1 << " " << i << endl;
      }
    } else if (maxx <= 0 && minn <= 0) {
      cout << n - 1 << endl;
      for (int i = n - 2; i >= 0; i--) {
        cout << i + 1 << " " << i + 2 << endl;
      }
    } else {
      auto x1 = add(n);
      auto x2 = sub(n);

      if (x1.size() > x2.size()) {
        print(x2);
      } else {
        print(x1);
      }
    }
  }
}
