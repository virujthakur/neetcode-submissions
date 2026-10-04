class Solution {
public:
    vector<vector<int>> subsets;
    void recur(vector<int>& numsDistinct, unordered_map<int,int>& f, int i, vector<int> subset){
        if(i == numsDistinct.size()){
            subsets.push_back(subset);
            return;
        }
        recur(numsDistinct, f, i+1, subset);

        vector<int> newSubset = subset;
        for(int j=1; j<= f[numsDistinct[i]]; j++){
            newSubset.push_back(numsDistinct[i]);
            recur(numsDistinct, f, i+1, newSubset);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsDistinct;
        unordered_map<int,int> f;
        for(int i=0; i<n; i++){
            f[nums[i]]+=1;
            if(f[nums[i]] == 1){
                numsDistinct.push_back(nums[i]);
            }
        }
        // cout<<numsDistinct.size()<<endl;
        vector<int> subset;
        recur(numsDistinct, f, 0, subset);
        return subsets;
    }
};
