class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int result =0;
        int curr = 0;
        int S = accumulate(begin(nums), end(nums), 0);//for loop bhi likh sakte ho


        for(int i = 0; i < n; i++) {
            curr += nums[i]; //left sum

            int left  = curr;
            int right = S - left;

            if(nums[i] != 0) {
                continue;
            }

            if(left == right)
                result += 2;
            
            if(abs(left - right) == 1)
                result += 1;
        }

        return result;
    }
};