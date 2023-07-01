#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 55;
pair<int, int> nums[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i].first >> nums[i].second;
  }
  sort(nums, nums + n,
       [](pair<int, int> a, pair<int, int> b) { return b.first > a.first; });
  int cnt = 1;
  int r = nums[0].second;
  for (int i = 1; i < n; i++) {
    if (nums[i].first > r) {
      cnt++;
    }
    r = max(r, nums[i].second);
  }
  cout << cnt << endl;
  return 0;
}
