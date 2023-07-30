#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int k, v;
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<Node> vec;
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> x;
      x %= k;
      if (x == 0) {
        x = k;
      }
      vec.push_back({i, x});
    }
    sort(vec.begin(), vec.end(), [](Node &x, Node &y) {
      if (x.v == y.v) {
        return x.k < y.k;
      }
      return x.v > y.v;
    });

    for (int i = 0; i < n; i++) {
      cout << vec[i].k + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
