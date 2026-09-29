class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans(n-k+1);
        for(int i=0; i<n; i++){
            while(dq.size() > 0 && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i>=k-1){
                if(dq.front() < i-k+1) dq.pop_front();
                ans[i-k+1] = nums[dq.front()];
            }
        }
        return ans;
    }
};
