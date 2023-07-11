#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e6 + 55;
int nums[maxn];
int vecs[maxn];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    while (l <= r && i - vecs[l] >= k) {
      l++;
    }

    while (l <= r && nums[vecs[r]] >= nums[i]) {
      r--;
    }
    vecs[++r] = i;
    if (i + 1 >= k) {
      cout << nums[vecs[l]] << " ";
    }
  }
  cout << endl;

  l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    while (l <= r && i - vecs[l] >= k) {
      l++;
    }

    while (l <= r && nums[vecs[r]] <= nums[i]) {
      r--;
    }
    vecs[++r] = i;
    if (i + 1 >= k) {
      cout << nums[vecs[l]] << " ";
    }
  }
  cout << endl;
  return 0;
}
