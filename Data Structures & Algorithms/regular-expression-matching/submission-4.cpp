class Solution {
public:
    map<vector<int>, bool> dp;
    bool dfs(string& s, string& p, int i, int j){
        if(j == p.size()) return i == s.size();
        if(i== s.size()){
            if(j+1 < p.size() and p[j+1] == '*' and j+2 == p.size())
                return true;
            return false;
        }

        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];
        bool ans = false;
        if((p[j] == s[i] or p[j] == '.')){
            ans |= dfs(s,p, i+1,j+1);
        }
        if(j+1 < p.size() and p[j+1] == '*'){
            ans |= dfs(s,p,i,j+2);
            if((s[i] == p[j] or p[j] == '.'))
                ans |= dfs(s,p,i+1,j);
        }
        return dp[{i,j}]= ans;
    }
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+2));
        dp[s.size()][p.size()] = true;
        for(int j=p.size()-2; j>=0; j--){
            if(p[j+1] =='*') dp[s.size()][j] = true;
            else break;
        }
        for(int i=s.size()-1; i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                if((p[j] == s[i] or p[j] == '.')){
                    dp[i][j] = dp[i][j] || dp[i+1][j+1];
                }
                if(j+1 < p.size() and p[j+1] == '*'){
                    dp[i][j] = dp[i][j] ||  dp[i][j+2];
                    if((s[i] == p[j] or p[j] == '.'))
                        dp[i][j]= dp[i][j] || dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};
