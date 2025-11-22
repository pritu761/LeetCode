class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        for (int &num : nums) {
            // Goal: Make every number divisible by 3.
            // num % 3 gives the remainder:
            //
            // 0 → already divisible (0 operations)
            // 1 → subtract 1 (1 operation)
            // 2 → add 1 (1 operation)
            //
            // So any number with remainder != 0 needs exactly 1 operation.
            if (num % 3 != 0) {
                operations++;
            }
        }

        return operations;
    }
};
