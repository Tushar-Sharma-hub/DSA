#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    char first = (n >= m) ? 'B' : 'G';
    char second = (first == 'B') ? 'G' : 'B';
    while (n > 0 && m > 0) {
        s.push_back(first);
        s.push_back(second);
        if (first == 'B') {
            n--; m--;
        } else {
            m--; n--;
        }
    }
    while (n--) s.push_back('B');
    while (m--) s.push_back('G');
    cout << s;
    return 0;
}
