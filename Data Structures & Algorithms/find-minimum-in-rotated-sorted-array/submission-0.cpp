class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int l=0;
        int h=n-1;
        int ans = 1e9;
        while(l<=h){
            int mid = l+(h-l)/2;
            cout<<l<<" "<<h<<" "<<mid<<endl;
            if(nums[mid] >=  nums[l]){ // left sorted portion
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                h = mid-1;
            }
        }
        return ans;
    }
};
