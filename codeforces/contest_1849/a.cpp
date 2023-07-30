#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y, z;
    cin >> x >> y >> z;
    y += z;
    if (x <= y) {
      cout << 2 * x - 1 << endl;
    } else {
      cout << 2 * y + 1 << endl;
    }
  }
  return 0;
}
