class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>result;
        int temp,n;
        bool ans;
        for(int i = left; i <= right;i++){
            n = i;
            ans = false;
            while(n != 0){
                temp = n % 10;
                n = n / 10;
                if(temp != 0 && i % temp == 0){
                    ans = true;
                }
                else{
                    ans = false;
                    break;
                }
            }
            if(ans == true){
                result.push_back(i);
            }
        }
        return result;
    }
};