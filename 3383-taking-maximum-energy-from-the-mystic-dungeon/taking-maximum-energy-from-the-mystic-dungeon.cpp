class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> t(n, 0); // DP array

        for (int i = n - 1; i >= 0; i--) { // see my video to understand why right to left traversal is needed here
            if (i + k < n)
                t[i] = energy[i] + t[i + k];
            else
                t[i] = energy[i];
        }

        return *max_element(begin(t), end(t));
    }
};