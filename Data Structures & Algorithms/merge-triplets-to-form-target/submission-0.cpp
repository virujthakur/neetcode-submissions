class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool check1 = false , check2 = false, check3 = false;
        for(vector<int> t: triplets){
            if(t[0] == target[0]){
                if(t[1] > target[1] or t[2] > target[2]) continue;
                check1 = true;
            }

            if(t[1] == target[1]){
                if(t[0] > target[0] or t[2] > target[2]) continue;
                check2 = true;
            }

            if(t[2] == target[2]){
                if(t[1] > target[1] or t[0] > target[0]) continue;
                check3 = true;
            }
        }
        return check1 && check2 && check3;
    }
};
