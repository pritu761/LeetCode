class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        
        unordered_map<int,int> mp; // stores lake -> last day it rained
        set<int> s; // stores dry days (days when it didn't rain)
        
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            int lake = rains[i];
            
            if(lake == 0){
                // It's a dry day, add to set
                s.insert(i);
            }
            else {
                // It's raining on this lake
                ans[i] = -1;
                
                // Check if lake already has water
                if(mp.count(lake)){
                    // Find a dry day after the last rain on this lake
                    auto it = s.lower_bound(mp[lake]);
                    
                    if(it == s.end()){
                        // No dry day available to drain this lake
                        return {};
                    }
                    
                    // Use this dry day to drain the lake
                    ans[*it] = lake;
                    s.erase(it);
                }
                
                // Update the map with current day for this lake
                mp[lake] = i;
            }
        }
        
        return ans;
    }   
};
