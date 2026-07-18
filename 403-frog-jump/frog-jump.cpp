class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    vector<vector<int>> dp;

    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump) {

        if (curr_stone_idx == n - 1)
            return true;

        if (dp[curr_stone_idx][prevJump] != -1)
            return dp[curr_stone_idx][prevJump];

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {

            if (nextJump <= 0)
                continue;

            int next_stone = stones[curr_stone_idx] + nextJump;

            if (mp.find(next_stone) != mp.end()) {
                if (solve(stones, mp[next_stone], nextJump))
                    return dp[curr_stone_idx][prevJump] = true;
            }
        }

        return dp[curr_stone_idx][prevJump] = false;
    }

    bool canCross(vector<int>& stones) {

        n = stones.size();

        if (n == 1)
            return true;

        if (stones[1] != 1)
            return false;

        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0);
    }
};