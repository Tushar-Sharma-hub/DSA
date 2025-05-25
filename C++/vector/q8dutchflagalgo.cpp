//Sort the array of 0's,1's,2's.[Dutch Flag algo.(as dutch flag has 3 colors.)]

//We can also use Two pass method like in q7.
// void sort(vector<int>& nums) {  //Two pass method
//     int nz=0,no=0,nt=0;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==0) nz++;
//         if(nums[i]==1) no++;
//         if(nums[i]==2) nt++;
//     }
//     for(int i=0;i<nums.size();i++){
//         if(i<nz) nums[i]=0;
//         else if(i<(nz+no)) nums[i]=1;
//         else nums[i]=2;
//     }
// }

#include<iostream>
#include<vector>
using namespace std;

void sortDutch(vector<int>& v) { //Play with mid.
    int n = v.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (v[mid] == 0) {
            swap(v[mid], v[low]);
            low++;
            mid++;
        }
        else if (v[mid] == 1) {
            mid++;
        }
        else { // v[mid] == 2
            swap(v[mid], v[high]);
            high--;
        }
    }
}


int main(){
    vector<int> v;
    int n;
    cout<<"Enter the size:";
    cin>>n;
    int i = 0;
    while (i < n) {
        int x;
        cout << "Enter element " << i + 1 << " (0 or 1 or 2): ";
        cin >> x;
        if (x != 0 && x != 1 && x!=2) {
            cout << "Invalid input. Please enter only 0 or 1 or 2." << endl;
            continue; // Don't increment i, ask again
        }
        v.push_back(x);
        i++;
    }
    sortDutch(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}