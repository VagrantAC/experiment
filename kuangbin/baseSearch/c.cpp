#include <iostream>
#include <map>
#include <queue>
#include <utility>

typedef std::pair<int, int> Pair;

int main() {
  int n, k;
  int mp[200000 + 55] = {0};
  int tot = 0;
  while (std::cin >> n >> k) {
    tot++;
    std::queue<Pair> que;
    que.push(std::make_pair(n, 0));
    mp[n] = tot;
    while (!que.empty()) {
      std::pair<int, int> no = que.front();
      que.pop();

      if (no.first == k) {
        std::cout << no.second << std::endl;
        break;
      }
      if (no.first - 1 >= 0 && mp[no.first - 1] != tot) {
        mp[no.first - 1] = tot;
        que.push(std::make_pair(no.first - 1, no.second + 1));
      }
      if (no.first + 1 <= 200000 && mp[no.first + 1] != tot) {
        mp[no.first + 1] = tot;
        que.push(std::make_pair(no.first + 1, no.second + 1));
      }
      if (no.first * 2 <= 200000 && mp[no.first * 2] != tot) {
        mp[no.first * 2] = tot;
        que.push(std::make_pair(no.first * 2, no.second + 1));
      }
    }
  }
  return 0;
}
