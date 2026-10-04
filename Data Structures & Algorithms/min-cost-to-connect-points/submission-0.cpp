class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        rank.resize(n, 1);
    }
    void unionf(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(rank[px] > rank[py]){
                parent[py]= px;
            }
            else if(rank[px] < rank[py]){
                parent[px] = py;
            }
            else{
                rank[px]+=1;
                parent[py] = px;
            }
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
};
class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[1]- p2[1]) + abs(p1[0]- p2[0]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                minHeap.push({distance(points[i], points[j]), i, j});
            }
        }
        DSU d(n);
        int ans =0;
        while(!minHeap.empty()){
            vector<int> cur = minHeap.top();
            minHeap.pop();
            if(d.find(cur[1]) == d.find(cur[2])) continue;
            d.unionf(cur[1], cur[2]);
            ans+= cur[0];
        }
        
        return ans;
    }
};
