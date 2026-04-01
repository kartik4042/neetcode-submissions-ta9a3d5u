struct TrieNode
{
    TrieNode* children[26];
    bool endOfWord;

    TrieNode()
    {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        endOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch : word)
        {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch : prefix)
        {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
