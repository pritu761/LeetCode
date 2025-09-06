class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mini = m-1, maxi = 0, minj = n-1, maxj = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mini = min(mini,i);
                    maxi = max(maxi,i);
                    minj = min(minj,j);
                    maxj = max(maxj,j);
                }
            }
        }
        int l = maxj - minj + 1, b = maxi - mini + 1;
        return l*b;
    }
};//hello