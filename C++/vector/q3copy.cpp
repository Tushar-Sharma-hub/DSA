//Write a program to copy the contents of one array into another in the reverse order.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    vector<int> v1(n), v2(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> v1[i];
    }

    // Copy in reverse order
    for (int i = 0; i < n; i++) {
        v2[i] = v1[n - 1 - i];
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }

    return 0;
}
