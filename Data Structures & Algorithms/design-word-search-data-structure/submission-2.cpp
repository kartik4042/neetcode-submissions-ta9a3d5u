struct TrieNode
{
    TrieNode* children[26];
    bool word;

    TrieNode()
    {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        word = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string word, int j, TrieNode* root)
    {
        TrieNode* curr = root;
        for(int i = j; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            if(ch == '.')
            {
                for(TrieNode* child : curr->children)
                {
                    if(child != nullptr && dfs(word, i + 1, child))
                        return true;
                }
                return false;
            }
            else
            {
                if(curr->children[idx] == nullptr)
                    return false;
                curr = curr->children[idx];
            }
        }
        return curr->word;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
