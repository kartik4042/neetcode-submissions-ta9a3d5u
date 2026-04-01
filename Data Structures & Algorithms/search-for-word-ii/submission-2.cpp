struct TrieNode
{
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode()
    {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;

        idx = -1;
        refs = 0;
    }

    void addWord(string& word, int i)
    {
        TrieNode* curr = this;
        curr->refs++;
        for(char ch : word)
        {
            int index = ch - 'a';
            if(curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
            curr->refs++;
        }
        curr->idx = i;
    }
};

class Solution {
public:
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++)
            root->addWord(words[i], i);

        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c < board[0].size(); c++)
            {
                dfs(r, c, board, words, root);
            }
        }  
        return res;  
    }

    void dfs(int r, int c, vector<vector<char>>& board, vector<string>& words, TrieNode* node)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '*' || node->children[board[r][c] - 'a'] == nullptr)
            return;

        char temp = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->children[temp - 'a'];
        if(node->idx != -1)
        {
            res.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;

            if(node->refs == 0)
            {
                prev->children[temp - 'a'] = nullptr;
                node = nullptr;
                board[r][c] = temp;
                return;
            }
        }

        dfs(r+1, c, board, words, node);
        dfs(r-1, c, board, words, node);
        dfs(r, c+1, board, words, node);
        dfs(r, c-1, board, words, node);

        board[r][c] = temp;
    }
};
