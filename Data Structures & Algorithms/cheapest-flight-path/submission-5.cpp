class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> graph(n);
        for(vector<int> f: flights){
            graph[f[0]].push_back({f[2], f[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costTo(n, INT_MAX);
        vector<int> stopsTo(n, INT_MAX);
        pq.push({0,0, src}); // cost, stops, node
        costTo[src] = 0;
        stopsTo[src] = 0;
        vector<int> visited(n, false);
        while(!pq.empty()){
            vector<int> cur = pq.top();
            // cout<<cur[2]<<endl;
            pq.pop();
            if(cur[1] > k+1) continue;
            if(cur[2] == dst) return cur[0];
            // if(visited[cur[2]]) continue;
            // visited[cur[2]] = true;
            for(vector<int> nbr: graph[cur[2]]){
                if(costTo[nbr[1]] > cur[0]+ nbr[0]){
                    costTo[nbr[1]] = cur[0]+ nbr[0];
                    stopsTo[nbr[1]] = cur[1] + 1;
                    pq.push({cur[0]+ nbr[0], cur[1]+ 1, nbr[1]});
                }
                else if(stopsTo[nbr[1]] > cur[1]+ 1){
                    costTo[nbr[1]] = cur[0]+ nbr[0];
                    stopsTo[nbr[1]] = cur[1] + 1;
                    pq.push({cur[0]+ nbr[0], cur[1]+ 1, nbr[1]});
                }
            }

        }
        return -1;
    }
};
