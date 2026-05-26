// 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

//Intuition: Tujhe sum k chahiye fibonacci series se toh ek vector bnake usme fibonacci daale <= k ke.
// fir right to left ja fib array right to left ja ki max fib no. lekr minimum mil ske.
// k ko reduce krte ja jab tak k 0 na ho jaye. ans++ krte ja jab bhi fib[i] <= k ho. age fib[i] bda hua toh left jaate rhega.

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k==1) return 1;
        int a=1,b=1,sum=2;
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        while(sum<=k){
            fib.push_back(sum);
            a=b;
            b=sum;
            sum+=a;
        }
        if(sum==k) return 1;
        int ans=0;
        for(int i=fib.size()-1;i>=0;i--){
            if(k==0) break;
            if(fib[i]<=k){
                if(k%fib[i]==0){
                    ans+=k/fib[i];
                }
                else ans++;
                k-=fib[i];
            }
        }
        return ans;
    }
};