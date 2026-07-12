class Solution {
public:
    int fib(int n) {

        if(n==1){
            return 1;
        }
        int result=0; 
        int a = 0;
        int b = 1;
        for(int i=0;i<n-1;i++){
            result = a+b;
           a = b;
           b = result;
        }
        return result;
    }
};