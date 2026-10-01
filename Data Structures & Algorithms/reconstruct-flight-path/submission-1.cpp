class Solution {
public:
    vector<string> itinerary;
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, string src){
        while(!graph[src].empty()){
            string nbr = graph[src].top();
            graph[src].pop();
            dfs(graph, nbr);
        }
        itinerary.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(vector<string> t: tickets){
            graph[t[0]].push(t[1]);
        }
        dfs(graph, "JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
