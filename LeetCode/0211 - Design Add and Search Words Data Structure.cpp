class WordDictionary {
public:
    
    struct node {
        node *children[26];
        node(){
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }
    };
    
    node * dictionary [26];

    WordDictionary() {            
        for(int i=0; i<26; i++)
            dictionary[i] = NULL;
    }
    
    void addWord(string word) {

        if(!dictionary[word.size()])
            dictionary[word.size()] = new node();
       
        node *current = dictionary[word.size()];
        for(int i = 0; i< word.size(); i++){
            int index = word[i] - 'a';
            if(current->children[index] == NULL)
                current->children[index] = new node();
            current = current->children[index];
        }
    }
    
    bool searchPattern(node* current,string word, int i){
        
        if(!current)
            return false;

        int index = word[i] - 'a';

        if(i == word.size()-1)
            return word[i]=='.' || current->children[index];
        
        bool ans = false;
        if(word[i]=='.'){
            for(int j=0; j<26  && !ans; j++)
                if(current->children[j])
                    ans |= searchPattern(current->children[j], word, i + 1);
        }
        else{
            if(current->children[index]) 
                ans = searchPattern(current->children[index], word, i + 1);
        }
        return ans;    
    }

    bool search(string word) {
        return searchPattern(dictionary[word.size()],word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */