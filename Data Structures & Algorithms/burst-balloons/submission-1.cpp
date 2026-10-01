class Solution {
public:
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp){
        if(l>r) return 0;
        if(dp[l][r]!= -1) return dp[l][r];
        int ans = 0;
        for(int k=l; k<=r; k++){
            ans = max(ans, dfs(nums,l,k-1, dp) + nums[k]* nums[l-1]* nums[r+1] + dfs(nums, k+1, r, dp));
        }
        return dp[l][r]= ans;
    }
    int maxCoins(vector<int>& nums) {
        // 0,0 0,1
        // 1,0
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int l=0; l<n; l++){
            for(int r=0; r<l; r++) dp[l][r] = 0;
        }
        for(int l=n-2; l>=1; l--){
            for(int r=l; r<=n-2; r++){
                for(int k=l; k<=r; k++){
                    dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r]+ nums[k]* nums[l-1]* nums[r+1]);
                }
            }
        }
        return dp[1][n-2];
    }
};
