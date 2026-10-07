class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> lastOcc(26);
        for(int i=0; i<n; i++){
            lastOcc[s[i]- 'a'] = i;
        }
        int st = 0;
        vector<int> ans;
        int farthest = 0;
        for(int i=0; i<n; i++){
            farthest = max(lastOcc[s[i]-'a'], farthest);
            if(i == farthest){
                ans.push_back(i-st+1);
                farthest = i+1;
                st = i+1;
            }
        }
        return ans;
    }
};
