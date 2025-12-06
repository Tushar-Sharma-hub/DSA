//Rotate from given k.[it will take k element from last of array and bring it in front.]
//Logic:1.select k element from last . 2. Now reverse the k elements and other elements . 3. Now reverse whole array.

//My try:
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the size :";
//     cin>>n;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         int x;
//         cout<<"Enter "<<i+1<<" element:";
//         cin>>x;
//         v.push_back(x);
//     }
//     int k;
//     cout<<"Enter k:";
//     cin>>k;
//     for(int i=0,j=n-k-1,a=j+1,b=n-1;i<j || a<b;i++,j--,a++,b--){
//         int temp1=v[i];
//         v[i]=v[j];
//         v[j]=temp1;
//         int temp2=v[a];
//         v[a]=v[b];
//         v[b]=temp2;
//     }
//     for(int i=0,j=n-1;i<j;i++,j--){
//         int temp3=v[i];
//         v[i]=v[j];
//         v[j]=temp3;
//     }
//     cout<<"After k rotation:";
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
// }

#include <iostream>
#include <vector>
using namespace std;

void reversePart(vector<int>& v, int start, int end) {
    while (start < end) {
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> v[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    // Handle cases where k > n
    k = k % n;

    // Step 1: Reverse first n-k elements
    reversePart(v, 0, n - k - 1);

    // Step 2: Reverse last k elements
    reversePart(v, n - k, n - 1);

    // Step 3: Reverse the entire array
    reversePart(v, 0, n - 1);

    cout << "After " << k << " rotation(s): ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
