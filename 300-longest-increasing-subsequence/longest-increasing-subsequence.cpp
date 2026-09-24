class Solution {
public:
    int n;
    int t[2501][2501];

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(nums, 0, -1);
    }

    int solve(vector<int>& nums, int i, int j) {

        // Base case
        if (i >= n) {
            return 0;
        }

        // Check memoization only when j is valid
        if (j != -1 && t[i][j] != -1) {
            return t[i][j];
        }

        // Take
        int take = 0;

        if (j == -1 || nums[i] > nums[j]) {
            take = 1 + solve(nums, i + 1, i);
        }

        // Skip
        int skip = solve(nums, i + 1, j);

        int ans = max(take, skip);

        // Store only when j is valid
        if (j != -1) {
            t[i][j] = ans;
        }

        return ans;
    }
};