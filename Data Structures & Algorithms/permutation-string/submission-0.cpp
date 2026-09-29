class Solution {
public:
    bool check(vector<int>& cnt1, vector<int>& cnt2){
        for(int i=0; i<26; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int i=0;
        int ans = false;
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for(int i=0; i<n; i++){
            cnt1[s1[i]-'a']+=1;
        }
        for(int j=0; j<m; j++){
            cnt2[s2[j]-'a']+=1;
            if(j-i+1 == n){
                if(check(cnt1, cnt2)){
                    return true;
                }
                cnt2[s2[i]-'a'] -=1;
                i+=1;
            }
        }
        return false;
    }
};
