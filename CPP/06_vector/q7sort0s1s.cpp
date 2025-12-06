//Sort the array of 0's and 1's.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cout<<"Enter the size:";
    cin>>n;
    int i = 0;
    while (i < n) {
        int x;
        cout << "Enter element " << i + 1 << " (0 or 1): ";
        cin >> x;
        if (x != 0 && x != 1) {
            cout << "Invalid input. Please enter only 0 or 1." << endl;
            continue; // Don't increment i, ask again
        }
        v.push_back(x);
        i++;
    }
    
    //Method 1-Two pass method
    //count number of zero and one then put zero at starting acc to their count and then put 1.
    // int numberofzero=0,numberofone=0;
    // for(int i=0;i<n;i++){ //One pass.
    //     if(v[i]==0) numberofzero++;
    //     else numberofone++;
    // }
    // for(int i=0;i<n;i++){ //Two pass.
    //     if(i<numberofzero) v[i]=0;
    //     else v[i]=1;
    // }

    // cout<<"After sorted:";
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }

    //Method 2-Two pointers.
    //use a at start and b at end then compare .
    int a=0,b=n-1;
    while(a<b){
        if(v[a]==1 && v[b]==0){
            // int temp=v[a]; swap
            // v[a]=v[b];
            // v[b]=temp;
            v[a]=0; //simple change.
            v[b]=1;
            a++;
            b--;
        }
        if(v[b]==1) b--;
        if(v[a]==0) a++;
    }

    cout<<"After sorted:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}