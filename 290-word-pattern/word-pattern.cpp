class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        if(pattern.length() != words.size()){
            return false;
        }
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;

        for(int i=0;i<pattern.length();i++){
            char ch = pattern[i];
            string w = words[i];

            if(mp1.count(ch)){
                if(mp1[ch] != w){
                    return false;
                }
            }
                else{
                    mp1[ch] = w;
                }
            
            if(mp2.count(w)){
                if(mp2[w] != ch){
                    return false;
                }
            }
                else{
                    mp2[w] = ch;
                }
            
            

        }
    return true;
    }
};