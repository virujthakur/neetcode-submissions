class Solution {
public:
    int recur(string& word1, string& word2, int i, int j){
        int n= word1.size();
        int m= word2.size();
        // if(i==n && j==m) return 0;
        if(j==m) return n-i;
        if(i==n) return m-j;
        if(word1[i] == word2[j]) return recur(word1, word2, i+1, j+1);
        else{
            // delete 
            int ans1 = 1+ recur(word1, word2, i+1, j);
            // replace
            int ans2 = 1e9, ans3 = 1e9;
            if(j<m)
            {
                ans2 = 1+ recur(word1, word2, i+1, j+1);
                // insert
                ans3 = 1+ recur(word1, word2, i, j+1);
            }
            return min({ans1, ans2, ans3});
        }
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n][m] = 0;
        for(int i=0; i<m; i++){
            dp[n][i] = m-i;
        }
        for(int i=0; i<n; i++){
            dp[i][m] = n-i;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] =1+ min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                }
            }
        }
        return dp[0][0];
        

        // return recur(word1, word2, 0, 0);
    }
};
