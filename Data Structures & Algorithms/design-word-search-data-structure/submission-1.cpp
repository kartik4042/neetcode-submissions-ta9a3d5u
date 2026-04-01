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
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void freeNode(TrieNode* node)
    {
        for(int i = 0; i < 26; i++)
        {
            if(node->children[i] != nullptr)
                freeNode(node->children[i]);
        }
        delete node;
    }

    ~WordDictionary()
    {
        freeNode(root);
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
        return dfs(word, root, 0);
    }

    bool dfs(string word, TrieNode* node, int j)
    {
        TrieNode* curr = node;
        for(int i = j; i < word.size(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            if(ch == '.')
            {
                for(TrieNode* child : curr->children)
                {
                    if(child != nullptr && dfs(word, child, i + 1))
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
};
