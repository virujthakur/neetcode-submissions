class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int curMax =1, curMin = 1;
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            int num = nums[i];
            int newCurMax = max({num* curMax, num* curMin, num});
            int newCurMin = min({num* curMin, num* curMax, num});
            curMax= newCurMax;
            curMin= newCurMin;
            res = max(res, curMax);
        }
        return res;
    }
};
