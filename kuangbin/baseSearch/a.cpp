#include <iostream>
#include <string>
const int kMaxChessboardSideLen = 8;

int solve(int index, int n, int m,
          std::string (&chessboard)[kMaxChessboardSideLen],
          bool (&row)[kMaxChessboardSideLen]) {
  if (m == 0) {
    return 1;
  }
  if (index == n) {
    return 0;
  }
  int res = solve(index + 1, n, m, chessboard, row);
  for (int i = 0; i < n; ++i) {
    if (!row[i] && chessboard[index][i] == '#') {
      row[i] = true;
      res += solve(index + 1, n, m - 1, chessboard, row);
      row[i] = false;
    }
  }
  return res;
}

int main() {
  int n, m;
  std::string chessboard[kMaxChessboardSideLen];
  bool row[kMaxChessboardSideLen];
  while (std::cin >> n >> m) {
    if (n == -1 && m == -1) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> chessboard[i];
      row[i] = false;
    }

    std::cout << solve(0, n, m, chessboard, row) << std::endl;
  }
  return 0;
}
