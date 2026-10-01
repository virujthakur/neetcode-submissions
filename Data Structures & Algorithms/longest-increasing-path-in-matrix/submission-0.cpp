class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        for(vector<int> d: directions){
            int newi = i+ d[0];
            int newj = j+ d[1];
            if(newi>=0 and newj>=0 and newi<m and newj<n and matrix[newi][newj] > matrix[i][j]){
                ans = max(ans, 1+ dfs(matrix, newi, newj, dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]==-1){
                    // cout<<i<<" "<<j<<endl;
                    ans = max(ans, dfs(matrix, i, j, dp));
                }
            }
        }
        // cout<<dfs(matrix, 2,0, dp)<<endl;
        return ans;
    }
};
