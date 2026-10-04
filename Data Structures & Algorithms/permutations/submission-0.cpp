class Solution {
public:
    vector<vector<int>> permutations;
    void recur(vector<int>& nums, int i){
        if(i== nums.size()){
            permutations.push_back(nums);
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            recur(nums, i+1);
            swap(nums[i], nums[j]);
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        recur(nums, 0);
        return permutations;
    }
};
