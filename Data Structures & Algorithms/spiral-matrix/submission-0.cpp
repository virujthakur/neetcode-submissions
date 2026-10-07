class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top =0 , left = 0, right = matrix[0].size(), bottom = matrix.size();
        vector<int> ans;
        while(left < right and top < bottom){
            // top row
            for(int i= left; i< right; i++){
                ans.push_back(matrix[top][i]);
            }
            top +=1;

            // right row
            for(int i= top; i< bottom; i++){
                ans.push_back(matrix[i][right-1]);
            }
            right -=1;

            if(left >= right or top >=bottom) break;

            // bottom row
            for(int i= right-1; i >=left; i--){
                ans.push_back(matrix[bottom-1][i]);
            }
            bottom -=1;

            // left row
            for(int i= bottom-1; i >=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left +=1;
        }
        return ans;
    }
};
