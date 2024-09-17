#include <iostream>

using namespace std;
const string str = "aeiou";
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 0; i < str.length(); ++ i) {
            for (int j = 0; j < n / str.length(); ++ j) {
                cout << str[i];
            }
            if (n % str.length() >= i + 1) {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}