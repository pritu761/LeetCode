class Solution {
public:
    int n;
    int K;

    int solve(int i, vector<int>& energy, vector<int>& t) {
        if (i >= n) 
            return 0;
        
        if (t[i] != INT_MIN)
            return t[i];

        // Take energy at i and then best from (i + k) onwards - Recursion leap of faith
        t[i] = energy[i] + solve(i + K, energy, t);
        
        return t[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;
        vector<int> t(n, INT_MIN);     // Initialize memoization array

        int maxEnergy = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxEnergy = max(maxEnergy, solve(i, energy, t));
        }

        return maxEnergy;
    }
};