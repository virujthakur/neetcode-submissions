class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> f;
        int mxF = 0;
        for(auto c: tasks) 
        {
            f[c]+=1;
            mxF = max(f[c], mxF);
        }
        int mxCnt = 0;
        for(auto x: f){
            if(x.second == mxF) mxCnt+=1;
        }
        // AB _  AB
        int parts = mxF -1;
        int spacesPerPart = n- (mxCnt- 1);
        int spaces = parts * spacesPerPart;
        // cout<<spaces<<endl;
        int available = tasks.size() - (mxF * mxCnt);

        int empty = max(0, spaces- available);
        return tasks.size() + empty;
    }
};
