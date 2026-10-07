class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans;
        for(int i=0; i<=num1.size()+ num2.size(); i++) ans.push_back(0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<num1.size(); i++){
            for(int j=0; j<num2.size(); j++){
                int d1 = num1[i] -'0';
                int d2 = num2[j] -'0';
                ans[i+j] += (d1*d2);
                ans[i+j+1] += ans[i+j] /10;
                ans[i+j] %=10;
            }
        }
        while(ans.back() == 0 && ans.size() > 1) ans.pop_back();
        reverse(ans.begin(), ans.end());
        string res;
        for(int d: ans){
            res.push_back(d+'0');
        }
        return res;
    }
};
