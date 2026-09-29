class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) 
        {
            swap(nums1, nums2);
            swap(n,m);
        }

        int half = (n+m)/2;
        int l=0;
        int h= min(half,n);
        int idx = -1;
        while(l<=h){
            // we take mid elements from the smaller array
            // half - mid -1 elements from the larger array
            int mid = (l + (h-l)/2);
            // cout<<mid<<endl;
            
            if((mid == 0 or nums1[mid-1] <= nums2[half-mid]) && (mid == n or nums2[half-mid-1] <= nums1[mid])){
                idx = mid;
                break;
            }
            else if(mid < n &&  nums1[mid] < nums2[half-mid-1]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
            
        }

        int j = half - idx;

        int left1  = (idx == 0) ? INT_MIN : nums1[idx - 1];
        int right1 = (idx == n) ? INT_MAX : nums1[idx];

        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == m) ? INT_MAX : nums2[j];

        if ((n + m) % 2) {
            return min(right1, right2);
        }

        return (max(left1, left2) + min(right1, right2)) / 2.0;

    }
};
