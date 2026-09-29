class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans =0;
        vector<int> cnt(26);
        int i=0;
        int maxf = 0;
        for(int j=0; j<n; j++){
            cnt[s[j]-'A']+=1;
            maxf = max(maxf, cnt[s[j]-'A']);
            while(i<= j && j-i+1 - maxf > k){
                cnt[s[i]-'A']-=1;
                i+=1;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
