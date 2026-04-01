struct Node
{
    unique_ptr<Node> children[26];
    bool isEnd;
    
    Node() : isEnd(false) {}
};

class PrefixTree
{
    private:
        unique_ptr<Node> root;

    public:
        PrefixTree() : root(make_unique<Node>()) {}
        ~PrefixTree() = default;

        void insert(string word)
        {
            Node* curr = root.get();
            for(char ch : word)
            {
                int idx = ch - 'a';
                if(curr->children[idx] == nullptr)
                    curr->children[idx] = make_unique<Node>();
                curr = curr->children[idx].get();
            }
            curr->isEnd = true;
        }

        bool search(string word)
        {
            Node* curr = root.get();
            for(char ch : word)
            {
                int idx = ch - 'a';
                if(curr->children[idx] == nullptr)
                    return false;
                curr = curr->children[idx].get();
            }
            return curr->isEnd;
        }

        bool startsWith(string prefix)
        {
            Node* curr = root.get();
            for(char ch : prefix)
            {
                int idx = ch - 'a';
                if(curr->children[idx] == nullptr)
                    return false;
                curr = curr->children[idx].get();
            }
            return true;
        }
};
