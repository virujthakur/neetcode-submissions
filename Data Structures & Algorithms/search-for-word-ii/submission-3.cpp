class Solution {
public:
    class TrieNode{
        public:
        TrieNode* child[26];
        int refs;
        bool isWord;

    };
    class Trie{
        public:
        TrieNode* root = new TrieNode();
        void insert(string& word){
            TrieNode* cur = root;
            for(char c: word){
                // cout<<c<<endl;
                if(cur->child[c-'a'] == nullptr){
                    cur->child[c-'a'] = new TrieNode();
                }
                cur = cur->child[c-'a'];
                cur->refs+=1;
            }
            cur->isWord = true;
        }
    };
    vector<string> ans;
    vector<vector<int>> directions ={{0,1}, {1,0}, {0,-1}, {-1,0}};
    int dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, TrieNode* prev, string word){
        int m= board.size();
        int n= board[0].size();
        if(root == nullptr) return 0;

        int found = 0;
        if(root->isWord == true){
            ans.push_back(word);
            root->isWord = false;
            found+=1;
        }

        char old = board[i][j];
        board[i][j] = '.';
        for(vector<int> d: directions){
            int newi = i+ d[0];
            int newj = j+ d[1];
            if(newi >=0 and newj >=0 and newi < m and newj < n and board[newi][newj]!='.'){
                string newWord = word;
                newWord.push_back(board[newi][newj]);
                found+= dfs(board, newi, newj, root->child[board[newi][newj]-'a'],root, newWord);
            }
        }
        root->refs-= found;
        if(root->refs == 0){
            prev->child[old-'a'] = nullptr;
        }
        board[i][j] = old;
        return found;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        int m = board.size();
        int n= board[0].size();
        for(string word: words){
            t.insert(word);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                string word;
                word.push_back(board[i][j]);
                dfs(board, i,j, t.root->child[board[i][j]-'a'], t.root, word);
            }
        }

        return ans;

    }
};
