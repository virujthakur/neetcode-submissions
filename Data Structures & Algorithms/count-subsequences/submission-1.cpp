class Solution {
public:
    int dfs(string&s, string&t, int i, int j, vector<vector<int>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans += dfs(s,t,i+1, j+1, dp);
        }
        ans += dfs(s,t,i+1, j, dp);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i=0; i<=s.size(); i++){
            dp[i][t.size()] = 1;
        }
        for(int i= s.size()-1; i>=0; i--){
            for(int j= t.size()-1; j>=0; j--){
                if(s[i] == t[j]) dp[i][j] += dp[i+1][j+1];
                dp[i][j] += dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
