#include <iostream>
#include <queue>
#include <string>

struct Vector3 {
  int x, y, z;
  Vector3(int _x, int _y, int _z) {
    x = _x;
    y = _y;
    z = _z;
  }
};

const int kMaxMazeSideLength = 30;
const Vector3 kMazeUnitVector3[] = {Vector3(0, 0, -1), Vector3(0, 0, 1),
                                    Vector3(0, 1, 0),  Vector3(0, -1, 0),
                                    Vector3(1, 0, 0),  Vector3(-1, 0, 0)};

int bfs(
    int l, int r, int c,
    std::string (&maze)[kMaxMazeSideLength][kMaxMazeSideLength],
    int (&dis)[kMaxMazeSideLength][kMaxMazeSideLength][kMaxMazeSideLength]) {
  std::queue<Vector3> points;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        if (maze[i][j][k] == 'S') {
          points.push(Vector3(i, j, k));
          dis[i][j][k] = 0;
        } else {
          dis[i][j][k] = -1;
        }
      }
    }
  }
  while (!points.empty()) {
    Vector3 point = points.front();
    points.pop();
    if (maze[point.x][point.y][point.z] == 'E') {
      return dis[point.x][point.y][point.z];
    }
    for (int i = 0; i < 6; ++i) {
      Vector3 unitVector3 = kMazeUnitVector3[i];
      Vector3 position =
          Vector3(unitVector3.x + point.x, unitVector3.y + point.y,
                  unitVector3.z + point.z);
      if (position.x >= 0 && position.x < l && position.y >= 0 &&
          position.y < r && position.z >= 0 && position.z <= c &&
          maze[position.x][position.y][position.z] != '#' &&
          dis[position.x][position.y][position.z] == -1) {
        dis[position.x][position.y][position.z] =
            dis[point.x][point.y][point.z] + 1;
        points.push(position);
      }
    }
  }
  return -1;
}

int main() {
  int l, r, c;
  std::string maze[kMaxMazeSideLength][kMaxMazeSideLength];
  int dis[kMaxMazeSideLength][kMaxMazeSideLength][kMaxMazeSideLength];
  while (std::cin >> l >> r >> c) {
    if (l == 0 && r == 0 && c == 0) {
      break;
    }
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        std::cin >> maze[i][j];
      }
    }
    int res = bfs(l, r, c, maze, dis);
    if (res == -1) {
      std::cout << "Trapped!" << std::endl;
    } else {
      std::cout << "Escaped in " << res << " minute(s)." << std::endl;
    }
  }
  return 0;
}
