class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sorted intervals
        // intervals[i][0] >= qPoint  and intervals[i][1] <= qPoint
        sort(intervals.begin(), intervals.end());
        vector<int> myQueries(queries.begin(), queries.end());
        sort(myQueries.begin(), myQueries.end());
        unordered_map<int,int> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int i=0;
        for(int j=0; j<myQueries.size(); j++){
            // skip intervals from heap that end before the query point
            // move till the interval that starts after query point
            while(i< intervals.size() && intervals[i][0] <= myQueries[j]) 
            {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right-left+1, right});
                i++;
            }
            while(pq.size() > 0 and pq.top()[1] < myQueries[j]){
                pq.pop();
            }
            if(pq.size() > 0){
                ans[myQueries[j]] = pq.top()[0];
            }
        }
        vector<int> res;

        for(int i=0; i<queries.size(); i++){
            if(ans.count(queries[i]))
                res.push_back(ans[queries[i]]);
            else
                res.push_back(-1);
        }
        return res;
    }
};
