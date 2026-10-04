class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void dfs(vector<vector<char>>& board, int i, int j){
        int m= board.size();
        int n= board[0].size();
        board[i][j] = 'Y';
        for(vector<int> d: directions){
            int newx = i+ d[0];
            int newy = j+ d[1];
            if(newx >=0 and newy>=0 and newx<m and newy<n and board[newx][newy] == 'O'){
                dfs(board, newx, newy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        for(int i=0; i<m; i++){
            if(board[i][0]== 'O'){
                dfs(board, i, 0);
            }

            if(board[i][n-1]== 'O'){
                dfs(board, i, n-1);
            }
        }

        for(int i=0; i<n; i++){
            if(board[0][i]== 'O'){
                dfs(board, 0, i);
            }

            if(board[m-1][i]== 'O'){
                dfs(board, m-1, i);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};
