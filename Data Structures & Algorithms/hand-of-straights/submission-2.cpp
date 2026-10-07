class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n% groupSize) return false;
        // 1 2 2 3 3 4 6 7 8
        // 1 3
        // 2
        // 2
        vector<vector<int>> groups(n/groupSize);
        set<int> m;
        unordered_map<int,int> f;
        for(int h: hand){
            m.insert(h);
            f[h]+=1;
        }
        for(int i=0; i<groups.size(); i++){
            int prev = *m.begin();
            f[prev]-=1;
            if(f[prev] == 0) m.erase(m.begin());

            for(int j=0; j<groupSize-1; j++)
            {
                if(m.find(prev+1) == m.end()) return false;
                f[prev+1]-=1;
                if(f[prev+1] == 0){
                    m.erase(prev+1);
                }
                prev +=1;
            }

        }

        return true;
    }
};
