#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        map<char, int> mp;
        int maxx = 0;
        for (auto ch : s)
        {
            mp[ch]++;
            maxx = max(maxx, mp[ch]);
        }
        switch (maxx)
        {
        case 1:
        case 2:
            cout << 4 << endl;
            break;
        case 3:
            cout << 6 << endl;
            break;
        default:
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}