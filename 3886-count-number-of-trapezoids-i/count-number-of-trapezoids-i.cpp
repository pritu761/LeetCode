class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int M = 1e9 + 7;
        unordered_map<int,int>mp;//y->count finding it out
        for(auto &points:points){
            int y = points[1];
            mp[y]++;

        }

        long long result = 0; // count of trapezoidds
        long long prevHorizontalLines = 0 ; 

        for(auto &it:mp){
            long long count = it.second;
            long long horizontalLines = count * (count-1)/2; // count c2 formula
            result+= horizontalLines * prevHorizontalLines;
            prevHorizontalLines += horizontalLines;

        }
        return result % M;
    }
};