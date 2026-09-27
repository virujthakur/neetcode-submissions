class Solution {
public:
    bool checkCells(vector<char> cells){
        vector<int> cnt(10,0);
        for(int i=0; i<cells.size(); i++){
            if(cells[i] == '.') continue;
            cnt[cells[i]-'0']+=1;
            if(cnt[cells[i]-'0'] > 1) return false; 
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(vector<char> row: board){
            if(!checkCells(row)) return false;
        }
        // cout<<"A"<<endl;

        for(int i=0; i<board.size(); i++){
            vector<char> col;
            for(int j=0; j<board[0].size(); j++){
                col.push_back(board[j][i]);   
            }
            if(!checkCells(col)) return false;
        }

        for(int i=0; i<board.size();i+=3){
            for(int j=0; j<board[0].size(); j+=3){
                vector<char> grid;
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        grid.push_back(board[k][l]);
                    }
                }
                if(!checkCells(grid)) return false;
            }
        }

        return true;
    }
};
