#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    for (int i = 1; i <= max(n, 10000ll); i++) {
      if (n % i != 0) {
        cout << i - 1 << endl;
        break;
      }
    }
  }
  return 0;
}
