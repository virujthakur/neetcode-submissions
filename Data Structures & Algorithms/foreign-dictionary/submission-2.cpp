class Solution {
public:
    string result;
    bool dfsTopo(vector<vector<int>>& graph, int src, vector<int>& visited){
        if(visited[src] == 1){
            return true;
        }
        if(visited[src] == 2){
            return false;
        }
        visited[src] = 1;
        for(int i=0; i<26; i++){
            if(graph[src][i] == 1)
                if(dfsTopo(graph, i, visited)) return true;
        }
        result.push_back((char)(src + 'a'));
        visited[src] = 2;
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> graph(26, vector<int>(26));
        vector<bool> found(26, 0);
        int src = -1;
        for(int i=0; i<n; i++){
            for(int k=0; k< words[i].size() ; k++){
                found[words[i][k]-'a'] = true;
            }

            for(int j=i+1; j<n; j++){
                int idx = -1;
                int minLen = min(words[i].size(), words[j].size());
                if (words[i].size() > words[j].size() && words[i].substr(0, minLen) == words[j].substr(0,minLen)) return "";


                for(int k=0; k< min(words[i].size(), words[j].size()); k++){
                    if(words[i][k]!= words[j][k]) {
                        idx = k;
                        break;
                    }
                }
                if(idx != -1){
                    graph[words[i][idx] -'a'][words[j][idx]-'a'] = 1;
                }
            }
        }

        vector<int> visited(26);
        for(int i=0; i<26; i++){
            if(found[i]){
                if(dfsTopo(graph, i, visited)) return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
