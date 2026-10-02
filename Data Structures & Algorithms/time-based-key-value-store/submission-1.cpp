class TimeMap {
public:
    int lessThanOrEqual(vector<pair<int,string>>& v, pair<int,string> val){
        int l = 0;
        int h = v.size()-1;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(v[mid].first > val.first){
                h = mid-1;
            }
            else{
                ans = max(ans, mid);
                l = mid + 1;
            }
        }
        return ans;
    }
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        // first value less than or equal to timestamp
        int idx = lessThanOrEqual(mp[key], {timestamp, ""});
        if(idx == -1) return "";
        return mp[key][idx].second;
    }
};
