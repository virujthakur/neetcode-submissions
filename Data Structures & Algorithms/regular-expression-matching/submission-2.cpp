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
        return dfs(s,p, 0, 0);
    }
};
