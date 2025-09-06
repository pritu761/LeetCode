class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> um;
        int cursum=0,count=0;
        um[0]=1;
        for(int i=0;i<n;i++){
            cursum+=nums[i];
            // agr hmlog cursum-k mil gy map me mtlb cursum=k wla bhi milgy
            if(um.find(cursum-k)!=um.end()) count+=um[cursum-k];
            um[cursum]++;
        }
        return count;
    }
};