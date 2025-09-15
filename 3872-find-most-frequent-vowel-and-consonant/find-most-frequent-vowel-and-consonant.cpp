class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        for (char c : s) {
            int idx = c - 'a';
            int count = ++freq[idx];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maxVowelFreq = max(maxVowelFreq, count);
            else
                maxConsonantFreq = max(maxConsonantFreq, count);
        }
        return maxVowelFreq + maxConsonantFreq;
    }
};
