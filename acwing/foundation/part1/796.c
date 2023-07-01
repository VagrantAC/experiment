#include <stdio.h>

const int MAXN = 1005;

int main() {
  int nums[MAXN][MAXN];
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &nums[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      nums[i][j] += nums[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      nums[i][j] += nums[i - 1][j];
    }
  }

  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", nums[x2][y2] - nums[x1 - 1][y2] - nums[x2][y1 - 1] +
                       nums[x1 - 1][y1 - 1]);
  }
}
