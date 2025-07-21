// We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. 
// Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
// For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
// Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
// LC-779

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){ //when k is even then by backtracking we will go to node which generated kth element (n-1,k/2) , when k is even then answer comes flipped from prevans.
            int prevans=kthGrammar(n-1,k/2);
            if(prevans==0) return 1;
            else return 0;
        }
        else{ //when k is odd then by backtracking we will go to the prev node which genrated it (n-1,k/2+1) ,when k is odd then answer is same wrt the prevans.
            return kthGrammar(n-1,k/2+1);
        }
    }
};