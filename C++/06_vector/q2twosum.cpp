// Two Sum Problem 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cout << "Enter target: ";
    cin >> x;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> v;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        v.push_back(q);
    }

    bool found = false;
    for (int i = 0; i <= v.size() - 2; i++) {
        for (int j = i + 1; j <= v.size() - 1; j++) {
            if (v[i] + v[j] == x) {
                cout << "Pair found at indices: (" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No pair found that adds up to the target." << endl;
    }

    return 0;
}
