class Solution {
public:
    bool isPalindrome(string&s, int i, int j){
        int n = s.size();
        if(i>=j) return true;
        if(s[i]!= s[j]) return false;
        return isPalindrome(s,i+1, j-1);
    }
    vector<vector<string>> ans;
    void recur(string& s, int i, vector<string> parts){
        int n= s.size();
        if(i==n){
            ans.push_back(parts);
            return;
        }
        vector<string> newParts = parts;
        string substr;
        substr.push_back(s[i]);
        newParts.push_back(substr);
        recur(s, i+1, newParts);
        newParts.pop_back();

        for(int j=i+1; j<n; j++){
            substr.push_back(s[j]);
            if(isPalindrome(s,i,j)){
                // cout<<i<<" "<<j<<endl;
                newParts.push_back(substr);
                recur(s, j+1, newParts);
                newParts.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        recur(s, 0, {});
        return ans;
    }
};
