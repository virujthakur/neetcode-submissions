class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 4 6 8 10
        // 1 4 7 10
        int n = position.size();
        vector<vector<int>> posAndSpeed;
        for(int i=0; i<n; i++){
            posAndSpeed.push_back({position[i], speed[i]});
        }
        sort(posAndSpeed.begin(), posAndSpeed.end());
        stack<double> st;
        for(int i=n-1; i>=0; i--){
            double curTime = (double) (target - posAndSpeed[i][0]) / posAndSpeed[i][1];
            if(st.size() > 0 and curTime <= st.top()){
                continue;
            }
            st.push(curTime);
        }

        return st.size();
    }
};
