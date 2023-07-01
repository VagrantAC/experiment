#include <stdio.h>
const int MAXN = 1e5 + 55;

int main() {
  int n, m;
  int a[MAXN];
  int b[MAXN];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = 0;
  }
  while (m--) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    b[l - 1] += c;
    b[r] -= c;
  }

  for (int i = 1; i < n; i++) {
    b[i] += b[i - 1];
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i] + b[i]);
  }
  printf("\n");
}
