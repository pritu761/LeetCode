class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long t1 =0 , t2 =1;
        while(t2<n){
            long long t3 = t1 + t2;
            if(t1+t2+t3 == n) return true;
            t1 = t2;
            t2 = t3;
        }
        return false;
    }
};