class KthLargest {
public:
    int partition(vector<int>& nums, int l, int r){
        int n= nums.size();
        int pivot = rand()%(r-l+1)  + l;
        swap(nums[r], nums[pivot]);
        int lastIdx = l;
        for(int i=l; i<r; i++){
            if(nums[i] <= nums[r]){
                swap(nums[i], nums[lastIdx]);
                lastIdx+=1;
            }
        }
        swap(nums[r], nums[lastIdx]);
        return lastIdx;
    }
    void quickselect(vector<int>& nums, int l, int r, int k){
        int n = nums.size();
        int p  = partition(nums, l, r);
        // cout<<p<<endl;
        // return;
        if (p==k) return;
        else if(p> k) quickselect(nums, l, p-1, k);
        else quickselect(nums, p+1, r, k);
    }
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k= k;
        this->nums = nums;
    }   
    
    int add(int val) {
        nums.push_back(val);
        int n= nums.size();
        quickselect(nums, 0, n-1, n-k);
        return nums[n-k];
    }
};
