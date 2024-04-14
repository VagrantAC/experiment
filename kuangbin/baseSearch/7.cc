#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, bool> vis;

string merge(string s, int n) {
  string str = "";
  for (int i = 0; i < n; ++i) {
    str += s[i + n];
    str += s[i];
  }
  return str;
}

int main() {
  int t, n;
  string a, b, c;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cin >> a >> b;
    cin >> c;

    int res = 1;
    vis.clear();
    string s = merge(a + b, n);
    vis[s] = true;

    while (s != c) {
      s = merge(s, n);
      if (vis.count(s)) {
        break;
      }
      vis[s] = true;
      res++;
    }

    cout << i + 1 << " ";
    if (vis.count(c)) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
