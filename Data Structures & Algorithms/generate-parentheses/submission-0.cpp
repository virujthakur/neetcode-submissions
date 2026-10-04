class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n+1);
        res[0] = {""};
        for(int i=0; i<=n; i++){
            for(int k=0; k<i; k++){
                vector<string> left= res[k];
                vector<string> right = res[i-k-1];
                for(string l: left){
                    for(string r: right){
                        res[i].push_back("(" + l + ")" + r);
                    }
                }
            }
        }
        return res[n];
    }
};
