#include <vector>
#include <iostream>

int main() {
    int n, q, k;
    std::cin >> n >> q;
    std::vector<int> vecs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vecs[i];
    }
    while (q--) {
        std::cin >> k;
        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (vecs[mid] < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l > vecs.size() || vecs[l] != k) {
            std::cout << -1 << " " << -1 << std::endl;
            continue;
        }
        std::cout << l << " ";

        l = 0, r = n-1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (vecs[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        std::cout << l << std::endl;
    }
    return 0;
}