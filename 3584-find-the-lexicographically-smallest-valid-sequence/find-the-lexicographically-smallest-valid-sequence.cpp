class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        // right[i] = index in word1 where we can start matching word2[i..] from the right
        vector<int> right(n, -1);
        int pos = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (pos >= 0 && word1[pos] != word2[i]) --pos;
            if (pos < 0) break;
            right[i] = pos;
            --pos;
        }
        
        vector<int> ans;
        bool usedChange = false;
        int i = 0; // index in word2
        int j = 0; // index in word1
        
        while (i < n && j < m) {
            if (word1[j] == word2[i]) {
                // exact match – take it
                ans.push_back(j);
                ++i;
                ++j;
            } else {
                // mismatch – try to use the one allowed change
                if (!usedChange) {
                    bool canChange = false;
                    if (i + 1 == n) {
                        // changing the last character always works
                        canChange = true;
                    } else {
                        // need to be able to match the rest of word2 after position j
                        if (right[i + 1] != -1 && right[i + 1] > j) {
                            canChange = true;
                        }
                    }
                    if (canChange) {
                        ans.push_back(j);   // change word1[j] to word2[i]
                        usedChange = true;
                        ++i;
                        ++j;
                    } else {
                        // cannot change here – skip this character in word1
                        ++j;
                    }
                } else {
                    // already used the change – just skip
                    ++j;
                }
            }
        }
        
        // if we matched all of word2, return the indices, else empty
        return (i == n) ? ans : vector<int>();
    }
};