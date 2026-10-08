class Solution {
public:
int longestStrChain(vector<string>& words) {
       int n = words.size();
       sort(begin(words), end(words), myFunc);
       vector<int> t(n,1);
       int maxL = 1;
       for(int i = 0; i < n; i++){
        for(int j = 0 ; j < i ; j++){
            if(isPredicisor(words[j],words[i])){

             t[i] = max(t[i],t[j]+1);
             maxL = max(maxL,t[i]);
            }
        }
       }
       return maxL;
    }
 bool isPredicisor(string &prev,string &curr){
            int M = prev.length();
            int N = curr.length();
            if(M>=N || N-M!=1){
                return false;
            }
            int i=0,j=0;
            while (i < M && j < N) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
            return i==M;
        }

        static bool myFunc(string &s1, string &s2) {
    return s1.length() < s2.length();
}
    
};