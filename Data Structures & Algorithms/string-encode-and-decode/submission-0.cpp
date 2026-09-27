class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string word: strs){
            ans +=to_string(word.size());
            ans+= "H";
            ans += word;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> words;
        for(int i=0; i<s.size(); i++){
            int len = 0;
            string l;
            while(s[i]!='H'){
                l.push_back(s[i]);
                i++;
            }
            len= stoi(l);
            // cout<<len<<endl;

            string word;
            int j=i+1;
            for(; j<=i+len; j++){
                word.push_back(s[j]);
            }
            i=j-1;
            words.push_back(word);
        }
        return words;
    }
};
