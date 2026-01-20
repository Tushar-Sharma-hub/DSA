//Merge two sorted array.
#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(vector<int>& a,vector<int>& b,vector<int>& c){
    int n1=a.size(),n2=b.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else{
            c[k]=b[j];
            k++;
            j++;
        }
    }
    //for remaining elements.
    if(i==n1){
        while(j<n2){
            c[k]=b[j];
            k++;
            j++;
        }
    }
    if(j==n2){
        while(i<n1){
            c[k]=a[i];
            k++;
            i++;
        }
    }
}

//Leet Code 88.
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = m - 1;       
//     int j = n - 1;      
//     int k = m + n - 1;   

//     while (i >= 0 && j >= 0) {
//         if (nums1[i] > nums2[j]) {
//             nums1[k--] = nums1[i--];
//         } else {
//             nums1[k--] = nums2[j--];
//         }
//     }

//     while (j >= 0) {
//         nums1[k--] = nums2[j--];
//     }

// }

int main() {
    vector<int> a, b;

    int n1, n2;
    cout << "Enter size of first sorted array: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements in sorted order:\n";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter size of second sorted array: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements in sorted order:\n";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    vector<int> c(n1+n2);
    mergeSortedArrays(a,b,c);
    int n=c.size();
    cout<<"After merge sorted :";
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
