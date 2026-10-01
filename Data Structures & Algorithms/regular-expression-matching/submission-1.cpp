class Solution {
public:
    map<vector<int>, bool> dp;
    bool dfs(string& s, string& p, int i, int j){
        if(j == p.size()) return i == s.size();
        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];
        bool ans = false;
        if(i<s.size() and (p[j] == s[i] or p[j] == '.')){
            ans |= dfs(s,p, i+1,j+1);
        }
        if(j+1 < p.size() and p[j+1] == '*'){
            ans |= dfs(s,p,i,j+2);
            if(i<s.size() and (s[i] == p[j] or p[j] == '.'))
                ans |= dfs(s,p,i+1,j);
        }
        return dp[{i,j}]= ans;
    }
    bool isMatch(string s, string p) {
        return dfs(s,p, 0, 0);
    }
};
