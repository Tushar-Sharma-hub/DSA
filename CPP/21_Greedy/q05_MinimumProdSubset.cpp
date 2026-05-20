//Minimum product subset of an array
//Given an array that contains both positive and negative integers, find the product of the maximum product subset in it. The maximum product subset can be one of the following:
//1) The product of all the elements of the array, if there are even number of negative elements and there is no zero in the array.
//2) The product of all the elements of the array except the negative element with the largest absolute value, if there are odd number of negative elements and there is no zero in the array.
//3) Zero, if there is any zero in the array and there are no negative elements in the array.
//4) The product of all the negative elements, if there are odd number of negative elements and there are no zero in the array.

#include<iostream>
using namespace std;

int minProd(vector<int>& arr){
    int n=arr.size();
    int cn=0,cz=0,cp=0,prod_pos=1,prod_neg=1,maxne=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<0){ cn++; prod_neg*=arr[i]; maxne=max(maxne,arr[i]);}
        else if(arr[i]==0) cz++;
        else {
            cp++;
            prod_pos*=arr[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto min_it = min_element(arr.begin(),arr.end());
            return *min_it;
        }
    }
    else{
        if(cn%2==0){
            return (prod_neg/maxne)*prod_pos;
        }
        else{
            return prod_neg*prod_pos;
        }
    }
}

int main(){
    vector<int> arr={-2,-2,-3,4,1,-5};
    int ans=minProd(arr);
    cout<<ans<<" ";
    return 0;
}