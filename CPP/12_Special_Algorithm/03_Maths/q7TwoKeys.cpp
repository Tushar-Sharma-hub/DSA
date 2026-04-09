// 650. 2 Keys Keyboard

// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
#include<iostream>
using namespace std;

class Solution {
public:
    int highestfactor(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return n/i;
        }
        return 1;
    }
    int minSteps(int n) {
        if(n==1) return 0;
        if(n<=4) return n;
        int count=0;
        while(n>1){
            int hf=highestfactor(n);
            count+=(n/hf);
            n=hf;
        }
        return count;
    }
};