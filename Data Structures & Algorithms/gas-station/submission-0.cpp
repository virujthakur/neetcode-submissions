class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff;
        for(int i=0; i<n; i++){
            diff.push_back(gas[i] - cost[i]);
        }
        for(int i=0; i<n; i++){
            diff.push_back(gas[i] - cost[i]);
        }

        int s= 0;
        int i=0;
        int ans = 0;
        int idx = -1;
        for(int j=0; j<2*n; j++){
            s+= diff[j];
            while(s < 0){
                s -= diff[i];
                i++;
            }
            ans = max(ans, j-i+1);
            if(ans >=n){
                idx = i % n;
            }
        }
        return idx;
    }
};
