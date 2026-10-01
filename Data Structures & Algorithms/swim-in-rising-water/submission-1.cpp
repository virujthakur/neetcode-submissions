class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> directions  = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            if(grid[cur[1]][cur[2]] == -1) continue;
            grid[cur[1]][cur[2]] = -1;
            if(cur[1] == n-1 and cur[2] == n-1) return cur[0];
            for(vector<int> d: directions){
                int newx = cur[1]+ d[0];
                int newy = cur[2]+ d[1];
                if(newx >=0 and newy>=0 and newx<n and newy<n and grid[newx][newy]!=-1){
                    pq.push({max(cur[0], grid[newx][newy]), newx, newy});
                }
            }
        }
        return -1;
    }
};
