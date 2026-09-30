class Solution {
public:
    vector<vector<string>> ans;
    void recur(vector<string>& board, int i, int colUsed, int lDiagUsed, int rDiagUsed){
        int n= board.size();
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j =0; j<n; j++){
            if(colUsed & (1<<j)) continue;
            if(lDiagUsed & (1<<(i+j))) continue;
            if(rDiagUsed & (1<<(j-i+2*n))) continue;
            board[i][j] = 'Q';
            recur(board, i+1, colUsed | (1<<j), lDiagUsed | (1<<(i+j)), rDiagUsed | (1<<(j-i+ 2*n)));
            board[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp;
        for(int i=0; i<n; i++){
            temp.push_back('.');
        }
        vector<string> board(n, temp);
        recur(board, 0, 0, 0, 0);
        return ans;
    }
};
