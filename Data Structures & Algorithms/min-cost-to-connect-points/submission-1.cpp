class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[0]- p2[0])+ abs(p1[1]- p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<int> distTo(n, INT_MAX);
        distTo[0] = 0;
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        int ans = 0;
        while(!q.empty()){
            int cur = q.front();
            visited[cur]= true;
            int nxtNode = -1;
            ans += distTo[cur];
            q.pop();
            for(int i=0; i<n; i++){
                if(visited[i]) continue;
                distTo[i] = min(distTo[i], distance(points[cur], points[i]));
                if(nxtNode == -1 || distTo[nxtNode] > distTo[i]){
                    nxtNode = i;
                }
            }
            
            if(nxtNode != -1)
            q.push(nxtNode);
        }
        return ans;
    }
};
