#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<ll, int> Pair2;
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char desc[4] = {'l', 'r', 'u', 'd'};
unordered_map<ll, char> mp;
unordered_map<ll, ll> nex;
ll mult[9];
queue<Pair2> que;

void init() {
  ll val = 1;
  for (int i = 0; i < 9; ++i) {
    mult[i] = val;
    val *= 10;
  }
}

int getVal(ll a, int b) {
  while (b--) {
    a /= 10;
  }
  return a % 10;
}

void solve(Pair2 &p) {
  for (int i = 0; i < 4; ++i) {
    int dx = step[i][0] + (p.second) / 3;
    int dy = step[i][1] + (p.second) % 3;
    if (dx < 0 || dx > 2 || dy < 0 || dy > 2)
      continue;
    int s = dx * 3 + dy;
    Pair2 q;
    q.second = s;
    int val = getVal(p.first, s);
    q.first = p.first - val * mult[q.second] + val * mult[p.second];
    if (!mp.count(q.first)) {
      // cout << p.second << " -----> " << q.second << endl;
      // debug(p.first, q.first);
      mp[q.first] = desc[i];
      nex[q.first] = p.first;
      que.push(q);
    }
  }
}

int main() {
  init();
  Pair2 a = make_pair(0, 0);
  string str;
  for (int i = 0; i < 9; ++i) {
    cin >> str;
    if (str[0] == 'x') {
      a.first = a.first * 10 + 0;
      a.second = 8 - i;
    } else {
      a.first = a.first * 10 + str[0] - '0';
    }
  }
  que.push(a);
  mp[a.first] = -1;
  ll tar = 123456780ll;
  while (!que.empty()) {
    Pair2 p = que.front();
    if (p.first == tar)
      break;
    que.pop();
    solve(p);
  }
  if (!mp.count(tar)) {
    cout << "unsolvable" << endl;
    return 0;
  }
  str = "";
  while (tar != a.first) {
    str += mp[tar];
    // cout << mp[tar] << endl;
    // debug(nex[tar], tar);
    // cout << mp[tar] << " " << str << endl;
    tar = nex[tar];
  }
  reverse(str.begin(), str.end());
  // str.reserve();
  // cout << mp.count(123456780ll) << endl;
  // cout << str.length() << endl;
  // cout << "ullddrurdllurdruldr" << endl;
  cout << str << endl;
  return 0;
}
