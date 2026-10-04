class TrieNode{
    public:
    TrieNode* next[26];
    bool isWord = false;
};
class Trie{
    public:
    TrieNode* root = new TrieNode();
    void insert(string& s){
        TrieNode* cur = root;
        for(char c: s){
            if(cur->next[c-'a'] == nullptr){
                TrieNode* newNode = new TrieNode();
                cur->next[c-'a'] = newNode;
            }
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }
    bool search(string& s, int i, TrieNode* cur){
        if(cur == nullptr) return false;

        if(i == s.size()){
            return cur->isWord;
        }

        if(s[i] == '.'){
            bool ans = false;
            for(int j=0; j<26; j++){
                ans |= search(s, i+1, cur->next[j]);
            }
            return ans;
        }
        else{
            return search(s, i+1, cur->next[s[i] -'a']);
        }
    }
};

class WordDictionary {
public:
    Trie t;
    WordDictionary() {

    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word, 0, t.root);
    }
};
