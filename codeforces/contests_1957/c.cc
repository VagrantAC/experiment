#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 3e5+55;
ll f[maxn];
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
void init() {
    f[0] = 1;
    for (int i = 1; i <= 300000; ++ i) {
        f[i] = (f[i-1] * i) % mod;
    }
}
ll c(ll n, ll m) {
    if (m > n) {
        return 0;
    }
    return (((f[n] * qpow(f[m], mod-2)) % mod) * qpow(f[n-m], mod-2) % mod);
}
int main() {
    init();
    int t;
    cin >> t;
    while (t --) {
        int n, k, x, y;
        cin >> n >> k;
        int diagonal = n;
        for (int i = 0; i < k; ++ i) {
            cin >> x >> y;
            if (x == y) {
                diagonal --;
            } else {
                diagonal -= 2;
            }
        }
        ll sum = 0;
        for (int i = diagonal % 2; i <= diagonal; i += 2) {
            int other = (diagonal - i) / 2;
            sum += (c(diagonal, i) * c(other * 2, other) % mod * f[other]) % mod;
            sum = (sum % mod + mod) % mod;
        }
        cout << sum << endl;
    }
    return 0;
}