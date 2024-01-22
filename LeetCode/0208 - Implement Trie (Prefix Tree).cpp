class Trie {
public:

    struct node {
        node *children[26];
        node(){
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }
    };
    unordered_set<string> st;
    node* root;
    
    Trie() {
        root= new node(); 
    }
    
    void insert(string value) {
        st.insert(value);
        node *current = root;
        for(int i = 0; i< value.size(); i++){
            int index = value[i] - 'a';
            if(current->children[index] == NULL)
                current->children[index] = new node();
            current = current->children[index];
        }
    }
    
    bool search(string value) {
        return st.count(value);
    }
    
    bool startsWith(string value) {
        node *current = root;
        for(int i = 0; i< value.size(); i++){
            int index = value[i] - 'a';
            if(current->children[index] == NULL)
                return false;
            current = current->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */