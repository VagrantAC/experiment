#include <iostream>
#include <algorithm>

int main() {
    int n, res = 0;
    std::cin >> n;
    while (n) {
        if (n&1) {
            res ++;
        }
        n = n >> 1;
    }
    std::cout << res << std::endl;
    return 0;
}