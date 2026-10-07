class Solution {
public:
    static bool compare(vector<int>& A, vector<int>& B){
        if(A[1] == B[1]){
            return A[0] < B[0];
        }
        return A[1]< B[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int i=0;    
        int cnt = 0;
        for(int j=1; j<n; j++){
            if(intervals[j][0] < intervals[i][1]){
                cnt+=1;
                continue;
            }
            else{
                i=j;
            }

        }
        return cnt;
    }
};
