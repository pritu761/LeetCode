// class Solution {
// public:
//     int longestMonotonicSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int result = 0;
//         for(int i=0; i < nums.size();i++){
//             int incr=1;
//             int j = i+1;
//             while(j<n && nums[j] < nums[j-1]){
//                 j++;
//                 incr++;
//             }
//             j = i+1;
//             int decr = 1;
//             while(j<n && nums[j-1] < nums[j]){
//                 j++;
//                 decr++;
//             }
//             result = max({result,incr,decr});
//         }
//         return result;
        
//     }
// };
class Solution{
public:
    int longestMonotonicSubarray(vector<int>& nums){
        int n = nums.size();
        int incr = 1;
        int decr = 1;
        int result = 1;
        for(int i= 1 ; i< nums.size();i++){
            if (nums[i] > nums[i-1]){
                incr++;
                decr=1;
                result = max(result,incr);
            }
            else if (nums[i] < nums[i-1]){
                incr=1;
                decr++;
                result = max(result,decr);
            }else{
                incr = 1;
                decr = 1;
            }
        }
        return result;
    }
};