class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        int nearestPowerOfTwo = 1;
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if(i == 2* nearestPowerOfTwo) nearestPowerOfTwo =i;
            dp[i] = 1 + dp[i-nearestPowerOfTwo];
        }
        return dp;
    }
};
