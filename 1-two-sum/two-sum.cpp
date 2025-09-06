class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){

            int first = arr[i];
            int second = target - first;
            if(m.find(second)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first] = i;

        }
        return ans;
    }
};