class Solution {
public:
    bool recur(string& s1, string&s2, string&s3, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(i== s1.size() && j== s2.size() && k == s3.size()) return true;
        if(k== s3.size()) return false;

        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        bool ans1 = false, ans2 = false;
        
        if(i<s1.size() && s1[i] == s3[k]){
            ans1 = recur(s1, s2, s3, i+1, j, k+1, dp);
        }
        
        if(j< s2.size() && s2[j] == s3[k]){
            ans2 = recur(s1, s2, s3, i, j+1, k+1, dp);
        }

        return dp[i][j][k] = ans1 or ans2;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m= s1.size();
        int n= s2.size();
        int o= s3.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(o, -1)));
        return recur(s1, s2, s3, 0,0,0, dp);
    }
};
