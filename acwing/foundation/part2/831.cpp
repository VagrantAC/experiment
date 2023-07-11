#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 55;
int nex[maxn] = {0};
void getNext(string &str) {
  int pos = 0;
  for (int i = 1; i < str.length(); i++) {
    while (pos && str[pos] != str[i]) {
      pos = nex[pos - 1];
    }
    if (str[pos] == str[i]) {
      pos++;
    }
    nex[i] = pos;
  }
}

void kmp(string &p, string &s) {
  int pos = 0;
  for (int i = 0; i < s.length(); i++) {
    while (pos && s[i] != p[pos]) {
      pos = nex[pos - 1];
    }
    if (s[i] == p[pos]) {
      pos++;
    }
    if (pos == p.length()) {
      pos = nex[pos - 1];
      cout << i + 1 - p.length() << " ";
    }
  }
  cout << endl;
}

int main() {
  int n, m;
  string p, s;
  cin >> n >> p >> m >> s;
  getNext(p);
  kmp(p, s);
  return 0;
}
