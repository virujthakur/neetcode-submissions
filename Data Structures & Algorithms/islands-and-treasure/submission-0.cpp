class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int cost = 0;
        while(!q.empty()){
            int sz= q.size();
            for(int i=0; i<sz; i++)
            {
                pair<int,int> cur = q.front();
                q.pop();
                if(grid[cur.first][cur.second]!= INT_MAX && grid[cur.first][cur.second]!=0){
                    continue;
                }
                grid[cur.first][cur.second] = cost;
                for(vector<int> d: directions){
                    int newx = cur.first + d[0];
                    int newy = cur.second + d[1];
                    if(newx >=0 and newy >=0 and newx <m and newy <n and grid[newx][newy] == INT_MAX){
                        q.push({newx, newy});
                    }
                }
            }
            cost +=1;
        }
    }
};
